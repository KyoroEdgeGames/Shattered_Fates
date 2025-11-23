"""
Player module for Shattered Fates.

Defines the Player class, which manages player attributes, movement, experience,
leveling, and inventory management.
"""


class Player:
    """
    Represents a player character in the game.

    Attributes:
        name (str): The player's name.
        clan (str): The player's clan.
        position (tuple): The player's (x, y) position.
        xp (int): The player's experience points.
        level (int): The player's current level.
        inventory (dict): The player's inventory with item quantities.
    """

    def __init__(self, name, clan="Lostclan"):
        """
        Initializes a new Player instance.

        Args:
            name (str): The player's name.
            clan (str, optional): The player's clan. Defaults to "Lostclan".
        """
        self.name = name
        self.clan = clan
        self.position = (0, 0)
        self.xp = 0
        self.level = 1
        self.inventory = {}  # Dictionary for item quantities

    def move(self, direction, bounds=None):
        """
        Moves the player in the specified direction, optionally checking map bounds.

        Args:
            direction (str): Direction to move ("up", "down", "left", "right").
            bounds (tuple, optional): (min_x, max_x, min_y, max_y) for boundary checks.

        Returns:
            None
        """
        x, y = self.position
        if direction == "up":
            new_pos = (x, y + 1)
        elif direction == "down":
            new_pos = (x, y - 1)
        elif direction == "left":
            new_pos = (x - 1, y)
        elif direction == "right":
            new_pos = (x + 1, y)
        else:
            print(f"Invalid direction: {direction}")
            return

        # Boundary check if bounds are provided
        if bounds:
            min_x, max_x, min_y, max_y = bounds
            if not (min_x <= new_pos[0] <= max_x and min_y <= new_pos[1] <= max_y):
                print(f"Cannot move outside bounds: {bounds}")
                return

        self.position = new_pos
        print(f"{self.name} moved {direction} to {self.position}")

    def gain_xp(self, amount):
        """
        Adds experience points to the player and checks for level up.

        Args:
            amount (int): Amount of XP to add. Must be non-negative.

        Returns:
            None
        """
        if amount < 0:
            print("Cannot gain negative XP.")
            return
        self.xp += amount
        print(f"{self.name} gained {amount} XP! Total XP: {self.xp}")
        self.check_level_up()

    def check_level_up(self):
        """
        Checks if the player has enough XP to level up and increases level accordingly.

        Returns:
            None
        """
        # Level up as many times as possible
        while self.xp >= self.level * 50:
            xp_needed = self.level * 50
            self.xp -= xp_needed
            self.level += 1
            print(f"{self.name} leveled up! Now Level {self.level}")

    def add_item(self, item, quantity=1):
        """
        Adds a specified quantity of an item to the player's inventory.

        Args:
            item (str): The item to add.
            quantity (int, optional): Quantity to add. Must be non-negative.

        Returns:
            None
        """
        if quantity < 0:
            print("Cannot add a negative quantity.")
            return
        self.inventory[item] = self.inventory.get(item, 0) + quantity
        print(f"Added {quantity}x {item} to inventory.")

    def remove_item(self, item, quantity=1):
        """
        Removes a specified quantity of an item from the player's inventory.

        Args:
            item (str): The item to remove.
            quantity (int, optional): Quantity to remove. Must be non-negative.

        Returns:
            None
        """
        if quantity < 0:
            print("Cannot remove a negative quantity.")
            return
        if item in self.inventory and self.inventory[item] >= quantity:
            self.inventory[item] -= quantity
            if self.inventory[item] <= 0:
                del self.inventory[item]
            print(f"Removed {quantity}x {item} from inventory.")
        else:
            print(f"Not enough {item} to remove.")

    def show_inventory(self):
        """
        Displays the player's inventory and item quantities.

        Returns:
            None
        """
        if not self.inventory:
            print("Inventory is empty.")
        else:
            print("Inventory:")
            for item, qty in self.inventory.items():
                print(f"  {item}: {qty}")
