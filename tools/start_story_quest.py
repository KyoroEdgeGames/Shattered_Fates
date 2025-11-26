"""Start next storyline quest (arc first, alignment fallback) and persist completion.

Uses QuestManager.next_for_cat; updates settings with completed quest id.
"""
from __future__ import annotations

import os
import json
import sys

SETTINGS = os.path.join("Settings", "game_settings.json")


def load_settings() -> dict:
    try:
        with open(SETTINGS, 'r', encoding='utf-8') as f:
            return json.load(f)
    except (OSError, json.JSONDecodeError):
        return {}


def save_settings(data: dict) -> None:
    try:
        os.makedirs(os.path.dirname(SETTINGS), exist_ok=True)
        with open(SETTINGS, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=2)
    except OSError:
        pass


class _CatAdapter:
    def __init__(self, raw: dict):
        self.name = raw.get('name', '')
        self.alignment = raw.get('alignment', 'neutral')
        self.story_arc = raw.get('story_arc', '')
        self.completed_quests = raw.get('completed_quests', []) or []


def main() -> int:
    try:
        from data.scripts.quests.quest_manager import QuestManager  # type: ignore
    except (ImportError, ModuleNotFoundError):
        print("QuestManager import failed.")
        return 2
    settings = load_settings()
    cat_raw = settings.get('last_created_cat') if isinstance(settings, dict) else None
    if not isinstance(cat_raw, dict):
        print("No cat found. Run tools/start_character.py first.")
        return 1
    cat = _CatAdapter(cat_raw)
    qm = QuestManager()
    quest = qm.next_for_cat(cat)
    if not quest:
        print("No storyline or alignment quest available.")
        return 0
    qm.start_quest(quest)
    qid = quest.get('id') or quest.get('name')
    if qid:
        cat.completed_quests.append(qid)
        cat_raw['completed_quests'] = cat.completed_quests
        # Potential alignment/arc shifts from rewards
        rewards = quest.get('rewards', {}) or {}
        shift = rewards.get('alignment_shift')
        if shift and isinstance(shift, str):
            cat_raw['alignment'] = shift
        save_settings(settings)
    return 0


if __name__ == '__main__':
    sys.exit(main())
