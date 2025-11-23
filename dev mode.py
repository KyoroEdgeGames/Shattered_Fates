# pylint: disable=no-member
"""
Developer mode module for Shattered Fates.
Provides debug controls, item/XP spawning, and testing tools.

This module prefers `pygame` but includes a lightweight import fallback
so the repository can be imported and type-checked even when `pygame` is
not installed (useful for CI or when running under the `arcade`-based
version of the project).
"""

from __future__ import annotations

import logging
from typing import Any, Optional

try:
    import pygame  # type: ignore
except Exception:  # pragma: no cover - fallback for environments without pygame
    # Minimal pygame-like stubs so this module can be imported without the
    # real `pygame` package. These implementations are intentionally tiny
    # and only provide the attributes used by DevMode.
    class _Rect:
        def __init__(self, x: int, y: int, w: int, h: int) -> None:
            self.x = x
            self.y = y
            self.w = w
            self.h = h

        def collidepoint(self, pos: tuple[int, int]) -> bool:
            px, py = pos
            return self.x <= px <= self.x + self.w and self.y <= py <= self.y + self.h

    class _Surface:
        SRCALPHA = 0

        def __init__(self, *_: Any, **__: Any) -> None:
            pass

        def fill(self, *_: Any, **__: Any) -> None:
            return None

        def blit(self, *_: Any, **__: Any) -> None:
            return None

    class _Font:
        def render(self, text: str, *_: Any, **__: Any) -> _Surface:
            return _Surface()

    class _Draw:
        @staticmethod
        def rect(*_: Any, **__: Any) -> None:
            return None

    class _Event:
        MOUSEBUTTONDOWN = 1
        KEYDOWN = 2

    class _Key:
        K_RETURN = 13
        K_BACKSPACE = 8

    pygame = type(
        "pygame",
        (),
    )
    # Attach attributes to the pygame stub
    pygame.Rect = _Rect  # type: ignore[attr-defined]
    pygame.Surface = _Surface  # type: ignore[attr-defined]
    pygame.font = type("font", (), {"Font": _Font})  # type: ignore[attr-defined]
    pygame.draw = _Draw  # type: ignore[attr-defined]
    pygame.event = type("event", (), {})  # type: ignore[attr-defined]
    pygame.MOUSEBUTTONDOWN = _Event.MOUSEBUTTONDOWN  # type: ignore[attr-defined]
    pygame.KEYDOWN = _Event.KEYDOWN  # type: ignore[attr-defined]
    pygame.K_RETURN = _Key.K_RETURN  # type: ignore[attr-defined]
    pygame.K_BACKSPACE = _Key.K_BACKSPACE  # type: ignore[attr-defined]
    pygame.SRCALPHA = _Surface.SRCALPHA  # type: ignore[attr-defined]


# --- Logging setup ---
logging.basicConfig(level=logging.INFO)


# --- Player class for dev mode ---
class Player:
    def __init__(self) -> None:
        self.inventory: list[str] = []
        self.exp: int = 0

    def add_item(self, item: str) -> None:
        item = (item or "").strip()
        if item:
            self.inventory.append(item)
            logging.info("Added %s to player inventory", item)

    def add_experience(self, amount: str | int) -> None:
        try:
            val = int(amount)
            if val > 0:
                self.exp += val
                logging.info("Added %s XP to player", val)
            else:
                logging.warning("XP must be positive")
        except (TypeError, ValueError):
            logging.warning("Invalid XP amount; must be integer")


