# Shattered Fates - Complete Setup Guide

## ?? Quick Start Checklist

### Phase 1: Project Compilation ?
- [x] C++ UI/UX classes created
- [x] Build.cs updated with UMG modules
- [ ] Project compiled successfully
- [ ] Visual Studio solution regenerated

### Phase 2: UMG Widget Creation
Follow these steps in Unreal Editor:

#### 1. Create Player HUD Widget (WBP_CatPlayerWidget)
**Location:** `Content/UI/HUD/`

1. **Right-click in Content Browser** ? User Interface ? Widget Blueprint
2. **Name it:** `WBP_CatPlayerWidget`
3. **Open the Widget** and in **Graph** tab, set **Parent Class** to `CatPlayerWidget`
4. **Switch to Designer tab** and add these components:

   **Canvas Panel (Root)**
   - Name: `RootCanvas`
   - Anchors: Full Screen

   **Health Bar (Top Left)**
   - Type: Progress Bar
   - Name: `HealthBar` (EXACT name required)
   - Position: X=50, Y=30
   - Size: 300x30
   - Anchor: Top-Left
   - Fill Color: Red (RGB: 204, 26, 26)

   **Stamina Bar (Below Health)**
   - Type: Progress Bar
   - Name: `StaminaBar` (EXACT name required)
   - Position: X=50, Y=70
   - Size: 300x20
   - Anchor: Top-Left
   - Fill Color: Green (RGB: 51, 204, 51)

   **Lives Display (Top Right)**
   - Type: Text Block
   - Name: `LivesText` (EXACT name required)
   - Position: X=-250, Y=30
   - Anchor: Top-Right
   - Font Size: 24
   - Text: "Lives: 9/9"

   **Lives Icon Container**
   - Type: Horizontal Box
   - Name: `LivesContainer` (EXACT name required)
   - Position: X=-250, Y=70
   - Anchor: Top-Right

   **Movement State (Bottom Center)**
   - Type: Text Block
   - Name: `MovementStateText` (EXACT name required)
   - Position: X=0, Y=-100 (relative to bottom)
   - Anchor: Bottom-Center
   - Alignment: Center
   - Font Size: 20
   - Text: "Walking"

   **Sprint Indicator (Bottom Right)**
   - Type: Text Block
   - Name: `SprintIndicator` (EXACT name required)
   - Position: X=-200, Y=-150
   - Anchor: Bottom-Right
   - Font Size: 18
   - Text: "Sprint [Ready]"

   **Climb Indicator (Bottom Right)**
   - Type: Text Block
   - Name: `ClimbIndicator` (EXACT name required)
   - Position: X=-200, Y=-120
   - Anchor: Bottom-Right
   - Font Size: 18
   - Text: "Climb [Ready]"

   **Pounce Indicator (Bottom Right)**
   - Type: Text Block
   - Name: `PounceIndicator` (EXACT name required)
   - Position: X=-200, Y=-90
   - Anchor: Bottom-Right
   - Font Size: 18
   - Text: "Pounce [Ready]"

5. **Compile and Save**

#### 2. Create Dialogue Widget (WBP_DialogueWidget)
**Location:** `Content/UI/Dialogue/`

1. **Create Widget Blueprint** named `WBP_DialogueWidget`
2. **Set Parent Class** to `DialogueWidget`
3. **Add components:**

   **Canvas Panel (Root)**
   
   **Dialogue Background (Bottom Center)**
   - Type: Image
   - Name: `DialogueBackground` (EXACT name required)
   - Position: Bottom center, Y offset -200
   - Size: 1200x250
   - Anchor: Bottom-Center
   - Color: Semi-transparent black (A=180)

   **Character Portrait (Left Side)**
   - Type: Image
   - Name: `CharacterPortrait` (EXACT name required)
   - Position: X=50, Y=-180
   - Size: 200x200
   - Anchor: Bottom-Left

   **Character Name**
   - Type: Text Block
   - Name: `CharacterNameText` (EXACT name required)
   - Position: X=270, Y=-220
   - Anchor: Bottom-Left
   - Font Size: 28
   - Font: Bold
   - Color: Yellow

   **Dialogue Text**
   - Type: Text Block
   - Name: `DialogueText` (EXACT name required)
   - Position: X=270, Y=-180
   - Size: 850x150
   - Anchor: Bottom-Left
   - Font Size: 20
   - Auto Wrap: True

   **Continue Button**
   - Type: Button
   - Name: `ContinueButton` (EXACT name required)
   - Position: X=1050, Y=-60
   - Size: 120x40
   - Anchor: Bottom-Left
   - Text: "Continue >"

