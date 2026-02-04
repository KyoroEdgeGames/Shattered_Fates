# ?? Shattered Fates - Complete Controls Guide

## ? Movement Controls (Already Implemented)

### Basic Movement
| Key | Action | Status |
|-----|--------|--------|
| **W** | Move Forward | ? Working |
| **S** | Move Backward | ? Working |
| **A** | Strafe Left | ? Working |
| **D** | Strafe Right | ? Working |
| **Mouse** | Look Around | ? Working |
| **Space** | Jump | ? Working |

### Advanced Movement
| Key | Action | Status | Notes |
|-----|--------|--------|-------|
| **Shift** (Hold) | Sprint | ? Working | Consumes stamina |
| **Ctrl** (Hold) | Crouch | ? Working | Slower, stealthier |
| **Left Mouse** | Pounce | ? Working | Forward leap attack |
| **Double Jump** | Wall Jump | ? Working | When near wall in air |

### Special Abilities
| Ability | How to Use | Requirements | Status |
|---------|-----------|--------------|--------|
| **Climbing** | Walk into wall + hold W | Near climbable surface | ? Working |
| **Prowling** | Crouch while moving slowly | None | ? Working |
| **Always Land on Feet** | Automatic in air | None | ? Working |

---

## ?? New System Controls (Need Setup)

### Interaction System
| Key | Action | Status | Setup Required |
|-----|--------|--------|----------------|
| **E** | Interact with Objects | ?? Needs Setup | Create IA_Interact input action |

**To Setup:**
1. Create Input Action: `IA_Interact` (Digital/Bool)
2. Add to your Input Mapping Context, map to **E** key
3. Assign to Cat Blueprint's `Interact Action` property

### Quick Save/Load (For Testing)
| Key | Action | Purpose |
|-----|--------|---------|
| **F5** | Quick Save | Save current state |
| **F9** | Quick Load | Load saved state |

*Add these bindings in Cat Blueprint for testing*

---

## ?? Cat Character Stats

### Health System
- **Max Health:** 100
- **Current Health:** Displays on HUD
- **Lives:** 9 (cat lives!)
- **Regeneration:** Use health items

### Stamina System
- **Max Stamina:** 100
- **Sprint Cost:** 10/second
- **Pounce Cost:** 20 per use
- **Regen Rate:** 20/second (when not sprinting)

### Movement Speeds
| State | Speed | Notes |
|-------|-------|-------|
| Walk | 300 | Default |
| Sprint | 600 | Hold Shift |
| Crouch | 150 | Hold Ctrl |
| Prowl | 75 | Crouch + slow movement |
| Climb | 200 | On walls |

---

## ?? Gameplay Controls (Upcoming)

### Inventory System (Ready)
- **I** - Open Inventory (needs UI setup)
- **1-5** - Quick item slots (optional)
- **Mouse Click** - Use/Equip items (in UI)

### Quest System (Ready)
- **J** - Open Quest Log (needs UI setup)
- **Track Quest** - Automatically tracks active quests

### Combat System (With Enemies)
- **Left Mouse** - Pounce Attack (implemented)
- **Right Mouse** - Hiss/Scare (optional to add)
- **Space + Shift** - Dodge Roll (optional to add)

---

## ?? Camera Controls

### Default Camera (Current)
- **Mouse** - Rotate camera
- **Mouse Wheel** - Zoom in/out (if CatCamera component used)

### Camera Modes (With CatCameraComponent)
| Mode | Zoom Distance | Auto-Activated When |
|------|---------------|---------------------|
| Normal | 300 | Walking normally |
| Combat | 250 | In combat (with enemies) |
| Stealth | 200 | Crouching/Prowling |
| Climbing | 350 | Climbing walls |
| Sprint | 400 | Sprinting |

---

## ?? HUD Display (Current)

### Visible Stats
- ?? Health Bar
- ? Stamina Bar
- ?? Lives Count (x9)
- ?? Movement State ("Walking", "Sprinting", etc.)
- ? Ability Indicators (Sprint, Pounce, Climb available)

### Sound Effects
- ?? Footsteps (speed-based)
- ?? Random meows (while sprinting)
- ?? Landing sounds
- ?? Action sounds (jump, pounce, etc.)

---

## ?? Controller Support (To Add)

