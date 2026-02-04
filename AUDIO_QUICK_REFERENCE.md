# ?? Audio System Quick Reference

## ?? Files Created

### C++ Classes
```
? AudioManager.h/cpp ............... Core audio system
? AudioSettingsWidget.h/cpp ........ Volume control UI
? Cat.h/cpp (Modified) ............. Footsteps, meows, action sounds
? MainMenuWidget.h/cpp (Modified) .. Menu music & button sounds
? PauseMenuWidget.h/cpp (Modified) . Pause audio & music control
```

## ?? Music Tracks (7)

```cpp
EMusicTrack::MainMenu       // Main menu background
EMusicTrack::Exploration    // Peaceful gameplay
EMusicTrack::Combat         // Action sequences
EMusicTrack::Dialogue       // Story scenes
EMusicTrack::Boss           // Boss battles
EMusicTrack::Victory        // Win condition
EMusicTrack::GameOver       // Death/failure
```

## ?? Sound Effects (24+)

### UI Sounds (4)
```
ButtonHover, ButtonClick, MenuOpen, MenuClose
```

### Cat Movement (5)
```
Footstep, Jump, Land, Crouch, Sprint
```

### Cat Actions (7)
```
Pounce, ClimbStart, Climbing, WallJump, Meow, Purr, Hiss
```

### Combat (3)
```
Hit, TakeDamage, Death
```

### Items (3)
```
HealthPickup, StaminaPickup, Collectible
```

### Environment (3)
```
DoorOpen, DoorClose, Checkpoint
```

## ?? Quick Setup

### 1. Place AudioManager in Level
```
1. Open GameLevel
2. Search "AudioManager" in Place Actors
3. Drag into level
4. Configure sound maps in Details panel
```

### 2. Assign Audio Assets
```
AudioManager Details:
?? Music Tracks ? Assign 7 music cues
?? Sound Effects ? Assign 24+ SFX cues
```

### 3. Create Audio Settings Widget
```
Name: WBP_AudioSettings
Parent: AudioSettingsWidget
Components (EXACT NAMES):
?? MasterVolumeSlider
?? MasterVolumeText
?? MusicVolumeSlider
?? MusicVolumeText
?? SFXVolumeSlider
?? SFXVolumeText
?? MuteAllCheckBox
?? ApplyButton
?? ResetButton
```

## ?? C++ API

### Playing Music
```cpp
// Play with fade in
AudioManager->PlayMusic(EMusicTrack::Exploration, 2.0f);

// Crossfade between tracks
AudioManager->CrossfadeMusic(EMusicTrack::Combat, 3.0f);

// Stop with fade out
AudioManager->StopMusic(1.0f);

// Pause/Resume
AudioManager->PauseMusic();
AudioManager->ResumeMusic();
```

### Playing Sound Effects
```cpp
// 2D sound (everywhere)
AudioManager->PlaySoundEffect(ESoundEffect::ButtonClick);

// 3D sound at location
AudioManager->PlaySoundEffect(ESoundEffect::Meow, GetActorLocation());

// 3D sound at actor
AudioManager->PlaySoundEffectAtActor(ESoundEffect::Footstep, Actor);

// Looping sound
UAudioComponent* Loop = AudioManager->PlaySoundEffectLooping(
    ESoundEffect::Climbing, 
    Location
);

// Stop looping
AudioManager->StopLoopingSoundEffect(Loop, 0.5f);
```

### Volume Control
```cpp
// Set volumes (0.0 - 1.0)
AudioManager->SetMasterVolume(0.8f);
AudioManager->SetMusicVolume(0.5f);
AudioManager->SetSFXVolume(0.7f);

// Get volumes
float Master = AudioManager->GetMasterVolume();
float Music = AudioManager->GetMusicVolume();
float SFX = AudioManager->GetSFXVolume();

// Mute/Unmute
AudioManager->MuteAll();
AudioManager->UnmuteAll();
bool IsMuted = AudioManager->IsMuted();
```

## ?? Blueprint Nodes

### Get AudioManager
```
Get All Actors of Class ? AudioManager
? Get (0) ? Promote to Variable
```

