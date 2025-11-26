"""Start next alignment-based quest for the created cat."""
from __future__ import annotations

import os
import sys
import json

_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
if _ROOT not in sys.path:
    sys.path.insert(0, _ROOT)

SETTINGS = os.path.join("Settings", "game_settings.json")


def load_settings() -> dict:
    try:
        with open(SETTINGS, "r", encoding="utf-8") as f:
            return json.load(f)
    except (OSError, json.JSONDecodeError):
        return {}


def main() -> int:
    try:
        from data.scripts.quests.quest_manager import QuestManager  # type: ignore
    except (ImportError, ModuleNotFoundError):
        print("QuestManager import failed. Ensure packages exist or adjust path.")
        return 2
    settings = load_settings()
    cat = settings.get("last_created_cat") if isinstance(settings, dict) else None
    if not isinstance(cat, dict):
        print("No cat found. Run tools/start_character.py first.")
        return 1
    alignment = (cat.get("alignment") or "neutral").lower()
    qm = QuestManager()
    quest = qm.next_quest_for_alignment(alignment)
    if not quest:
        print(f"No quest available for alignment '{alignment}'.")
        return 0
    qm.start_quest(quest)
    return 0


if __name__ == "__main__":
    sys.exit(main())
