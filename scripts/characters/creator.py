"""Character creation scaffolding for Shattered Fates.

This module provides a minimal data model for Cats (name, clan, role,
traits) and a CLI `create_character_cli()` to quickly create a character
from prompts. It reads known clans and roles when available.
"""
from __future__ import annotations

import json
import os
from dataclasses import dataclass, asdict
from typing import List, Dict, Optional

DATA_CLANS = os.path.join("data", "Clans", "clans.json")
SETTINGS = os.path.join("Settings", "game_settings.json")


ALIGNMENTS = ["good", "neutral", "evil"]
ROLES = [
    "kit",
    "apprentice",
    "warrior",
    "mediator",
    "medicine_cat",
    "leader",
    # apprentices per synopsis
    "medicine_cat_apprentice",
    "warrior_apprentice",
    "mediator_apprentice",
    "queen_apprentice",
    # den roles
    "queen",
    "den_dad",
]

PERSONALITY_TRAITS = [
    "brave",
    "cunning",
    "loyal",
    "curious",
    "compassionate",
    "stoic",
    "hotheaded",
    "patient",
    "ambitious",
    "diplomatic",
]

PERMANENT_INJURIES = [
    "blind_eye",
    "limp",
    "torn_ear",
    "scarred_paw",
    "crippled_leg",
]


@dataclass
class Cat:
    name: str
    clan: str
    role: str
    traits: List[str]
    alignment: str
    injuries: List[str]
    mentor: str = ""
    story_arc: str = ""
    completed_quests: List[str] = None  # type: ignore

    def to_dict(self) -> Dict:
        return asdict(self)


def _load_json(path: str) -> Optional[Dict]:
    try:
        if os.path.exists(path):
            with open(path, "r", encoding="utf-8") as f:
                return json.load(f)
    except (OSError, json.JSONDecodeError):
        return None
    return None


def list_known_clans() -> List[str]:
    data = _load_json(DATA_CLANS) or {}
    names = []
    for c in data.get("clans", []):
        name = c.get("name")
        if isinstance(name, str):
            names.append(name)
    return names or ["Frostclan", "Bloodclan", "Lostclan", "Heavyclan"]


def list_known_roles() -> List[str]:
    # Expanded roles per synopsis
    return ROLES


def list_alignments() -> List[str]:
    return ALIGNMENTS


def _choose_from_list(title: str, options: List[str], default_idx: int = 0) -> str:
    print(title)
    for i, opt in enumerate(options, 1):
        print(f"  {i}. {opt}")
    try:
        idx = int(input(f"Choice # (1..{len(options)}): ")) - 1
    except ValueError:
        idx = default_idx
    return options[idx] if 0 <= idx < len(options) else options[default_idx]


def _choose_traits(max_traits: int = 3) -> List[str]:
    print("Choose up to", max_traits, "personality traits (comma-separated numbers):")
    for i, t in enumerate(PERSONALITY_TRAITS, 1):
        print(f"  {i}. {t}")
    raw = input("Traits #: ").strip()
    if not raw:
        return []
    picks: List[str] = []
    for part in raw.split(","):
        part = part.strip()
        if not part:
            continue
        try:
            idx = int(part) - 1
        except ValueError:
            continue
        if 0 <= idx < len(PERSONALITY_TRAITS):
            picks.append(PERSONALITY_TRAITS[idx])
        if len(picks) >= max_traits:
            break
    return picks


def _maybe_born_with_injury() -> List[str]:
    ans = input("Born with a permanent injury? [y/N]: ").strip().lower()
    if ans not in ("y", "yes"):  # default no
        return []
    print("Choose an injury:")
    for i, inj in enumerate(PERMANENT_INJURIES, 1):
        print(f"  {i}. {inj}")
    try:
        ii = int(input("Injury # (1..n): ")) - 1
    except ValueError:
        ii = 0
    if 0 <= ii < len(PERMANENT_INJURIES):
        return [PERMANENT_INJURIES[ii]]
    return []


def create_character_cli() -> Cat:
    print("Create your warrior cat!")
    name = input("Name: ").strip() or "Unnamed"
    clans = list_known_clans()
    clan = _choose_from_list("Choose clan:", clans, default_idx=0)

    roles = list_known_roles()
    role = _choose_from_list("Choose clan role:", roles, default_idx=0)

    alignment = _choose_from_list("Choose alignment:", list_alignments(), default_idx=1)

    traits = _choose_traits(max_traits=3)
    injuries = _maybe_born_with_injury()

    mentor = ""
    if "apprentice" in role:
        # Simple mentor assignment prompt
        possible = ["SeniorWarrior", "MedicineMaster", "ClanDeputy", "ElderShade"]
        mentor = _choose_from_list("Choose mentor:", possible, default_idx=0)

    # Derive story arc by canonical names
    if name.lower() == 'ivy':
        story_arc = 'ivy'
    elif name.lower() == 'coal':
        story_arc = 'coal'
    else:
        story_arc = 'custom_branch'
    cat = Cat(name=name, clan=clan, role=role, traits=traits, alignment=alignment, injuries=injuries, mentor=mentor, story_arc=story_arc, completed_quests=[])
    print("\nCreated:")
    print(json.dumps(cat.to_dict(), indent=2))

    # Optionally persist last created in settings
    try:
        settings = _load_json(SETTINGS) or {}
        settings["last_created_cat"] = cat.to_dict()
        os.makedirs(os.path.dirname(SETTINGS), exist_ok=True)
        with open(SETTINGS, "w", encoding="utf-8") as f:
            json.dump(settings, f, indent=2)
        print(f"Saved to {SETTINGS}")
    except OSError:
        pass

    return cat


if __name__ == "__main__":
    create_character_cli()
