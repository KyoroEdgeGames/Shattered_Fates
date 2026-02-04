# Shattered Fates - Game Setup Guide

## Overview
This is an Unreal Engine 5.7 third-person cat adventure game. The game features a playable cat character with custom movement abilities, audio system, UI, and narrative features.

## Current Status
? **COMPILATION**: The C++ code compiles successfully
? **CORE SYSTEMS**: All C++ classes are implemented
- Cat Character with movement abilities (sprint, crouch, pounce, climb)
- Game Mode and Player Controller
- Audio Manager
- HUD and UI widgets
- Narrative system

## Making the Game Playable

### Step 1: Create or Configure a Map
1. **Option A - Use Existing Map:**
   - Open the project in Unreal Editor
   - The DefaultEngine.ini currently points to `/Game/ThirdPerson/Maps/ThirdPersonMap`
   - If this map exists, you're ready to test

2. **Option B - Create a New Map:**
   - In Unreal Editor: File > New Level
   - Choose "Basic" or "Open World" template
   - Add a floor plane (scaled up cube or landscape)
   - Add lighting (Directional Light, Sky Light)
   - Save the map to `Content/Maps/TestLevel.umap`
   - Update `Config/DefaultEngine.ini`:
     ```ini
     [/Script/EngineSettings.GameMapsSettings]
     EditorStartupMap=/Game/Maps/TestLevel.TestLevel
     GameDefaultMap=/Game/Maps/TestLevel.TestLevel
     ```

### Step 2: Create Enhanced Input Assets

The Cat character requires Enhanced Input assets:

1. **Create Input Mapping Context:**
   - Right-click in Content Browser > Input > Input Mapping Context
   - Name it `IMC_Cat`
   - Add the following mappings:
     - `IA_Move`: W/S/D/A keys, Left Stick
     - `IA_Look`: Mouse XY, Right Stick
     - `IA_Jump`: Spacebar, Face Button Bottom
     - `IA_Sprint`: Left Shift, Left Trigger
     - `IA_Crouch`: C, Face Button Right
     - `IA_Pounce`: Left Mouse Button, Right Trigger
     - `IA_Pause`: Escape, Start Button

2. **Create Input Actions:**
   - Right-click in Content Browser > Input > Input Action
   - Create these actions:
     - `IA_Move` (Value Type: Axis2D)
     - `IA_Look` (Value Type: Axis2D)
     - `IA_Jump` (Value Type: Digital/Boolean)
     - `IA_Sprint` (Value Type: Digital/Boolean)
     - `IA_Crouch` (Value Type: Digital/Boolean)
     - `IA_Pounce` (Value Type: Digital/Boolean)
     - `IA_Pause` (Value Type: Digital/Boolean)

### Step 3: Create Blueprint from C++ Cat Class

1. **Create Cat Blueprint:**
   - Right-click in Content Browser > Blueprint Class
   - Choose "Cat" as parent class (under All Classes)
   - Name it `BP_Cat`
   - Open the blueprint
   - In Class Defaults:
     - Set `Cat Mapping Context` to your created `IMC_Cat`
     - Set `Move Action` to `IA_Move`
     - Set `Look Action` to `IA_Look`
     - Set `Jump Action` to `IA_Jump`
     - Set `Sprint Action` to `IA_Sprint`
     - Set `Crouch Action` to `IA_Crouch`
     - Set `Pounce Action` to `IA_Pounce`

2. **Add Visual Components:**
   - In the Viewport, add a Static Mesh or Skeletal Mesh for the cat model
   - Adjust capsule collision size if needed
   - Add a Camera Component or use the default third-person camera

### Step 4: Create UI Widgets (Optional but Recommended)

The HUD expects these widgets to exist:

1. **Create Cat Player Widget:**
   - Create a Widget Blueprint named `WBP_CatPlayer`
   - Parent class: `CatPlayerWidget`
   - Add these named widgets (match the C++ meta BindWidget names):
     - `HealthBar` (Progress Bar)
     - `StaminaBar` (Progress Bar)
     - `LivesText` (Text Block)
     - `MovementStateText` (Text Block)
     - `SprintIndicator` (Text Block)
     - `ClimbIndicator` (Text Block)
     - `PounceIndicator` (Text Block)
     - `LivesContainer` (Horizontal Box)
     - `RootCanvas` (Canvas Panel - should be root)

