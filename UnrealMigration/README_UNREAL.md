# Shattered Fates → Unreal Engine 5.7.1 Migration

This guide helps you bring the current content and data into Unreal Engine 5.7.1. It provides data exporters, a starter Unreal plugin with runtime data structures, and practical import paths.

## Overview
- Export JSON and CSV data from this repo.
- Copy the provided Unreal plugin into your UE project.
- Import assets (sprites/audio) via Content Browser.
- Use DataTables (CSV) or runtime JSON loaders (plugin) for gameplay data.

## 1) Export data & manifests
Run from the repo root:

```
python tools/unreal_export.py
```

Outputs in `export_unreal/`:
- `data_tables/*.csv` — flat CSVs for UE DataTables.
- `json/*.json` — structured JSON for plugin loaders.
- `unreal_manifest.json` — list of sprites/music/sfx file paths.

## 2) Install the Unreal plugin
Copy the folder `UnrealPlugin/ShatteredFates` into your Unreal project at `Plugins/ShatteredFates/`.

In Unreal:
- Open Project Settings → Plugins, enable “Shattered Fates Data”.
- Build the project (C++), or let UE recompile modules.

The plugin provides:
- `UCharacterDataAsset`, `UQuestDataAsset`, `UClanDataAsset`, `UItemDataAsset`, `UHerbDataAsset` — runtime containers.
- `UShatteredFatesBlueprintLibrary` — Blueprint-callable JSON import functions.

## 3) Import data
Option A — DataTables (Editor import):
1. Create `UStruct` types matching CSV columns (recommended to define only what you need initially).
2. Right-click in Content Browser → Import → Data Table → choose CSV and Struct.
3. Reference `UDataTable` assets in Blueprint/C++.

Option B — Runtime JSON (Plugin loaders):
1. Place exported JSON files (`export_unreal/json/*.json`) somewhere accessible at runtime (e.g., project `Content/RawData` or `Saved/`, or absolute path during development).
2. In Blueprint, call:
   - `Load Characters From Json File`
   - `Load Quests From Json File`
   - `Load Clans From Json File`
   - `Load Items From Json File`
   - `Load Herbs From Json File`
3. The functions return transient `UDataAsset` instances with arrays you can iterate/use.

## 4) Import sprites and audio
Use `export_unreal/unreal_manifest.json` to locate source files.
- Sprites (`.png`, `.jpg`) → import as Textures or Paper2D sprites.
- Music/SFX (`.wav/.ogg/.mp3`) → import into `SoundWave` assets (prefer `.wav`).

## 5) Map systems to Unreal modules
- Rendering/UI → UMG/Widgets, Paper2D, or 3D as needed.
- Pathfinding → `NavigationSystem`, `DetourCrowd`, or custom.
- Combat/Abilities → Ability System Component (ASC) recommended.
- Story/Quests → DataTables or JSON + Blueprint/C++ managers.

## Notes
- Python runtime gameplay is not supported in packaged UE. Use C++/Blueprint for gameplay; Python is editor-only.
- Start with data import + basic displays, then incrementally replace Python systems with UE equivalents.

## Next Steps
- Create initial `UStruct` rows for Characters/Quests to import CSVs as DataTables.
- Build simple UI to list characters/quests and confirm data integrity.
- Incrementally port mechanics (e.g., inventory, relationships) using the provided data assets.