4. **Compile and Save**

#### 3. Create Main Menu Widget (WBP_MainMenu)
**Location:** `Content/UI/Menus/`

1. **Create Widget Blueprint** named `WBP_MainMenu`
2. **Set Parent Class** to `MainMenuWidget`
3. **Add components:**

   **Canvas Panel**
   
   **Background Image**
   - Type: Image
   - Full screen
   - Add your game's background art

   **Title Text**
   - Type: Text Block
   - Name: `TitleText` (EXACT name required)
   - Position: Center top, Y=150
   - Font Size: 72
   - Text: "Shattered Fates"

   **Menu Container**
   - Type: Vertical Box
   - Name: `MenuContainer` (EXACT name required)
   - Position: Center
   - Size: 400x400

   **Inside MenuContainer, add buttons:**
   - Button ? Name: `PlayButton` with Text "Play Game"
   - Button ? Name: `OptionsButton` with Text "Options"
   - Button ? Name: `CreditsButton` with Text "Credits"
   - Button ? Name: `QuitButton` with Text "Quit Game"
   - Each button size: 300x60
   - Spacing: 20px between buttons

4. **In the Details panel:**
   - Set `LevelToLoad` = Name of your gameplay level (e.g., "GameLevel")

5. **Compile and Save**

#### 4. Create Pause Menu Widget (WBP_PauseMenu)
**Location:** `Content/UI/Menus/`

1. **Create Widget Blueprint** named `WBP_PauseMenu`
2. **Set Parent Class** to `PauseMenuWidget`
3. **Add components:**

   **Canvas Panel**
   
   **Background Overlay**
   - Type: Image
   - Full screen
   - Color: Semi-transparent black (A=200)

   **Pause Title**
   - Type: Text Block
   - Name: `PauseTitleText` (EXACT name required)
   - Position: Center top, Y=200
   - Font Size: 64
   - Text: "PAUSED"

   **Menu Container**
   - Type: Vertical Box
   - Name: `MenuContainer` (EXACT name required)
   - Position: Center
   - Size: 400x350

   **Inside MenuContainer:**
   - Button ? Name: `ResumeButton` with Text "Resume"
   - Button ? Name: `RestartButton` with Text "Restart"
   - Button ? Name: `OptionsButton` with Text "Options"
   - Button ? Name: `MainMenuButton` with Text "Main Menu"

4. **In the Details panel:**
   - Set `MainMenuLevelName` = Your main menu level name

5. **Compile and Save**

### Phase 3: Input Configuration

#### Create Enhanced Input Assets

1. **Create Input Mapping Context**
   - Location: `Content/Input/`
   - Right-click ? Input ? Input Mapping Context
   - Name: `IMC_Cat`

2. **Create Input Actions**
   - `IA_Move` (Value Type: Axis2D) - Movement
   - `IA_Look` (Value Type: Axis2D) - Camera
   - `IA_Jump` (Value Type: Digital) - Jump
   - `IA_Sprint` (Value Type: Digital) - Sprint
   - `IA_Crouch` (Value Type: Digital) - Crouch
   - `IA_Pounce` (Value Type: Digital) - Pounce
   - `IA_Pause` (Value Type: Digital) - Pause Menu

3. **Map Keys in IMC_Cat:**
   - Move: W/A/S/D keys
   - Look: Mouse X/Y
   - Jump: Spacebar
   - Sprint: Left Shift
   - Crouch: Left Ctrl
   - Pounce: Left Mouse Button
   - Pause: Escape

### Phase 4: Blueprint Configuration

#### 1. Create Game Mode Blueprint
**Location:** `Content/Blueprints/GameModes/`

1. Create Blueprint Class ? Search for `CatGameMode`
2. Name it: `BP_CatGameMode`
3. Open it and verify:
   - Default Pawn Class: `Cat` or `BP_Cat`
   - HUD Class: `CatHUD`
   - Player Controller Class: `CatPlayerController` or `BP_CatPlayerController`

#### 2. Create Cat Character Blueprint (Optional)
**Location:** `Content/Blueprints/Characters/`

1. Create Blueprint Class based on `Cat` C++ class
2. Name: `BP_Cat`
3. Open and configure:
   - **Input Section:**
     - Cat Mapping Context: Select `IMC_Cat`
     - Move Action: Select `IA_Move`
     - Look Action: Select `IA_Look`
     - Jump Action: Select `IA_Jump`
     - Sprint Action: Select `IA_Sprint`
     - Crouch Action: Select `IA_Crouch`
     - Pounce Action: Select `IA_Pounce`
   
   - **Cat Movement Section:**
     - Walk Speed: 300
     - Run Speed: 600
     - Crouch Speed: 150
     - Jump Height: 500
     - Pounce Force: 1000
     - Climb Speed: 200
   
   - **Cat Stats:**
     - Max Health: 100
     - Max Stamina: 100
     - Stamina Regen Rate: 20
     - Sprint Stamina Cost: 10
     - Lives Remaining: 9

