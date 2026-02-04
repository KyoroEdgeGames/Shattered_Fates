# 🐱 Shattered Fates

<p align="center">
  <img src="https://img.shields.io/badge/Unreal%20Engine-5.7-informational?logo=unrealengine" alt="Unreal Engine">
  <img src="https://img.shields.io/badge/C++-17-blue?logo=cplusplus" alt="C++">
  <img src="https://img.shields.io/badge/build-passing-brightgreen" alt="Build">
  <img src="https://img.shields.io/badge/license-MIT-blue" alt="License">
  <img src="https://img.shields.io/badge/version-0.1.0--alpha-orange" alt="Version">
</p>

<p align="center">
  <strong>A cat-based action-adventure RPG built in Unreal Engine 5.7</strong>
</p>

<p align="center">
  Play as a mystical cat with unique abilities, exploring a rich world filled with quests, enemies, and secrets. Featuring a complete save system, inventory management, quest tracking, and dynamic combat!
</p>

<p align="center">
  <a href="#-features">Features</a> •
  <a href="#-quick-start">Quick Start</a> •
  <a href="#-controls">Controls</a> •
  <a href="#-documentation">Documentation</a> •
  <a href="#-contributing">Contributing</a>
</p>

---

## ✨ Features

### 🎮 Gameplay
- **Play as a Cat** - Unique feline movement and abilities
- **9 Lives System** - Innovative death mechanic
- **Dynamic Combat** - Pounce attacks, stealth, and agility-based gameplay
- **Cat-Specific Movement** - Wall climbing, wall jumping, always lands on feet
- **Rich Audio** - Footsteps, meows, purrs, and environmental sounds

### 🎯 Core Systems
- ✅ **Save/Load System** - Complete game state persistence with multiple save slots
- ✅ **Inventory System** - 5 item types, stacking, weight system
- ✅ **Quest System** - Complex quest tracking with multiple objective types
- ✅ **Interaction System** - Dynamic world interactions with context-sensitive prompts
- ✅ **AI/Enemy System** - 8 enemy states, 4 enemy types, patrol and combat
- ✅ **Camera System** - 5 camera modes with dynamic zoom
- ✅ **Audio System** - Comprehensive audio management and spatial audio
- ✅ **Dialogue System** - NPC conversations and narrative
- ✅ **Camp System** - Rest points and safe zones

### 🎨 Character Features
- 🏃 WASD Movement (Sprint, Crouch, Prowl)
- ⬆️ Jump and Double Jump
- 🐾 Pounce Attack
- 🧗 Wall Climbing
- 💪 Stamina System
- ❤️ Health and Lives
- 🎒 Inventory Management
- 📋 Quest Tracking

---

## 🚀 Quick Start

