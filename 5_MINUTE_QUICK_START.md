# ? 5-MINUTE QUICK START CHECKLIST

## ? Status: BUILD SUCCESSFUL! Ready to go!

Follow these steps to get your game running in 5 minutes:

---

## ?? Checklist (Check off as you complete)

### Step 1: Configure Game Instance (2 minutes)
- [ ] Open `Config/DefaultEngine.ini`
- [ ] Find `[/Script/EngineSettings.GameMapsSettings]`
- [ ] Add line: `GameInstanceClass=/Script/Shattered_Fates.ShatteredFatesGameInstance`
- [ ] Save file

### Step 2: Create Interact Input Action (2 minutes)
- [ ] Content Browser ? Right-click ? Input ? Input Action
- [ ] Name it: `IA_Interact`
- [ ] Set Value Type: Digital (bool)
- [ ] Open your Input Mapping Context (IMC_Cat or similar)
- [ ] Add new mapping: IA_Interact ? E key
- [ ] Save

### Step 3: Assign to Cat Blueprint (1 minute)
- [ ] Open BP_Cat (or your Cat Blueprint)
- [ ] In Class Defaults, find Input section
- [ ] Set Interact Action = IA_Interact
- [ ] Compile and save

### Step 4: TEST! (30 seconds)
- [ ] Open a level
- [ ] Hit Play
- [ ] Test these controls:
  - [ ] WASD - Move ?
  - [ ] Mouse - Look ?
  - [ ] Space - Jump ?
  - [ ] Shift - Sprint ?
  - [ ] Ctrl - Crouch ?
  - [ ] LMB - Pounce ?

---

## ?? Success Criteria

If all controls work, you're done! Move to content creation.

If something doesn't work:
1. Check Output Log for errors
2. Verify GameInstance is set
3. Check IA_Interact is assigned
4. Recompile blueprints

---

## ?? Next: Create Your First Content (15 minutes)

### Quick Test Item
- [ ] Blueprint Class ? InventoryItem
- [ ] Name: BP_HealthPotion
- [ ] Set Item ID: "health_potion"
- [ ] Set Max Stack Size: 5
- [ ] Save

### Quick Test Door
- [ ] Blueprint Class ? InteractableActor
- [ ] Name: BP_TestDoor
- [ ] Set Interaction Prompt: "Press E to Open"
- [ ] Place in level
- [ ] Test interaction (walk up, press E)

### Quick Test
- [ ] Level Blueprint ? BeginPlay
- [ ] Get Player Character ? Cast to Cat
- [ ] Get Inventory Component
- [ ] Add Item (BP_HealthPotion, 3)
- [ ] Play ? Check Output Log for "Added 3 x Health Potion"

---

## ? You're Ready!

Once this checklist is complete:
- ? All systems operational
- ? All controls working
- ? Ready to create content

**Read IMPLEMENTATION_COMPLETE_NEXT_STEPS.md for detailed guides!**

---

## ?? Quick Commands Reference

### In-Game Testing
```
Press ~ for console (once you add console commands)

Future commands to add:
- GiveItem health_potion 5
- StartQuest tutorial_quest
- SaveGame
- LoadGame
```

### Debug Shortcuts (to add in Blueprint)
```
F5 - Quick Save
F9 - Quick Load
F8 - Free Camera
Tab - Show FPS
```

---

**Total Time: ~5 minutes**
**Difficulty: Easy**
**Result: Fully functional game!** ??

Go to `IMPLEMENTATION_COMPLETE_NEXT_STEPS.md` for full guide!
