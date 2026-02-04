# Shattered Fates - UI/UX Implementation Guide

## Overview
This document describes the complete UI/UX system implemented for the Shattered Fates cat character game.

## Components Created

### 1. CatHUD (C++ HUD Class)
**Files:** `CatHUD.h`, `CatHUD.cpp`

Main HUD controller that manages all UI widgets and provides API for updating UI elements.

**Key Features:**
- Player widget management
- Health bar updates
- Stamina bar updates
- Lives display
- Movement state indicators
- Ability availability indicators
- Debug info display (optional)

**Usage:**
```cpp
// Get HUD reference
ACatHUD* CatHUD = Cast<ACatHUD>(PlayerController->GetHUD());

// Update UI elements
CatHUD->UpdateHealthBar(0.75f); // 75% health
CatHUD->UpdateStaminaBar(0.50f); // 50% stamina
CatHUD->UpdateLivesDisplay(7); // 7 lives remaining
CatHUD->ShowMovementState(TEXT("Sprinting"));
CatHUD->ShowAbilityIndicator(TEXT("Pounce"), true);
```

### 2. CatPlayerWidget (UMG Widget)
**Files:** `CatPlayerWidget.h`, `CatPlayerWidget.cpp`

Main gameplay HUD widget that displays player statistics and status.

**Widget Components Required (Bind in UMG):**
- `HealthBar` (UProgressBar) - Displays current health
- `StaminaBar` (UProgressBar) - Displays current stamina
- `LivesText` (UTextBlock) - Shows remaining lives (x/9)
- `MovementStateText` (UTextBlock) - Current movement state
- `SprintIndicator` (UTextBlock) - Sprint ability status
- `ClimbIndicator` (UTextBlock) - Climb ability status
- `PounceIndicator` (UTextBlock) - Pounce ability status
- `LivesContainer` (UHorizontalBox) - Container for life icons
- `RootCanvas` (UCanvasPanel) - Main canvas panel

**Features:**
- Dynamic health bar with color coding (Red < 30%, Orange < 60%, Normal)
- Stamina bar with low-stamina warning (Orange < 20%)
- Lives counter with color warnings (Red <= 3, Orange <= 5)
- Movement state display with color coding by state type
- Ability indicators showing availability/cooldown
- Blueprint events for extended customization

### 3. Cat Character Integration
**Files:** `Cat.h`, `Cat.cpp` (Modified)

Enhanced the Cat character class with UI integration.

**New Properties:**
```cpp
float MaxHealth = 100.0f;
float CurrentHealth = 100.0f;
float MaxStamina = 100.0f;
float CurrentStamina = 100.0f;
float StaminaRegenRate = 20.0f;
float SprintStaminaCost = 10.0f;
```

**New Functions:**
- `TakeDamageCustom(float DamageAmount)` - Apply damage with life system
- `Heal(float HealAmount)` - Restore health
- `ConsumeStamina(float Amount)` - Use stamina for abilities
- `GetHealthPercent()` - Get normalized health value
- `GetStaminaPercent()` - Get normalized stamina value

**Automatic HUD Updates:**
- Health/Stamina bars update every frame
- Movement state updates automatically based on character state
- Ability indicators update based on stamina and conditions

### 4. Main Menu Widget
**Files:** `MainMenuWidget.h`, `MainMenuWidget.cpp`

Complete main menu implementation with navigation.

**Widget Components Required:**
- `PlayButton` (UButton) - Start game
- `OptionsButton` (UButton) - Open options
- `CreditsButton` (UButton) - View credits
- `QuitButton` (UButton) - Exit game
- `TitleText` (UTextBlock) - Game title
- `MenuContainer` (UVerticalBox) - Menu layout container

**Features:**
- Level loading on Play
- Mouse cursor management
- Blueprint events for extended functionality
- Configurable level to load

### 5. Pause Menu Widget
**Files:** `PauseMenuWidget.h`, `PauseMenuWidget.cpp`

