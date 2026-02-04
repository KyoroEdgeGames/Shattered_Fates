# Quick Setup Guide - New Game Systems

## ?? 5-Minute Setup

### Step 1: Configure Game Instance (REQUIRED)
Open `Config/DefaultEngine.ini` and add:
```ini
[/Script/EngineSettings.GameMapsSettings]
GameInstanceClass=/Script/Shattered_Fates.ShatteredFatesGameInstance
```

### Step 2: Add Components to Cat Character
In Cat Blueprint or `Cat.h`:

```cpp
// Add to Cat.h
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
UInventoryComponent* InventoryComponent;

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
UQuestManagerComponent* QuestManager;

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
UInteractionComponent* InteractionComponent;

// Add to Cat.cpp constructor
InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
QuestManager = CreateDefaultSubobject<UQuestManagerComponent>(TEXT("QuestManager"));
InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("Interaction"));
```

### Step 3: Add Interaction Input
In Enhanced Input:
1. Create new Input Action: `IA_Interact`
2. Map to 'E' key
3. Bind in Cat's SetupPlayerInputComponent:

```cpp
if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
{
    EnhancedInput->BindAction(InteractAction, ETriggerEvent::Triggered, InteractionComponent, &UInteractionComponent::AttemptInteract);
}
```

---

## ?? Quick Usage Examples

### Save/Load
```cpp
// Get Game Instance
auto GI = Cast<UShatteredFatesGameInstance>(GetGameInstance());

// Save
GI->SaveGame();          // Default save
GI->QuickSave();         // Quick save slot
GI->SaveCheckpoint("CP1"); // Checkpoint

// Load
GI->LoadGame();
GI->QuickLoad();
GI->LoadCheckpoint();
```

### Inventory
```cpp
// Add item (create in Blueprint first)
InventoryComponent->AddItem(ItemObject, Quantity);

// Check item
if (InventoryComponent->HasItem("key_item"))
{
    // Player has key
}

// Use item
InventoryComponent->UseItem(ItemObject);
```

### Quests
```cpp
// Start quest
QuestManager->StartQuestByID("quest_001");

// Update objective
QuestManager->UpdateQuestObjective("quest_001", "obj_001", 1);

// Check status
if (QuestManager->IsQuestCompleted("quest_001"))
{
    // Quest done
}
```

### Interaction
```cpp
// Check for interactable (in Tick or UI update)
if (InteractionComponent->HasInteractableInRange())
{
    FText Prompt = InteractionComponent->GetCurrentInteractionPrompt();
    // Show prompt: "Press E to Open Door"
}

// Interact (bound to input)
InteractionComponent->AttemptInteract();
```

### Camera
```cpp
// Set camera mode
CatCamera->SetCameraMode(ECameraMode::Combat);

// Zoom
CatCamera->ZoomIn(50.0f);
CatCamera->ZoomOut(50.0f);

// Shake (on impact)
CatCamera->ApplyCameraShake(0.5f, 0.3f);
```

### Enemies
```cpp
// Spawn enemy
AEnemyCharacter* Enemy = GetWorld()->SpawnActor<AEnemyCharacter>(
    EnemyClass, Location, Rotation);

// Configure
Enemy->MaxHealth = 100.0f;
Enemy->AttackDamage = 20.0f;
Enemy->SightRange = 1000.0f;

// Setup patrol
Enemy->PatrolPoints = {Point1, Point2, Point3};
Enemy->bLoopPatrol = true;

// Listen to death
Enemy->OnDeath.AddDynamic(this, &AMyClass::OnEnemyKilled);
```

---

## ?? Blueprint Quick Setup

### 1. Create Item Blueprint
- Right-click ? Blueprint Class ? InventoryItem
- Set ItemID, ItemName, ItemType, Icon
- Configure stack size, weight

### 2. Create Quest Blueprint  
- Right-click ? Blueprint Class ? Quest
- Set QuestID, QuestName, Description
- Add objectives array
- Configure rewards

### 3. Create Interactable Blueprint
- Right-click ? Blueprint Class ? InteractableActor
- Set InteractionType, Prompt Text
- Set Distance, Required Items
- Bind OnInteracted event

### 4. Create Enemy Blueprint
- Right-click ? Blueprint Class ? EnemyCharacter
- Set stats (Health, Damage, Speed)
- Set patrol points in viewport
- Configure loot table

---

## ?? Common Configurations

