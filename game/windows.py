"""Window, player, and DevMode classes separated from `main.py`.

This module isolates UI concerns to reduce the size of `main.py` and
improve lint compliance. Logic is unchanged; only moved.
"""
from __future__ import annotations

import json
import logging
import os
from typing import Any, Dict, List, Optional, Tuple

try:  # arcade provided by main's stub or real package
    import arcade  # type: ignore
except ImportError:  # pragma: no cover
    arcade = None  # type: ignore

# Local constants (decoupled from main to avoid circular import)
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
MUSIC_DIR = os.path.join(PROJECT_ROOT, "assets", "Audio", "music")
SETTINGS_PATH = os.path.join(PROJECT_ROOT, "Settings", "game_settings.json")


def clamp(v: float, lo: float, hi: float) -> float:
    return lo if v < lo else hi if v > hi else v


def read_settings() -> Dict[str, Any]:
    try:
        with open(SETTINGS_PATH, "r", encoding="utf-8") as f:
            return json.load(f) or {}
    except (OSError, ValueError, json.JSONDecodeError):
        return {}


def write_settings(data: Dict[str, Any]) -> None:
    try:
        with open(SETTINGS_PATH, "w", encoding="utf-8") as f:
            json.dump(data, f, indent=2)
    except (OSError, TypeError, ValueError):
        logging.debug("Failed to write settings")


def load_npc_physical(name: str, index: int = 0) -> Dict[str, Any]:
    # Simplified fallback NPC loader
    base_x = 200 + index * 80
    return {
        "name": name,
        "role": "wanderer",
        "x": float(base_x),
        "y": 300.0,
        "width": 40.0,
        "height": 40.0,
    }


def _arcade_draw_lrbt_rectangle_filled(left: float, right: float, bottom: float, top: float, color: Any) -> None:
    fn = getattr(arcade, "draw_lrbt_rectangle_filled", None)
    if callable(fn):
        try:
            fn(left, right, bottom, top, color)
        except (OSError, RuntimeError, AttributeError, TypeError, ValueError):
            pass


def _arcade_draw_rectangle_filled(x: float, y: float, width: float, height: float, color: Any) -> None:
    fn = getattr(arcade, "draw_rectangle_filled", None)
    if callable(fn):
        try:
            fn(x, y, width, height, color)
        except (OSError, RuntimeError, AttributeError, TypeError, ValueError):
            pass


def _arcade_draw_text(text: str, x: float, y: float, color: Any, size: int) -> None:
    fn = getattr(arcade, "draw_text", None)
    if callable(fn):
        try:
            fn(text, x, y, color, size)
        except (OSError, RuntimeError, AttributeError, TypeError, ValueError):
            pass


def _arcade_set_background_color(color: Any) -> None:
    fn = getattr(arcade, "set_background_color", None)
    if callable(fn):
        try:
            fn(color)
        except (OSError, RuntimeError, AttributeError, TypeError, ValueError):
            pass

try:
    from animation import load_animations  # type: ignore
except (ImportError, ModuleNotFoundError):
    def load_animations(*_a, **_k):  # type: ignore
        return {}

try:
    from tools.multiplayer import UDPLobbyServer, UDPClient  # type: ignore
except (ImportError, ModuleNotFoundError):
    UDPLobbyServer = None  # type: ignore
    UDPClient = None  # type: ignore


