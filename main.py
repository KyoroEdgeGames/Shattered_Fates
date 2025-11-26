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
from typing import TYPE_CHECKING, Any, Dict, List, Optional, Tuple

# Prefer importing these at module level so linters don't flag imports inside
# functions; fall back to None when unavailable.
try:
    import uuid as _uuid
except ImportError:
    _uuid = None

# Multiplayer helpers now imported only in window module; no direct use here.

if TYPE_CHECKING:
    import arcade  # pragma: no cover  # type: ignore[import]

# Safe runtime import with a minimal stub for environments where arcade is not installed
try:
    import arcade  # type: ignore[import]
except ImportError:

    class _ArcadeStub:  # pragma: no cover
        """Stub replacement for the `arcade` module when not installed.

        Exposes nested `key` and `color` containers plus minimal drawing
        no-ops so downstream code can continue to run headless or in CI.
        """

        class key:  # pylint: disable=invalid-name
            """Stub of `arcade.key` constants."""
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

        class color:  # pylint: disable=invalid-name
            """Stub of `arcade.color` tuples."""
            WHITE = (255, 255, 255)
            LIGHT_GRAY = (200, 200, 200)
            DARK_GRAY = (64, 64, 64)
            GRAY = (128, 128, 128)
            RED_ORANGE = (200, 50, 50)
            AERO_BLUE = (0, 150, 200)
            DARK_SLATE_GRAY = (47, 79, 79, 255)

        class Window:
            """Minimal shim for `arcade.Window` preserving expected attributes."""
            def __init__(self, width=800, height=600, title=""):
                self.width = width
                self.height = height
                self.title = title

            def clear(self, *_, **__):
                return None

        @staticmethod
        def draw_lrbt_rectangle_filled(*_, **__):
            """No-op rectangle draw (left, right, bottom, top)."""
            return None

        @staticmethod
        def draw_rectangle_filled(*_, **__):
            """No-op filled rectangle draw."""
            return None

        @staticmethod
        def draw_text(*_, **__):
            """No-op text draw."""
            return None

        @staticmethod
        def set_background_color(*_, **__):
            """No-op background color setter."""
            return None

        def run(self):  # noqa: D401 - raises for clarity
            """Raise informing Arcade is unavailable."""
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
    PYGAME_AVAILABLE = True
except (ImportError, ModuleNotFoundError):
    pygame = None  # type: ignore
    PYGAME_AVAILABLE = False

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
# Import window classes lazily inside main() to avoid circular imports.
MUSIC_STATE: Dict[str, Optional[Any]] = {"handle": None, "path": None}
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
    if PYGAME_AVAILABLE:
        try:
            pg = pygame  # type: ignore
            mixer = getattr(pg, "mixer", None)
            if mixer is None:
                return None
            if isinstance(sound, str):
                getattr(mixer, "init", lambda: None)()
                sound_class = getattr(mixer, "Sound", None)
                if sound_class is None:
                    return None
                s = sound_class(sound)
                return getattr(s, "play", lambda: None)()
            # If we somehow got a pygame.Sound-like object
            return getattr(sound, "play", lambda: None)()
        except (OSError, RuntimeError):
            return None

    return None


def play_music_file(name_or_path: str, loop: bool = True, volume: float = 0.5) -> Optional[Any]:
    """Play background music by name or path and return a backend handle.

    The function searches `MUSIC_DIR` when a bare name is provided (without
    extension). It prefers Arcade's sound API but falls back to pygame if
    available. Looping semantics are best-effort; for pygame we manually
    set `loops=-1` when requested.
    """
    path = name_or_path
    if not os.path.isabs(path):
        # Accept name without extension; try common audio extensions.
        path = _find_audio_path(MUSIC_DIR, name_or_path)
    if not path:
        logging.debug("Music file not found: %s", name_or_path)
        return None
    handle: Optional[Any] = None
    # Arcade path
    load_fn = getattr(arcade, "load_sound", None)
    play_fn = getattr(arcade, "play_sound", None)
    if callable(load_fn) and callable(play_fn):
        try:
            snd = load_fn(path)
            handle = play_fn(snd, volume)
        except (OSError, RuntimeError, AttributeError) as exc:  # pragma: no cover - backend dependent
            logging.debug("Arcade music play failed: %s", exc)
            handle = None
    # pygame fallback
    if handle is None and PYGAME_AVAILABLE:
        try:
            pygame.mixer.init()
            pygame.mixer.music.load(path)
            loops = -1 if loop else 0
            pygame.mixer.music.play(loops=loops)
            pygame.mixer.music.set_volume(volume)
            handle = "pygame-music"
        except (OSError, RuntimeError, AttributeError) as exc:  # pragma: no cover - backend dependent
            logging.debug("pygame music play failed: %s", exc)
            handle = None
    MUSIC_STATE["handle"] = handle
    MUSIC_STATE["path"] = path if handle else None
    return handle


def stop_music() -> None:
    """Stop any currently playing music started via `play_music_file`."""
    stopped = False
    handle = MUSIC_STATE.get("handle")
    if handle is not None:
        # Attempt arcade stop
        stop_fn = getattr(arcade, "stop_sound", None)
        if callable(stop_fn):
            try:
                stop_fn(handle)
                stopped = True
            except (OSError, RuntimeError, AttributeError):  # pragma: no cover
                pass
    if not stopped and PYGAME_AVAILABLE:
        try:
            pygame.mixer.music.stop()
        except (OSError, RuntimeError, AttributeError):  # pragma: no cover
            pass
    MUSIC_STATE["handle"] = None
    MUSIC_STATE["path"] = None


def main() -> None:
    """Start the arcade application.

    If the runtime environment cannot create an OpenGL context (for example
    on systems without a suitable GPU/driver), the function will print a
    helpful message and exit. Use `--no-window` to skip creating a window
    (useful for CI or headless runs).
    """
    import sys  # pylint: disable=import-outside-toplevel
    from game.windows import GameWindow, MainMenuWindow  # type: ignore  # pylint: disable=import-outside-toplevel

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
                    px = int(getattr(win, "player_x", 0))
                    py = int(getattr(win, "player_y", 0))
                    print(f"Player position: x={px} y={py}")
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
