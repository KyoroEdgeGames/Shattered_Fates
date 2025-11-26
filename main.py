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
from typing import TYPE_CHECKING, Any, Dict, List, Optional, Tuple, Union, Callable, cast

# Prefer importing these at module level so linters don't flag imports inside
# functions; fall back to None when unavailable.
try:
    import uuid as _uuid
except ImportError:
    _uuid = None

try:
    from tools.multiplayer import UDPLobbyServer, UDPClient  # type: ignore
except (ImportError, ModuleNotFoundError):
    UDPLobbyServer = None  # type: ignore
    UDPClient = None  # type: ignore

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

# Optional pygame import for audio fallback (keep silent if unavailable)
try:
    import pygame  # type: ignore
    _pygame_available = True
except (ImportError, ModuleNotFoundError):
    pygame = None  # type: ignore
    _pygame_available = False

try:
    # animation module may depend on arcade being importable; import when available
    from animation import load_animations  # type: ignore
except (ImportError, ModuleNotFoundError):
    def load_animations(*_a, **_k):
        """Fallback loader that returns an empty mapping when animations are
        unavailable.
        """
        return {}

# Preload animations once for helper functions and DevMode use.
ANIMATIONS: Dict[str, Any] = {}
try:
    ANIMATIONS = load_animations()
except (ImportError, OSError, ValueError):
    ANIMATIONS = {}

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
# Audio directories
AUDIO_DIR = os.path.join(BASE_DIR, "assets", "Audio")
MUSIC_DIR = os.path.join(AUDIO_DIR, "music")
SFX_DIR = os.path.join(AUDIO_DIR, "SFX")

# Settings path
SETTINGS_PATH = os.path.join(BASE_DIR, "Settings", "game_settings.json")


def read_settings() -> Dict[str, Any]:
    """Read user settings from `Settings/game_settings.json` with safe defaults."""
    defaults = {
        "resolution": [SCREEN_WIDTH, SCREEN_HEIGHT],
        "volume": 70,
        "multiplayer": False,
        "multiplayer_role": "host",  # host or client
        "multiplayer_host": "127.0.0.1",
        "multiplayer_port": 50000,
    }
    data = read_json_safe(SETTINGS_PATH) or {}
    # merge defaults
    out: Dict[str, Any] = {}
    out.update(defaults)
    out.update({k: v for k, v in data.items() if v is not None})
    return out


def write_settings(settings: Dict[str, Any]) -> None:
    try:
        os.makedirs(os.path.dirname(SETTINGS_PATH), exist_ok=True)
        with open(SETTINGS_PATH, "w", encoding="utf-8") as fh:
            json.dump(settings, fh, indent=2)
    except OSError:
        logging.exception("Failed to write settings to %s", SETTINGS_PATH)


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


def point_in_button(x: float, y: float, button: Tuple[float, float, float, float]) -> bool:
    """Utility: test whether a point is inside a center-based rect button."""
    cx, cy, w, h = button
    left = cx - w / 2
    right = cx + w / 2
    bottom = cy - h / 2
    top = cy + h / 2
    return left <= x <= right and bottom <= y <= top


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


def get_npc_visual(npc_name: str) -> Optional[Any]:
    """Return an animation object or texture/path for an NPC.

    Priority:
    - If an animation exists in `assets/Animation/<npc_name>/`, return the Animation object.
    - Else, if the NPC JSON has a `sprite` field and the file exists in `SPRITE_DIR`, return the texture (via arcade) or path.
    - Otherwise return None.
    """
    # Check preloaded animations
    anim = ANIMATIONS.get(npc_name)
    if anim is not None:
        return anim

    # Fallback to sprite file referenced in NPC JSON
    info = read_json_safe(os.path.join(CHAR_DIR, f"{npc_name}.json")) or {}
    sprite_name = info.get("sprite") or info.get("Sprite")
    if sprite_name:
        p = sprite_path(sprite_name)
        if p:
            loader = getattr(arcade, "load_texture", None)
            if callable(loader):
                try:
                    return loader(p)
                except (OSError, ValueError):
                    return p
            return p

    return None


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