### Prerequisites
- **Unreal Engine 5.7** or later
- **Visual Studio 2022** (with C++ development tools)
- **Windows 10/11** (64-bit)
- **8GB RAM** minimum (16GB recommended)

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/Shattered_Fates.git
   cd Shattered_Fates
   ```

2. **Generate project files:**
   - Right-click `Shattered_Fates.uproject`
   - Select "Generate Visual Studio project files"

3. **Build the project:**
   - Open `Shattered_Fates.sln` in Visual Studio
   - Build Solution (Ctrl+Shift+B)

4. **Configure Game Instance:**
   - Open `Config/DefaultEngine.ini`
   - Add under `[/Script/EngineSettings.GameMapsSettings]`:
     ```ini
     GameInstanceClass=/Script/Shattered_Fates.ShatteredFatesGameInstance
     ```

5. **Setup Input (First Time):**
   - Open Unreal Editor
   - Content Browser → Right-click → Input → Input Action
   - Create `IA_Interact` (Digital/Bool)
   - Add to your Input Mapping Context
   - Map to **E** key
   - Assign to Cat Blueprint

6. **Play!**
   - Open any level
   - Press Play (Alt+P)
   - Use WASD to move, Space to jump, E to interact

### 📖 Full Setup Guide
See [5_MINUTE_QUICK_START.md](5_MINUTE_QUICK_START.md) for detailed setup instructions.

---

## 🎮 Controls

| Key | Action | Description |
|-----|--------|-------------|
| **W A S D** | Move | Standard movement |
| **Mouse** | Look | Camera control |
| **Space** | Jump | Double tap for double jump |
| **Left Shift** | Sprint | Hold to sprint (uses stamina) |
| **Left Ctrl** | Crouch/Prowl | Stealth movement |
| **Left Mouse** | Pounce | Cat's primary attack |
| **E** | Interact | Interact with objects/NPCs |
| **Tab** | Inventory | Open inventory menu |
| **J** | Quest Log | View active quests |
| **Esc** | Pause | Open pause menu |

See [CONTROLS_GUIDE.md](CONTROLS_GUIDE.md) for the complete control reference.

---

## 📁 Project Structure

```
Shattered_Fates/
├── Config/                     # Engine and game configuration
├── Content/                    # Game assets (not in repo)
│   ├── Blueprints/            # Blueprint classes
│   ├── Maps/                  # Game levels
│   ├── UI/                    # User interface widgets
│   ├── Audio/                 # Sound effects and music
│   └── Materials/             # Materials and textures
├── Source/
│   └── Shattered_Fates/       # C++ source code
│       ├── Cat.h/cpp          # Player character
│       ├── Inventory/         # Inventory system
│       ├── Quest/             # Quest system
│       ├── Interaction/       # Interaction system
│       ├── AI/                # Enemy AI
│       ├── Audio/             # Audio management
│       └── UI/                # UI components
├── Docs/                       # Documentation
└── README.md                   # This file
```

---

## 🔧 Systems Overview

### Save/Load System
- **Files:** `ShatteredFatesSaveGame`, `ShatteredFatesGameInstance`
- **Features:** Multiple save slots, quick save/load, checkpoints, settings persistence
- **Usage:**
  ```cpp
  // Quick save
  GetGameInstance<UShatteredFatesGameInstance>()->QuickSave();
  
  // Save to specific slot
  GetGameInstance<UShatteredFatesGameInstance>()->SaveGame("MainSave");
  ```

### Inventory System
- **Files:** `InventoryItem`, `InventoryComponent`
- **Features:** 5 item types, stacking, weight system, rarity levels
- **Usage:**
  ```cpp
  InventoryComponent->AddItem(ItemObject, Quantity);
  InventoryComponent->UseItem(ItemObject);
  ```

### Quest System
- **Files:** `QuestSystem`, `QuestManagerComponent`
- **Features:** Multiple objective types, prerequisites, rewards, branching
- **Usage:**
  ```cpp
  QuestManager->StartQuestByID("main_quest_01");
  QuestManager->UpdateQuestObjective("main_quest_01", "objective_01", 1);
  ```

### Interaction System
- **Files:** `InteractableActor`, `InteractionComponent`
- **Features:** 8 interaction types, distance checks, required items/quests
- **Usage:**
  ```cpp
  InteractionComponent->AttemptInteract();
  ```

### AI/Enemy System
- **Files:** `EnemyCharacter`, `EnemyAIController`
- **Features:** 8 AI states, patrol, combat, detection, loot drops
- **Usage:**
  ```cpp
  Enemy->SetPatrolPoints(Waypoints);
  Enemy->OnDeath.AddDynamic(this, &MyClass::HandleEnemyDeath);
  ```

For complete API documentation, see [NEW_SYSTEMS_DOCUMENTATION.md](NEW_SYSTEMS_DOCUMENTATION.md).

---

## 📚 Documentation

| Document | Description |
|----------|-------------|
| [5_MINUTE_QUICK_START.md](5_MINUTE_QUICK_START.md) | Get started in 5 minutes |
| [CONTROLS_GUIDE.md](CONTROLS_GUIDE.md) | Complete control reference |
| [NEW_SYSTEMS_DOCUMENTATION.md](NEW_SYSTEMS_DOCUMENTATION.md) | Complete API reference |
| [IMPLEMENTATION_COMPLETE_NEXT_STEPS.md](IMPLEMENTATION_COMPLETE_NEXT_STEPS.md) | Step-by-step setup guide |
| [FINAL_SUMMARY.md](FINAL_SUMMARY.md) | Project overview and statistics |

---

## 🛠️ Development

### Building from Source

1. **Prerequisites:**
   - Visual Studio 2022
   - Unreal Engine 5.7
   - Windows SDK 10.0.22621.0 or later

2. **Compile:**
   ```bash
   # Clean build
   .\Engine\Build\BatchFiles\Clean.bat Shattered_Fates Win64 Development
   
   # Build
   .\Engine\Build\BatchFiles\Build.bat Shattered_Fates Win64 Development
   ```

3. **Run Tests:**
   - Open project in Unreal Editor
   - Window → Test Automation
   - Run all tests

### Code Standards
- Follow [Unreal Engine C++ Coding Standard](https://docs.unrealengine.com/5.7/en-US/epic-cplusplus-coding-standard-for-unreal-engine/)
- Use `UPROPERTY()` for all member variables
- Use `UFUNCTION()` for Blueprint-callable functions
- Comment all public APIs
- Use const correctness

---

## 📊 Statistics

- **C++ Classes:** 28
- **Lines of Code:** ~5,500+
- **Game Systems:** 9
- **Blueprint-Callable Functions:** 120+
- **Development Time:** ~2 months
- **Build Status:** ✅ Passing

---

## 🎯 Roadmap

### Current Version: 0.1.0 (Alpha)
- [x] Core movement system
- [x] Save/Load system
- [x] Inventory system
- [x] Quest system
- [x] Interaction system
- [x] Enemy AI
- [x] Audio system
- [x] Dialogue system

### Version 0.2.0 (Beta) - Planned
- [ ] Complete UI/UX polish
- [ ] Tutorial level
- [ ] 5 main quests
- [ ] 10+ enemy types
- [ ] Boss battles
- [ ] Gamepad support
- [ ] Settings menu
- [ ] Achievement system

### Version 1.0.0 (Release) - Future
- [ ] Full story campaign
- [ ] 20+ hours of gameplay
- [ ] 50+ quests
- [ ] 100+ items
- [ ] Multiple endings
- [ ] New Game+
- [ ] Steam Workshop support

---

## 🤝 Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

### Development Setup
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **Unreal Engine** by Epic Games
- **Community Contributors** - Thank you to everyone who has contributed!
- **Asset Credits** - See [CREDITS.md](CREDITS.md) for full asset attribution

---

## 📧 Contact

**Project Maintainer:** [Your Name]
- GitHub: [@yourusername](https://github.com/yourusername)
- Email: your.email@example.com
- Discord: [Shattered Fates Community](https://discord.gg/your-invite)

---

## 🐛 Known Issues

- [ ] Camera can clip through walls in tight spaces
- [ ] Some audio files may not be optimized for streaming
- [ ] Quest UI can overlap with inventory in ultrawide resolutions

See [Issues](https://github.com/KyoroEdgeGames/Shattered_Fates/issues) for the complete list.

---

## ⭐ Support the Project

If you find this project useful, please consider:
- ⭐ Starring the repository
- 🐛 Reporting bugs
- 💡 Suggesting features
- 🔀 Contributing code
- 📢 Sharing with others

---

<p align="center">
  Made with ❤️ and 🐱 by the Shattered Fates Team
</p>

<p align="center">
  <strong>Happy Gaming! 🎮</strong>
</p>
