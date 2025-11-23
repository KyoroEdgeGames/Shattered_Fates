"""
Main entry point for Shattered Fates (Arcade version).

Provides a simple Arcade window-friendly DevMode class, player utilities,
and JSON helpers. This file converts the previously pygame-based UI to use
arcade drawing and event conventions.
"""

from __future__ import annotations

import json
import logging
import os
from typing import TYPE_CHECKING, Any, Dict, List, Optional, Tuple, Union

if TYPE_CHECKING:
    import arcade  # pragma: no cover  # type: ignore[import]

# Safe runtime import with a minimal stub for environments where arcade is not installed
try:
    import arcade  # type: ignore[import]
except ImportError:

    class _ArcadeStub:  # pragma: no cover
        class key:
            ENTER = 13
            RETURN = 13
            BACKSPACE = 8
            F1 = 282
            W = 119
            A = 97
            S = 115
            D = 100
            UP = 273
            DOWN = 274
            LEFT = 276
            RIGHT = 275

        class color:
            WHITE = (255, 255, 255)
            LIGHT_GRAY = (200, 200, 200)
            DARK_GRAY = (64, 64, 64)
            GRAY = (128, 128, 128)
            RED_ORANGE = (200, 50, 50)
            AERO_BLUE = (0, 150, 200)
            DARK_SLATE_GRAY = (47, 79, 79, 255)

        class Window:
            def __init__(self, width=800, height=600, title=""):
                self.width = width
                self.height = height
                self.title = title

            def clear(self, *_, **__):
                return None

        @staticmethod
        def draw_lrbt_rectangle_filled(*_, **__):
            return None

        @staticmethod
        def draw_rectangle_filled(*_, **__):
            return None

        @staticmethod
        def draw_text(*_, **__):
            return None

        @staticmethod
        def set_background_color(*_, **__):
            return None

        def run(self):
            raise RuntimeError("Arcade not available")

    arcade = _ArcadeStub()  # type: ignore
    # Expose module-level drawing functions on the stub instance so code that
    # calls `arcade.draw_rectangle_filled(...)` resolves during static analysis
    # and at runtime when the real `arcade` package is not installed.
    try:
        arcade.draw_lrbt_rectangle_filled = _ArcadeStub.draw_lrbt_rectangle_filled
        arcade.draw_rectangle_filled = _ArcadeStub.draw_rectangle_filled
        arcade.draw_text = _ArcadeStub.draw_text
        arcade.set_background_color = _ArcadeStub.set_background_color
    except AttributeError:
        pass

# Provide a stable base class alias for static analysis and dynamic use.
BaseWindow = getattr(arcade, "Window", object)


# Safe, analyzer-friendly wrappers for drawing functions. These resolve to the
# real `arcade` functions if present, or the stub equivalents, otherwise no-op.
def _arcade_draw_lrbt_rectangle_filled(*args, **kwargs):
    func = getattr(arcade, "draw_lrbt_rectangle_filled", None)
    if not callable(func):
        func = getattr(
            getattr(arcade, "Window", object), "draw_lrbt_rectangle_filled", None
        )
    if callable(func):
        return func(*args, **kwargs)


def _arcade_draw_rectangle_filled(*args, **kwargs):
    func = getattr(arcade, "draw_rectangle_filled", None)
    if not callable(func):
        func = getattr(getattr(arcade, "Window", object), "draw_rectangle_filled", None)
    if callable(func):
        return func(*args, **kwargs)


def _arcade_draw_text(*args, **kwargs):
    func = getattr(arcade, "draw_text", None)
    if not callable(func):
        func = getattr(getattr(arcade, "Window", object), "draw_text", None)
    if callable(func):
        return func(*args, **kwargs)


def _arcade_set_background_color(*args, **kwargs):
    func = getattr(arcade, "set_background_color", None)
    if not callable(func):
        func = getattr(getattr(arcade, "Window", object), "set_background_color", None)
    if callable(func):
        return func(*args, **kwargs)


# --- Logging setup ---
logging.basicConfig(level=logging.INFO)

# Window settings
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
FPS = 60