# --- Audio helpers ---
def _find_audio_path(audio_dir: str, name: str) -> str:
    if not name:
        return ""
    candidate = os.path.join(audio_dir, name)
    if os.path.exists(candidate):
        return candidate
    for ext in (".ogg", ".mp3", ".wav"):
        p = candidate + ext
        if os.path.exists(p):
            return p
    return ""


def _arcade_load_sound(path: str) -> Optional[Any]:
    loader = getattr(arcade, "load_sound", None)
    if callable(loader):
        try:
            return loader(path)
        except (OSError, ValueError):
            return None
    return None


def load_sound(name: str) -> Optional[Any]:
    """Load an SFX by name (searches `SFX_DIR`). Returns a sound object or path."""
    path = _find_audio_path(SFX_DIR, name)
    if not path:
        return None
    snd = _arcade_load_sound(path)
    return snd or path


def play_sound(sound: Any, volume: float = 1.0) -> Optional[Any]:
    """Play a short sound effect. Accepts a loaded sound object or filename."""
    # Resolve string -> sound
    if isinstance(sound, str):
        snd = load_sound(sound)
        if snd is None:
            return None
        sound = snd

    # Prefer arcade.play_sound
    play_fn = getattr(arcade, "play_sound", None)
    if callable(play_fn):
        try:
            return play_fn(sound, volume)
        except (TypeError, OSError):
            # Continue to other fallbacks
            pass

    # If the object has a play method, call it
    play_method = getattr(sound, "play", None)
    if callable(play_method):
        try:
            return play_method()
        except (AttributeError, TypeError):
            pass

    # Fallback to pygame mixer if available
    if _pygame_available:
        try:
            pg = pygame  # type: ignore
            mixer = getattr(pg, "mixer", None)
            if mixer is None:
                return None
            if isinstance(sound, str):
                getattr(mixer, "init", lambda: None)()
                SoundClass = getattr(mixer, "Sound", None)
                if SoundClass is None:
                    return None
                s = SoundClass(sound)
                return getattr(s, "play", lambda: None)()
            # If we somehow got a pygame.Sound-like object
            return getattr(sound, "play", lambda: None)()
        except (OSError, RuntimeError):
            return None

    return None


def play_music_file(name_or_path: str, loop: bool = True, volume: float = 0.5) -> Optional[Any]:
    """Play background music from `assets/Audio/music` or an absolute path.

    Returns a handle for the backend used, or None on failure.
    """
    # Resolve to a file path
    path = name_or_path
    if not os.path.isabs(path):
        path = _find_audio_path(MUSIC_DIR, name_or_path) or path
    if not os.path.exists(path):
        return None

    # Try arcade first
    snd = _arcade_load_sound(path)
    if snd is not None:
        play_fn = getattr(arcade, "play_sound", None)
        if callable(play_fn):
            try:
                return play_fn(snd, volume)
            except (TypeError, OSError):
                pass

    # Fallback to pygame mixer music
    if _pygame_available:
        try:  # Try pygame mixer if arcade cannot play sound
            pg = pygame  # type: ignore
            mixer = getattr(pg, "mixer", None)
            if mixer is None:
                return None
            music = getattr(mixer, "music", None)
            if music is None:
                return None
            getattr(mixer, "init", lambda: None)()
            getattr(music, "load", lambda *_: None)(path)
            getattr(music, "set_volume", lambda *_: None)(volume)
            getattr(music, "play", lambda *_: None)(-1 if loop else 0)
            return "pygame_music"
        except (OSError, RuntimeError):
            return None

    return None