4. **Add Mesh and Animations** (your cat character model)

#### 3. Create Player Controller Blueprint (Optional)
**Location:** `Content/Blueprints/Controllers/`

1. Create Blueprint based on `CatPlayerController`
2. Name: `BP_CatPlayerController`
3. Set:
   - Pause Menu Class: `WBP_PauseMenu`
   - Main Menu Class: `WBP_MainMenu`
   - Pause Action: `IA_Pause`

#### 4. Create HUD Blueprint (Optional)
**Location:** `Content/Blueprints/HUD/`

1. Create Blueprint based on `CatHUD`
2. Name: `BP_CatHUD`
3. Set:
   - Player Widget Class: `WBP_CatPlayerWidget`
   - Show Debug Info: False (enable for testing)

### Phase 5: Level Setup

#### Create Main Menu Level
1. Create New Level: `MainMenuLevel`
2. Location: `Content/Maps/`
3. Add to level:
   - Lighting (Directional Light, Sky Light)
   - Atmospheric effects
4. **Level Blueprint:**
   - BeginPlay ? Create Widget (`WBP_MainMenu`)
   - Add to Viewport
   - Set Input Mode ? UI Only
   - Show Mouse Cursor

#### Create Gameplay Level
1. Create New Level: `GameLevel`
2. Location: `Content/Maps/`
3. Add Player Start
4. **Place Narrative Manager:**
   - Search for `NarrativeManager` in Place Actors
   - Drag into level
   - Configure in Details:
     - Dialogue Widget Class: `WBP_DialogueWidget`
     - Auto Start Story: True/False as needed
     - Story Chapters can be edited here or in Blueprint

### Phase 6: Project Settings

1. **Maps & Modes**
   - Edit ? Project Settings ? Maps & Modes
   - Default GameMode: `BP_CatGameMode`
   - Editor Startup Map: `MainMenuLevel`
   - Game Default Map: `MainMenuLevel`

2. **Input**
   - Edit ? Project Settings ? Input
   - Default Mapping Context: `IMC_Cat`
   - Clear old input bindings if migrating from Action/Axis system

3. **Engine - General Settings**
   - Game Viewport Client Class: Leave default

### Phase 7: Testing

#### Test Main Menu
- [ ] Play in editor starts at Main Menu
- [ ] Mouse cursor is visible
- [ ] All buttons are clickable
- [ ] Play button loads game level
- [ ] Quit button works (in standalone)

#### Test In-Game HUD
- [ ] Health bar displays correctly
- [ ] Health decreases when taking damage
- [ ] Stamina bar displays correctly
- [ ] Stamina depletes when sprinting
- [ ] Stamina regenerates when idle
- [ ] Lives counter shows "Lives: 9/9"
- [ ] Movement state updates (Walking, Sprinting, Crouching, etc.)
- [ ] Ability indicators show availability

#### Test Cat Movement
- [ ] WASD moves character
- [ ] Mouse looks around
- [ ] Spacebar jumps
- [ ] Left Shift sprints (depletes stamina)
- [ ] Left Ctrl crouches
- [ ] Left Mouse Button pounces

#### Test Pause Menu
- [ ] Escape opens pause menu
- [ ] Game pauses when menu opens
- [ ] Mouse cursor appears
- [ ] Resume button works
- [ ] Restart button reloads level
- [ ] Main Menu button returns to main menu

#### Test Dialogue System
- [ ] Dialogue appears when triggered
- [ ] Typewriter effect works (if enabled)
- [ ] Character names display correctly
- [ ] Continue button advances dialogue
- [ ] Dialogue closes when complete

### Phase 8: Add Narrative Manager to Level

1. **Place Narrative Manager in GameLevel:**
   - Find `NarrativeManager` in Place Actors
   - Drag into level viewport
   - Select it

2. **Configure Story in Details Panel:**
   - Dialogue Widget Class: `WBP_DialogueWidget`
   - Auto Start Story: Check this to start on level load
   - Story Chapters: The default story from StorylineEngine is pre-configured

3. **Test Narrative:**
   - Play level
   - Story should start automatically (if Auto Start is enabled)
   - Dialogue appears with first chapter

