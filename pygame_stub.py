"""Lightweight pygame stub module used when real `pygame` is not available.

Provides a `pygame` object with only the attributes `dev_mode.py` needs.
This file lives in the project root so it can be imported as a fallback.
"""
from __future__ import annotations

import types
from typing import Any, Tuple


class _Rect:
    def __init__(self, x: int, y: int, w: int, h: int) -> None:
        self.x = x
        self.y = y
        self.w = w
        self.h = h

    def collidepoint(self, pos: Tuple[int, int]) -> bool:
        px, py = pos
        return self.x <= px <= self.x + self.w and self.y <= py <= self.y + self.h


class _Surface:
    SRCALPHA = 0

    def __init__(self, *_: Any, **__: Any) -> None:
        pass

    def fill(self, *_: Any, **__: Any) -> None:
        return None

    def blit(self, *_: Any, **__: Any) -> None:
        return None


class _Font:
    def render(self, _text: str, *_: Any, **__: Any) -> _Surface:
        return _Surface()


class _Draw:
    @staticmethod
    def rect(*_: Any, **__: Any) -> None:
        return None


class _Event:
    MOUSEBUTTONDOWN = 1
    KEYDOWN = 2


class _Key:
    K_RETURN = 13
    K_BACKSPACE = 8


pygame = types.SimpleNamespace()
pygame.Rect = _Rect  # type: ignore[attr-defined]
pygame.Surface = _Surface  # type: ignore[attr-defined]
pygame.font = types.SimpleNamespace(Font=_Font)  # type: ignore[attr-defined]
pygame.draw = _Draw  # type: ignore[attr-defined]
pygame.event = types.SimpleNamespace()  # type: ignore[attr-defined]
pygame.MOUSEBUTTONDOWN = _Event.MOUSEBUTTONDOWN  # type: ignore[attr-defined]
pygame.KEYDOWN = _Event.KEYDOWN  # type: ignore[attr-defined]
pygame.K_RETURN = _Key.K_RETURN  # type: ignore[attr-defined]
pygame.K_BACKSPACE = _Key.K_BACKSPACE  # type: ignore[attr-defined]
pygame.SRCALPHA = _Surface.SRCALPHA  # type: ignore[attr-defined]

__all__ = ["pygame"]