# Paths (data folder is assumed to be at project_root/data)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.normpath(os.path.join(BASE_DIR, "data"))
CHAR_DIR = os.path.join(DATA_DIR, "Characters")
SPRITE_DIR = os.path.normpath(os.path.join(BASE_DIR, "sprites"))

# Ensure character folder exists (so file checks won't error)
os.makedirs(CHAR_DIR, exist_ok=True)


# --- Utility functions ---
def read_json_safe(path: str) -> Optional[Dict[str, Any]]:
    """Read a JSON file safely, returning a dict or None if missing/invalid."""
    if not os.path.exists(path):
        return None
    try:
        with open(path, "r", encoding="utf-8") as fh:
            return json.load(fh)
    except (json.JSONDecodeError, OSError):
        return None


def clamp(value: float, minimum: float, maximum: float) -> float:
    """Clamp a float value between min and max inclusive."""
    return max(minimum, min(maximum, value))


def load_npc(npc_name: str, fallback_index: int = 0) -> Dict[str, Any]:
    """Load NPC data from JSON, with fallbacks for missing keys."""
    path = os.path.join(CHAR_DIR, f"{npc_name}.json")
    data = read_json_safe(path) or {}
    return {
        "name": data.get("name", npc_name),
        "sprite": data.get("sprite", f"npc_{fallback_index}.png"),
        "level": data.get("level", 1),
        "dialogue": data.get("dialogue", []),
        **{
            k: v
            for k, v in data.items()
            if k not in {"name", "sprite", "level", "dialogue"}
        },
    }


def load_npc_physical(npc_name: str, fallback_index: int = 0) -> Dict[str, Any]:
    """
    Load NPC data including physical rectangle fields (x, y, width, height).
    Returns a dict with keys: name, clan, role, x, y, width, height.
    """
    path = os.path.join(CHAR_DIR, f"{npc_name}.json")
    data = read_json_safe(path) or {}

    x = int(data.get("x", 200 + fallback_index * 100))
    y = int(data.get("y", 200))
    w = int(data.get("width", 40))
    h = int(data.get("height", 40))

    if w <= 0:
        w = 40
    if h <= 0:
        h = 40

    return {
        "name": data.get("name", npc_name),
        "clan": data.get("clan", data.get("Clan", "Unknown")),
        "role": data.get("role", data.get("Role", "NPC")),
        "x": x,
        "y": y,
        "width": w,
        "height": h,
    }


# --- Sprite helpers ---
def list_sprites() -> List[str]:
    """Return list of sprite filenames in the sprites directory."""
    try:
        return [f for f in os.listdir(SPRITE_DIR) if os.path.isfile(os.path.join(SPRITE_DIR, f))]
    except OSError:
        return []


def sprite_path(sprite_name: str) -> str:
    """Return a filesystem path to `sprite_name`.

    If `sprite_name` already includes an extension and exists, that path is
    returned. Otherwise the function will try common image extensions.
    Returns an empty string when not found.
    """
    if not sprite_name:
        return ""

    # If sprite_name already looks like a path, check directly
    candidate = os.path.join(SPRITE_DIR, sprite_name)
    if os.path.exists(candidate):
        return candidate

    # Try common image extensions
    for ext in (".png", ".jpg", ".jpeg", ".gif"):
        p = candidate + ext
        if os.path.exists(p):
            return p

    return ""


def load_sprite(sprite_name: str) -> Optional[Any]:
    """Load a sprite as an `arcade` texture when possible, otherwise return
    the filesystem path or None if not found.
    """
    path = sprite_path(sprite_name)
    if not path:
        return None

    load_fn = getattr(arcade, "load_texture", None)
    if callable(load_fn):
        try:
            return load_fn(path)
        except (OSError, ValueError):
            # Fall back to returning the path if arcade cannot load it at runtime
            return path
    return path