def stop_music() -> bool:
    """Stop background music if a backend supports it. Returns True if stopped."""
    if _pygame_available:
        try:
            pg = pygame  # type: ignore
            mixer = getattr(pg, "mixer", None)
            music = getattr(mixer, "music", None) if mixer is not None else None
            get_init = getattr(mixer, "get_init", None)
            if callable(get_init) and get_init():
                stop_fn = getattr(music, "stop", None)
                if callable(stop_fn):
                    stop_fn()
                    return True
        except (OSError, RuntimeError):
            return False
    # No generic stop for arcade's simple API
    return False


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
            "Prev Anim": (125.0, 425.0, 150.0, 30.0),
            "Next Anim": (125.0, 385.0, 150.0, 30.0),
            "Toggle Music": (125.0, 345.0, 150.0, 30.0),
            "Prev Track": (125.0, 305.0, 70.0, 26.0),
            "Next Track": (205.0, 305.0, 70.0, 26.0),
        }

        self.input_mode: Optional[str] = None  # "item" | "xp" | None
        self.input_text: str = ""
        self.panel_left = 40.0
        self.panel_bottom = 440.0
        self.panel_width = 260.0
        self.panel_height = 210.0
        # Load animations from assets/Animation (if available)
        try:
            self.animations: Dict[str, Any] = load_animations()
        except (ImportError, OSError, ValueError):
            self.animations = {}
        self.current_animation: Optional[str] = next(iter(self.animations.keys()), None)
        self._last_dt_time = 0.0
        self._music_playing: bool = False
        # Load available music files for UI
        try:
            self.music_files: List[str] = [f for f in os.listdir(MUSIC_DIR) if os.path.isfile(os.path.join(MUSIC_DIR, f))]
        except OSError:
            self.music_files = []
        self._music_index: int = 0 if self.music_files else -1

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

    def point_in_button(self, x: float, y: float, button: Button) -> bool:
        """Public wrapper for hit-testing a button rectangle."""
        return DevMode._point_in_button(x, y, button)

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
                elif name == "Prev Anim":
                    keys = list(self.animations.keys())
                    if keys:
                        if self.current_animation in keys:
                            i = keys.index(self.current_animation)
                            self.current_animation = keys[(i - 1) % len(keys)]
                        else:
                            self.current_animation = keys[0]
                elif name == "Next Anim":
                    keys = list(self.animations.keys())
                    if keys:
                        if self.current_animation in keys:
                            i = keys.index(self.current_animation)
                            self.current_animation = keys[(i + 1) % len(keys)]
                        else:
                            self.current_animation = keys[0]
                elif name == "Prev Track":
                    if self.music_files:
                        self._music_index = (self._music_index - 1) % len(self.music_files)
                        # auto-play selected track
                        stop_music()
                        handle = play_music_file(self.music_files[self._music_index])
                        self._music_playing = handle is not None
                elif name == "Next Track":
                    if self.music_files:
                        self._music_index = (self._music_index + 1) % len(self.music_files)
                        stop_music()
                        handle = play_music_file(self.music_files[self._music_index])
                        self._music_playing = handle is not None
                elif name == "Toggle Music":
                    # Simple toggle: attempt to play/stop a default music file
                    if self._music_playing:
                        stop_music()
                        self._music_playing = False
                    else:
                        # Try a default music file name; this will search MUSIC_DIR
                        handle = play_music_file("Music_Map/loop.ogg")
                        if handle is not None:
                            self._music_playing = True
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

        # F2 cycles animations forward
        if symbol == getattr(arcade.key, "F2", None):
            keys = list(self.animations.keys())
            if not keys:
                return
            try:
                idx = keys.index(self.current_animation) if self.current_animation in keys else -1
            except ValueError:
                idx = -1
            idx = (idx + 1) % len(keys)
            self.current_animation = keys[idx]

    def on_text(self, text: str) -> None:
        if not self.active or not self.input_mode:
            return
        if text and text.isprintable():
            self.input_text += text

    def update(self, dt: float) -> None:
        """Advance animations by `dt` seconds. Call from your Window.on_update(dt)."""
        if not self.active:
            return
        if self.current_animation and self.current_animation in self.animations:
            anim = self.animations[self.current_animation]
            try:
                anim.update(dt)
            except (AttributeError, TypeError, ValueError, OSError):
                pass

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

        # Animated preview from assets/Animation (if any)
        if self.current_animation and self.current_animation in self.animations:
            anim = self.animations[self.current_animation]
            frame = None
            try:
                frame = anim.get_frame()
            except (AttributeError, TypeError):
                frame = None

            if frame is not None:
                draw_fn = getattr(arcade, "draw_texture_rectangle", None)
                if callable(draw_fn):
                    try:
                        if isinstance(frame, str):
                            # frame is a path, try to load texture
                            tex = getattr(arcade, "load_texture", None)
                            if callable(tex):
                                tex_obj = tex(frame)
                            else:
                                tex_obj = None
                        else:
                            tex_obj = frame

                        if tex_obj is not None:
                            w = getattr(tex_obj, "width", 64)
                            h = getattr(tex_obj, "height", 64)
                            draw_fn(
                                self.panel_left + self.panel_width + 60,
                                self.panel_bottom + self.panel_height - 40,
                                w,
                                h,
                                tex_obj,
                            )
                    except (AttributeError, TypeError, OSError):
                        pass


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

        # Networking / multiplayer support (optional)
        self._net_id = None
        self.network_server = None
        self.network_client = None
        self.other_players: Dict[str, Dict[str, float]] = {}
        try:
            settings = read_settings()
            if settings.get("multiplayer"):
                # generate network id
                try:
                    import uuid

                    self._net_id = str(uuid.uuid4())
                except ImportError:
                    # uuid should be available in stdlib; fall back to a simple id
                    self._net_id = f"player-{id(self)}"

                # Attempt to start multiplayer helpers if the imported symbols
                # are available at module import time (they were imported at
                # module scope where possible).
                role = settings.get("multiplayer_role", "host")
                host = settings.get("multiplayer_host", "127.0.0.1")
                port = int(settings.get("multiplayer_port", 50000))
                if role == "host":
                    # start server and also a client to receive forwarded messages
                    if UDPLobbyServer is not None:
                        try:
                            self.network_server = UDPLobbyServer(host="0.0.0.0", port=port)
                            self.network_server.start()
                        except (OSError, RuntimeError) as exc:
                            logging.debug("Failed to start UDPLobbyServer: %s", exc)
                            self.network_server = None
                    else:
                        self.network_server = None

                    if UDPClient is not None:
                        try:
                            self.network_client = UDPClient(host, port, on_message=self._on_network_msg)
                            self.network_client.start()
                        except (OSError, RuntimeError, ValueError) as exc:
                            logging.debug("Failed to start UDPClient (host client): %s", exc)
                            self.network_client = None
                    else:
                        self.network_client = None
                else:
                    if UDPClient is not None:
                        try:
                            self.network_client = UDPClient(host, port, on_message=self._on_network_msg)
                            self.network_client.start()
                        except (OSError, RuntimeError, ValueError) as exc:
                            logging.debug("Failed to start UDPClient (client role): %s", exc)
                            self.network_client = None
                    else:
                        self.network_client = None
        except (OSError, ValueError, TypeError) as exc:
            # settings failure should not break window; log for debugging
            logging.debug("Failed to read settings for GameWindow: %s", exc)

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

        # Networking: periodically send our position to peers
        # Networking: periodically send our position to peers
        client = getattr(self, "network_client", None)
        net_id = getattr(self, "_net_id", None)
        if client is not None and net_id:
            msg = f"POS|{net_id}|{int(self.player_x)}|{int(self.player_y)}"
            # Tell static analyzers this is expected to be a callable send function
            send_fn = cast(Optional[Callable[[str], Any]], getattr(client, "send", None))
            if send_fn is not None:
                try:
                    send_fn(msg)
                except (OSError, RuntimeError) as exc:
                    logging.debug("Failed to send network message: %s", exc)

    def _on_network_msg(self, msg: str) -> None:
        """Handle incoming network messages from other peers (simple protocol)."""
        if not msg:
            return
        # expected format: POS|id|x|y
        try:
            parts = msg.split("|")
        except AttributeError:
            # msg was not a string
            return

        if parts and parts[0] == "POS" and len(parts) >= 4:
            pid = parts[1]
            if pid == getattr(self, "_net_id", None):
                return
            try:
                x = float(parts[2])
                y = float(parts[3])
            except (ValueError, TypeError):
                return
            # update or create simple player entry
            self.other_players[pid] = {"x": x, "y": y}

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


