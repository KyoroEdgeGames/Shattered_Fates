"""Minimal world rendering and loading utilities.

Provides a `World` class that can load an optional JSON tile map
(`data/world/map.json`) describing simple rectangular terrain/obstacles
and draws them using Arcade primitives. Falls back to a generated grid
background when no map exists.

Map format (optional):
{
  "tiles": [
    {"x": 0, "y": 0, "width": 64, "height": 64, "kind": "grass"},
    ...
  ]
}
"""
from __future__ import annotations

import json
import os
from dataclasses import dataclass
from typing import List, Tuple, Optional

try:
    import arcade  # type: ignore
except ImportError:  # pragma: no cover
    arcade = None  # type: ignore

MAP_PATH = os.path.join("data", "world", "map.json")


@dataclass
class Tile:
    """Single terrain cell used for rendering & collision."""
    x: float
    y: float
    width: float
    height: float
    kind: str = ""


class World:
    """Procedural / loaded tile world with biome & collision helpers."""
    def __init__(self, auto_generate: bool = True, width: int = 800, height: int = 600, cell: int = 32) -> None:
        self.tiles: List[Tile] = []
        self.loaded: bool = False
        self.width = width
        self.height = height
        self.cell = cell
        self.cols = max(1, self.width // self.cell)
        self.rows = max(1, self.height // self.cell)
        self.blocked_kinds = {"water", "den"}
        self._load()
        if not self.loaded and auto_generate:
            self.generate_forest()

    def _load(self) -> None:
        try:
            if os.path.exists(MAP_PATH):
                with open(MAP_PATH, "r", encoding="utf-8") as f:
                    data = json.load(f)
                for t in data.get("tiles", []):
                    if not isinstance(t, dict):
                        continue
                    try:
                        self.tiles.append(
                            Tile(
                                x=float(t.get("x", 0)),
                                y=float(t.get("y", 0)),
                                width=float(t.get("width", 32)),
                                height=float(t.get("height", 32)),
                                kind=str(t.get("kind", "")),
                            )
                        )
                    except (TypeError, ValueError):
                        continue
                self.loaded = True
        except (OSError, json.JSONDecodeError):
            self.loaded = False

    def draw(self) -> None:
        if arcade is None:
            return
        # Background grid (subtle) – only if tiles not loaded
        if not self.loaded and not self.tiles:
            draw_rect = getattr(arcade, "draw_lrbt_rectangle_filled", None)
            if callable(draw_rect):
                # Just fill entire background once; GameWindow sets bg color already
                pass
            # Draw faint grid lines if API available
            line_fn = getattr(arcade, "draw_line", None)
            if callable(line_fn):
                for gx in range(0, self.width, 40):
                    line_fn(gx, 0, gx, self.height, (50, 50, 50, 60))
                for gy in range(0, self.height, 40):
                    line_fn(0, gy, self.width, gy, (50, 50, 50, 60))
            return

        rect_fn = getattr(arcade, "draw_lrbt_rectangle_filled", None)
        if not callable(rect_fn):
            return
        for tile in self.tiles:
            # Color choice based on kind
            if tile.kind == "grass":
                col = getattr(arcade.color, "DARK_SLATE_GRAY", (30, 60, 30))
            elif tile.kind == "water":
                col = getattr(arcade.color, "BLUE", (40, 80, 160))
            elif tile.kind == "den":
                col = getattr(arcade.color, "GRAY", (120, 120, 120))
            elif tile.kind == "clearing":
                col = getattr(arcade.color, "AERO_BLUE", (120, 160, 120))
            elif tile.kind == "tree":
                col = getattr(arcade.color, "FOREST_GREEN", (34, 139, 34)) if hasattr(arcade.color, "FOREST_GREEN") else (34, 100, 34)
            elif tile.kind == "marsh":
                col = (60, 90, 60)
            elif tile.kind == "rock":
                col = (100, 100, 110)
            else:
                col = getattr(arcade.color, "DARK_GRAY", (64, 64, 64))
            rect_fn(tile.x, tile.x + tile.width, tile.y, tile.y + tile.height, col)

    # --- Generation ---
    def generate_forest(self, seed: int | None = None, tree_clusters: int = 8, water_patches: int = 2, clearings: int = 3, rock_patches: int = 3) -> None:
        """Populate tiles with a random forest layout.

        Creates clusters of tree tiles, scattered grass, some water pools,
        and a few clearings. Does not overwrite existing tiles.
        """
        import random
        if seed is not None:
            random.seed(seed)
        cols = self.cols
        rows = self.rows
        # Start with grass everywhere
        occupied = set()
        for cy in range(rows):
            for cx in range(cols):
                x = cx * self.cell
                y = cy * self.cell
                self.tiles.append(Tile(x=x, y=y, width=self.cell, height=self.cell, kind="grass"))
                occupied.add((cx, cy))

        def in_bounds(cx: int, cy: int) -> bool:
            return 0 <= cx < cols and 0 <= cy < rows

        # Tree clusters
        for _ in range(tree_clusters):
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
                                self.tiles[idx].kind = "tree"
                            except IndexError:
                                pass

        # Clearings (convert tree to clearing)
        for _ in range(clearings):
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
                                if self.tiles[idx].kind == "tree":
                                    self.tiles[idx].kind = "clearing"
                            except IndexError:
                                pass

        # Water patches (organic pool via random walk)
        for _ in range(water_patches):
            wx = random.randrange(cols)
            wy = random.randrange(rows)
            steps = random.randint(20, 40)
            for _s in range(steps):
                idx = wy * cols + wx
                if in_bounds(wx, wy):
                    try:
                        self.tiles[idx].kind = "water"
                    except IndexError:
                        pass
                # random step
                wx += random.choice([-1, 0, 1])
                wy += random.choice([-1, 0, 1])
                if not in_bounds(wx, wy):
                    wx = min(max(wx, 0), cols - 1)
                    wy = min(max(wy, 0), rows - 1)

        # Marsh generation: tiles adjacent to water become marsh (subset)
        def neighbors(cx: int, cy: int) -> List[Tuple[int,int]]:
            out = []
            for dx, dy in ((1,0),(-1,0),(0,1),(0,-1)):
                nx, ny = cx+dx, cy+dy
                if in_bounds(nx, ny):
                    out.append((nx, ny))
            return out
        for cy in range(rows):
            for cx in range(cols):
                idx = cy * cols + cx
                try:
                    if self.tiles[idx].kind == "grass":
                        for nx, ny in neighbors(cx, cy):
                            nidx = ny * cols + nx
                            if self.tiles[nidx].kind == "water":
                                # chance to become marsh
                                if random.random() < 0.35:
                                    self.tiles[idx].kind = "marsh"
                                    break
                except IndexError:
                    pass

        # Rock patches: random elliptical clusters
        for _ in range(rock_patches):
            rcx = random.randrange(cols)
            rcy = random.randrange(rows)
            rw = random.randint(2,4)
            rh = random.randint(2,4)
            for dx in range(-rw, rw+1):
                for dy in range(-rh, rh+1):
                    if (dx*dx)/(rw*rw+0.1) + (dy*dy)/(rh*rh+0.1) <= 1.0:
                        cx = rcx + dx
                        cy = rcy + dy
                        if in_bounds(cx, cy):
                            idx = cy * cols + cx
                            try:
                                if self.tiles[idx].kind in {"grass", "tree"}:
                                    self.tiles[idx].kind = "rock"
                            except IndexError:
                                pass

        # Single den location near center
        dcx = cols // 2 + random.randint(-3, 3)
        dcy = rows // 2 + random.randint(-3, 3)
        if in_bounds(dcx, dcy):
            idx = dcy * cols + dcx
            try:
                self.tiles[idx].kind = "den"
            except IndexError:
                pass

        self.loaded = False  # Generated, not loaded from file

    # --- Query helpers ---
    def tile_at(self, x: float, y: float) -> Optional[Tile]:
        """Return tile containing given pixel coordinate or None if OOB."""
        cx = int(x // self.cell)
        cy = int(y // self.cell)
        if cx < 0 or cy < 0 or cx >= self.cols or cy >= self.rows:
            return None
        idx = cy * self.cols + cx
        try:
            return self.tiles[idx]
        except IndexError:
            return None

    def is_walkable(self, x: float, y: float) -> bool:
        """Return True when tile at position is not a blocked kind."""
        t = self.tile_at(x, y)
        if t is None:
            return False
        return t.kind not in self.blocked_kinds

    def get_random_tile_center(self, kind: str) -> Optional[Tuple[float,float]]:
        """Pick random tile of given kind and return its center coordinates."""
        matches = [t for t in self.tiles if t.kind == kind]
        if not matches:
            return None
        import random
        t = random.choice(matches)
        return (t.x + t.width/2, t.y + t.height/2)
