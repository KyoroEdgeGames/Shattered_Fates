# Patch Notes — Shattered_Fates workspace

## 2025-11-26

Status: UNPLAYABLE (core gameplay windows refactored; networking and event data incomplete)

### Summary
Today's session focused on structural cleanup, naming normalization, and lint/maintenance improvements rather than new playable features. The game remains unplayable pending restoration of full window logic, event data relocation, and networking re‑integration.

### Key Changes
- Quest Package Migration: Renamed `data/scripts/Quests` -> `data/scripts/quests`; added deprecation stubs raising clear `ImportError` for old uppercase path.
- Quest Data Path: Normalized quest JSON constant to lowercase `data/quests/quests.json` with legacy fallback; retained functionality while enabling future case‑consistent asset layout.
- Event JSON Stubs: Uppercase legacy event files in `data/scripts/Quests` replaced with empty arrays to eliminate duplicate data sources (will migrate real event data next phase).
- Main Module Lint: Added docstrings to Arcade stub, renamed `_pygame_available` -> `PYGAME_AVAILABLE`, wrapped overlong lines, converted `SoundClass` to `sound_class`, and suppressed intentional late imports with targeted pylint disables.
- Deprecated Uppercase Package: Added import guards raising guidance to switch to lowercase naming per Python style conventions.
- Patch Notes Overhaul: Replaced prior networking‑focused notes with an accurate record of today's structural refactors.

### Rationale
- Consistent snake_case directories prevent case‑sensitive import issues on Unix-like systems.
- Deprecation stubs provide immediate developer feedback if stale imports linger.
- Early lint conformance (line length, naming, docstrings) reduces CI noise and clarifies intent.
- Data path normalization prepares for unified asset loading pipeline.

### Affected Files (Representative)
- `main.py` (lint/docstrings/renames)
- `data/scripts/quests/quest_manager.py` (path normalization retained)
- `data/scripts/Quests/*` (stubs + empty JSON arrays)
- `tools/start_story_quest.py`, `tools/start_alignment_quest.py` (import path updates)
- `PATCH_NOTES.md` (current entry)

### Follow-Up (Needed to Reach Playable State)
- Reintroduce networking broadcast logic using a dedicated interface module with typed protocol.
- Migrate event JSON to new lowercase data directory and rewire `story_system.py` paths.
- Complete lint pass for: `game/windows.py`, `battle.py`, `creator.py`, `clan_system.py`, `abilities.py`, `world.py`, `pathfinding.py`, and tool scripts.
- Add tests for quest selection alignment + arc fallback behavior.
- Restore music and SFX asset loading consistency after directory normalization.

### Verification Suggestions
```powershell
# Headless sanity (should start stub loop; still limited gameplay)
python main.py --no-window

# Run existing tests (will highlight remaining structural gaps)
python -m pytest -q
```

### Commit Message Template
```
chore: quest package rename, path normalization, main.py lint, event stubs (still unplayable)

Includes:
- Lowercase quest package & deprecation stubs
- Normalized QUESTS_JSON path with fallback
- Main arcade stub docstrings and pygame constant rename
- Empty legacy event JSON stubs
- Updated patch notes (status: unplayable)
```

---
Earlier entries have been superseded by this consolidated snapshot for 2025-11-26.