# --- Developer mode system ---
class DevMode:
    """Simple developer-mode UI using a pygame-compatible API.

    The implementation is intentionally small — it draws a panel with
    two buttons (Give Item, Give XP) and accepts simple text input when
    a button is active.
    """

    def __init__(self, player: Player, screen: Any, font: Any) -> None:
        self.player = player
        self.screen = screen
        self.font = font
        self.active: bool = False
        self.buttons = {
            "Give Item": pygame.Rect(50, 50, 150, 40),
            "Give XP": pygame.Rect(50, 100, 150, 40),
        }
        self.input_mode: Optional[str] = None
        self.input_text: str = ""

    def toggle(self) -> None:
        self.active = not self.active
        if not self.active:
            self.input_mode = None
            self.input_text = ""

    def handle_event(self, event: Any) -> None:
        if not self.active:
            return

        if getattr(event, "type", None) == getattr(pygame, "MOUSEBUTTONDOWN", None):
            mouse_pos = getattr(event, "pos", None) or getattr(event, "button", None)
            if mouse_pos:
                if self.buttons["Give Item"].collidepoint(mouse_pos):
                    self.input_mode = "item"
                    self.input_text = ""
                elif self.buttons["Give XP"].collidepoint(mouse_pos):
                    self.input_mode = "xp"
                    self.input_text = ""

        elif getattr(event, "type", None) == getattr(pygame, "KEYDOWN", None):
            if not self.input_mode:
                return
            key = getattr(event, "key", None)
            if key == getattr(pygame, "K_RETURN", None):
                if self.input_mode == "item":
                    self.player.add_item(self.input_text.strip())
                elif self.input_mode == "xp":
                    self.player.add_experience(self.input_text.strip())
                self.input_mode = None
                self.input_text = ""
            elif key == getattr(pygame, "K_BACKSPACE", None):
                self.input_text = self.input_text[:-1]
            else:
                self.input_text += getattr(event, "unicode", "")

    def draw(self) -> None:
        if not self.active:
            return

        # Semi-transparent panel (pygame Surface supports SRCALPHA)
        panel = pygame.Surface((250, 200), pygame.SRCALPHA)
        panel.fill((50, 50, 50, 180))
        try:
            self.screen.blit(panel, (40, 40))
        except Exception:
            # If using the stub, blit may be a no-op.
            pass

        # Draw buttons
        for name, rect in self.buttons.items():
            try:
                pygame.draw.rect(self.screen, (100, 100, 100), rect)
            except Exception:
                pass
            try:
                text_surf = self.font.render(name, True, (255, 255, 255))
                self.screen.blit(text_surf, (rect.x + 5, rect.y + 5))
            except Exception:
                pass

        # Draw input box
        if self.input_mode:
            input_rect = pygame.Rect(50, 150, 150, 30)
            try:
                pygame.draw.rect(self.screen, (80, 80, 80), input_rect)
                input_surf = self.font.render(self.input_text, True, (255, 255, 255))
                self.screen.blit(input_surf, (input_rect.x + 5, input_rect.y + 5))
            except Exception:
                pass
# pylint: disable=no-member
"""
Developer mode module for Shattered Fates.
Provides debug controls, item/XP spawning, and testing tools.
"""

import logging
from typing import Optional

import pygame

# --- Logging setup ---
logging.basicConfig(level=logging.INFO)


# --- Player class for dev mode ---
class Player:
    def __init__(self) -> None:
        self.inventory: list[str] = []
        self.exp: int = 0

    def add_item(self, item: str) -> None:
        item = (item or "").strip()
        if item:
            self.inventory.append(item)
            logging.info("Added %s to player inventory", item)

    def add_experience(self, amount: str) -> None:
        try:
            val = int(amount)
            if val > 0:
                self.exp += val
                logging.info("Added %s XP to player", val)
            else:
                logging.warning("XP must be positive")
        except (TypeError, ValueError):
            logging.warning("Invalid XP amount; must be integer")


# --- Developer mode system ---
class DevMode:
    def __init__(self, player: Player, screen: pygame.Surface, font: pygame.font.Font) -> None:
        self.player = player
        self.screen = screen
        self.font = font
        self.active: bool = False
        self.buttons = {
            "Give Item": pygame.Rect(50, 50, 150, 40),
            "Give XP": pygame.Rect(50, 100, 150, 40),
        }
        self.input_mode: Optional[str] = None
        self.input_text: str = ""

    def toggle(self) -> None:
        self.active = not self.active

    def handle_event(self, event: pygame.event.Event) -> None:
        if not self.active:
            return

        if event.type == pygame.MOUSEBUTTONDOWN:
            mouse_pos = event.pos
            if self.buttons["Give Item"].collidepoint(mouse_pos):
                self.input_mode = "item"
                self.input_text = ""
            elif self.buttons["Give XP"].collidepoint(mouse_pos):
                self.input_mode = "xp"
                self.input_text = ""

        elif event.type == pygame.KEYDOWN:
            if self.input_mode:
                if event.key == pygame.K_RETURN:
                    if self.input_mode == "item":
                        self.player.add_item(self.input_text.strip())
                    elif self.input_mode == "xp":
                        self.player.add_experience(self.input_text.strip())
                    self.input_mode = None
                    self.input_text = ""
                elif event.key == pygame.K_BACKSPACE:
                    self.input_text = self.input_text[:-1]
                else:
                    self.input_text += getattr(event, "unicode", "")

    def draw(self) -> None:
        if not self.active:
            return

        # Semi-transparent panel
        panel = pygame.Surface((250, 200), pygame.SRCALPHA)
        panel.fill((50, 50, 50, 180))
        self.screen.blit(panel, (40, 40))

        # Draw buttons
        for name, rect in self.buttons.items():
            pygame.draw.rect(self.screen, (100, 100, 100), rect)
            text_surf = self.font.render(name, True, (255, 255, 255))
            self.screen.blit(text_surf, (rect.x + 5, rect.y + 5))

        # Draw input box
        if self.input_mode:
            input_rect = pygame.Rect(50, 150, 150, 30)
            pygame.draw.rect(self.screen, (80, 80, 80), input_rect)
            input_surf = self.font.render(self.input_text, True, (255, 255, 255))
            self.screen.blit(input_surf, (input_rect.x + 5, input_rect.y + 5))