### Inventory Settings
```cpp
InventoryComponent->MaxInventorySize = 20;
InventoryComponent->MaxWeight = 100.0f;
InventoryComponent->bEnableWeightLimit = false;
```

### Quest Settings
```cpp
// In Quest Blueprint/Object
Quest->RecommendedLevel = 5;
Quest->PrerequisiteQuests = {"quest_000"};
Quest->Reward.ItemRewards = {"sword", "shield"};
Quest->Reward.ExperienceReward = 100;
```

### Interaction Settings
```cpp
InteractableActor->InteractionDistance = 200.0f;
InteractableActor->bRequiresLookAt = true;
InteractableActor->bSingleUse = false;
InteractableActor->RequiredItemID = "key";
InteractableActor->RequiredQuestID = "quest_001";
```

### Camera Settings
```cpp
CatCamera->NormalZoomDistance = 300.0f;
CatCamera->CombatZoomDistance = 250.0f;
CatCamera->MinZoomDistance = 150.0f;
CatCamera->MaxZoomDistance = 600.0f;
CatCamera->bEnableCameraCollision = true;
```

### Enemy Settings
```cpp
Enemy->EnemyType = EEnemyType::Melee;
Enemy->SightRange = 1000.0f;
Enemy->SightAngle = 90.0f;
Enemy->AttackRange = 150.0f;
Enemy->AttackCooldown = 1.5f;
Enemy->LootDropChance = 0.5f;
```

---

## ?? Debug Features

### Enable Debug Drawing
```cpp
// Interaction
InteractionComponent->bDrawDebugTrace = true;

// Camera
// Shows collision spheres and lines in viewport
```

### Check Output Log
All systems log important events:
- Save/Load operations
- Inventory changes
- Quest updates
- Interaction attempts
- Enemy state changes

### Console Commands (if implemented)
```
// Example additions you could add:
SaveGame MySave
LoadGame MySave
GiveItem health_potion 5
StartQuest quest_001
```

---

## ?? Troubleshooting Quick Fixes

### Save not working?
- Check GameInstance is set in DefaultEngine.ini
- Check save directory has write permissions
- Look for error in Output Log

### Inventory not updating UI?
- Bind to OnInventoryUpdated delegate
- Check component is added to character
- Verify item creation is correct

### Quests not tracking?
- Verify QuestManager component exists
- Check QuestID matches exactly
- Ensure quest is started before updating

### Interaction not working?
- Check TraceDistance value
- Enable bDrawDebugTrace to see trace
- Verify InteractionComponent is ticking
- Check InteractableActor is in scene

### Camera issues?
- Verify SpringArm component exists
- Check camera is attached to SpringArm
- Adjust CameraLagSpeed for smoothness

### Enemy not moving?
- Ensure NavMesh is in level (P key to view)
- Check AIController is set
- Verify patrol points are set
- Check enemy state in debugger

---

## ?? Testing Checklist

Quick test for each system:

- [ ] **Save System:** Save, close editor, load - data persists
- [ ] **Inventory:** Add item, count increases, UI updates
- [ ] **Quest:** Start quest, update objective, completion works
- [ ] **Interaction:** Walk up to object, see prompt, interact works
- [ ] **Camera:** Movement smooth, zooms work, collision works
- [ ] **Enemy:** Patrols waypoints, detects player, attacks player

---

## ?? Next Steps After Setup

1. Create your first item in Blueprint
2. Add that item to player inventory on BeginPlay (test)
3. Create a simple quest with one objective
4. Place an interactable door in level
5. Replace Cat's camera with CatCameraComponent
6. Spawn a test enemy with patrol route

---

## ?? Full Documentation

For detailed information, see:
- `NEW_SYSTEMS_DOCUMENTATION.md` - Complete API reference
- `NEW_SYSTEMS_SUMMARY.md` - Full feature list
- Code comments in source files

---

## ?? Pro Tips

1. **Blueprint Child Classes:** Create Blueprint children of C++ classes for easy tweaking
2. **Data Tables:** Use Data Tables for items and quests (optional advanced feature)
3. **Save Slots:** Use player name/profile as save slot name
4. **Quest Chains:** Use PrerequisiteQuests for story progression
5. **Enemy Variants:** Create different enemy blueprints from base class
6. **Camera Profiles:** Create different camera setups for different areas

---

**You're ready to go! Start creating content in the Unreal Editor!** ??

For questions, check the full documentation or code comments.
