"""Simple animation loader for frame sequences stored in directories.

Usage:
    from animation import Animation, load_animations
    anim = Animation("assets/Animation/ripples", fps=18)
    anim.update(dt)
    frame = anim.get_frame()

The loader will use `arcade.load_texture` when available, otherwise it returns
file paths for frames so calling code can decide how to draw them.
"""
from __future__ import annotations

import os
from typing import Any, List, Optional, Dict

try:
    import arcade  # type: ignore
except (ImportError, ModuleNotFoundError):
    arcade = None  # type: ignore


class Animation:
    def __init__(self, folder: str, fps: int = 12, loop: bool = True) -> None:
        self.folder = folder
        self.fps = max(1, int(fps))
        self.loop = bool(loop)
        self._frame_paths: List[str] = []
        self._frames: List[Any] = []
        self._frame_duration = 1.0 / self.fps
        self._time = 0.0
        self._index = 0

        self._discover_frames()
        self._load_frames()

    def _discover_frames(self) -> None:
        if not os.path.isdir(self.folder):
            return
        names = [n for n in os.listdir(self.folder) if os.path.isfile(os.path.join(self.folder, n))]
        # Prefer common image extensions and sort by filename
        names = sorted(names)
        self._frame_paths = [os.path.join(self.folder, n) for n in names]

    def _load_frames(self) -> None:
        self._frames = []
        loader = getattr(arcade, "load_texture", None) if arcade is not None else None
        for p in self._frame_paths:
            if loader:
                try:
                    tex = loader(p)
                    self._frames.append(tex)
                except (OSError, ValueError):
                    # if texture loading fails, keep path as fallback
                    self._frames.append(p)
            else:
                self._frames.append(p)

    def update(self, dt: float) -> None:
        if not self._frames:
            return
        self._time += dt
        steps = int(self._time / self._frame_duration)
        if steps > 0:
            self._time -= steps * self._frame_duration
            self._index += steps
            if self.loop and self._frames:
                self._index %= len(self._frames)
            else:
                self._index = min(self._index, len(self._frames) - 1)

    def get_frame(self) -> Optional[Any]:
        if not self._frames:
            return None
        idx = self._index % len(self._frames)
        return self._frames[idx]

    def frame_count(self) -> int:
        return len(self._frames)


def load_animations(root: str = "assets/Animation", fps: int = 12) -> Dict[str, Animation]:
    """Discover subdirectories in `root` and create Animation objects for each."""
    out: Dict[str, Animation] = {}
    if not os.path.isdir(root):
        return out
    for name in sorted(os.listdir(root)):
        path = os.path.join(root, name)
        if os.path.isdir(path):
            out[name] = Animation(path, fps=fps)
    return out
