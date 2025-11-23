"""
Quest system module for Shattered Fates.

Handles loading, starting, and managing quest data from JSON files.
"""

import json
import os


class Quest:
    """
    Represents a quest loaded from a JSON file.

    Attributes:
        data (dict): The quest data loaded from the file.
        active (bool): Whether the quest is currently active.
    """

    def __init__(self, path):
        """
        Initializes a Quest instance by loading quest data from a JSON file.

        Args:
            path (str): Path to the quest JSON file.

        Raises:
            FileNotFoundError: If the quest file does not exist.
            KeyError: If the quest data does not contain a 'name' key.
        """
        if not os.path.exists(path):
            raise FileNotFoundError(f"Quest file not found: {path}")
        with open(path, encoding="utf-8") as f:
            self.data = json.load(f)
        if "name" not in self.data:
            raise KeyError("Quest data must contain a 'name' key.")
        self.active = self.data.get("active", False)

    def start(self):
        """
        Marks the quest as active and prints a start message.

        Returns:
            None
        """
        self.active = True
        print(f"Quest '{self.data['name']}' started!")


def load_quest(path):
    """
    Loads a quest from the specified JSON file path.

    Args:
        path (str): Path to the quest JSON file.

    Returns:
        Quest: The loaded Quest instance.
    """
    return Quest(path)