In-game pause menu with game control options.

**Widget Components Required:**
- `ResumeButton` (UButton) - Continue playing
- `RestartButton` (UButton) - Restart level
- `OptionsButton` (UButton) - Game settings
- `MainMenuButton` (UButton) - Return to main menu
- `PauseTitleText` (UTextBlock) - Pause header
- `MenuContainer` (UVerticalBox) - Menu layout

**Features:**
- Automatic game pause/unpause
- Level restart functionality
- Return to main menu
- Mouse cursor control

### 6. CatGameMode
**Files:** `CatGameMode.h`, `CatGameMode.cpp`

Game mode that sets up the cat character and HUD automatically.

**Configuration:**
- DefaultPawnClass = ACat
- HUDClass = ACatHUD

## Setup Instructions

### Step 1: Update Build Configuration
The `Shattered_Fates.Build.cs` has been updated to include:
- UMG module
- Slate module
- SlateCore module

### Step 2: Create UMG Widget Blueprints

#### A. Player HUD Widget (WBP_CatPlayerWidget)
1. Create new Widget Blueprint based on `CatPlayerWidget` class
2. Add Canvas Panel named "RootCanvas"
3. Add components with exact names:
   - **Top Left - Health & Stamina:**
     - Add ProgressBar named "HealthBar" (Red tint)
     - Add ProgressBar named "StaminaBar" (Green tint)
   - **Top Right - Lives:**
     - Add TextBlock named "LivesText"
     - Add HorizontalBox named "LivesContainer" (for life icons)
   - **Bottom Center - Movement State:**
     - Add TextBlock named "MovementStateText"
   - **Bottom Right - Abilities:**
     - Add TextBlock named "SprintIndicator"
     - Add TextBlock named "ClimbIndicator"
     - Add TextBlock named "PounceIndicator"

4. **Styling Recommendations:**
   - Use semi-transparent backgrounds
   - Large, readable fonts
   - Align elements to screen edges with padding
   - Use anchors for responsive design

#### B. Main Menu Widget (WBP_MainMenu)
1. Create Widget Blueprint based on `MainMenuWidget` class
2. Add components:
   - TextBlock "TitleText" (large, centered)
   - VerticalBox "MenuContainer" (centered)
   - Button "PlayButton" with text "Play Game"
   - Button "OptionsButton" with text "Options"
   - Button "CreditsButton" with text "Credits"
   - Button "QuitButton" with text "Quit"

3. Set "LevelToLoad" property to your game level name

#### C. Pause Menu Widget (WBP_PauseMenu)
1. Create Widget Blueprint based on `PauseMenuWidget` class
2. Add components:
   - Semi-transparent overlay background
   - TextBlock "PauseTitleText"
   - VerticalBox "MenuContainer"
   - Button "ResumeButton"
   - Button "RestartButton"
   - Button "OptionsButton"
   - Button "MainMenuButton"

3. Set "MainMenuLevelName" to your main menu level

### Step 3: Configure Game Mode
1. Open Project Settings ? Maps & Modes
2. Set Default GameMode to `CatGameMode` (or create Blueprint based on it)
3. In the GameMode Blueprint:
   - Set HUD Class to your `WBP_CatPlayerWidget` parent class
   - Ensure Default Pawn Class is set to `Cat`

### Step 4: Set Up Input for Pause Menu
Add pause functionality to your Cat character or PlayerController:
```cpp
// In your input setup
if (PauseAction)
{
    EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AYourClass::TogglePauseMenu);
}

void AYourClass::TogglePauseMenu()
{
    if (!PauseMenuWidget)
    {
        PauseMenuWidget = CreateWidget<UPauseMenuWidget>(GetWorld(), PauseMenuWidgetClass);
        PauseMenuWidget->AddToViewport(999); // High Z-order
    }
    else
    {
        PauseMenuWidget->OnResumeClicked();
    }
}
```

## UI Color Scheme

