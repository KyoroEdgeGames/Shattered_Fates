"""Generate and save a random forest world map JSON.

Usage (PowerShell):
    python -u tools/spawn_world.py [seed]

If a seed integer is provided, generation is deterministic.
Creates/overwrites `data/world/map.json`.
"""
from __future__ import annotations

import json
import os
import sys
import random

_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
if _ROOT not in sys.path:
    sys.path.insert(0, _ROOT)

MAP_DIR = os.path.join("data", "world")
MAP_PATH = os.path.join(MAP_DIR, "map.json")


def generate(seed: int | None = None, width: int = 800, height: int = 600, cell: int = 32) -> dict:
    if seed is not None:
        random.seed(seed)
    cols = width // cell
    rows = height // cell
    tiles: list[dict] = []

    def in_bounds(cx: int, cy: int) -> bool:
        return 0 <= cx < cols and 0 <= cy < rows

    # Base grass layer
    for cy in range(rows):
        for cx in range(cols):
            tiles.append({"x": cx * cell, "y": cy * cell, "width": cell, "height": cell, "kind": "grass"})

    # Tree clusters
    for _ in range(8):
        center_cx = random.randrange(cols)
        center_cy = random.randrange(rows)
        radius = random.randint(2, 4)
        for dx in range(-radius, radius + 1):
            for dy in range(-radius, radius + 1):
                if dx * dx + dy * dy <= radius * radius:
                    cx = center_cx + dx
                    cy = center_cy + dy
                    if in_bounds(cx, cy):
                        idx = cy * cols + cx
                        try:
                            tiles[idx]["kind"] = "tree"
                        except IndexError:
                            pass

    # Clearings
    for _ in range(3):
        ccx = random.randrange(cols)
        ccy = random.randrange(rows)
        radius = random.randint(2, 3)
        for dx in range(-radius, radius + 1):
            for dy in range(-radius, radius + 1):
                if dx * dx + dy * dy <= radius * radius:
                    cx = ccx + dx
                    cy = ccy + dy
                    if in_bounds(cx, cy):
                        idx = cy * cols + cx
                        try:
                            if tiles[idx]["kind"] == "tree":
                                tiles[idx]["kind"] = "clearing"
                        except IndexError:
                            pass

    # Water patches
    for _ in range(2):
        wx = random.randrange(cols)
        wy = random.randrange(rows)
        steps = random.randint(20, 40)
        for _s in range(steps):
            if in_bounds(wx, wy):
                idx = wy * cols + wx
                try:
                    tiles[idx]["kind"] = "water"
                except IndexError:
                    pass
            wx += random.choice([-1, 0, 1])
            wy += random.choice([-1, 0, 1])
            if not in_bounds(wx, wy):
                wx = min(max(wx, 0), cols - 1)
                wy = min(max(wy, 0), rows - 1)

    # Den near center
    dcx = cols // 2 + random.randint(-3, 3)
    dcy = rows // 2 + random.randint(-3, 3)
    if in_bounds(dcx, dcy):
        idx = dcy * cols + dcx
        try:
            tiles[idx]["kind"] = "den"
        except IndexError:
            pass

    return {"width": width, "height": height, "cell": cell, "tiles": tiles}


def main(argv: list[str]) -> int:
    seed = None
    if len(argv) > 1:
        try:
            seed = int(argv[1])
        except ValueError:
            print("Seed must be an integer; ignoring.")
    data = generate(seed=seed)
    os.makedirs(MAP_DIR, exist_ok=True)
    with open(MAP_PATH, "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2)
    print(f"World generated ({len(data['tiles'])} tiles) -> {MAP_PATH}")
    if seed is not None:
        print(f"Seed: {seed}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
