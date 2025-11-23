"""
npc_behavior.py

Defines the NPC class and its behavior for Shattered Fates.
Handles NPC dialogue, quests, and other interactions.
"""

from typing import List, Optional


class NPC:
    """
    Represents a non-player character (NPC) in the game.
    """
    def __init__(self, name: str, clan: str, quests: Optional[List[str]] = None):
        self.name = name
        self.clan = clan
        self.quests = quests if quests is not None else []

def talk(self):
    """Prints a greeting from the NPC."""
    print(f"{self.name} of {self.clan} says: Hello, traveler!")

def give_quest(self):
    """Prints the list of quests the NPC offers."""
    if not self.quests:
        print(f"{self.name} has no quests to offer.")
        return
    for quest in self.quests:
        print(f"{self.name} offers quest: {quest}")
