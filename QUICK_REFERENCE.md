# Shattered Fates - Quick Reference Card

## ?? Created Files Overview

### C++ Classes (Source/Shattered_Fates/)
| File | Purpose | Key Features |
|------|---------|--------------|
| `CatHUD.h/cpp` | Main HUD Controller | Health, stamina, lives display management |
| `CatPlayerWidget.h/cpp` | Player HUD Widget | Visual HUD with progress bars and indicators |
| `DialogueWidget.h/cpp` | Dialogue Display | Typewriter effect, character dialogue |
| `MainMenuWidget.h/cpp` | Main Menu UI | Play, Options, Credits, Quit |
| `PauseMenuWidget.h/cpp` | Pause Menu UI | Resume, Restart, Main Menu |
| `NarrativeManager.h/cpp` | Story Management | Chapter/dialogue system integration |
| `CatPlayerController.h/cpp` | Enhanced Controller | Input handling, UI management |
| `CatGameMode.h/cpp` | Game Mode Setup | Auto-configuration of game systems |
| `Cat.h/cpp` | Cat Character | Movement, abilities, stats (UPDATED) |

### Widget Names (MUST MATCH EXACTLY)
```cpp
// CatPlayerWidget components:
HealthBar          // UProgressBar - Health display
StaminaBar         // UProgressBar - Stamina display
LivesText          // UTextBlock - Lives counter
MovementStateText  // UTextBlock - Current movement state
SprintIndicator    // UTextBlock - Sprint availability
ClimbIndicator     // UTextBlock - Climb availability
PounceIndicator    // UTextBlock - Pounce availability
LivesContainer     // UHorizontalBox - Life icons
RootCanvas         // UCanvasPanel - Main container

// DialogueWidget components:
CharacterNameText  // UTextBlock - Speaker name
DialogueText       // UTextBlock - Dialogue content
ContinueButton     // UButton - Advance dialogue
DialogueBackground // UImage - Background panel
CharacterPortrait  // UImage - Character image

// MainMenuWidget components:
PlayButton         // UButton - Start game
OptionsButton      // UButton - Open settings
CreditsButton      // UButton - Show credits
QuitButton         // UButton - Exit game
TitleText          // UTextBlock - Game title
MenuContainer      // UVerticalBox - Button container

// PauseMenuWidget components:
ResumeButton       // UButton - Continue game
RestartButton      // UButton - Reload level
OptionsButton      // UButton - Settings
MainMenuButton     // UButton - Return to menu
PauseTitleText     // UTextBlock - "PAUSED"
MenuContainer      // UVerticalBox - Button layout
```

## ?? Input Actions Required

### Enhanced Input Assets to Create
```
Content/Input/
??? IMC_Cat                 (Input Mapping Context)
??? IA_Move                 (Axis2D - WASD)
??? IA_Look                 (Axis2D - Mouse)
??? IA_Jump                 (Digital - Space)
??? IA_Sprint               (Digital - Shift)
??? IA_Crouch               (Digital - Ctrl)
??? IA_Pounce               (Digital - LMB)
??? IA_Pause                (Digital - Escape)
```

## ??? Folder Structure Recommendation

```
Content/
??? Blueprints/
?   ??? Characters/
?   ?   ??? BP_Cat
?   ??? Controllers/
?   ?   ??? BP_CatPlayerController
?   ??? GameModes/
?   ?   ??? BP_CatGameMode
?   ??? HUD/
?       ??? BP_CatHUD
??? UI/
?   ??? HUD/
?   ?   ??? WBP_CatPlayerWidget
?   ??? Dialogue/
?   ?   ??? WBP_DialogueWidget
?   ??? Menus/
?   ?   ??? WBP_MainMenu
?   ?   ??? WBP_PauseMenu
?   ??? Materials/
?   ?   ??? (UI materials)
?   ??? Portraits/
?       ??? T_Ivy
?       ??? T_Coal
?       ??? T_Silence
?       ??? T_Stolenstar
??? Input/
?   ??? (Input Actions & Contexts)
??? Maps/
?   ??? MainMenuLevel
?   ??? GameLevel
??? Audio/
    ??? UI/
    ?   ??? (Button sounds)
    ??? Character/
        ??? (Movement sounds)
```

## ?? Quick Setup Steps

1. **Compile Project**
   ```
   Close Unreal Editor
   Right-click .uproject ? Generate Visual Studio files
   Open solution ? Build
   ```

2. **Create Widgets (30 min)**
   - WBP_CatPlayerWidget (10 min)
   - WBP_DialogueWidget (10 min)
   - WBP_MainMenu (5 min)
   - WBP_PauseMenu (5 min)

3. **Create Input Assets (5 min)**
   - IMC_Cat + 7 Input Actions

4. **Configure Blueprints (10 min)**
   - BP_CatGameMode
   - BP_Cat (assign inputs)
   - BP_CatPlayerController (assign widgets)

5. **Set Project Settings (2 min)**
   - Default GameMode
   - Default Maps

6. **Test** ?

## ?? Cat Character Stats

### Default Values
```cpp
// Movement
WalkSpeed:     300.0f
RunSpeed:      600.0f
CrouchSpeed:   150.0f
JumpHeight:    500.0f
ClimbSpeed:    200.0f
PounceForce:   1000.0f

// Stats
MaxHealth:     100.0f
MaxStamina:    100.0f
StaminaRegen:  20.0f/sec
SprintCost:    10.0f/sec
LivesRemaining: 9

// Abilities
bCanClimb:     true
```

