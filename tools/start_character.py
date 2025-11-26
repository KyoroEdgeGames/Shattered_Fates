"""Runner for character creation CLI."""
from __future__ import annotations

import os
import sys

_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
if _ROOT not in sys.path:
    sys.path.insert(0, _ROOT)

from scripts.characters.creator import create_character_cli


def main() -> int:
    create_character_cli()
    return 0


if __name__ == "__main__":
    sys.exit(main())
