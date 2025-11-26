"""Simple turn-based battle system for Shattered Fates.

This module provides a minimal `Battle` class and a small CLI runner
`run_battle_cli()` useful for testing the battle flow and playing
`Combat.mp3` using the game's existing audio helpers.

The implementation is intentionally simple: it models two combatants
with HP and attack values and alternates turns until one side is
defeated. It uses `play_music_file` to play the battle music on start
and `stop_music` on finish.
"""
from __future__ import annotations

import logging
import random
from dataclasses import dataclass, field
from typing import Optional, List, Dict

try:
    # Import audio helpers from main (safe: main exposes helpers without
    # starting the game loop when imported).
    from main import play_music_file, stop_music  # type: ignore
except (ImportError, ModuleNotFoundError):  # pragma: no cover - keep battle resilient
    def play_music_file(*_args, **_kwargs):  # type: ignore
        """Fallback no-op for battle music when audio helpers unavailable."""
        return None

    def stop_music():  # type: ignore
        """Fallback no-op for stopping music when audio helpers unavailable."""
        return None


@dataclass
class Combatant:
    """A simple entity participating in battles.

    Attributes:
        name: Identifier for logging.
        hp: Current health points.
        attack: Base attack value used when no ability fires.
        role: Optional role key for ability lookup.
        injuries: List of injury codes applying penalties.
        status: Mapping of status effect -> {'ticks': remaining, 'dmg': per-tick}.
    """
    name: str
    hp: int
    attack: int
    role: Optional[str] = None
    injuries: List[str] = None  # type: ignore
    status: Dict[str, Dict[str, int]] = field(default_factory=dict)  # {'necrotic': {'ticks':3,'dmg':2}}

    def is_alive(self) -> bool:
        return self.hp > 0

    def effective_attack(self) -> int:
        pen = 0
        if self.injuries:
            # Simple penalty: up to -2 for multiple injuries
            pen = min(2, len(self.injuries))
        return max(1, self.attack - pen)


class Battle:
    """Very small, deterministic (with small randomness) battle simulator.

    Usage:
        b = Battle(Combatant('Hero', 30, 6), Combatant('Goblin', 18, 4))
        winner = b.run()
    """

    def __init__(self, p1: Combatant, p2: Combatant) -> None:
        self.p1 = p1
        self.p2 = p2
        self.turn = 0

    def _apply_statuses(self, combatant: Combatant) -> None:
        """Apply ticking status damage and expire spent effects."""
        # Apply each ticking status then decrement ticks; remove expired.
        expired = []
        for key, data in combatant.status.items():
            ticks = data.get('ticks', 0)
            dmg = data.get('dmg', 0)
            if ticks > 0 and dmg > 0:
                combatant.hp -= dmg
                logging.info("%s suffers %s %s damage (hp=%s)", combatant.name, dmg, key, combatant.hp)
                data['ticks'] = ticks - 1
            if data.get('ticks', 0) <= 0:
                expired.append(key)
        for key in expired:
            combatant.status.pop(key, None)

    def step(self) -> Optional[Combatant]:
        """Execute a single turn. Returns winner if battle ends, else None.

        If the attacker has an ability defined based on role, it may be
        used; otherwise a base attack is applied.
        """
        attacker, defender = (self.p1, self.p2) if (self.turn % 2 == 0) else (self.p2, self.p1)
        # Apply statuses at start of defender's upcoming turn (i.e., before they act when they become attacker next frame)
        # Here we apply to current attacker as they start acting.
        self._apply_statuses(attacker)
        if not attacker.is_alive():
            logging.info("%s is defeated by status effect", attacker.name)
            return defender
        # Status summary visual indicator
        def _fmt_status(c: Combatant) -> str:
            if not c.status:
                return "none"
            return ", ".join(f"{k}:{v.get('ticks',0)}" for k, v in c.status.items())
        logging.info("Status -> %s: [%s] | %s: [%s]", attacker.name, _fmt_status(attacker), defender.name, _fmt_status(defender))
        # Try abilities when the attacker has a role attribute
        dmg = 0
        ability_used = None
        try:
            role = getattr(attacker, "role", None)
            if isinstance(role, str):
                from scripts.abilities import list_abilities_for_role, use_ability  # local import to avoid cycles
                abilities = list_abilities_for_role(role)
                if abilities:
                    for ab in abilities:
                        if hasattr(ab, "ready") and ab.ready():
                            ability_used = ab
                            dmg = use_ability(attacker, defender, ab)
                            # Necrotic status application triggered inside use_ability by returning negative flag via attribute or side-effect
                            break
        except (ImportError, ModuleNotFoundError, AttributeError, TypeError):
            dmg = 0
        if dmg <= 0:
            variance = random.randint(-1, 2)
            base = attacker.effective_attack() if hasattr(attacker, "effective_attack") else attacker.attack
            dmg = max(1, base + variance)
            defender.hp -= dmg
        log_extra = f" using {ability_used.name}" if ability_used else ""
        logging.info("%s attacks %s for %s damage%s (hp=%s)", attacker.name, defender.name, dmg, log_extra, defender.hp)
        self.turn += 1
        if not defender.is_alive():
            logging.info("%s is defeated", defender.name)
            return attacker
        return None

    def run(self) -> Combatant:
        """Run the battle loop until one combatant wins."""
        logging.info("Battle start: %s vs %s", self.p1.name, self.p2.name)
        # Attempt to play battle music (filename expected in assets)
        try:
            play_music_file("Combat.mp3", loop=True, volume=0.6)
        except (OSError, RuntimeError, TypeError):
            logging.debug("Playing music failed; continuing without audio")

        winner: Optional[Combatant] = None
        while winner is None:
            winner = self.step()

        # Stop music when done
        try:
            stop_music()
        except (OSError, RuntimeError):
            logging.debug("Stopping music failed; ignoring")

        logging.info("Battle finished: winner=%s", winner.name)
        return winner


def run_battle_cli() -> None:
    """Simple CLI demo to run a single battle and print the outcome.

    This is intended for headless testing (quickly exercise combat and
    battle music). It is safe to call from scripts or tests.
    """
    logging.basicConfig(level=logging.INFO)
    hero = Combatant("Hero", hp=30, attack=6)
    gob = Combatant("Goblin", hp=18, attack=4)
    b = Battle(hero, gob)
    winner = b.run()
    print(f"Battle complete — winner: {winner.name}")


if __name__ == "__main__":
    run_battle_cli()