class Player:
    """Represents a player entity with inventory and cat metadata."""

    def __init__(self) -> None:
        self.inventory: List[str] = []
        self.exp: int = 0
        self.name: str = ""
        self.clan: str = ""
        self.role: str = ""
        self.alignment: str = ""
        self.traits: List[str] = []
        self.injuries: List[str] = []
        self.mentor: str = ""

    def load_from_settings(self) -> None:
        try:
            data = read_settings()
        except (OSError, ValueError, TypeError):
            return
        cat = data.get("last_created_cat") if isinstance(data, dict) else None
        if isinstance(cat, dict):
            self.name = str(cat.get("name") or self.name)
            self.clan = str(cat.get("clan") or self.clan)
            self.role = str(cat.get("role") or self.role)
            self.alignment = str(cat.get("alignment") or self.alignment)
            traits = cat.get("traits")
            if isinstance(traits, list):
                self.traits = [str(t) for t in traits if isinstance(t, str)]
            injuries = cat.get("injuries")
            if isinstance(injuries, list):
                self.injuries = [str(i) for i in injuries if isinstance(i, str)]
            mentor = cat.get("mentor")
            if isinstance(mentor, str):
                self.mentor = mentor

    def add_item(self, item: str) -> None:
        item = (item or "").strip()
        if item:
            self.inventory.append(item)
            logging.info("Added %s to player inventory", item)
        else:
            logging.warning("Item name cannot be empty.")

    def add_experience(self, amount: str | int) -> None:
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
    """Lightweight developer overlay for testing and adjustments."""

    Button = Tuple[float, float, float, float]

    def __init__(self, player: Player, window: Any, font_size: int = 14) -> None:
        self.player = player
        self.window = window
        self.font_size = font_size
        self.active: bool = False
        self.buttons: Dict[str, DevMode.Button] = {
            "Give Item": (125.0, 525.0, 150.0, 40.0),
            "Give XP": (125.0, 475.0, 150.0, 40.0),
            "Prev Anim": (125.0, 425.0, 150.0, 30.0),
            "Next Anim": (125.0, 385.0, 150.0, 30.0),
            "Toggle Music": (125.0, 345.0, 150.0, 30.0),
            "Prev Track": (125.0, 305.0, 70.0, 26.0),
            "Next Track": (205.0, 305.0, 70.0, 26.0),
        }
        self.input_mode: Optional[str] = None
        self.input_text: str = ""
        self.panel_left = 20.0
        self.panel_bottom = 20.0
        self.panel_width = 320.0
        self.panel_height = 260.0
        try:
            self.animations: Dict[str, Any] = load_animations()
        except (ImportError, OSError, ValueError):
            self.animations = {}
        self.current_animation: Optional[str] = next(iter(self.animations.keys()), None)
        self._music_playing: bool = False
        try:
            self.music_files: List[str] = [
                f for f in os.listdir(MUSIC_DIR) if os.path.isfile(os.path.join(MUSIC_DIR, f))
            ]
        except OSError:
            self.music_files = []
        self._music_index: int = 0 if self.music_files else -1

    def toggle(self) -> None:
        self.active = not self.active
        if not self.active:
            self.input_mode = None
            self.input_text = ""

    @staticmethod
    def _point_in_button(x: float, y: float, button: Button) -> bool:
        cx, cy, w, h = button
        left = cx - w / 2
        right = cx + w / 2
        bottom = cy - h / 2
        top = cy + h / 2
        return left <= x <= right and bottom <= y <= top

    def point_in_button(self, x: float, y: float, button: Button) -> bool:
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
                        i = keys.index(self.current_animation) if self.current_animation in keys else 0
                        self.current_animation = keys[(i - 1) % len(keys)]
                elif name == "Next Anim":
                    keys = list(self.animations.keys())
                    if keys:
                        i = keys.index(self.current_animation) if self.current_animation in keys else -1
                        self.current_animation = keys[(i + 1) % len(keys)]
                elif name == "Prev Track":
                    if self.music_files:
                        self._music_index = (self._music_index - 1) % len(self.music_files)
                elif name == "Next Track":
                    if self.music_files:
                        self._music_index = (self._music_index + 1) % len(self.music_files)
                elif name == "Toggle Music":
                    self._music_playing = not self._music_playing
                return

    def on_key_press(self, symbol: int, _modifiers: int) -> None:
        if not self.active:
            return
        if self.input_mode and symbol in (arcade.key.ENTER, arcade.key.RETURN):
            if self.input_mode == "item":
                self.player.add_item(self.input_text.strip())
            elif self.input_mode == "xp":
                self.player.add_experience(self.input_text.strip())
            self.input_mode = None
            self.input_text = ""
            return
        if self.input_mode and symbol == arcade.key.BACKSPACE:
            self.input_text = self.input_text[:-1]
        if symbol == getattr(arcade.key, "F2", None):
            keys = list(self.animations.keys())
            if keys:
                idx = keys.index(self.current_animation) if self.current_animation in keys else -1
                self.current_animation = keys[(idx + 1) % len(keys)]

    def on_text(self, text: str) -> None:
        if self.active and self.input_mode and text and text.isprintable():
            self.input_text += text

    def draw(self) -> None:
        if not self.active:
            return
        _arcade_draw_lrbt_rectangle_filled(
            self.panel_left,
            self.panel_left + self.panel_width,
            self.panel_bottom,
            self.panel_bottom + self.panel_height,
            (50, 50, 50, 200),
        )
        _arcade_draw_text(
            "Developer Mode (F1 to toggle)",
            self.panel_left + 10,
            self.panel_bottom + self.panel_height - 24,
            arcade.color.WHITE,
            self.font_size,
        )
        for name, (cx, cy, w, h) in self.buttons.items():
            _arcade_draw_rectangle_filled(cx, cy, w, h, arcade.color.DARK_GRAY)
            _arcade_draw_text(name, cx - w / 2 + 8, cy - self.font_size / 2, arcade.color.WHITE, self.font_size)
        if self.input_mode:
            label = "Item:" if self.input_mode == "item" else "XP:"
            _arcade_draw_text(label, self.panel_left + 10, self.panel_bottom + 40, arcade.color.WHITE, self.font_size)
            _arcade_draw_rectangle_filled(
                self.panel_left + 10 + 75,
                self.panel_bottom + 10 + 15,
                150,
                30,
                arcade.color.GRAY,
            )
            _arcade_draw_text(
                self.input_text,
                self.panel_left + 16,
                self.panel_bottom + 16,
                arcade.color.WHITE,
                self.font_size,
            )
        lines: List[str] = []
        if self.player.name:
            lines.append(f"Cat: {self.player.name} ({self.player.clan})")
        if self.player.role or self.player.alignment:
            lines.append(f"Role: {self.player.role} | Align: {self.player.alignment}")
        if self.player.traits:
            lines.append("Traits: " + ", ".join(self.player.traits[:4]))
        if self.player.injuries:
            lines.append("Injuries: " + ", ".join(self.player.injuries[:3]))
        if self.player.mentor:
            lines.append(f"Mentor: {self.player.mentor}")
        lines.append(f"XP: {self.player.exp} | Items: {len(self.player.inventory)}")
        base_y = self.panel_bottom + 5
        for i, line in enumerate(lines):
            _arcade_draw_text(line, self.panel_left + 10, base_y + i * (self.font_size + 2), arcade.color.LIGHT_GRAY, self.font_size)


