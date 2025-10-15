"""
Main entry point for Shattered Fates.

Provides a simple Pygame window, player movement, NPC placeholders, and developer mode utilities.
Pylint false positives for pygame (compiled extension) are disabled only
inside the main function to avoid noisy "no-member" warnings.
"""

from __future__ import annotations

import sys
import os
import json
import logging
from typing import Dict, Any, List, Optional, Union

# type: ignore
import pygame 


# --- Logging setup ---
logging.basicConfig(level=logging.INFO)

# --- Developer mode utilities ---
class Player:
    """Represents a player entity in developer mode with inventory and experience."""

    def __init__(self) -> None:
        """Initialize the player with empty inventory and zero experience."""
        self.inventory: List[str] = []
        self.exp: int = 0

    def add_item(self, item: str) -> None:
        """Add an item to the player's inventory if valid."""
        item = (item or "").strip()
        if item:
            self.inventory.append(item)
            logging.info("Added %s to player inventory", item)
        else:
            logging.warning("Item name cannot be empty.")

    def add_experience(self, amount: Union[str, int]) -> None:
        """Add experience points to the player if the amount is valid."""
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
    """Handles developer mode UI and interactions for testing."""

    def __init__(self, player: Player, screen: pygame.Surface, font: pygame.font.Font) -> None:
        """Initialize the dev mode with player, screen, and font."""
        self.player = player
        self.screen = screen
        self.font = font
        self.active = False
        self.buttons: Dict[str, pygame.Rect] = {
            "Give Item": pygame.Rect(50, 50, 150, 40),
            "Give XP": pygame.Rect(50, 100, 150, 40),
        }
        self.input_mode: Optional[str] = None  # "item" | "xp" | None
        self.input_text: str = ""

    def toggle(self) -> None:
        """Toggle the active state of the dev mode panel."""
        self.active = not self.active
        if not self.active:
            self.input_mode = None
            self.input_text = ""

    def handle_event(self, event: pygame.event.Event) -> None:
        """Process events for dev mode interactions."""
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
                    # Append printable unicode characters
                    if event.unicode and event.unicode.isprintable():
                        self.input_text += event.unicode

    def draw(self) -> None:
        """Render the dev mode UI on the screen if active."""
        if not self.active:
            return

        # Semi-transparent panel
        panel = pygame.Surface((260, 210), pygame.SRCALPHA)
        panel.fill((50, 50, 50, 180))
        self.screen.blit(panel, (40, 40))

        # Title
        title_surf = self.font.render("Developer Mode (F1 to toggle)", True, (255, 255, 255))
        self.screen.blit(title_surf, (50, 50 - 25))

        # Draw buttons
        for name, rect in self.buttons.items():
            pygame.draw.rect(self.screen, (100, 100, 100), rect)
            text_surf = self.font.render(name, True, (255, 255, 255))
            self.screen.blit(text_surf, (rect.x + 8, rect.y + 8))

        # Draw input box
        if self.input_mode:
            label = "Item:" if self.input_mode == "item" else "XP:"
            label_surf = self.font.render(label, True, (255, 255, 255))
            self.screen.blit(label_surf, (50, 150 - 22))

            input_rect = pygame.Rect(50, 150, 150, 30)
            pygame.draw.rect(self.screen, (80, 80, 80), input_rect)
            input_surf = self.font.render(self.input_text, True, (255, 255, 255))
            self.screen.blit(input_surf, (input_rect.x + 6, input_rect.y + 6))

        # Debug info (current XP and number of items)
        info = f"XP: {self.player.exp} | Items: {len(self.player.inventory)}"
        info_surf = self.font.render(info, True, (220, 220, 220))
        self.screen.blit(info_surf, (50, 190))

# Window settings
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
FPS = 60

# Paths (data folder is assumed to be at project_root/data)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.normpath(os.path.join(BASE_DIR, "data"))
CHAR_DIR = os.path.join(DATA_DIR, "Characters")
SPRITE_DIR = os.path.normpath(os.path.join(BASE_DIR, "sprites", "cats"))

# Ensure character folder exists (so file checks won't error)
os.makedirs(CHAR_DIR, exist_ok=True)

