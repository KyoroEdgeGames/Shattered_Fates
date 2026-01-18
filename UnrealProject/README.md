# Shattered Fates UE5.7.1 (C++)

A minimal Unreal Engine 5.7.1 C++ project scaffold with an embedded `ShatteredFates` plugin to migrate data and systems from the Python repo.

## Prereqs
- Unreal Engine 5.7.1 installed (Launcher or source build)
- Visual Studio 2022 with C++ toolset

## Open & Build (Windows)
1. Generate project files (or right‑click the `.uproject`):

```bat
"C:\Program Files\Epic Games\UE_5.7\Engine\Build\BatchFiles\GenerateProjectFiles.bat" -project="%USERPROFILE%\OneDrive\Documents\Shattered_Fates\UnrealProject\ShatteredFates.uproject" -game -engine
```

2. Build Editor target from CLI (optional):

```bat
"C:\Program Files\Epic Games\UE_5.7\Engine\Build\BatchFiles\Build.bat" ShatteredFatesEditor Win64 Development "%USERPROFILE%\OneDrive\Documents\Shattered_Fates\UnrealProject\ShatteredFates.uproject"
```

3. Launch the project:
- Double‑click `UnrealProject/ShatteredFates.uproject`, or
- Open from Unreal Editor → Select existing project.

## Data Import
- Run the repo exporter to produce JSON/CSV:

```bat
python tools\unreal_export.py
```

- Use the plugin blueprint functions to load at runtime:
  - Characters JSON: `export_unreal/json/Characters.json`
  - Clans JSON: `export_unreal/json/Clans.json`
  - Items/Herbs/Quests JSON and CSV in `export_unreal/`

In Blueprint (e.g., in `GameInstance`), call:
- `UShatteredFatesBlueprintLibrary::LoadCharactersFromJsonFile(AbsolutePath)`
- `UCharacterSubsystem::LoadFromJson(AbsolutePath)` then query with `GetPlayableCharacters()`.

## Project Layout
- `UnrealProject/Source/ShatteredFates/` — Game C++ module
- `UnrealProject/Plugins/ShatteredFates/` — Data/plugin module
- `UnrealProject/Content/` — UE assets (create `Maps`, `DataTables`, etc.)
- `UnrealProject/Config/` — minimal defaults

## Next Steps
- Add `Maps/Default` and set real startup map in `DefaultEngine.ini`.
- Use `ShatteredFatesGameInstance` (already configured) to auto-load characters from `export_unreal/json/Characters.json`.
- Import CSVs into `Content/DataTables` to use with UE DataTable assets.
- Fill out subsystem stubs (`QuestSubsystem`, `StorySubsystem`, `SkillsSubsystem`, `RelationshipsSubsystem`) to replace Python systems progressively.