### Health Bar
- **Green (100-60%):** Healthy
- **Orange (60-30%):** Damaged
- **Red (<30%):** Critical

### Stamina Bar
- **Green (100-20%):** Normal
- **Orange (<20%):** Low stamina warning

### Lives Display
- **White (9-6 lives):** Safe
- **Orange (5-4 lives):** Warning
- **Red (3-1 lives):** Danger

### Movement States
- **White:** Walking
- **Yellow:** Sprinting
- **Blue:** Crouching/Prowling
- **Green:** Climbing
- **Orange:** Falling

### Ability Indicators
- **Yellow:** Available
- **Gray:** Unavailable/Cooldown

## Customization Options

### Blueprint Events
Both widgets expose Blueprint-implementable events:

**CatPlayerWidget:**
- `OnHealthChanged(float)` - Called when health updates
- `OnStaminaChanged(float)` - Called when stamina updates
- `OnLivesChanged(int32)` - Called when lives change
- `OnMovementStateChanged(FString)` - Called when state changes

**MainMenuWidget:**
- `OnPlayGameStarted()` - Before loading game level
- `OnOptionsOpened()` - When options is clicked
- `OnCreditsOpened()` - When credits is clicked

**PauseMenuWidget:**
- `OnGameResumed()` - Before unpausing
- `OnGameRestarted()` - Before restarting level
- `OnReturnToMainMenu()` - Before loading main menu

### Styling Properties
Edit in Blueprint or C++:
- `HealthColor` - Default health bar color
- `StaminaColor` - Default stamina bar color
- `AbilityAvailableColor` - Color when ability is ready
- `AbilityUnavailableColor` - Color when ability is on cooldown

## Debug Features

Enable debug info in `CatHUD`:
```cpp
bShowDebugInfo = true; // In Blueprint or C++
```

This displays:
- Player position
- Player velocity
- Additional runtime information

## Performance Considerations

- HUD updates every frame via Tick - optimize if needed
- Use Blueprint events sparingly to avoid overhead
- Consider disabling widgets that aren't visible
- Progress bars use efficient native rendering

## Testing Checklist

- [ ] Health bar updates correctly when taking damage
- [ ] Stamina depletes when sprinting
- [ ] Stamina regenerates when not sprinting
- [ ] Lives counter decrements on death
- [ ] Movement state displays correctly for all states
- [ ] Ability indicators show correct availability
- [ ] Main menu buttons work (Play, Options, Credits, Quit)
- [ ] Pause menu pauses game
- [ ] Resume button unpauses game
- [ ] Restart button reloads level
- [ ] Return to main menu works
- [ ] Mouse cursor shows/hides appropriately

## Future Enhancements

Consider adding:
1. Health/Stamina pickup indicators
2. Objective/quest tracker
3. Minimap
4. Dialogue system
5. Inventory UI
6. Skill tree/upgrade menu
7. Settings menu with graphics/audio options
8. Save/Load game UI
9. Achievement notifications
10. Interactive tutorial overlays

## Troubleshooting

**Issue: Widgets not appearing**
- Check that Widget Blueprint class is set in GameMode
- Verify AddToViewport is being called
- Check Z-order if multiple widgets overlap

**Issue: Buttons not working**
- Ensure Button components have correct names matching BindWidget properties
- Check mouse cursor is enabled
- Verify click events are enabled on PlayerController

**Issue: HUD not updating**
- Verify HUD reference is valid in Cat class
- Check that UpdateHUD() is being called
- Ensure Widget components are bound correctly

**Issue: Compile errors**
- Clean and rebuild project
- Regenerate Visual Studio project files
- Check that UMG module is in Build.cs

## Support

For questions or issues with this UI/UX system, refer to:
- Unreal Engine UMG Documentation
- Enhanced Input System Documentation
- This README file

---

**Version:** 1.0  
**Last Updated:** 2024  
**Unreal Engine Version:** 5.7+
