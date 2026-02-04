# Contributing to Shattered Fates

Thank you for your interest in contributing to Shattered Fates! ??

## Table of Contents
- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [How to Contribute](#how-to-contribute)
- [Development Guidelines](#development-guidelines)
- [Pull Request Process](#pull-request-process)
- [Reporting Bugs](#reporting-bugs)
- [Suggesting Features](#suggesting-features)

---

## Code of Conduct

### Our Pledge
We are committed to providing a welcoming and inclusive environment for all contributors, regardless of experience level, background, or identity.

### Expected Behavior
- Be respectful and considerate in your communication
- Accept constructive criticism gracefully
- Focus on what is best for the project
- Show empathy towards other contributors

### Unacceptable Behavior
- Harassment or discrimination of any kind
- Trolling or insulting comments
- Publishing others' private information
- Any behavior that would be inappropriate in a professional setting

---

## Getting Started

### Prerequisites
1. **Unreal Engine 5.7** installed
2. **Visual Studio 2022** with C++ development tools
3. **Git** for version control
4. Basic knowledge of C++ and Unreal Engine

### Setting Up Your Development Environment

1. **Fork the repository:**
   ```bash
   # Go to GitHub and click "Fork"
   ```

2. **Clone your fork:**
   ```bash
   git clone https://github.com/YOUR_USERNAME/Shattered_Fates.git
   cd Shattered_Fates
   ```

3. **Add upstream remote:**
   ```bash
   git remote add upstream https://github.com/ORIGINAL_OWNER/Shattered_Fates.git
   ```

4. **Generate project files:**
   - Right-click `Shattered_Fates.uproject`
   - Select "Generate Visual Studio project files"

5. **Build the project:**
   - Open `Shattered_Fates.sln`
   - Build Solution (Ctrl+Shift+B)

---

## How to Contribute

### Types of Contributions We Welcome
- ?? **Bug fixes** - Fix existing issues
- ? **New features** - Add new gameplay systems
- ?? **Documentation** - Improve or add documentation
- ?? **Assets** - Contribute art, audio, or animations
- ?? **Tests** - Add or improve automated tests
- ?? **Tools** - Develop editor tools or utilities
- ?? **Localization** - Translate to other languages

---

## Development Guidelines

### Code Style
Follow the [Unreal Engine C++ Coding Standard](https://docs.unrealengine.com/5.7/en-US/epic-cplusplus-coding-standard-for-unreal-engine/):

```cpp
// ? Good
class SHATTERED_FATES_API ACatCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    /** Maximum health of the cat */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float MaxHealth;

    /** Called when health changes */
    UFUNCTION(BlueprintCallable, Category = "Health")
    void TakeDamage(float Damage);

private:
    /** Current health value */
    float CurrentHealth;
};

// ? Bad
class cat : public ACharacter
{
public:
    float maxhealth;
    void takedamage(float damage);
private:
    float currenthealth;
};
```

### Naming Conventions
- **Classes:** Prefix with `A` for Actors, `U` for Objects, `F` for structs
- **Interfaces:** Prefix with `I`
- **Enums:** Prefix with `E`
- **Bool variables:** Prefix with `b`
- **Functions:** Use PascalCase
- **Variables:** Use PascalCase with descriptive names

### Comments
```cpp
/**
 * Detailed function description
 * 
 * @param ItemToAdd The item to add to inventory
 * @param Quantity Number of items to add
 * @return True if item was added successfully
 */
UFUNCTION(BlueprintCallable, Category = "Inventory")
bool AddItem(UInventoryItem* ItemToAdd, int32 Quantity);
```

### Blueprint Compatibility
All public functions that gameplay designers need should be:
- Marked with `UFUNCTION(BlueprintCallable)` or `BlueprintImplementableEvent`
- Have clear, descriptive names
- Include tooltips via `meta=(ToolTip="")`

### Performance
- Use `const` references for parameters when possible
- Avoid unnecessary copying of large objects
- Use object pooling for frequently spawned actors
- Profile before optimizing

---

## Pull Request Process

### Before Submitting

1. **Create a feature branch:**
   ```bash
   git checkout -b feature/YourFeatureName
   ```

2. **Make your changes:**
   - Write clean, well-documented code
   - Follow coding standards
   - Test your changes thoroughly

3. **Commit your changes:**
   ```bash
   git add .
   git commit -m "feat: Add amazing new feature"
   ```

   Use conventional commit messages:
   - `feat:` - New feature
   - `fix:` - Bug fix
   - `docs:` - Documentation changes
   - `style:` - Code style changes (formatting)
   - `refactor:` - Code refactoring
   - `test:` - Adding or updating tests
   - `chore:` - Maintenance tasks

4. **Keep your fork updated:**
   ```bash
   git fetch upstream
   git rebase upstream/main
   ```

5. **Push to your fork:**
   ```bash
   git push origin feature/YourFeatureName
   ```

### Submitting the PR

1. Go to GitHub and create a Pull Request from your fork
2. Fill out the PR template completely
3. Link any related issues
4. Wait for review

### PR Template
```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Performance improvement

## Testing
Describe how you tested your changes

## Screenshots/Videos
If applicable, add visual proof of changes

## Checklist
- [ ] Code follows style guidelines
- [ ] Commented complex code sections
- [ ] Updated documentation
- [ ] No new compiler warnings
- [ ] Tested in editor
- [ ] Blueprint compatibility maintained
```

### Review Process
1. A maintainer will review your PR
2. Address any requested changes
3. Once approved, your PR will be merged
4. Celebrate! ??

---

## Reporting Bugs

### Before Reporting
1. Check if the bug has already been reported
2. Ensure you're using the latest version
3. Try to reproduce the bug consistently

### Bug Report Template
```markdown
**Describe the bug**
Clear description of what the bug is

**To Reproduce**
Steps to reproduce:
1. Go to '...'
2. Click on '...'
3. See error

**Expected behavior**
What you expected to happen

**Screenshots/Videos**
If applicable

**Environment:**
- OS: [e.g., Windows 11]
- Unreal Engine: [e.g., 5.7]
- Build: [e.g., Development, Shipping]

**Additional context**
Any other relevant information
```

---

## Suggesting Features

### Feature Request Template
```markdown
**Is your feature request related to a problem?**
Describe the problem

**Describe the solution you'd like**
Clear description of what you want

**Describe alternatives you've considered**
Other solutions you've thought about

**Additional context**
Mockups, examples, or references

**Priority**
How important is this feature to you?
```

---

## Project Structure for Contributors

```
Shattered_Fates/
??? Source/
?   ??? Shattered_Fates/
?       ??? Cat.h/cpp              # Player character
?       ??? InventoryComponent/     # Inventory system
?       ??? QuestSystem/           # Quest management
?       ??? InteractionSystem/     # World interactions
?       ??? AI/                    # Enemy AI
??? Config/                        # Configuration files
??? Content/                       # Game content (Blueprints, assets)
??? Docs/                          # Documentation
```

---

## Communication

### Where to Ask Questions
- **Discord:** [Join our community](https://discord.gg/your-invite)
- **GitHub Discussions:** For general questions
- **GitHub Issues:** For bugs and feature requests

### Response Times
- Bug reports: Within 48 hours
- Feature requests: Within 1 week
- Pull requests: Within 1 week

---

## Recognition

Contributors will be recognized in:
- The `CREDITS.md` file
- Release notes
- Project README

---

## License

By contributing to Shattered Fates, you agree that your contributions will be licensed under the MIT License.

---

## Thank You!

Every contribution, no matter how small, helps make Shattered Fates better. Thank you for being part of our community! ????

---

**Questions?** Feel free to reach out to the maintainers or ask in our Discord!
