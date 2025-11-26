"""Grid-based A* pathfinding for the generated world.

The world is treated as a grid of cells of size `world.cell`. Tiles are
considered walkable unless their kind is in the BLOCKED_KINDS set.

Usage:
    from scripts.pathfinding import find_path
    path = find_path(world, (sx, sy), (tx, ty))  # returns list[(x,y)]
"""
from __future__ import annotations

from typing import List, Tuple, Dict
import heapq

BLOCKED_KINDS = {"water"}


def cell_from_pos(world, x: float, y: float) -> Tuple[int, int]:
    """Convert pixel coordinates to integer grid cell indices."""
    cx = int(x // world.cell)
    cy = int(y // world.cell)
    return cx, cy


def is_walkable(world, cx: int, cy: int) -> bool:
    """Return True if cell indices are within bounds and not blocked."""
    if cx < 0 or cy < 0 or cx >= world.cols or cy >= world.rows:
        return False
    idx = cy * world.cols + cx
    try:
        kind = world.tiles[idx].kind
    except IndexError:
        return False
    return kind not in BLOCKED_KINDS


def neighbors(world, cx: int, cy: int) -> List[Tuple[int, int]]:
    """Return 4-way walkable neighbor cells for a given cell."""
    out: List[Tuple[int, int]] = []
    for dx, dy in ((1,0),(-1,0),(0,1),(0,-1)):
        nx, ny = cx + dx, cy + dy
        if is_walkable(world, nx, ny):
            out.append((nx, ny))
    return out


def heuristic(a: Tuple[int,int], b: Tuple[int,int]) -> int:
    """Manhattan distance heuristic for grid A*."""
    return abs(a[0]-b[0]) + abs(a[1]-b[1])


def reconstruct(came_from: Dict[Tuple[int,int], Tuple[int,int]], current: Tuple[int,int]) -> List[Tuple[int,int]]:
    """Backtrack predecessor map into a path list."""
    path = [current]
    while current in came_from:
        current = came_from[current]
        path.append(current)
    path.reverse()
    return path


def find_path(world, start_pos: Tuple[float,float], target_pos: Tuple[float,float]) -> List[Tuple[float,float]]:
    """Compute path of world-coordinate centers from start to target.

    Returns empty list when no route exists or endpoints blocked.
    """
    sx, sy = start_pos
    tx, ty = target_pos
    start = cell_from_pos(world, sx, sy)
    goal = cell_from_pos(world, tx, ty)
    if not is_walkable(world, *start) or not is_walkable(world, *goal):
        return []
    open_set: List[Tuple[int, Tuple[int,int]]] = []
    heapq.heappush(open_set, (0, start))
    came_from: Dict[Tuple[int,int], Tuple[int,int]] = {}
    g_score: Dict[Tuple[int,int], int] = {start: 0}
    f_score: Dict[Tuple[int,int], int] = {start: heuristic(start, goal)}
    visited = set()
    while open_set:
        _, current = heapq.heappop(open_set)
        if current == goal:
            cells = reconstruct(came_from, current)
            # Convert cells to world coordinates (center of tile)
            return [((c[0] * world.cell) + world.cell/2, (c[1]*world.cell) + world.cell/2) for c in cells]
        visited.add(current)
        for nb in neighbors(world, *current):
            tentative_g = g_score[current] + 1
            if tentative_g < g_score.get(nb, 1_000_000):
                came_from[nb] = current
                g_score[nb] = tentative_g
                f_score[nb] = tentative_g + heuristic(nb, goal)
                if nb not in visited:
                    heapq.heappush(open_set, (f_score[nb], nb))
    return []