### Phase 9: Custom Story Configuration

#### Add Your Own Story Chapters (in Editor)

1. Select Narrative Manager in level
2. In Details ? Story Chapters ? Add Element
3. For each chapter:
   - **Chapter Name:** "Prologue", "Chapter 1", etc.
   - **Chapter Summary:** Brief description
   - **Dialogues:** Add dialogue sequences
     - **Sequence Name:** Scene identifier
     - **Lines:** Add individual dialogue lines
       - **Character Name:** Who is speaking
       - **Dialogue Text:** What they say
       - **Display Duration:** How long (if auto-advance)
       - **Auto Advance:** Check for automatic progression

#### Example Chapter Structure:
```
Chapter 1: "Prologue"
  ?? Dialogue Sequence: "Morning Awakening"
      ?? Line 1: Narrator - "The morning light crept..."
      ?? Line 2: Coal - "Woah... your eyes..."
      ?? Line 3: Narrator - "Silence watched Ivy..."
```

### Phase 10: Polish and Customize

#### Styling Recommendations
1. **Create Material for UI Elements**
   - Location: `Content/UI/Materials/`
   - Add gradients, glow effects
   - Apply to HUD backgrounds

2. **Add Sound Effects**
   - Button click sounds
   - Dialogue text sounds
   - UI feedback sounds

3. **Add Animations**
   - Health/Stamina bar animations
   - Menu button hover effects
   - Dialogue box slide-in/out

4. **Add Character Portraits**
   - Create portraits for: Ivy, Coal, Silence, Stolenstar
   - Import to `Content/UI/Portraits/`
   - Assign in Dialogue Widget

### Common Issues & Solutions

#### Issue: Widgets not appearing
**Solution:**
- Check widget class is set in GameMode/HUD
- Verify AddToViewport is called
- Check Z-order (higher = on top)

#### Issue: Buttons not working
**Solution:**
- Ensure component names EXACTLY match (case-sensitive)
- Check mouse cursor is enabled
- Verify Input Mode is set correctly

#### Issue: HUD not updating
**Solution:**
- Check HUD reference in Cat.cpp BeginPlay
- Verify Tick is enabled
- Check UpdateHUD() is being called

#### Issue: Stamina not regenerating
**Solution:**
- Check StaminaRegenRate > 0
- Verify RegenerateStamina is called in Tick
- Make sure not sprinting

#### Issue: Dialogue not showing
**Solution:**
- Verify DialogueWidget class is set in NarrativeManager
- Check widget is added to viewport
- Ensure story has valid chapters/dialogues

#### Issue: Pause menu doesn't pause
**Solution:**
- Check SetGamePaused is called
- Verify PlayerController is CatPlayerController
- Ensure PauseAction input is bound

### Advanced Features to Add

1. **Save/Load System**
   - Save current chapter progress
   - Save health/lives/stats
   - Save game settings

2. **Achievement System**
   - Complete chapters
   - Perform special moves
   - Find secrets

3. **Localization**
   - Multi-language support
   - String tables for all text

4. **Accessibility**
   - Subtitles toggle
   - Colorblind modes
   - Text size options

5. **Mini-Map**
   - Add scene capture
   - Display player position
   - Show objectives

### Performance Optimization

1. **Widget Pooling**
   - Reuse dialogue widgets
   - Cache menu widgets

2. **Tick Optimization**
   - Only update HUD when values change
   - Use timers instead of Tick where possible

3. **LOD for UI**
   - Reduce widget complexity on lower settings

### Final Checklist

- [ ] All widgets created and configured
- [ ] All input actions mapped
- [ ] Game Mode set up correctly
- [ ] Main menu functional
- [ ] In-game HUD displays correctly
- [ ] Pause menu works
- [ ] Dialogue system functional
- [ ] Cat movement works perfectly
- [ ] Stamina/health systems working
- [ ] Lives system functional
- [ ] Story progression works
- [ ] All sounds added
- [ ] All visuals polished
- [ ] Tested in packaged build

## ?? Congratulations!

Your Shattered Fates UI/UX system is now complete! You have:
- ? Dynamic player HUD with health, stamina, and abilities
- ? Complete menu system (Main Menu, Pause Menu)
- ? Dialogue and narrative system
- ? Enhanced input system
- ? Full cat character with special abilities
- ? Story integration from StorylineEngine

## Next Steps
1. Add your own story content
2. Create character models and animations
3. Design levels and environments
4. Add sound effects and music
5. Implement additional gameplay mechanics
6. Polish and playtest

Happy game development! ???