# --- Developer mode utilities ---
class Player:
    """Represents a player entity in developer mode with inventory and experience."""

    def __init__(self) -> None:
        self.inventory: List[str] = []
        self.exp: int = 0

    def add_item(self, item: str) -> None:
        item = (item or "").strip()
        if item:
            self.inventory.append(item)
            logging.info("Added %s to player inventory", item)
        else:
            logging.warning("Item name cannot be empty.")

    def add_experience(self, amount: Union[str, int]) -> None:
        try:
            val = int(amount)
            if val > 0:
                self.exp += val
                logging.info("Added %s XP to player (total=%s)", val, self.exp)
            else:
                logging.warning("XP must be a positive integer.")
        except (TypeError, ValueError):
            logging.warning("Invalid XP amount; must be an integer.")


class DevMode:
    """
    Handles developer mode UI and interactions for testing using arcade.

    Usage with an arcade.Window subclass:
    - In the Window's __init__, create DevMode(window, font_size=14).
    - In Window.on_draw call dev_mode.draw().
    - In Window.on_mouse_press call dev_mode.on_mouse_press(x, y, button, modifiers).
    - In Window.on_key_press call dev_mode.on_key_press(symbol, modifiers).
    - In Window.on_text call dev_mode.on_text(text).
    - Toggle with dev_mode.toggle().
    """

    Button = Tuple[float, float, float, float]  # center_x, center_y, width, height

    def __init__(self, player: Player, window: Any, font_size: int = 14) -> None:
        self.player = player
        self.window = window
        self.font_size = font_size
        self.active: bool = False

        # Buttons stored as (center_x, center_y, width, height)
        self.buttons: Dict[str, DevMode.Button] = {
            "Give Item": (125.0, 525.0, 150.0, 40.0),
            "Give XP": (125.0, 475.0, 150.0, 40.0),
        }

        self.input_mode: Optional[str] = None  # "item" | "xp" | None
        self.input_text: str = ""
        self.panel_left = 40.0
        self.panel_bottom = 440.0
        self.panel_width = 260.0
        self.panel_height = 210.0

    # --- Public control ---
    def toggle(self) -> None:
        self.active = not self.active
        if not self.active:
            self.input_mode = None
            self.input_text = ""

    # --- Input helpers ---
    @staticmethod
    def _point_in_button(x: float, y: float, button: Button) -> bool:
        cx, cy, w, h = button
        left = cx - w / 2
        right = cx + w / 2
        bottom = cy - h / 2
        top = cy + h / 2
        return left <= x <= right and bottom <= y <= top

    def on_mouse_press(self, x: float, y: float, _button: int, _modifiers: int) -> None:
        if not self.active:
            return

        for name, rect in self.buttons.items():
            if self._point_in_button(x, y, rect):
                if name == "Give Item":
                    self.input_mode = "item"
                    self.input_text = ""
                elif name == "Give XP":
                    self.input_mode = "xp"
                    self.input_text = ""
                return

    def on_key_press(self, symbol: int, _modifiers: int) -> None:
        if not self.active:
            return

        # Enter/Return submits input
        if self.input_mode and symbol in (arcade.key.ENTER, arcade.key.RETURN):
            if self.input_mode == "item":
                self.player.add_item(self.input_text.strip())
            elif self.input_mode == "xp":
                self.player.add_experience(self.input_text.strip())
            self.input_mode = None
            self.input_text = ""
            return

        # Backspace removes character
        if self.input_mode and symbol == arcade.key.BACKSPACE:
            self.input_text = self.input_text[:-1]

    def on_text(self, text: str) -> None:
        if not self.active or not self.input_mode:
            return
        if text and text.isprintable():
            self.input_text += text

    # --- Drawing ---
    def draw(self) -> None:
        if not self.active:
            return

        # Panel background (semi-transparent)
        _arcade_draw_lrbt_rectangle_filled(
            self.panel_left,
            self.panel_left + self.panel_width,
            self.panel_bottom,
            self.panel_bottom + self.panel_height,
            (50, 50, 50, 200),
        )

        # Title
        _arcade_draw_text(
            "Developer Mode (F1 to toggle)",
            self.panel_left + 10,
            self.panel_bottom + self.panel_height - 24,
            arcade.color.WHITE,
            self.font_size,
        )

        # Draw buttons
        for name, (cx, cy, w, h) in self.buttons.items():
            _arcade_draw_rectangle_filled(cx, cy, w, h, arcade.color.DARK_GRAY)
            _arcade_draw_text(
                name,
                cx - w / 2 + 8,
                cy - self.font_size / 2,
                arcade.color.WHITE,
                self.font_size,
            )

        # Input box
        if self.input_mode:
            label = "Item:" if self.input_mode == "item" else "XP:"
            _arcade_draw_text(
                label,
                self.panel_left + 10,
                self.panel_bottom + 40,
                arcade.color.WHITE,
                self.font_size,
            )

            input_left = self.panel_left + 10
            input_bottom = self.panel_bottom + 10
            input_width = 150
            input_height = 30
            _arcade_draw_rectangle_filled(
                input_left + input_width / 2,
                input_bottom + input_height / 2,
                input_width,
                input_height,
                arcade.color.GRAY,
            )
            _arcade_draw_text(
                self.input_text,
                input_left + 6,
                input_bottom + 6,
                arcade.color.WHITE,
                self.font_size,
            )

        # Debug info (current XP and number of items)
        info = f"XP: {self.player.exp} | Items: {len(self.player.inventory)}"
        _arcade_draw_text(
            info,
            self.panel_left + 10,
            self.panel_bottom + 5,
            arcade.color.LIGHT_GRAY,
            self.font_size,
        )