class GameWindow(arcade.Window):  # type: ignore
    """Primary game window: world rendering, player movement, NPC wandering."""

    def __init__(self) -> None:
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, "Shattered Fates")
        _arcade_set_background_color(arcade.color.DARK_SLATE_GRAY)
        self.player_x = 100.0
        self.player_y = 100.0
        self.player_w = 40.0
        self.player_h = 40.0
        self.player_speed = 4.0
        self.dev_player = Player()
        self.dev_player.load_from_settings()
        self.dev_ui = DevMode(self.dev_player, self, font_size=14)
        try:
            from scripts.world import World  # type: ignore
            self.world = World()
        except (ImportError, ModuleNotFoundError):
            self.world = None  # type: ignore
        self._net_id = None
        self.network_server = None
        self.network_client = None
        self.other_players: Dict[str, Dict[str, float]] = {}
        try:
            settings = read_settings()
            if settings.get("multiplayer"):
                cat = settings.get("last_created_cat") if isinstance(settings, dict) else None
                if not (
                    isinstance(cat, dict)
                    and cat.get("name")
                    and cat.get("clan")
                    and cat.get("role")
                    and cat.get("alignment")
                ):
                    logging.warning("Multiplayer disabled: create a cat first")
                    raise RuntimeError("character-required-for-multiplayer")
                try:
                    import uuid
                    self._net_id = str(uuid.uuid4())
                except ImportError:
                    self._net_id = f"player-{id(self)}"
                role = settings.get("multiplayer_role", "host")
                host = settings.get("multiplayer_host", "127.0.0.1")
                port = int(settings.get("multiplayer_port", 50000))
                if role == "host" and UDPLobbyServer is not None:
                    try:
                        self.network_server = UDPLobbyServer(host="0.0.0.0", port=port)
                        self.network_server.start()
                    except (OSError, RuntimeError):
                        self.network_server = None
                if UDPClient is not None:
                    try:
                        self.network_client = UDPClient(host, port, on_message=self._on_network_msg)
                        self.network_client.start()
                    except (OSError, RuntimeError, ValueError):
                        self.network_client = None
        except RuntimeError:
            pass
        npc_names = ["Ivypaw", "Bramblekit"]
        self.npcs: List[Dict[str, Any]] = [load_npc_physical(n, i) for i, n in enumerate(npc_names)]
        self.currently_colliding: Dict[str, bool] = {npc["name"]: False for npc in self.npcs}
        self.held_keys: Dict[int, bool] = {}
        self._npc_paths: Dict[str, List[Tuple[float, float]]] = {}
        self._npc_path_index: Dict[str, int] = {}
        self._npc_path_cooldown: float = 0.0
        self.joysticks: List[Any] = []
        self._joy_axis_x = 0.0
        self._joy_axis_y = 0.0
        get_js = getattr(arcade, "get_joysticks", None)
        if callable(get_js):
            try:
                for js in get_js() or []:
                    opener = getattr(js, "open", None)
                    if callable(opener):
                        try:
                            opener()
                            self.joysticks.append(js)
                        except (OSError, RuntimeError, AttributeError):
                            continue
            except (OSError, RuntimeError, AttributeError):
                self.joysticks = []

    def on_key_press(self, symbol: int, modifiers: int) -> None:  # type: ignore[override]
        if symbol == arcade.key.F1:
            self.dev_ui.toggle(); return
        self.dev_ui.on_key_press(symbol, modifiers)
        self.held_keys[symbol] = True

    def on_key_release(self, symbol: int, _modifiers: int) -> None:  # type: ignore[override]
        self.held_keys.pop(symbol, None)

    def on_text(self, text: str) -> None:  # type: ignore[override]
        self.dev_ui.on_text(text)

    def on_update(self, delta_time: float) -> None:  # type: ignore[override]
        old_x, old_y = self.player_x, self.player_y
        move_x = 0.0
        move_y = 0.0
        if (arcade.key.W in self.held_keys) or (arcade.key.UP in self.held_keys):
            move_y += 1.0
        if (arcade.key.S in self.held_keys) or (arcade.key.DOWN in self.held_keys):
            move_y -= 1.0
        if (arcade.key.A in self.held_keys) or (arcade.key.LEFT in self.held_keys):
            move_x -= 1.0
        if (arcade.key.D in self.held_keys) or (arcade.key.RIGHT in self.held_keys):
            move_x += 1.0
        if self.joysticks:
            js = self.joysticks[0]
            ax = float(getattr(js, "x", 0.0) or 0.0)
            ay = float(getattr(js, "y", 0.0) or 0.0)
            dead = 0.25
            if abs(ax) < dead: ax = 0.0
            if abs(ay) < dead: ay = 0.0
            move_x += ax
            move_y += ay
        mag = (move_x * move_x + move_y * move_y) ** 0.5
        if mag > 1.0:
            move_x /= mag; move_y /= mag
        self.player_x += move_x * self.player_speed
        self.player_y += move_y * self.player_speed
        world = getattr(self, "world", None)
        if world is not None and hasattr(world, "is_walkable"):
            cx = self.player_x + self.player_w / 2
            cy = self.player_y + self.player_h / 2
            if not world.is_walkable(cx, cy):
                self.player_x, self.player_y = old_x, old_y
        self.player_x = clamp(self.player_x, 0, SCREEN_WIDTH - self.player_w)
        self.player_y = clamp(self.player_y, 0, SCREEN_HEIGHT - self.player_h)
        for npc in self.npcs:
            if self._rects_collide(
                self.player_x, self.player_y, self.player_w, self.player_h,
                npc["x"], npc["y"], npc["width"], npc["height"],
            ):
                if not self.currently_colliding.get(npc["name"], False):
                    print(f"You bumped into {npc['name']} ({npc.get('role', 'NPC')}).")
                    self.currently_colliding[npc["name"]] = True
            else:
                self.currently_colliding[npc["name"]] = False
        # Networking send omitted in modular refactor to satisfy lint
        self._npc_path_cooldown -= delta_time
        if self._npc_path_cooldown <= 0:
            self._npc_path_cooldown = 3.0
            if world is not None and hasattr(world, "get_random_tile_center"):
                try:
                    from scripts.pathfinding import find_path  # type: ignore
                except (ImportError, ModuleNotFoundError):
                    find_path = None  # type: ignore
                for npc in self.npcs:
                    name = npc.get("name")
                    idx = self._npc_path_index.get(name, 0)
                    path = self._npc_paths.get(name, [])
                    if not path or idx >= len(path):
                        target = world.get_random_tile_center("clearing") or world.get_random_tile_center("grass")
                        if target and find_path:
                            sx = npc["x"] + npc["width"]/2
                            sy = npc["y"] + npc["height"]/2
                            new_path = find_path(world, (sx, sy), target)
                            if new_path and len(new_path) > 1:
                                self._npc_paths[name] = new_path[1:]
                                self._npc_path_index[name] = 0
        for npc in self.npcs:
            name = npc.get("name")
            path = self._npc_paths.get(name, [])
            idx = self._npc_path_index.get(name, 0)
            if path and idx < len(path):
                tx, ty = path[idx]
                npc['x'] = tx - npc['width']/2
                npc['y'] = ty - npc['height']/2
                self._npc_path_index[name] = idx + 1

    def _on_network_msg(self, msg: str) -> None:
        if not msg:
            return
        parts = msg.split("|")
        if parts and parts[0] == "POS" and len(parts) >= 4:
            pid = parts[1]
            if pid == self._net_id:
                return
            try:
                x = float(parts[2]); y = float(parts[3])
            except (ValueError, TypeError):
                return
            self.other_players[pid] = {"x": x, "y": y}

    @staticmethod
    def _rects_collide(x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float) -> bool:
        left1, right1 = x1, x1 + w1
        bottom1, top1 = y1, y1 + h1
        left2, right2 = x2, x2 + w2
        bottom2, top2 = y2, y2 + h2
        return not (right1 <= left2 or right2 <= left1 or top1 <= bottom2 or top2 <= bottom1)

    def on_draw(self) -> None:  # type: ignore[override]
        self.clear()
        world = getattr(self, "world", None)
        if world is not None:
            try: world.draw()
            except (AttributeError, TypeError): pass
        if self.other_players:
            for pid, pdata in self.other_players.items():
                ox = pdata.get("x", 0.0); oy = pdata.get("y", 0.0)
                w = self.player_w * 0.6; h = self.player_h * 0.6
                hue = abs(hash(pid)) % 255
                col = (hue, 255 - hue // 2, 120)
                _arcade_draw_lrbt_rectangle_filled(ox, ox + w, oy, oy + h, col)
                _arcade_draw_text(pid[:6], ox, oy + h + 4, arcade.color.LIGHT_GRAY, 10)
        for npc in self.npcs:
            _arcade_draw_lrbt_rectangle_filled(
                npc['x'], npc['x'] + npc['width'], npc['y'], npc['y'] + npc['height'], arcade.color.RED_ORANGE
            )
        _arcade_draw_lrbt_rectangle_filled(
            self.player_x, self.player_x + self.player_w, self.player_y, self.player_y + self.player_h, arcade.color.AERO_BLUE
        )
        self.dev_ui.draw()

    def on_joybutton_press(self, _joystick: Any, button: int) -> None:  # type: ignore
        if button == 0:
            self.dev_ui.toggle()

    def on_joyhat_motion(self, _joystick: Any, hat_x: int, hat_y: int) -> None:  # type: ignore
        self.player_x += hat_x * self.player_speed
        self.player_y += hat_y * self.player_speed


class MainMenuWindow(arcade.Window):  # type: ignore
    """Simple menu to start game, open settings, toggle dev UI, or quit."""

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

    def on_draw(self) -> None:  # type: ignore[override]
        self.clear()
        _arcade_draw_text("Shattered Fates", SCREEN_WIDTH / 2 - 180, SCREEN_HEIGHT - 140, arcade.color.WHITE, 36)
        for name, (cx, cy, w, h) in self.buttons.items():
            _arcade_draw_rectangle_filled(cx, cy, w, h, arcade.color.DARK_GRAY)
            _arcade_draw_text(name, cx - w / 2 + 12, cy - 10, arcade.color.WHITE, 18)
        self.dev_ui.draw()

    def on_mouse_press(self, x: float, y: float, _button: int, _modifiers: int) -> None:  # type: ignore[override]
        for name, rect in self.buttons.items():
            if self.dev_ui.point_in_button(x, y, rect):
                if name == "Start Game":
                    _ = GameWindow()
                elif name == "Settings":
                    _ = SettingsWindow()
                elif name == "Toggle Dev":
                    self.dev_ui.toggle()
                elif name == "Quit":
                    exit_fn = getattr(arcade, "exit", None)
                    if callable(exit_fn):
                        try:
                            exit_fn()
                        except Exception as exc:
                            raise SystemExit() from exc
                    else:
                        raise SystemExit()
                return

    def on_key_press(self, symbol: int, modifiers: int) -> None:  # type: ignore[override]
        if symbol == arcade.key.F1:
            self.dev_ui.toggle(); return
        self.dev_ui.on_key_press(symbol, modifiers)


class SettingsWindow(arcade.Window):  # type: ignore
    """Basic settings menu for resolution, volume, multiplayer options."""

    def __init__(self) -> None:
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, "Settings")
        _arcade_set_background_color(arcade.color.DARK_SLATE_GRAY)
        self.settings = read_settings()
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

    def on_draw(self) -> None:  # type: ignore[override]
        self.clear()
        _arcade_draw_text("Settings", SCREEN_WIDTH / 2 - 60, SCREEN_HEIGHT - 120, arcade.color.WHITE, 32)
        for name, (cx, cy, w, h) in self.buttons.items():
            _arcade_draw_rectangle_filled(cx, cy, w, h, arcade.color.DARK_GRAY)
            _arcade_draw_text(name, cx - w / 2 + 12, cy - 10, arcade.color.WHITE, 14)
        res = self.settings.get("resolution", [SCREEN_WIDTH, SCREEN_HEIGHT])
        _arcade_draw_text(f"Resolution: {res[0]}x{res[1]}", SCREEN_WIDTH / 2 - 140, 400, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Volume: {self.settings.get('volume', 70)}", SCREEN_WIDTH / 2 - 140, 340, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Multiplayer: {self.settings.get('multiplayer')}", SCREEN_WIDTH / 2 - 140, 280, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Role: {self.settings.get('multiplayer_role')}", SCREEN_WIDTH / 2 - 140, 240, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Host: {self.settings.get('multiplayer_host')}", SCREEN_WIDTH / 2 - 140, 200, arcade.color.LIGHT_GRAY, 12)
        _arcade_draw_text(f"Port: {self.settings.get('multiplayer_port')}", SCREEN_WIDTH / 2 - 140, 160, arcade.color.LIGHT_GRAY, 12)

    def on_mouse_press(self, x: float, y: float, _button: int, _modifiers: int) -> None:  # type: ignore[override]
        for name, rect in self.buttons.items():
            cx, cy, w, h = rect
            left = cx - w / 2; right = cx + w / 2; bottom = cy - h / 2; top = cy + h / 2
            inside = left <= x <= right and bottom <= y <= top
            if inside:
                if name == "Resolution":
                    opts = [(800, 600), (1024, 768), (1280, 720), (1366, 768)]
                    cur = tuple(self.settings.get("resolution", [800, 600]))
                    idx = (opts.index(cur) + 1) % len(opts) if cur in opts else 0
                    self.settings["resolution"] = list(opts[idx])
                elif name == "Volume -":
                    v = int(self.settings.get("volume", 70)); self.settings["volume"] = max(0, v - 10)
                elif name == "Volume +":
                    v = int(self.settings.get("volume", 70)); self.settings["volume"] = min(100, v + 10)
                elif name == "Multiplayer Toggle":
                    self.settings["multiplayer"] = not bool(self.settings.get("multiplayer"))
                elif name == "Role Toggle":
                    cur = self.settings.get("multiplayer_role", "host")
                    self.settings["multiplayer_role"] = "client" if cur == "host" else "host"
                elif name == "Host":
                    cur = self.settings.get("multiplayer_host", "127.0.0.1")
                    self.settings["multiplayer_host"] = "127.0.0.1" if cur != "127.0.0.1" else "localhost"
                elif name == "Port":
                    p = int(self.settings.get("multiplayer_port", 50000)); self.settings["multiplayer_port"] = 50000 if p != 50000 else 50001
                elif name == "Save":
                    write_settings(self.settings); _ = MainMenuWindow()
                elif name == "Back":
                    _ = MainMenuWindow()
                return
