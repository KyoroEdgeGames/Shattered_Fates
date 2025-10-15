# UI/Menus/main_menu.py

"""
Main menu module for Shattered Fates.
Provides player with options to start a new game, load a save,
access settings, or exit the game.
"""

def main_menu():
    """
    Displays the main menu of Shattered Fates and handles player selection.
    Options include:
        1. New Game
        2. Load Game
        3. Settings
        4. Exit
    """
    while True:
        print("\n=== Welcome to Shattered Fates ===")
        print("1. New Game")
        print("2. Load Game")
        print("3. Settings")
        print("4. Exit")

        choice = input("Enter your choice: ").strip()

        if choice == "1":
            start_new_game()
        elif choice == "2":
            load_game()
        elif choice == "3":
            settings_menu()
        elif choice == "4":
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Try again.")

def start_new_game():
    """
    Handles starting a new game.
    Player can choose to create a custom cat or play as a main NPC.
    """
    print("\n--- New Game ---")
    print("1. Create Custom Cat")
    print("2. Play as Main NPC")
    choice = input("Enter your choice: ").strip()

    if choice == "1":
        create_custom_cat()
    elif choice == "2":
        select_main_npc()
    else:
        print("Invalid choice. Returning to main menu.")

def create_custom_cat():
    """
    Allows the player to create a custom cat character.
    Player chooses name, clan, sex, and optionally age stage.
    """
    print("\n--- Create Your Custom Cat ---")
    name = input("Enter your cat's name: ").strip()
    clan = input("Enter your clan (Lostclan, Frostclan, Heavyclan, Bloodclan): ").strip()
    sex = input("Enter your cat's sex (male/female): ").strip()
    # Optional: age stage could be kit, apprentice, warrior
    age_stage = input("Enter age stage (kit/apprentice/warrior) [default: kit]: ").strip().lower()
    if age_stage not in ["kit", "apprentice", "warrior"]:
        age_stage = "kit"

    print(f"\nCustom cat created!\nName: {name}\nClan: {clan}\nSex: {sex}\nAge Stage: {age_stage}")

    # Here you would normally save to a character JSON file
    # or initialize the character object for gameplay.

def select_main_npc():
    """
    Allows the player to select a main NPC character from the story.
    Example NPCs: Ivy, Coal, Brambleflower
    """
    print("\n--- Select Main NPC ---")
    npcs = ["Ivy", "Coal", "Brambleflower"]
    for idx, npc in enumerate(npcs, start=1):
        print(f"{idx}. {npc}")

    choice = input("Enter your choice: ").strip()
    try:
        npc_index = int(choice) - 1
        if 0 <= npc_index < len(npcs):
            print(f"\nYou are now playing as {npcs[npc_index]}!")
        else:
            print("Invalid choice. Returning to main menu.")
    except ValueError:
        print("Invalid input. Returning to main menu.")

def load_game():
    """
    Placeholder for load game functionality.
    Can be extended to load player JSON saves.
    """
    print("\nLoad Game feature is not implemented yet.")

def settings_menu():
    """
    Placeholder for settings menu functionality.
    Can be extended for audio, graphics, controls, etc.
    """
    print("\nSettings menu is not implemented yet.")

# Entry point if this module is run directly
if __name__ == "__main__":
    main_menu()
