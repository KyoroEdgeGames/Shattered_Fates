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
