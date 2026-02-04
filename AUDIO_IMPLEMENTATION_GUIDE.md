# ?? Shattered Fates - Audio System Implementation Guide

## ?? What's Been Created

### C++ Audio Classes (6 new files)
```
Source/Shattered_Fates/
??? AudioManager.h .................. Complete audio management system
??? AudioManager.cpp ................
??? AudioSettingsWidget.h ........... In-game audio settings UI
??? AudioSettingsWidget.cpp .........
??? (Modified Files)
    ??? Cat.h ....................... Added audio integration
    ??? Cat.cpp ..................... Added footsteps, meows, action sounds
    ??? MainMenuWidget.h ............ Added menu audio
    ??? MainMenuWidget.cpp ..........
    ??? PauseMenuWidget.h ........... Added pause menu audio
    ??? PauseMenuWidget.cpp .........
```

---

## ?? Audio System Features

### AudioManager (Core System)
**Location:** Acts as singleton in your level

**Features:**
- ? **Music System** with crossfading
- ? **Sound Effects** (2D and 3D positional)
- ? **Volume Control** (Master, Music, SFX)
- ? **Mute/Unmute** functionality
- ? **Looping Sounds** management
- ? **Auto-cleanup** of finished sounds

### Music Tracks (7 tracks)
```cpp
EMusicTrack::MainMenu      // Main menu background
EMusicTrack::Exploration   // Peaceful exploration
EMusicTrack::Combat        // Action/combat music
EMusicTrack::Dialogue      // Story/dialogue scenes
EMusicTrack::Boss          // Boss battle music
EMusicTrack::Victory       // Win condition
EMusicTrack::GameOver      // Death/failure
```

### Sound Effects (24+ sounds)
```cpp
// UI Sounds (4)
ButtonHover, ButtonClick, MenuOpen, MenuClose

// Cat Movement (5)
Footstep, Jump, Land, Crouch, Sprint

// Cat Actions (6)
Pounce, ClimbStart, Climbing, WallJump, Meow, Purr, Hiss

// Combat (3)
Hit, TakeDamage, Death

// Items (3)
HealthPickup, StaminaPickup, Collectible

// Environment (3)
DoorOpen, DoorClose, Checkpoint
```

---

## ?? Setup Instructions

### Phase 1: Place AudioManager in Level

