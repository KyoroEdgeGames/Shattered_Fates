"""Abilities scaffold: defines basic active abilities for roles.

Provides a registry mapping roles to abilities and simple resolution
logic to compute damage/effects. Integrates with the `Battle` module by
offering a `use_ability(attacker, defender, ability)` helper.
"""
from __future__ import annotations

from dataclasses import dataclass, field
from typing import Dict, List
import time


@dataclass
class Ability:
    """Active skill with simple cooldown tracking."""
    name: str
    power: int  # base effect magnitude
    kind: str   # e.g., "damage", "heal", "buff"
    cooldown: float = 5.0  # seconds
    last_used: float = field(default_factory=lambda: -1.0)

    def ready(self) -> bool:
        if self.last_used < 0:
            return True
        return (time.time() - self.last_used) >= self.cooldown

    def mark_used(self) -> None:
        self.last_used = time.time()


ABILITIES_BY_ROLE: Dict[str, List[Ability]] = {
    "warrior": [Ability("Claw Swipe", power=5, kind="damage"), Ability("Ferocious Roar", power=2, kind="buff")],
    "warrior_apprentice": [Ability("Training Swipe", power=3, kind="damage")],
    "medicine_cat": [Ability("Herbal Salve", power=4, kind="heal")],
    "medicine_cat_apprentice": [Ability("Poultice", power=2, kind="heal")],
    "mediator": [Ability("Disarm", power=2, kind="buff")],
    "mediator_apprentice": [Ability("Calm Words", power=1, kind="buff")],
    "apprentice": [Ability("Pounce", power=3, kind="damage")],
    "leader": [Ability("Leadership Rally", power=3, kind="buff")],
    "queen": [Ability("Protect Kit", power=4, kind="buff")],
    "queen_apprentice": [Ability("Nurture", power=2, kind="buff")],
    "den_dad": [Ability("Guard Den", power=4, kind="buff")],
    # Specialized arc roles / unique characters
    "ivy": [Ability("Necrotic Slash", power=7, kind="damage"), Ability("Claw Swipe", power=5, kind="damage")],
}


def list_abilities_for_role(role: str) -> List[Ability]:
    """Return abilities registered for a given role key."""
    return ABILITIES_BY_ROLE.get(role, [])


def use_ability(attacker, defender, ability: Ability) -> int:
    """Apply an ability and return effect magnitude (e.g., damage dealt).

    This is intentionally simple: damage subtracts defender hp; heal adds
    attacker hp; buff does nothing yet but could affect future turns.
    """
    if not ability.ready():
        return 0  # on cooldown
    if ability.kind == "damage":
        dmg = max(1, ability.power)
        defender.hp -= dmg
        # Necrotic Slash adds a status effect (erosion over time)
        if ability.name.lower() == "necrotic slash":
            status = getattr(defender, 'status', None)
            if isinstance(status, dict):
                existing = status.get('necrotic')
                if existing:
                    # Refresh / stack limited: increase ticks up to 6 total
                    existing['ticks'] = min(6, existing.get('ticks', 0) + 2)
                    existing['dmg'] = max(existing.get('dmg', 2), 2)
                else:
                    status['necrotic'] = {'ticks': 3, 'dmg': 2}
        ability.mark_used()
        return dmg
    if ability.kind == "heal":
        attacker.hp += ability.power
        ability.mark_used()
        return ability.power
    # Buff placeholder
    ability.mark_used()
    return 0
