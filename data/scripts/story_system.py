"""
Story system module for Shattered Fates.

Manages seasonal, spring, and general events, as well as quests and story triggers.
"""

import os
import json
import random

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA_DIR = os.path.join(BASE_DIR, "Data")
EVENTS_DIR = os.path.join(DATA_DIR, "Events")

def read_json(path: str) -> dict:
    """Reads a JSON file and returns its contents as a dictionary."""
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

class StoryEvent:
    """Represents a single story event."""

    def __init__(self, event_data: dict):
        self.name = event_data.get("name", "Unnamed Event")
        self.description = event_data.get("description", "")
        self.effects = event_data.get("effects", {})  # dictionary of changes
        self.quest = event_data.get("quest", None)   # optional quest object

    def trigger_event(self) -> tuple:
        """
        Trigger the event.

        Returns:
            tuple: (effects dictionary, quest object or None)
        """
        # Event can have effects applied to the game state
        return self.effects, self.quest

class StorySystem:
    """Manages all story and seasonal events."""

    def __init__(self):
        # Load all event JSONs
        self.spring_events = read_json(os.path.join(EVENTS_DIR, "spring_events.json"))
        self.seasonal_events = read_json(os.path.join(EVENTS_DIR, "seasonal_events.json"))
        self.general_events = read_json(os.path.join(EVENTS_DIR, "general_events.json"))

    def get_random_event(self, event_type: str) -> StoryEvent:
        """
        Get a random event from a given category.

        Args:
            event_type (str): "spring", "seasonal", or "general"

        Returns:
            StoryEvent: A StoryEvent object
        """
        if event_type == "spring":
            events_list = self.spring_events
        elif event_type == "seasonal":
            events_list = self.seasonal_events
        elif event_type == "general":
            events_list = self.general_events
        else:
            raise ValueError(f"Unknown event type: {event_type}")

        event_data = random.choice(events_list)
        return StoryEvent(event_data)

    def trigger_random_event(self, event_type: str):
        """
        Trigger a random event and return its quest (if any).

        Args:
            event_type (str): "spring", "seasonal", or "general"

        Returns:
            quest or None: The quest object from the event
        """
        event_obj = self.get_random_event(event_type)
        # Ignore effects for now to prevent Pylint warning
        _, quest = event_obj.trigger_event()
        return quest