def read_json_safe(path: str) -> Optional[Dict[str, Any]]:
    """Read a JSON file safely, returning a dict or None if missing/invalid."""
    if not os.path.exists(path):
        return None
    try:
        with open(path, "r", encoding="utf-8") as fh:
            return json.load(fh)
    except (json.JSONDecodeError, OSError):
        return None

def load_npc(npc_name: str, fallback_index: int = 0) -> Dict[str, Any]:
    """Load NPC data from JSON, with fallbacks for missing keys."""
    path = os.path.join(CHAR_DIR, f"{npc_name}.json")
    data = read_json_safe(path) or {}

    x = int(data.get("x", 200 + fallback_index * 100))
    y = int(data.get("y", 200))
    w = int(data.get("width", 40))
    h = int(data.get("height", 40))

    return {
        "name": data.get("name", npc_name),
        "clan": data.get("clan", data.get("Clan", "Unknown")),
        "role": data.get("role", data.get("Role", "NPC")),
        "rect": pygame.Rect(x, y, w, h),
    }

def clamp(value: int, minimum: int, maximum: int) -> int:
    """Clamp an integer value between min and max inclusive."""
    return max(minimum, min(maximum, value))

def main() -> None:
    """Initialize Pygame, run the main game loop with player movement, NPCs, and dev mode."""
    # pylint: disable=no-member
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Shattered Fates")
    clock = pygame.time.Clock()

    # Initialize font for dev mode
    font = pygame.font.Font(None, 22)

    # Player placeholder (rectangle)
    player_rect = pygame.Rect(100, 100, 40, 40)
    player_speed = 4

    # Dev mode player and UI
    dev_player = Player()
    dev_ui = DevMode(dev_player, screen, font)

    # Load example NPCs (positions staggered so they don't overlap)
    npc_names = ["Ivypaw", "Bramblekit"]
    npcs: List[Dict[str, Any]] = []
    for idx, name in enumerate(npc_names):
        npc = load_npc(name, fallback_index=idx)
        # Ensure valid rect (some JSON may supply 0 or invalid values)
        if npc["rect"].width <= 0 or npc["rect"].height <= 0:
            npc["rect"].width = 40
            npc["rect"].height = 40
        npcs.append(npc)

    currently_colliding: Dict[str, bool] = {npc["name"]: False for npc in npcs}

    running = True
    while running:
        clock.tick(FPS)

        # Event handling (quit and dev mode)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            # Toggle dev panel with F1
            if event.type == pygame.KEYDOWN and event.key == pygame.K_F1:
                dev_ui.toggle()
            # Pass all events to dev UI (it ignores when inactive)
            dev_ui.handle_event(event)

        # Movement input (WASD + arrows)
        keys = pygame.key.get_pressed()
        if keys[pygame.K_w] or keys[pygame.K_UP]:
            player_rect.y -= player_speed
        if keys[pygame.K_s] or keys[pygame.K_DOWN]:
            player_rect.y += player_speed
        if keys[pygame.K_a] or keys[pygame.K_LEFT]:
            player_rect.x -= player_speed
        if keys[pygame.K_d] or keys[pygame.K_RIGHT]:
            player_rect.x += player_speed

        # Keep player inside window bounds
        player_rect.x = clamp(player_rect.x, 0, SCREEN_WIDTH - player_rect.width)
        player_rect.y = clamp(player_rect.y, 0, SCREEN_HEIGHT - player_rect.height)

        # Rendering
        screen.fill((50, 50, 50))  # background

        # Draw NPCs and simple collision detection
        for npc in npcs:
            rect: pygame.Rect = npc["rect"]
            pygame.draw.rect(screen, (200, 50, 50), rect)
            if player_rect.colliderect(rect):
                if not currently_colliding.get(npc["name"], False):
                    # Triggered once when collision begins
                    print(f"You bumped into {npc['name']} ({npc.get('role', 'NPC')}).")
                    currently_colliding[npc["name"]] = True
            else:
                currently_colliding[npc["name"]] = False

        # Draw player on top
        pygame.draw.rect(screen, (0, 150, 200), player_rect)

        # Draw dev mode UI
        dev_ui.draw()

        # Flip buffer
        pygame.display.flip()

    pygame.quit()
    # pylint: enable=no-member
    sys.exit(0)

if __name__ == "__main__":
    main() # type ignore
