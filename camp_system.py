"""
Camp system module for Shattered Fates.

Provides classes and functions to manage clan camps, den spaces, nursery spaces,
Starcove, and kit spawning.
"""

import os
import json
import random
from datetime import datetime
from typing import Any, Dict, List, Optional

# Base directory is the folder this file lives in. Adjust if you place this file
# elsewhere (for example, one level deeper).
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

DATA_DIR = os.path.join(BASE_DIR, "data")
CHAR_DIR = os.path.join(DATA_DIR, "Characters")
CAMP_DIR = os.path.join(DATA_DIR, "Camps")

# Make sure data folders exist to avoid write errors
os.makedirs(CHAR_DIR, exist_ok=True)
os.makedirs(CAMP_DIR, exist_ok=True)


def read_json(path: str) -> Dict[str, Any]:
    """Read JSON from a file. Return {} on error or if file is missing."""
    if not os.path.exists(path):
        return {}
    try:
        with open(path, "r", encoding="utf-8") as fh:
            return json.load(fh)
    except (json.JSONDecodeError, OSError):
        return {}


def write_json(path: str, data: Dict[str, Any]) -> None:
    """Write a dictionary to a JSON file, creating directories if needed."""
    parent = os.path.dirname(path)
    if parent and not os.path.exists(parent):
        os.makedirs(parent, exist_ok=True)
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(data, fh, indent=4, ensure_ascii=False)


class Camp:
    """
    Represents a clan camp, including layout, dens, and nursery management.
    """

    def __init__(self, clan_name: str) -> None:
        """
        Initialize a Camp. Load layout from camp_structure.json if present,
        otherwise use a sane default layout.
        """
        self.clan_name: str = clan_name
        self.structure_file: str = os.path.join(CAMP_DIR, "camp_structure.json")
        stored = read_json(self.structure_file)

        default_layout: Dict[str, Any] = {
            "Warrior's Den": [],
            "Apprentice's Den": [],
            "Medicine Cat Den": [],
            "Nursery": [],
            "Leader's Den": [],
            "Starcove": None,
        }

        # Load stored layout for this clan or use defaults
        self.layout: Dict[str, Any] = stored.get(clan_name, default_layout.copy())
        self.nursery: List[str] = list(self.layout.get("Nursery", []))

    def get_space(self, space_name: str) -> Optional[Any]:
        """Return a named space from the layout (list/dict/None)."""
        return self.layout.get(space_name)

    def _ensure_den_exists(self, den_name: str) -> None:
        """Create an empty list for the den in the layout if it is missing."""
        if den_name not in self.layout:
            self.layout[den_name] = []

    def add_cat_to_den(self, cat_name: str, role: str) -> None:
        """
        Add a cat to the correct den according to its role.

        - 'Kit' => Nursery
        - roles containing 'medicine' => Medicine Cat Den
        - roles containing 'apprentice' => Apprentice's Den
        - otherwise => Warrior's Den
        """
        role_low = (role or "").strip().lower()

        if role_low == "kit":
            self._ensure_den_exists("Nursery")
            if cat_name not in self.layout["Nursery"]:
                self.layout["Nursery"].append(cat_name)
            if cat_name not in self.nursery:
                self.nursery.append(cat_name)
            return

        if "medicine" in role_low:
            den = "Medicine Cat Den"
        elif "apprentice" in role_low:
            den = "Apprentice's Den"
        else:
            den = "Warrior's Den"

        self._ensure_den_exists(den)
        if cat_name not in self.layout[den]:
            self.layout[den].append(cat_name)

    def list_den(self, den_name: str) -> List[str]:
        """Return a shallow list of cats in the named den (empty list if none)."""
        den = self.layout.get(den_name)
        if isinstance(den, list):
            return list(den)
        return []

    def add_kit_to_nursery(self, kit_data: Dict[str, Any]) -> None:
        """
        Persist a kit file and add the kit to the nursery and appropriate den.

        kit_data must include 'name' and 'role'.
        """
        if "name" not in kit_data or "role" not in kit_data:
            raise ValueError("kit_data must include 'name' and 'role' keys")

        kit_filename = f"{kit_data['name']}.json"
        kit_path = os.path.join(CHAR_DIR, kit_filename)
        write_json(kit_path, kit_data)

        self.add_cat_to_den(kit_data["name"], kit_data["role"])
        print(f"Kit {kit_data['name']} added to {self.clan_name} nursery.")

    def list_nursery(self) -> List[str]:
        """Return list of kit names currently tracked in the nursery."""
        return list(self.nursery)


def generate_kit_name(parent1: str, parent2: str) -> str:
    """
    Generate a simple kit name from parent names + microsecond suffix.

    This tolerates empty or short parent names.
    """
    p1 = (parent1 or "")[: max(1, len(parent1 or "") // 2)]
    p2 = (parent2 or "")[len(parent2 or "") // 2 :]
    suffix = datetime.utcnow().strftime("%f")[:3]
    return (f"{p1}{p2}{suffix}").capitalize()


def spawn_kits(
    mother_name: str,
    father_name: str,
    clan_name: str,
    num_kits: int = 2,
    sexes: Optional[List[str]] = None,
) -> List[str]:
    """
    Spawn `num_kits` kits for `clan_name`, save their files, and register them.

    Returns the list of kit names created.
    """
    if num_kits <= 0:
        return []

    if sexes is None or len(sexes) < num_kits:
        sexes = [random.choice(["male", "female"]) for _ in range(num_kits)]

    clan_camp = Camp(clan_name)
    created: List[str] = []

    for i in range(num_kits):
        kit_name = generate_kit_name(mother_name, father_name)
        kit = {
            "name": kit_name,
            "clan": clan_name,
            "role": "Kit",
            "age_stage": "kit",
            "sex": sexes[i],
            "mate": None,
            "children": [],
            "romance_flags": {},
        }
        clan_camp.add_kit_to_nursery(kit)
        created.append(kit_name)

    # Persist layout back to camp_structure.json for persistence across runs
    structure_path = os.path.join(CAMP_DIR, "camp_structure.json")
    structure = read_json(structure_path) or {}
    structure[clan_name] = clan_camp.layout
    write_json(structure_path, structure)

    return created


# Manual test block
if __name__ == "__main__":
    demo = Camp("Bloodclan")
    demo.add_cat_to_den("Batpaw", "Medicine Cat Apprentice")
    demo.add_cat_to_den("Coalpaw", "Apprentice")
    demo.add_cat_to_den("Ivyclaw", "Warrior")
    print("Warriors:", demo.list_den("Warrior's Den"))
    print("Apprentices:", demo.list_den("Apprentice's Den"))
    print("Medicine Cats:", demo.list_den("Medicine Cat Den"))
    print("Nursery:", demo.list_nursery())
