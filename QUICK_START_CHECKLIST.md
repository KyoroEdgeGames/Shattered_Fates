# Quick Start Checklist - Make Shattered Fates Playable

## ? Status: C++ Code is Complete and Compiles Successfully

## Minimal Setup for Testing (30 minutes)

### Phase 1: Basic Level Setup (5 minutes)
- [ ] Open project in Unreal Editor 5.7
- [ ] File > New Level > Basic
- [ ] Add Cube actor, scale to (100, 100, 1) for floor
- [ ] Add Directional Light
- [ ] Save as `Content/Maps/TestLevel`

### Phase 2: Input Setup (10 minutes)
- [ ] Create Input Action: `IA_Move` (Axis2D)
- [ ] Create Input Action: `IA_Look` (Axis2D)
- [ ] Create Input Action: `IA_Jump` (Boolean)
- [ ] Create Input Action: `IA_Sprint` (Boolean)
- [ ] Create Input Action: `IA_Crouch` (Boolean)
- [ ] Create Input Action: `IA_Pounce` (Boolean)
- [ ] Create Input Action: `IA_Pause` (Boolean)
- [ ] Create Input Mapping Context: `IMC_Cat`
  - Map IA_Move to: W/S/D/A keys
  - Map IA_Look to: Mouse X/Y
  - Map IA_Jump to: Spacebar
  - Map IA_Sprint to: Left Shift
  - Map IA_Crouch to: C key
  - Map IA_Pounce to: Left Mouse Button
  - Map IA_Pause to: Escape

### Phase 3: Character Blueprint (10 minutes)
- [ ] Create Blueprint Class from "Cat" (search in All Classes)
- [ ] Name it `BP_Cat`
- [ ] Open BP_Cat
- [ ] Set Class Defaults:
  - [ ] Cat Mapping Context = IMC_Cat
  - [ ] Move Action = IA_Move
  - [ ] Look Action = IA_Look
  - [ ] Jump Action = IA_Jump
  - [ ] Sprint Action = IA_Sprint
  - [ ] Crouch Action = IA_Crouch
  - [ ] Pounce Action = IA_Pounce
- [ ] Add Camera Component:
  - [ ] Add Spring Arm Component
  - [ ] Add Camera to Spring Arm
  - [ ] Set Spring Arm length to 300
  - [ ] Set Spring Arm rotation: Pitch -20
- [ ] Add Temporary Mesh (Cube or Sphere) to visualize the cat
- [ ] Compile and Save

### Phase 4: Game Configuration (5 minutes)
- [ ] Edit > Project Settings > Maps & Modes
- [ ] Set Default GameMode to: CatGameMode (or create BP_CatGameMode)
- [ ] Set Default Pawn Class to: BP_Cat
- [ ] Set Editor Startup Map: TestLevel
- [ ] Set Game Default Map: TestLevel
- [ ] Close Project Settings

### Phase 5: Test! ??
- [ ] Click Play (PIE) button
- [ ] Test Controls:
  - [ ] WASD - Move character
  - [ ] Mouse - Look around
  - [ ] Spacebar - Jump
  - [ ] Left Shift - Sprint (drains stamina)
  - [ ] C - Crouch
  - [ ] Left Mouse - Pounce (requires stamina)
  - [ ] Escape - Pause (if widgets created)

## Expected Behavior

When you press Play, you should see:
? Character spawns in the level
? Can move in all directions with WASD
? Can look around with mouse
? Can jump and sprint
? Movement feels responsive

## Optional Enhancements (Add Later)

### UI Widgets
- [ ] Create WBP_CatPlayer widget (health/stamina bars)
- [ ] Create WBP_PauseMenu widget
- [ ] Create BP_CatHUD blueprint
- [ ] Assign Player Widget Class in CatHUD

### Audio
- [ ] Create BP_AudioManager blueprint
- [ ] Import sound effects
- [ ] Populate Sound Effects map in BP_AudioManager
- [ ] Place BP_AudioManager in level

### Visual Polish
- [ ] Import cat character mesh
- [ ] Replace temporary mesh in BP_Cat
- [ ] Add animations
- [ ] Create Animation Blueprint
- [ ] Add particle effects

### Level Design
- [ ] Add walls and platforms to test climbing
- [ ] Add collectibles
- [ ] Create multiple levels
- [ ] Add checkpoints

## Troubleshooting

**Character doesn't respond to input:**
- Verify Enhanced Input plugin is enabled (Plugins window)
- Check that IMC_Cat is assigned in BP_Cat
- Ensure all Input Actions are properly mapped

**Character falls through floor:**
- Select floor cube > Details > Collision > Set to "Block All"
- Ensure floor has a collision mesh

**Can't find Cat class:**
- Compile the C++ project first
- Refresh the editor
- Search "Cat" in Class Viewer (Window > Developer Tools > Class Viewer)

**No camera view:**
- Add Spring Arm and Camera components to BP_Cat
- Make sure Camera is attached to Spring Arm
- Set Spring Arm to a reasonable length (300 units)

## Success Criteria

Your game is working when:
1. ? Character spawns and is visible
2. ? Movement controls respond (WASD works)
3. ? Camera follows character
4. ? Jump works
5. ? Sprint works (character moves faster)
6. ? No compilation errors
7. ? No runtime errors in Output Log

## Next Steps After Basic Test Works

1. Replace placeholder visuals with actual art assets
2. Build UI widgets for health/stamina display
3. Create multiple game levels
4. Add enemies and obstacles
5. Implement narrative system
6. Add audio and sound effects
7. Polish camera and movement feel
8. Create main menu and level transitions

---

**Remember:** The C++ code is 100% complete and compiles. You just need to create the Unreal Engine assets (Blueprints, Widgets, Input Mappings) to bring it all together! ???
