"""Clan system scaffolding.

Defines `Clan`, `ClanRelation`, and a simple `ClanRegistry` that can
load and save clan data, plus update relations (alliances, rivalries).
"""
from __future__ import annotations

import json
import os
from dataclasses import dataclass, asdict
from typing import Dict, List, Optional

DATA_CLANS = os.path.join("data", "Clans", "clans.json")


@dataclass
class ClanRelation:
    other: str
    status: str  # e.g., "ally", "rival", "neutral"


@dataclass
class Clan:
    name: str
    territory: str = "unknown"
    relations: List[ClanRelation] = None  # type: ignore
    reputation: int = 0  # Aggregate reputation score for this clan

    def to_dict(self) -> Dict:
        return {
            "name": self.name,
            "territory": self.territory,
            "relations": [asdict(r) for r in (self.relations or [])],
            "reputation": self.reputation,
        }


class ClanRegistry:
    def __init__(self) -> None:
        self.clans: Dict[str, Clan] = {}

    def load(self) -> None:
        try:
            if os.path.exists(DATA_CLANS):
                with open(DATA_CLANS, "r", encoding="utf-8") as f:
                    data = json.load(f)
                for c in data.get("clans", []):
                    name = c.get("name")
                    if not isinstance(name, str):
                        continue
                    territory = c.get("territory", "unknown")
                    rels = []
                    for r in c.get("relations", []):
                        other = r.get("other")
                        status = r.get("status", "neutral")
                        if isinstance(other, str):
                            rels.append(ClanRelation(other=other, status=status))
                    reputation = int(c.get("reputation", 0)) if isinstance(c.get("reputation"), (int, float)) else 0
                    self.clans[name] = Clan(name=name, territory=territory, relations=rels, reputation=reputation)
        except (OSError, json.JSONDecodeError):
            pass

    def save(self) -> None:
        try:
            os.makedirs(os.path.dirname(DATA_CLANS), exist_ok=True)
            with open(DATA_CLANS, "w", encoding="utf-8") as f:
                data = {"clans": [c.to_dict() for c in self.clans.values()]}
                json.dump(data, f, indent=2)
        except OSError:
            pass

    def get(self, name: str) -> Optional[Clan]:
        return self.clans.get(name)

    def set_relation(self, a: str, b: str, status: str) -> None:
        ca = self.clans.setdefault(a, Clan(name=a, relations=[]))
        cb = self.clans.setdefault(b, Clan(name=b, relations=[]))
        def _upd(c: Clan, other: str, st: str) -> None:
            rlist = c.relations or []
            for r in rlist:
                if r.other == other:
                    r.status = st
                    break
            else:
                rlist.append(ClanRelation(other=other, status=st))
            c.relations = rlist
        _upd(ca, b, status)
        # Symmetric default (can be customized)
        _upd(cb, a, status)

    def adjust_reputation(self, clan: str, delta: int) -> int:
        c = self.clans.setdefault(clan, Clan(name=clan, relations=[]))
        c.reputation += delta
        return c.reputation


if __name__ == "__main__":
    reg = ClanRegistry()
    reg.load()
    reg.set_relation("Frostclan", "Bloodclan", "rival")
    reg.save()
    print(f"Saved relations to {DATA_CLANS}")