# --- Main menu window ---
class MainMenuWindow(BaseWindow):  # type: ignore
    """A simple main menu that can start the game, open settings, toggle dev mode, or quit."""

    def __init__(self) -> None:
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, "Shattered Fates - Menu")
        _arcade_set_background_color(arcade.color.DARK_SLATE_GRAY)
        self.buttons = {
            "Start Game": (SCREEN_WIDTH / 2, 320, 240, 48),
            "Settings": (SCREEN_WIDTH / 2, 260, 240, 40),
            "Toggle Dev": (SCREEN_WIDTH / 2, 200, 240, 36),
            "Quit": (SCREEN_WIDTH / 2, 140, 240, 36),
        }
        self.dev_player = Player()
        self.dev_ui = DevMode(self.dev_player, self, font_size=14)

    def on_draw(self) -> None:
        self.clear()
        _arcade_draw_text(
            "Shattered Fates",
            SCREEN_WIDTH / 2 - 180,
            SCREEN_HEIGHT - 140,
            arcade.color.WHITE,
            36,
        )

        for name, (cx, cy, w, h) in self.buttons.items():
            _arcade_draw_rectangle_filled(cx, cy, w, h, arcade.color.DARK_GRAY)
            _arcade_draw_text(name, cx - w / 2 + 12, cy - 10, arcade.color.WHITE, 18)

        # Draw dev UI if active
        self.dev_ui.draw()

    def on_mouse_press(self, x: float, y: float, _button: int, _modifiers: int) -> None:
        for name, rect in self.buttons.items():
            if self.dev_ui.point_in_button(x, y, rect):
                if name == "Start Game":
                    # Instantiate the game window (actual window/switching handled by runtime)
                    _ = GameWindow()
                elif name == "Settings":
                    # Open settings UI
                    _ = SettingsWindow()
                elif name == "Toggle Dev":
                    self.dev_ui.toggle()
                elif name == "Quit":
                    exit_fn = getattr(arcade, "exit", None)
                    if callable(exit_fn):
                        try:
                            exit_fn()
                        except Exception as exc:  # pragma: no cover - platform dependent
                            raise SystemExit() from exc
                    else:
                        raise SystemExit()

    def on_key_press(self, symbol: int, modifiers: int) -> None:
        # Forward to dev UI and allow F1 toggle
        if symbol == arcade.key.F1:
            self.dev_ui.toggle()
            return
        self.dev_ui.on_key_press(symbol, modifiers)


