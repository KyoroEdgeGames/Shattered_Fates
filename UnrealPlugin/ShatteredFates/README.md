# Shattered Fates Unreal Plugin

This plugin provides runtime data assets, import helpers, and gameplay subsystems to support migrating Shattered Fates from Python to Unreal C++/Blueprint.

## Components

- Data Assets: `UCharacterDataAsset`, `UQuestDataAsset`, `UClanDataAsset`, `UItemDataAsset`, `UHerbDataAsset`
- Import Helpers: `UShatteredFatesBlueprintLibrary` to load JSON/CSV into DataAssets/DataTables
- Subsystems: `UCharacterSubsystem` for querying characters

## Quick Start

1. Export data from the repo:
   ```bash
   python tools/unreal_export.py
   ```
2. Copy this plugin folder to your Unreal project at `Plugins/ShatteredFates/` and enable it.
3. In Blueprint (e.g., your `GameInstance`):
   - Call `LoadFromJson` on `CharacterSubsystem` with an absolute path to `export_unreal/json/Characters.json`.
   - Use `GetPlayableCharacters`, `FindByName`, or `FindByClan` for gameplay logic.

## Notes

- CSV loading functions create transient `UDataTable` instances at runtime.
- JSON loaders return transient DataAssets suitable for prototyping and runtime use.
- Extend with additional subsystems (Quests, Inventory, Relationships) to progressively replace Python systems.
