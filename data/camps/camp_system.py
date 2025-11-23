# Scripts/camp_system.py
"""camp_system.py

Handles clan camp management and kit generation for the Shattered Fates game.
Includes functionality for reading/writing character data, managing camp layout,
and spawning new kits with randomized attributes.
"""


import json
import os
import random
from datetime import datetime
from typing import List, Optional

# Base directories
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DATA_DIR = os.path.join(BASE_DIR, "Data")
CHAR_DIR = os.path.join(DATA_DIR, "Characters")
CAMP_DIR = os.path.join(DATA_DIR, "Camps")


def read_json(path: str) -> dict:
    """Read JSON file from path and return as dict."""
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def write_json(path: str, data: dict) -> None:
    """Write dictionary data to a JSON file at path."""
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=4)



class Camp:
    """Represents a clan camp with spaces and nursery."""

    def __init__(self, clan_name: str):
        self.clan_name = clan_name
        self.structure_file = os.path.join(CAMP_DIR, "camp_structure.json")
        if os.path.exists(self.structure_file):
            all_struct = read_json(self.structure_file)
            self.layout = all_struct.get(clan_name, {})
        else:
            self.layout = {}
        self.nursery: List[str] = []  # list of kit names

    def get_space(self, space_name: str) -> Optional[dict]:
        """Return the layout data of a given space in camp."""
        return self.layout.get(space_name, None)

    def add_kit_to_nursery(self, kit_data: dict) -> None:
        """Add a kit to nursery and save as JSON character file."""
        kit_filename = f"{kit_data['name']}.json"
        kit_path = os.path.join(CHAR_DIR, kit_filename)
        write_json(kit_path, kit_data)
        self.nursery.append(kit_data["name"])
        print(f"Kit {kit_data['name']} added to {self.clan_name} nursery.")

    def list_nursery(self) -> List[str]:
        """Return a list of kits currently in the nursery."""
        return list(self.nursery)


def generate_kit_name(parent1: str, parent2: str) -> str:
    """Generate a kit name based on halves of parent names + timestamp."""
    p1 = parent1[: len(parent1) // 2]
    p2 = parent2[len(parent2) // 2 :]
    suffix = datetime.utcnow().strftime("%f")[:3]
    return (p1 + p2 + suffix).capitalize()


def generate_kits(
    mother_name: str,
    father_name: str,
    clan_name: str,
    num_kits: int = 2,
    sexes: Optional[List[str]] = None,
) -> List[str]:
    """Create kits for a clan and add them to the nursery.

    Args:
        mother_name: Name of the mother cat
        father_name: Name of the father cat
        clan_name: Clan name where kits will belong
        num_kits: Number of kits to spawn (default 2)
        sexes: Optional list of sexes ('male'/'female'); randomize if None

    Returns:
        List of created kit names
    """
    if num_kits <= 0:
        raise ValueError("num_kits must be >= 1")
    if not mother_name or not father_name:
        raise ValueError("mother_name and father_name must be provided")
    if sexes is not None and len(sexes) != num_kits:
        raise ValueError("Length of sexes list must equal num_kits")

    camp = Camp(clan_name)
    kits_created: List[str] = []

    for i in range(num_kits):
        kit_name = generate_kit_name(mother_name, father_name)
        kit_data = {
            "name": kit_name,
            "clan": clan_name,
            "role": "Kit",
            "age_stage": "kit",
            "sex": random.choice(["male", "female"]) if sexes is None else sexes[i],
            "mate": None,
            "children": [],
            "romance_flags": {},
        }
        camp.add_kit_to_nursery(kit_data)
        kits_created.append(kit_name)

    return kits_created