## ?? UI Color Scheme

### Health Bar
- 100-60%: Green `#cc661a` / RGB(204, 102, 26)
- 60-30%: Orange `#ff7f00` / RGB(255, 127, 0)
- <30%: Red `#ff0000` / RGB(255, 0, 0)

### Stamina Bar
- 100-20%: Green `#33cc33` / RGB(51, 204, 51)
- <20%: Orange `#ff7f00` / RGB(255, 127, 0)

### Lives Counter
- 9-6: White `#ffffff`
- 5-4: Orange `#ff7f00`
- 3-1: Red `#ff0000`

### Ability Indicators
- Available: Yellow `#ffff00`
- Cooldown: Gray `#4d4d4d`

## ?? Quick Troubleshooting

| Problem | Solution |
|---------|----------|
| Widgets not showing | Check class assignment in GameMode |
| Buttons not clicking | Verify exact component names (case-sensitive) |
| HUD not updating | Check HUD reference in Cat::BeginPlay |
| Input not working | Verify Input Actions assigned in Cat Blueprint |
| Dialogue not appearing | Check DialogueWidget class in NarrativeManager |
| Pause not working | Ensure PauseAction is bound in PlayerController |

## ?? Key Functions

### From Cat Character
```cpp
TakeDamageCustom(float Amount)  // Damage with life system
Heal(float Amount)               // Restore health
ConsumeStamina(float Amount)    // Use stamina for abilities
StartSprinting()                 // Begin sprint
StopSprinting()                  // End sprint
Pounce()                         // Special attack
StartClimbing()                  // Climb walls
```

### From CatHUD
```cpp
UpdateHealthBar(float Percent)     // Update health display
UpdateStaminaBar(float Percent)    // Update stamina display
UpdateLivesDisplay(int32 Lives)    // Update lives counter
ShowMovementState(FString State)   // Display movement state
ShowAbilityIndicator(FString, bool) // Show ability status
```

### From NarrativeManager
```cpp
StartChapter(int32 Index)                      // Begin chapter
PlayDialogueSequence(int32 Chapter, int32 Seq) // Play dialogue
NextChapter()                                   // Advance story
```

### From DialogueWidget
```cpp
StartDialogue(FDialogueSequence)  // Begin dialogue sequence
AdvanceDialogue()                  // Next line
SkipDialogue()                     // Close dialogue
```

## ?? Testing Checklist

### Main Menu
- [ ] Mouse visible
- [ ] Buttons work
- [ ] Level loads

### In-Game HUD
- [ ] Health decreases when damaged
- [ ] Stamina depletes when sprinting
- [ ] Lives counter updates
- [ ] Movement state changes
- [ ] Ability indicators update

### Movement
- [ ] Walk with WASD
- [ ] Sprint with Shift (uses stamina)
- [ ] Jump with Space
- [ ] Crouch with Ctrl
- [ ] Pounce with LMB

### Pause Menu
- [ ] Escape opens menu
- [ ] Game pauses
- [ ] Resume works
- [ ] Restart works

### Dialogue
- [ ] Appears when triggered
- [ ] Typewriter effect (if enabled)
- [ ] Advances with button
- [ ] Closes when complete

## ?? File Relationships

```
CatGameMode
??> Sets: Cat (Pawn)
??> Sets: CatHUD (HUD)
??> Sets: CatPlayerController (Controller)

CatHUD
??> Creates: CatPlayerWidget

CatPlayerController
??> Creates: PauseMenuWidget
??> Creates: MainMenuWidget

NarrativeManager
??> Creates: DialogueWidget

Cat Character
??> References: CatHUD
??> Uses: Enhanced Input Actions
```

## ?? Performance Tips

1. **Only update HUD when values change** (not every frame)
2. **Pool widgets** instead of creating/destroying
3. **Use timers** instead of Tick where possible
4. **Disable unused widgets** (SetVisibility Hidden)
5. **Optimize texture sizes** for UI images

## ?? Pro Tips

1. **Use Blueprints for rapid iteration** of UI layout
2. **Keep C++ for logic**, Blueprint for design
3. **Test in PIE first**, then standalone
4. **Use Widget Reflector** (Ctrl+Shift+W) to debug UI
5. **Enable "Show FPS"** in editor for performance monitoring

## ?? Useful Blueprint Nodes

- **Create Widget** - Instantiate UI
- **Add to Viewport** - Show widget
- **Remove from Parent** - Hide widget
- **Set Input Mode** - Game/UI/Both
- **Set Game Paused** - Pause/Unpause
- **Open Level** - Change maps
- **Get Player Controller** - Access controller
- **Cast to Cat** - Access cat functions

---

## ?? Documentation Files

1. `UI_UX_IMPLEMENTATION_GUIDE.md` - Original implementation guide
2. `COMPLETE_SETUP_GUIDE.md` - Step-by-step setup instructions
3. `QUICK_REFERENCE.md` - This file (quick reference)
4. `StorylineEngine.cpp` - Story content and structure

**Total Setup Time:** ~1-2 hours
**Difficulty:** Intermediate
**Unreal Version:** 5.7+ (Compatible with 5.0+)

---

*Last Updated: 2024*
*Shattered Fates - A Cat's Journey* ???
