"""Simple runner for the battle demo.

Usage: run this file to start a quick CLI battle which will attempt to
play `Combat.mp3` from the game's music assets (via `play_music_file`).
"""
from __future__ import annotations

import logging
import os
import sys

# Ensure project root is on sys.path when executing the script directly
_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
if _ROOT not in sys.path:
    sys.path.insert(0, _ROOT)

from scripts.Combat.battle import run_battle_cli


def main() -> int:
    logging.basicConfig(level=logging.INFO)
    try:
        run_battle_cli()
        return 0
    except (RuntimeError, OSError, ValueError) as exc:
        logging.exception("Battle demo failed (runtime): %s", exc)
        return 2


if __name__ == "__main__":
    sys.exit(main())