1. **Open your GameLevel in Unreal Editor**
2. **Search for "AudioManager"** in Place Actors panel
3. **Drag AudioManager into level** (anywhere - it's not visual)
4. **Select the AudioManager**
5. **Configure in Details Panel:**

#### Music Tracks Configuration
```
Music Tracks (Map):
?? Key: MainMenu      ? Value: Your MainMenu music asset
?? Key: Exploration   ? Value: Your Exploration music asset
?? Key: Combat        ? Value: Your Combat music asset
?? Key: Dialogue      ? Value: Your Dialogue music asset
?? Key: Boss          ? Value: Your Boss music asset
?? Key: Victory       ? Value: Your Victory music asset
?? Key: GameOver      ? Value: Your GameOver music asset
```

#### Sound Effects Configuration
```
Sound Effects (Map):
?? UI Sounds:
?  ?? Key: ButtonHover    ? Value: Button hover sound
?  ?? Key: ButtonClick    ? Value: Button click sound
?  ?? Key: MenuOpen       ? Value: Menu open sound
?  ?? Key: MenuClose      ? Value: Menu close sound
?
?? Cat Movement:
?  ?? Key: Footstep       ? Value: Paw footstep sound
?  ?? Key: Jump           ? Value: Jump sound
?  ?? Key: Land           ? Value: Landing sound
?  ?? Key: Crouch         ? Value: Crouch sound
?  ?? Key: Sprint         ? Value: Sprint start sound
?
?? Cat Actions:
?  ?? Key: Pounce         ? Value: Pounce attack sound
?  ?? Key: ClimbStart     ? Value: Climb start sound
?  ?? Key: Climbing       ? Value: Climbing loop sound
?  ?? Key: WallJump       ? Value: Wall jump sound
?  ?? Key: Meow           ? Value: Cat meow sound
?  ?? Key: Purr           ? Value: Cat purr sound
?  ?? Key: Hiss           ? Value: Cat hiss sound
?
?? Combat:
?  ?? Key: Hit            ? Value: Hit impact sound
?  ?? Key: TakeDamage     ? Value: Damage taken sound
?  ?? Key: Death          ? Value: Death sound
?
?? Items:
?  ?? Key: HealthPickup   ? Value: Health pickup sound
?  ?? Key: StaminaPickup  ? Value: Stamina pickup sound
?  ?? Key: Collectible    ? Value: Item collect sound
?
?? Environment:
   ?? Key: DoorOpen       ? Value: Door open sound
   ?? Key: DoorClose      ? Value: Door close sound
   ?? Key: Checkpoint     ? Value: Checkpoint sound
```

#### Volume Settings
```
Default Music Volume: 0.5  (50%)
Default SFX Volume: 0.7    (70%)
Max Hearing Distance: 5000.0
Attenuation Multiplier: 1.0
```

6. **Save the level**

---

### Phase 2: Create Audio Assets

#### Option A: Use Temporary Sounds (For Testing)
Unreal Engine has built-in sounds you can use temporarily:
1. In Content Browser, navigate to `Engine Content ? EngineSounds`
2. Find placeholder sounds
3. Use these for initial testing

#### Option B: Import Your Own Sounds (Recommended)
1. **Create folder structure:**
   ```
   Content/Audio/
   ??? Music/
   ?   ??? MainMenu_Music
   ?   ??? Exploration_Music
   ?   ??? Combat_Music
   ?   ??? Dialogue_Music
   ?   ??? Boss_Music
   ?   ??? Victory_Music
   ?   ??? GameOver_Music
   ?
   ??? SFX/
   ?   ??? UI/
   ?   ?   ??? ButtonHover_SFX
   ?   ?   ??? ButtonClick_SFX
   ?   ?   ??? MenuOpen_SFX
   ?   ?   ??? MenuClose_SFX
   ?   ?
   ?   ??? Cat/
   ?   ?   ??? Footstep_SFX
   ?   ?   ??? Jump_SFX
   ?   ?   ??? Land_SFX
   ?   ?   ??? Meow_SFX
   ?   ?   ??? Purr_SFX
   ?   ?   ??? Hiss_SFX
   ?   ?
   ?   ??? Combat/
   ?       ??? Hit_SFX
   ?       ??? TakeDamage_SFX
   ?       ??? Death_SFX
   ?
   ??? Cues/
       ??? (Sound Cues created from above)
   ```

2. **Import audio files:**
   - Right-click in Content Browser ? Import
   - Select your .wav, .mp3, or .ogg files
   - Recommended format: WAV 16-bit, 44.1kHz

3. **Create Sound Cues:**
   - Right-click audio file ? Create Cue
   - Name it appropriately (e.g., `ButtonClick_Cue`)
   - Sound Cues allow for variations and effects

4. **Configure Sound Cue Properties:**
   - Open the Sound Cue
   - Add variety:
     - Random node (for footsteps with multiple samples)
     - Attenuation (for 3D positional sounds)
     - Volume modulation
     - Pitch variation

---

### Phase 3: Create Audio Settings Widget

1. **Create Widget Blueprint:**
   - Location: `Content/UI/Settings/`
   - Name: `WBP_AudioSettings`
   - Parent Class: `AudioSettingsWidget`

2. **Design the Widget:**

```
???????????????????????????????????????????????
?         AUDIO SETTINGS                      ?
???????????????????????????????????????????????
?                                             ?
?  Master Volume:  [??????????] 80%           ?
?  Music Volume:   [??????????] 50%           ?
?  SFX Volume:     [??????????] 70%           ?
?                                             ?
?  [?] Mute All                               ?
?                                             ?
?  [  Apply  ]  [  Reset  ]                   ?
?                                             ?
???????????????????????????????????????????????
```

**Required Components (EXACT NAMES):**
```
?? MasterVolumeSlider (Slider)
?? MasterVolumeText (Text Block)
?? MusicVolumeSlider (Slider)
?? MusicVolumeText (Text Block)
?? SFXVolumeSlider (Slider)
?? SFXVolumeText (Text Block)
?? MuteAllCheckBox (Check Box)
?? ApplyButton (Button)
?? ResetButton (Button)
```

**Slider Configuration:**
- Min Value: 0.0
- Max Value: 1.0
- Step Size: 0.01

3. **Compile and Save**

---

## ?? Usage Examples

### Playing Music
```cpp
// In C++
AudioManager->PlayMusic(EMusicTrack::Exploration, 2.0f);
AudioManager->CrossfadeMusic(EMusicTrack::Combat, 3.0f);
AudioManager->StopMusic(1.0f);
AudioManager->PauseMusic();
AudioManager->ResumeMusic();

// In Blueprint
Get Audio Manager ? Play Music (Track: Exploration, Fade In: 2.0)
```

### Playing Sound Effects
```cpp
// 2D Sound (everywhere)
AudioManager->PlaySoundEffect(ESoundEffect::ButtonClick);

// 3D Sound at location
AudioManager->PlaySoundEffect(ESoundEffect::Meow, GetActorLocation());

// 3D Sound at actor
AudioManager->PlaySoundEffectAtActor(ESoundEffect::Footstep, PlayerCharacter);

// Looping sound
UAudioComponent* Loop = AudioManager->PlaySoundEffectLooping(ESoundEffect::Climbing);
// Later...
AudioManager->StopLoopingSoundEffect(Loop, 0.5f);
```

### Volume Control
```cpp
// Set volumes (0.0 to 1.0)
AudioManager->SetMasterVolume(0.8f);
AudioManager->SetMusicVolume(0.5f);
AudioManager->SetSFXVolume(0.7f);

// Get current volumes
float Master = AudioManager->GetMasterVolume();
float Music = AudioManager->GetMusicVolume();
float SFX = AudioManager->GetSFXVolume();

// Mute/Unmute
AudioManager->MuteAll();
AudioManager->UnmuteAll();
bool IsMuted = AudioManager->IsMuted();
```

---

## ?? Cat Character Audio Integration

The Cat character now automatically plays sounds for:

### Movement Sounds (Automatic)
- **Footsteps** - Every 0.4s when walking (0.25s when sprinting)
  - Volume adjusts based on movement speed
  - Quieter when prowling (20% volume)
- **Jump** - When leaving ground
- **Land** - When hitting ground
- **Sprint** - When starting to sprint

### Action Sounds (Automatic)
- **Pounce** - When pounce attack is used
- **Climb Start** - When starting wall climb
- **Wall Jump** - When jumping off wall
- **Crouch** - When crouching
- **Meow/Purr** - Random chance while sprinting (5% chance every 3s)

### Combat Sounds (Automatic)
- **Take Damage** - When health decreases
- **Death** - When losing a life
- **Heal** - When picking up health (via Heal function)

### Configuration
```cpp
// In Cat Blueprint or C++
bEnableFootstepSounds = true;    // Toggle footsteps on/off
FootstepInterval = 0.4f;         // Time between footsteps (walking)
SprintFootstepInterval = 0.25f;  // Time between footsteps (sprinting)
```

---

## ?? UI Audio Integration

### Main Menu (Automatic)
- **Music** - Starts MainMenu track on menu open
- **Button Hover** - Plays hover sound on mouse over
- **Button Click** - Plays click sound on button press
- **Music Fade** - Stops music when starting game

### Pause Menu (Automatic)
- **Menu Open** - Plays open sound
- **Music Pause** - Pauses game music
- **Button Hover** - Plays hover sound
- **Button Click** - Plays click sound
- **Menu Close** - Plays close sound on resume
- **Music Resume** - Resumes game music

### Audio Settings Widget
- **Real-time Volume** - Changes apply immediately
- **Test Sound** - SFX slider plays click on change
- **Mute Toggle** - Saves previous volumes
- **Reset Button** - Returns to defaults

---

## ?? Blueprint Integration

### Getting AudioManager Reference
```
Event BeginPlay
??? Get All Actors of Class (Class: AudioManager)
    ??? Get (index 0)
        ??? Promote to Variable "Audio Manager"
```

### Playing Music on Level Start
```
Event BeginPlay
??? Get Audio Manager
    ??? Play Music
        ?? Track: Exploration
        ?? Fade In Time: 2.0
```

### Crossfade Music on Event
```
On Enter Combat Zone
??? Get Audio Manager
    ??? Crossfade Music
        ?? New Track: Combat
        ?? Crossfade Time: 3.0
```

### Play Sound at Location
```
On Pickup Collected
??? Get Audio Manager
    ??? Play Sound Effect
        ?? Effect: Collectible
        ?? Location: Get Actor Location (Self)
        ?? Volume Multiplier: 1.0
```

---

## ?? Advanced Features

### Dynamic Music System
```cpp
// Change music based on gameplay state
void AGameStateManager::UpdateMusicBasedOnState()
{
    if (bInCombat)
    {
        AudioManager->CrossfadeMusic(EMusicTrack::Combat, 2.0f);
    }
    else if (bNearBoss)
    {
        AudioManager->CrossfadeMusic(EMusicTrack::Boss, 3.0f);
    }
    else
    {
        AudioManager->CrossfadeMusic(EMusicTrack::Exploration, 4.0f);
    }
}
```

### Footstep System with Surface Types
```cpp
void ACat::PlayFootstepSound()
{
    // Detect surface type
    FHitResult Hit;
    FVector Start = GetActorLocation();
    FVector End = Start - FVector(0, 0, 100);
    
    if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility))
    {
        // Play different sound based on surface
        EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
        
        switch(SurfaceType)
        {
            case SurfaceType_Default:
                AudioManager->PlaySoundEffect(ESoundEffect::Footstep, GetActorLocation());
                break;
            // Add more surface types...
        }
    }
}
```

### Random Sound Variations
```cpp
// In Sound Cue, add Random node with multiple wave files
// Or programmatically:
void PlayRandomMeow()
{
    float Random = FMath::FRand();
    if (Random < 0.33f)
        AudioManager->PlaySoundEffect(ESoundEffect::Meow);
    else if (Random < 0.66f)
        AudioManager->PlaySoundEffect(ESoundEffect::Purr);
    else
        AudioManager->PlaySoundEffect(ESoundEffect::Hiss);
}
```

---

## ?? Performance Optimization

### Best Practices
1. **Use Sound Cues** instead of raw wave files
2. **Limit active sounds** - AudioManager auto-cleans inactive sounds
3. **Use attenuation** for 3D sounds (reduces CPU when far away)
4. **Compress audio** - Use Vorbis compression for music
5. **Short sounds** - Keep SFX under 2 seconds when possible

### Memory Management
```cpp
// AudioManager automatically:
// - Cleans up finished one-shot sounds
// - Manages looping sounds array
// - Fades out instead of hard stops

// You can help by:
// - Not playing too many sounds at once
// - Using sound pooling for frequent sounds
// - Properly stopping looping sounds when done
```

---

## ?? Sound Design Tips

### Cat Sounds
- **Meow** - Use various pitched cat meows (3-5 variations)
- **Purr** - Looped purring sound
- **Hiss** - Short, aggressive hiss
- **Footsteps** - Soft paw sounds on various surfaces

### UI Sounds
- **Button Hover** - Subtle whoosh or beep
- **Button Click** - Satisfying click/pop
- **Menu Open/Close** - Swoosh sounds with reverb

### Music Loops
- Ensure loops are seamless
- Add 1-2 second crossfade overlap
- Keep combat music energetic but not overwhelming
- Exploration music should be calm and atmospheric

---

## ?? Testing Checklist

### Music System
- [ ] Music plays on main menu
- [ ] Music crossfades smoothly between tracks
- [ ] Music pauses when game is paused
- [ ] Music resumes when game is unpaused
- [ ] Music stops when returning to main menu

### Sound Effects
- [ ] UI sounds play on button hover/click
- [ ] Cat footsteps play when moving
- [ ] Jump/land sounds play correctly
- [ ] Pounce sound plays on attack
- [ ] Damage sound plays when hit
- [ ] Pickup sounds play when collecting items

### Volume Control
- [ ] Master volume affects all sounds
- [ ] Music volume only affects music
- [ ] SFX volume only affects sound effects
- [ ] Mute button silences everything
- [ ] Unmute restores previous volumes
- [ ] Settings persist (if save system added)

### 3D Audio
- [ ] Sounds get quieter with distance
- [ ] Sounds pan left/right based on position
- [ ] Max hearing distance works correctly

---

## ?? Troubleshooting

### No Sound Playing
**Check:**
- AudioManager is placed in level
- Sound assets are assigned in AudioManager
- Master/Music/SFX volumes are > 0
- Not muted
- Audio device is working

### Sounds Playing Too Loud/Quiet
**Fix:**
- Adjust volume multipliers in PlaySoundEffect calls
- Adjust Default volumes in AudioManager
- Check individual sound asset volumes

### Music Not Crossfading
**Check:**
- Both music tracks are assigned
- Crossfade time > 0
- Music components exist

### Footsteps Not Playing
**Check:**
- bEnableFootstepSounds = true
- Cat is moving (velocity > 50)
- FootstepInterval is reasonable (0.3-0.5)
- Footstep sound is assigned in AudioManager

---

## ?? File Structure

```
Content/
??? Audio/
?   ??? Music/
?   ?   ??? MainMenu_Music.uasset
?   ?   ??? Exploration_Music.uasset
?   ?   ??? Combat_Music.uasset
?   ?   ??? Dialogue_Music.uasset
?   ?   ??? Boss_Music.uasset
?   ?   ??? Victory_Music.uasset
?   ?   ??? GameOver_Music.uasset
?   ?
?   ??? SFX/
?   ?   ??? UI/
?   ?   ??? Cat/
?   ?   ??? Combat/
?   ?   ??? Items/
?   ?   ??? Environment/
?   ?
?   ??? Cues/
?       ??? UI_Cues/
?       ??? Cat_Cues/
?       ??? etc...
?
??? Blueprints/
?   ??? Managers/
?       ??? BP_AudioManager
?
??? UI/
    ??? Settings/
        ??? WBP_AudioSettings
```

---

## ?? Complete!

Your Shattered Fates game now has:
- ? Complete audio management system
- ? Music with crossfading
- ? 24+ sound effects
- ? Cat character audio integration
- ? UI audio for all menus
- ? In-game audio settings
- ? Volume control (Master, Music, SFX)
- ? Mute functionality
- ? 3D positional audio support

**Next Steps:**
1. Place AudioManager in your level
2. Assign audio assets
3. Create WBP_AudioSettings widget
4. Test all audio features
5. Add more sound variations
6. Fine-tune volumes

**Enjoy your immersive audio experience!** ?????

---

*Audio System v1.0*
*Compatible with Shattered Fates UI/UX System*
*Unreal Engine 5.7+*