2. **Create Pause Menu Widget:**
   - Create Widget Blueprint named `WBP_PauseMenu`
   - Parent class: `PauseMenuWidget`
   - Add these named widgets:
     - `ResumeButton` (Button)
     - `RestartButton` (Button)
     - `OptionsButton` (Button)
     - `MainMenuButton` (Button)
     - `PauseTitleText` (Text Block)
     - `MenuContainer` (Vertical Box)

3. **Create Main Menu Widget:**
   - Create Widget Blueprint named `WBP_MainMenu`
   - Parent class: `MainMenuWidget`
   - Add these named widgets:
     - `PlayButton` (Button)
     - `OptionsButton` (Button)
     - `CreditsButton` (Button)
     - `QuitButton` (Button)
     - `TitleText` (Text Block)
     - `MenuContainer` (Vertical Box)

### Step 5: Create Game Mode Blueprint

1. **Create Blueprint:**
   - Right-click in Content Browser > Blueprint Class
   - Choose "CatGameMode" as parent
   - Name it `BP_CatGameMode`
   - Open it and set:
     - Default Pawn Class: `BP_Cat`
     - HUD Class: `CatHUD` (or create `BP_CatHUD` with widget class set)

2. **Update DefaultEngine.ini:**
   ```ini
   GlobalDefaultGameMode=/Game/Blueprints/BP_CatGameMode.BP_CatGameMode_C
   ```

### Step 6: Create Audio Manager (Optional)

1. Create a Blueprint from `AudioManager` class
2. Name it `BP_AudioManager`
3. Place it in your level or set it to spawn automatically
4. In Class Defaults, populate the `Music Tracks` and `Sound Effects` maps with your audio assets

## Quick Test Setup (Minimal)

For the absolute fastest way to test:

1. Create a new Basic level
2. Add a large floor (Cube scaled to 100,100,1)
3. Add a Directional Light
4. Create `BP_Cat` from Cat class with input actions set up
5. Set `BP_Cat` as the Default Pawn in Project Settings > Maps & Modes
6. Press Play in Editor (PIE)

You should be able to:
- Move with WASD
- Look with Mouse
- Jump with Spacebar
- Sprint with Left Shift
- Crouch with C
- Pounce with Left Mouse Button (when not falling)

## Troubleshooting

### Character doesn't move:
- Check that Enhanced Input plugin is enabled
- Verify Input Mapping Context is assigned to the Cat blueprint
- Verify Input Actions are assigned and mapped correctly

### No HUD appears:
- HUD widgets are optional; game will work without them
- Create the widget blueprints following Step 4 if you want UI

### Character falls through floor:
- Ensure the floor has collision enabled (Block All)
- Check that Cat's capsule component has collision enabled

### Camera issues:
- Add a Spring Arm and Camera component to BP_Cat
- Or use the default third-person camera setup

## Next Steps

Once basic movement works:
1. Add cat mesh/model
2. Create environment and obstacles to test climbing/jumping
3. Add audio assets for footsteps, meows, etc.
4. Build out UI widgets
5. Create game levels with objectives
6. Implement the narrative system

## Project Structure

```
Source/Shattered_Fates/
??? Cat.h/cpp                    - Main playable character
??? CatGameMode.h/cpp           - Game mode configuration
??? CatPlayerController.h/cpp    - Player input and pause handling
??? CatHUD.h/cpp                - HUD management
??? CatPlayerWidget.h/cpp       - Player UI widget
??? AudioManager.h/cpp          - Audio system
??? PauseMenuWidget.h/cpp       - Pause menu
??? MainMenuWidget.h/cpp        - Main menu
??? NarrativeManager.h/cpp      - Story/dialogue system
??? DialogueWidget.h/cpp        - Dialogue UI

Config/
??? DefaultEngine.ini           - Engine configuration
??? DefaultInput.ini            - Input configuration
```

## Support

The C++ code is complete and compiles. The main task is creating the Unreal Engine assets (Blueprints, Widgets, Input Assets) to connect everything together.