class SettingsWindow(BaseWindow):  # type: ignore
    """Simple settings UI: resolution, volume, and multiplayer toggles."""

    def __init__(self) -> None:
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, "Settings")
        _arcade_set_background_color(arcade.color.DARK_SLATE_GRAY)
        self.settings = read_settings()
        # Buttons: label -> (cx, cy, w, h)
        self.buttons = {
            "Resolution": (SCREEN_WIDTH / 2, 380, 300, 40),
            "Volume -": (SCREEN_WIDTH / 2 - 80, 320, 120, 36),
            "Volume +": (SCREEN_WIDTH / 2 + 80, 320, 120, 36),
            "Multiplayer Toggle": (SCREEN_WIDTH / 2, 260, 300, 36),
            "Role Toggle": (SCREEN_WIDTH / 2, 220, 300, 36),
            "Host": (SCREEN_WIDTH / 2, 180, 300, 36),
            "Port": (SCREEN_WIDTH / 2, 140, 300, 36),
            "Save": (SCREEN_WIDTH / 2 - 80, 80, 140, 36),
            "Back": (SCREEN_WIDTH / 2 + 80, 80, 140, 36),
        }

    def on_draw(self) -> None:
        self.clear()
        _arcade_draw_text("Settings", SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT - 120, arcade.color.WHITE, 32)
        # Draw buttons and values
        for name, (cx, cy, w, h) in self.buttons.items():
            _arcade_draw_rectangle_filled(cx, cy, w, h, arcade.color.DARK_GRAY)
            _arcade_draw_text(name, cx - w / 2 + 12, cy - 10, arcade.color.WHITE, 14)

        # Show current values
        res = self.settings.get("resolution", [SCREEN_WIDTH, SCREEN_HEIGHT])
        _arcade_draw_text(f"Resolution: {res[0]}x{res[1]}", SCREEN_WIDTH / 2 - 140, 400, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Volume: {self.settings.get('volume', 70)}", SCREEN_WIDTH / 2 - 140, 340, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Multiplayer: {self.settings.get('multiplayer')}", SCREEN_WIDTH / 2 - 140, 280, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Role: {self.settings.get('multiplayer_role')}", SCREEN_WIDTH / 2 - 140, 240, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Host: {self.settings.get('multiplayer_host')}", SCREEN_WIDTH / 2 - 140, 200, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Port: {self.settings.get('multiplayer_port')}", SCREEN_WIDTH / 2 - 140, 160, arcade.color.LIGHT_GRAY, 12)

    def on_mouse_press(self, x: float, y: float, _button: int, _modifiers: int) -> None:
        for name, rect in self.buttons.items():
            if point_in_button(x, y, rect):
                if name == "Resolution":
                    # cycle between common resolutions
                    opts = [(800, 600), (1024, 768), (1280, 720), (1366, 768)]
                    cur = tuple(self.settings.get("resolution", [800, 600]))
                    try:
                        idx = opts.index(cur)
                    except ValueError:
                        idx = 0
                    idx = (idx + 1) % len(opts)
                    self.settings["resolution"] = list(opts[idx])
                elif name == "Volume -":
                    v = int(self.settings.get("volume", 70))
                    self.settings["volume"] = max(0, v - 10)
                elif name == "Volume +":
                    v = int(self.settings.get("volume", 70))
                    self.settings["volume"] = min(100, v + 10)
                elif name == "Multiplayer Toggle":
                    self.settings["multiplayer"] = not bool(self.settings.get("multiplayer"))
                elif name == "Role Toggle":
                    cur = self.settings.get("multiplayer_role", "host")
                    self.settings["multiplayer_role"] = "client" if cur == "host" else "host"
                elif name == "Host":
                    # toggle between localhost and empty for quick testing
                    cur = self.settings.get("multiplayer_host", "127.0.0.1")
                    self.settings["multiplayer_host"] = "127.0.0.1" if cur != "127.0.0.1" else "localhost"
                elif name == "Port":
                    p = int(self.settings.get("multiplayer_port", 50000))
                    # cycle a small set of ports
                    p = 50000 if p != 50000 else 50001
                    self.settings["multiplayer_port"] = p
                elif name == "Save":
                    write_settings(self.settings)
                    _ = MainMenuWindow()
                elif name == "Back":
                    _ = MainMenuWindow()
                return


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
        print("Headless mode: running simple terminal player (no window).")
        # Provide a minimal interactive headless mode so the game is playable
        # without arcade/OpenGL. Controls: W/A/S/D to move, P to print state,
        # Q to quit. This is intentionally small and useful for CI or testing.
        try:
            win = GameWindow()
        except (RuntimeError, ImportError, OSError) as exc:
            logging.debug("GameWindow construction failed, falling back to mini window: %s", exc)
            # If GameWindow construction fails, create a minimal object with needed fields
            class _MiniWin:
                def __init__(self):
                    self.player_x = 100.0
                    self.player_y = 100.0
                    self.player_w = 40.0
                    self.player_h = 40.0
                    self.player_speed = 4.0
                    self.other_players = {}

                def on_update(self, dt: float) -> None:  # pragma: no cover - best-effort fallback
                    _ = dt
                    return None

            win = _MiniWin()

        print("Controls: W/A/S/D = move, P = print position, L = list peers, Q = quit")
        try:
            while True:
                cmd = input("> ").strip().lower()
                if not cmd:
                    continue
                if cmd in ("q", "quit", "exit"):
                    print("Exiting headless mode.")
                    break
                if cmd in ("w", "up"):
                    win.player_y += getattr(win, "player_speed", 4.0)
                elif cmd in ("s", "down"):
                    win.player_y -= getattr(win, "player_speed", 4.0)
                elif cmd in ("a", "left"):
                    win.player_x -= getattr(win, "player_speed", 4.0)
                elif cmd in ("d", "right"):
                    win.player_x += getattr(win, "player_speed", 4.0)
                elif cmd in ("p", "pos"):
                    print(f"Player position: x={int(getattr(win, 'player_x', 0))} y={int(getattr(win, 'player_y', 0))}")
                elif cmd in ("l", "list"):
                    print("Other players:", getattr(win, "other_players", {}))
                else:
                    print("Unknown command. Use W/A/S/D, P, L, Q.")
                # call update hook if available (simulate a frame)
                win.on_update(1.0 / FPS)
        except (KeyboardInterrupt, EOFError):
            print("\nExiting headless mode.")
        return

    try:
        # Start at the main menu window by default
        _window = None
        try:
            _window = MainMenuWindow()
        except NameError:
            # If MainMenuWindow isn't defined (older code path), fall back to GameWindow
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