# --- Main game window ---
class GameWindow(BaseWindow):  # type: ignore
    """Main game window using arcade, with simple player rectangle, NPCs, and DevMode."""

    def __init__(self) -> None:
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, "Shattered Fates")
        _arcade_set_background_color(arcade.color.DARK_SLATE_GRAY)

        # Player placeholder (rectangle)
        self.player_x = 100.0
        self.player_y = 100.0
        self.player_w = 40.0
        self.player_h = 40.0
        self.player_speed = 4.0

        # Dev mode player and UI
        self.dev_player = Player()
        self.dev_ui = DevMode(self.dev_player, self, font_size=14)

        # Load example NPCs (positions staggered so they don't overlap)
        npc_names = ["Ivypaw", "Bramblekit"]
        self.npcs: List[Dict[str, Any]] = []
        for idx, name in enumerate(npc_names):
            npc = load_npc_physical(name, fallback_index=idx)
            self.npcs.append(npc)

        self.currently_colliding: Dict[str, bool] = {
            npc["name"]: False for npc in self.npcs
        }

        # Keyboard state
        self.held_keys: Dict[int, bool] = {}

    # Implement methods that some type-checkers expect from `arcade.Window`.
    # These are lightweight, no-op implementations needed only to satisfy
    # static analysis when the real `arcade` base class defines them as
    # abstract.
    def get_clipboard_text(self) -> str:
        return ""

    def set_clipboard_text(self, text: str) -> None:
        # Parameter kept to match arcade.Window API; mark as used.
        _ = text
        return None

    def set_mouse_passthrough(self, state: bool) -> None:
        _ = state
        return None

    # --- Input forwarding for DevMode ---
    def on_mouse_press(self, x: float, y: float, _button: int, _modifiers: int) -> None:
        self.dev_ui.on_mouse_press(x, y, _button, _modifiers)

    def on_key_press(self, symbol: int, _modifiers: int) -> None:
        # Toggle dev panel with F1
        if symbol == arcade.key.F1:
            self.dev_ui.toggle()
            return

        # Forward to dev mode (it will ignore if inactive)
        self.dev_ui.on_key_press(symbol, _modifiers)

        # Track movement keys
        self.held_keys[symbol] = True

    def on_key_release(self, symbol: int, _modifiers: int) -> None:
        # Remove tracked key
        self.held_keys.pop(symbol, None)

    def on_text(self, text: str) -> None:
        # Forward typed characters to dev mode for text input
        self.dev_ui.on_text(text)

    # --- Update / logic ---
    def on_update(self, delta_time: float) -> None:
        # Movement input (WASD + arrows)
        _ = delta_time
        if (arcade.key.W in self.held_keys) or (arcade.key.UP in self.held_keys):
            self.player_y += self.player_speed
        if (arcade.key.S in self.held_keys) or (arcade.key.DOWN in self.held_keys):
            self.player_y -= self.player_speed
        if (arcade.key.A in self.held_keys) or (arcade.key.LEFT in self.held_keys):
            self.player_x -= self.player_speed
        if (arcade.key.D in self.held_keys) or (arcade.key.RIGHT in self.held_keys):
            self.player_x += self.player_speed

        # Keep player inside window bounds
        self.player_x = clamp(self.player_x, 0, SCREEN_WIDTH - self.player_w)
        self.player_y = clamp(self.player_y, 0, SCREEN_HEIGHT - self.player_h)

        # Simple collision detection (AABB)
        for npc in self.npcs:
            if self._rects_collide(
                self.player_x,
                self.player_y,
                self.player_w,
                self.player_h,
                npc["x"],
                npc["y"],
                npc["width"],
                npc["height"],
            ):
                if not self.currently_colliding.get(npc["name"], False):
                    print(f"You bumped into {npc['name']} ({npc.get('role', 'NPC')}).")
                    self.currently_colliding[npc["name"]] = True
            else:
                self.currently_colliding[npc["name"]] = False

    @staticmethod
    def _rects_collide(
        x1: float,
        y1: float,
        w1: float,
        h1: float,
        x2: float,
        y2: float,
        w2: float,
        h2: float,
    ) -> bool:
        """Axis-aligned rectangle collision test. These are corner-based rectangles."""
        left1, right1 = x1, x1 + w1
        bottom1, top1 = y1, y1 + h1
        left2, right2 = x2, x2 + w2
        bottom2, top2 = y2, y2 + h2
        return not (
            right1 <= left2 or right2 <= left1 or top1 <= bottom2 or top2 <= bottom1
        )

    # --- Drawing ---
    def on_draw(self) -> None:
        self.clear()

        # Draw NPCs
        for npc in self.npcs:
            _arcade_draw_lrbt_rectangle_filled(
                npc["x"],
                npc["x"] + npc["width"],
                npc["y"],
                npc["y"] + npc["height"],
                arcade.color.RED_ORANGE,
            )

        # Draw player (on top)
        _arcade_draw_lrbt_rectangle_filled(
            self.player_x,
            self.player_x + self.player_w,
            self.player_y,
            self.player_y + self.player_h,
            arcade.color.AERO_BLUE,
        )

        # Draw dev mode UI on top
        self.dev_ui.draw()