### Play Music
```
Audio Manager ? Play Music
?? Track: Exploration
?? Fade In Time: 2.0
```

### Play Sound Effect
```
Audio Manager ? Play Sound Effect
?? Effect: ButtonClick
?? Location: (0,0,0) for 2D
?? Volume Multiplier: 1.0
```

### Crossfade Music
```
Audio Manager ? Crossfade Music
?? New Track: Combat
?? Crossfade Time: 3.0
```

## ?? Cat Audio (Automatic)

### What Plays Automatically
```
Walking/Running ? Footsteps (interval-based)
Jumping ? Jump sound
Landing ? Land sound
Sprinting ? Sprint start + faster footsteps
Crouching ? Crouch sound
Pouncing ? Pounce attack sound
Climbing ? Climb start sound
Wall Jump ? Wall jump sound
Taking Damage ? Damage sound + Death (if life lost)
Healing ? Health pickup sound
Random Meows ? 5% chance every 3s while sprinting
```

### Configuration
```cpp
bEnableFootstepSounds = true;     // Toggle on/off
FootstepInterval = 0.4f;          // Walking interval
SprintFootstepInterval = 0.25f;   // Sprinting interval
```

## ?? UI Audio (Automatic)

### Main Menu
```
On Open ? MainMenu music starts (fade in 2s)
Button Hover ? ButtonHover sound
Button Click ? ButtonClick sound
On Play ? Music stops (fade out 1s)
```

### Pause Menu
```
On Open ? MenuOpen sound + Music pauses
Button Hover ? ButtonHover sound
Button Click ? ButtonClick sound
On Resume ? MenuClose sound + Music resumes
On Restart/MainMenu ? Music stops (fade 0.5s)
```

## ??? Default Volumes

```
Master Volume: 1.0   (100%)
Music Volume:  0.5   (50%)
SFX Volume:    0.7   (70%)
```

## ?? Folder Structure

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
?   ?   ??? etc...
?   ?
?   ??? Combat/
?       ??? etc...
?
??? Cues/
    ??? (Sound Cues)
```

## ?? Troubleshooting

| Problem | Solution |
|---------|----------|
| No sound | Check AudioManager in level, volumes > 0 |
| Music won't play | Assign music cue in AudioManager |
| SFX too loud | Reduce SFXVolume or volume multiplier |
| No footsteps | Check bEnableFootstepSounds = true |
| No crossfade | Check both tracks assigned, time > 0 |

## ?? Testing Checklist

- [ ] AudioManager placed in level
- [ ] All music tracks assigned (7)
- [ ] All SFX assigned (24+)
- [ ] WBP_AudioSettings created
- [ ] Music plays on main menu
- [ ] Music crossfades in-game
- [ ] Button sounds work
- [ ] Cat footsteps play
- [ ] Cat action sounds work
- [ ] Volume sliders work
- [ ] Mute button works

## ? Performance Tips

1. Use Sound Cues (not raw wave files)
2. Compress music (Vorbis)
3. Keep SFX short (<2 seconds)
4. Use attenuation for 3D sounds
5. Limit concurrent sounds (<10 active)

## ?? Sound Design Recommendations

### Music
- Seamless loops (1-2s crossfade overlap)
- Combat: 120-140 BPM
- Exploration: 60-90 BPM
- Boss: 140-160 BPM

### SFX
- Footsteps: 3-5 variations (random)
- UI: Subtle, clear sounds
- Cat vocals: Various pitches
- Combat: Punchy, satisfying hits

## ?? Pro Tips

1. **Test with headphones** for 3D audio
2. **Use random pitch** variation in Sound Cues
3. **Add reverb** for large spaces
4. **Duck music** during important dialogue
5. **Layer sounds** for richness
6. **EQ cleanup** - remove unnecessary frequencies

---

## ?? Full Documentation

See **AUDIO_IMPLEMENTATION_GUIDE.md** for:
- Detailed setup instructions
- Advanced features
- Blueprint integration examples
- Sound design tips
- Complete API reference

---

**?? Ready to add immersive audio to your game!**

*Audio System v1.0 | Shattered Fates*
