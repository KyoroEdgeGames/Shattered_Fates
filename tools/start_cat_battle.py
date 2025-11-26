"""Run a battle using the created cat against a generated opponent."""
from __future__ import annotations

import os
import sys
import json
import random

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
    from scripts.Combat.battle import Battle, Combatant  # type: ignore
    from scripts.clans.clan_system import ClanRegistry  # type: ignore
    settings = load_settings()
    cat = settings.get("last_created_cat") if isinstance(settings, dict) else None
    if not isinstance(cat, dict):
        print("No cat found. Run tools/start_character.py first.")
        return 1

    name = str(cat.get("name") or "Unnamed")
    role = str(cat.get("role") or "warrior")
    injuries = cat.get("injuries") if isinstance(cat.get("injuries"), list) else []
    # Basic HP/attack derivation from role & injuries
    base_hp = 30 if "kit" not in role else 20
    if "leader" in role:
        base_hp += 10
    attack = 6 if "warrior" in role else 4
    if "apprentice" in role:
        attack -= 1
    # Penalties for injuries (mirrors effective_attack logic later)
    base_hp -= min(6, len(injuries) * 2)
    hp = max(10, base_hp)

    player_c = Combatant(name=name, hp=hp, attack=attack, role=role, injuries=injuries)  # type: ignore

    # Generate opponent
    opp_names = ["Rogue", "Badger", "Fox", "Owl", "Shadowcat"]
    opp_name = random.choice(opp_names)
    opp = Combatant(name=opp_name, hp=random.randint(18, 32), attack=random.randint(3, 6), role="rogue", injuries=[])  # type: ignore

    print(f"Battle: {player_c.name} ({role}, hp={player_c.hp}, atk={player_c.attack}) vs {opp.name} (hp={opp.hp})")
    b = Battle(player_c, opp)
    winner = b.run()
    print(f"Winner: {winner.name}")

    # Alignment drift: simplistic heuristic
    # Good if healed (medicine/apprentice) won; evil if pure damage warrior won with no heals; else neutral
    old_align = str(cat.get("alignment") or "neutral").lower()
    new_align = old_align
    if winner.name == player_c.name:
        if "medicine_cat" in role:
            new_align = "good"
        elif "warrior" in role and not injuries:
            new_align = "evil" if old_align != "good" else old_align
        else:
            new_align = old_align or "neutral"
    else:
        # Losing battle may push toward neutral if previously extreme
        if old_align in ("evil", "good"):
            new_align = "neutral"

    if new_align != old_align:
        cat["alignment"] = new_align
        print(f"Alignment drift: {old_align} -> {new_align}")

    # Clan reputation update
    clan = str(cat.get("clan") or "UnknownClan")
    reg = ClanRegistry()
    reg.load()
    delta = 2 if winner.name == player_c.name else -1
    rep = reg.adjust_reputation(clan, delta)
    reg.save()
    print(f"Clan {clan} reputation changed by {delta} (now {rep})")

    # Persist cat changes (alignment) back to settings
    try:
        settings["last_created_cat"] = cat
        with open(SETTINGS, "w", encoding="utf-8") as f:
            json.dump(settings, f, indent=2)
    except OSError:
        pass
    return 0

if __name__ == "__main__":
    sys.exit(main())