If you want gamepad support, map these:

| Gamepad | PC Keyboard | Action |
|---------|-------------|--------|
| Left Stick | WASD | Movement |
| Right Stick | Mouse | Camera |
| A Button | Space | Jump |
| B Button | Ctrl | Crouch |
| X Button | E | Interact |
| Y Button | I | Inventory |
| LT | Shift | Sprint |
| RT | Left Mouse | Pounce |
| D-Pad Up | J | Quest Log |
| Start | Esc | Pause Menu |

---

## ?? Debug Controls (Developer)

### Current Debug Features
- **` (Tilde)** - Open Console
- **F8** - Eject from character (free cam)
- **P** - Toggle NavMesh visualization
- **Tab** - Toggle AI debug

### Custom Debug Commands (To Add)
```
GiveItem [ItemID] [Quantity]
StartQuest [QuestID]
CompleteQuest [QuestID]
GodMode
NoClip
SetHealth [Amount]
SetStamina [Amount]
TeleportToCheckpoint [Name]
```

---

## ?? Recommended Control Improvements

### Quality of Life Additions
1. **Mouse Sensitivity Slider** (in settings menu)
2. **Invert Y-Axis Option** (in settings menu)
3. **Rebindable Keys** (in settings menu)
4. **Toggle Crouch** (vs hold)
5. **Auto-Sprint** (optional)
6. **Camera Smoothing** (optional)

### Accessibility Options
1. **Simplified Controls Mode**
2. **One-Button Abilities**
3. **Camera Assistance**
4. **Visual Indicators** for abilities ready

---

## ?? Control Customization (Future)

Create a Settings Menu with:

### Input Settings
- Key Bindings
- Mouse Sensitivity
- Invert Axes
- Controller Vibration

### Gameplay Settings
- Sprint: Toggle vs Hold
- Aim Assist (if needed)
- Auto-Collect Items
- Quest Tracking

### Audio Settings (Already in Save System!)
- Master Volume
- Music Volume
- SFX Volume
- Mute All

---

## ?? Control Tips for Players

### Movement Tips
?? **Crouch in tight spaces** - Cats fit through small openings
?? **Sprint uses stamina** - Plan your energy use
?? **Pounce for distance** - Best way to traverse gaps
?? **Wall jump for height** - Combine with regular jumps
?? **Always lands on feet** - No fall damage from reasonable heights

### Combat Tips (With Enemies)
?? **Pounce as opener** - Start fights with big damage
?? **Crouch to stealth** - Sneak past enemies
?? **Sprint to escape** - When overwhelmed
?? **Use environment** - Jump to unreachable places

### Exploration Tips
?? **Check everywhere** - Cats can reach high places
?? **Interact with everything** - Press E near objects
?? **Listen for audio cues** - Footsteps, meows
?? **Save often** - Use quick save (F5)

---

## ?? Current Status Summary

### ? Fully Implemented Controls
- WASD Movement
- Mouse Look
- Jump (Space)
- Sprint (Shift)
- Crouch (Ctrl)
- Pounce (LMB)
- Wall Jump
- Climbing
- All movement abilities

### ?? Needs Editor Setup
- Interact (E) - needs input action
- Inventory UI - needs widget
- Quest UI - needs widget
- Save/Load keys - optional
- Pause Menu - needs input

### ?? Future Additions
- Gamepad support
- Custom key bindings
- Advanced combat moves
- Special cat abilities
- Contextual actions

---

## ?? Getting Started (Quick Reference)

### First Time Setup
1. ? Game compiles (DONE)
2. ?? Create `IA_Interact` input action
3. ?? Assign to Cat Blueprint
4. ?? Test in editor!

### Test Your Controls
1. Hit **Play** in editor
2. **WASD** - Move around
3. **Space** - Jump
4. **Shift** - Sprint
5. **Mouse** - Look around
6. **Ctrl** - Crouch
7. **LMB** - Pounce

If all of these work, you're ready to build your game! ??

---

## ?? Related Documentation
- Full setup: `IMPLEMENTATION_COMPLETE_NEXT_STEPS.md`
- System docs: `NEW_SYSTEMS_DOCUMENTATION.md`
- Quick guide: `QUICK_SETUP_GUIDE.md`

---

**Enjoy playing as a cat! ??**