def main() -> None:
    """Start the arcade application.

    If the runtime environment cannot create an OpenGL context (for example
    on systems without a suitable GPU/driver), the function will print a
    helpful message and exit. Use `--no-window` to skip creating a window
    (useful for CI or headless runs).
    """
    import sys

    no_window = "--no-window" in sys.argv or "--headless" in sys.argv

    if no_window:
        print("Headless mode: skipping window creation (--no-window passed).")
        return

    try:
        _window = GameWindow()
        arcade.run()
    except Exception as exc:  # pragma: no cover - runtime environment dependent
        # Detect common platform/driver errors and provide guidance rather
        # than crashing with a low-level traceback the user may not parse.
        msg = str(exc)
        if (
            "glGetStringi" in msg
            or "OpenGL 3.0" in msg
            or "MissingFunctionException" in type(exc).__name__
        ):
            print(
                "Unable to create an OpenGL context. Your system OpenGL driver may be too old or missing."
            )
            print("Suggestions:")
            print(" - Update your GPU drivers (Windows Update or vendor drivers).")
            print(" - Run this program on a machine with a modern GPU/driver.")
            print(
                " - For CI/headless runs, start with `python main.py --no-window` instead."
            )
            return
        if isinstance(exc, RuntimeError) and "Arcade not available" in msg:
            print(
                "Arcade package not available in this environment. Install it or run with --no-window."
            )
            return
        # Unknown error: re-raise so it's visible during debugging
        raise


if __name__ == "__main__":
    main()
