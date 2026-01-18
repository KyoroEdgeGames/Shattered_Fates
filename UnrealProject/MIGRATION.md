# Shattered Fates Migration (Python → Unreal C++)

This document outlines how existing Python systems map to Unreal Engine C++ modules and subsystems, with a phased plan to port functionality.

## Modules
- Game: `ShatteredFatesGame` — gameplay, entry, and orchestration
- Data/Core: `ShatteredFatesProject` — data assets, import helpers, common types

## Python → C++ Mapping
- `tools/unreal_export.py` → `UShatteredFatesBlueprintLibrary` loaders (JSON/CSV → DataAssets/DataTables)
- `data/scripts/relationship_system.py` → `URelationshipsSubsystem` (runtime state & queries)
- `data/scripts/skills.py` → `USkillsSubsystem` (skill tree, unlocks)
- `data/scripts/story_system.py` → `UStorySubsystem` (story progression, arcs)
- `data/Quests/quest_system.py` → `UQuestSubsystem` (quest state, filters)
- `scripts/world.py` → World components (Actors, `UWorldSubsystem` as needed)
- `scripts/pathfinding.py` → UE NavMesh (`UNavigationSystemV1`) + custom path helpers
- `scripts/Combat/*` → UE Gameplay framework (Actors, Components, `UCombatSubsystem`)
- `game/windows.py` → UE UI (UMG Widgets, HUD)

## Phased Port Plan
1. Data import: characters/clans/items/herbs/quests JSON/CSV via loaders.
2. Subsystems: implement runtime state + queries for relationships, skills, story, quests.
3. Gameplay Actors: player, NPCs, inventory, combat actors/components.
4. UI: UMG widgets replacing Python windows/menus.
5. Maps/Levels: create startup map; place actors with data-driven behavior.

## Implementation Checklist
- [x] UE project scaffold (5.7.1), targets, config
- [x] Core data assets and loaders
- [x] `GameInstance` autoload of characters
- [x] Subsystem stubs (quests, story, skills, relationships)
- [ ] Implement quest state machine
- [ ] Implement relationship modifiers and queries
- [ ] Implement skills unlocks and effects
- [ ] Import UE assets for UI/Maps
- [ ] Player/NPC spawning + basic interaction

## Notes
- Use `FPaths::ProjectDir()/../export_unreal/...` for absolute file paths.
- Prefer UE subsystems for global runtime state; use components for per-actor logic.
- Iteratively replace Python with C++/Blueprint, validating with unit tests and in-editor play.
