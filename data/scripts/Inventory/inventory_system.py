"""
Inventory system module for Shattered Fates.

Provides the Inventory class to manage a player's items and their quantities.
"""

class Inventory:
    """
    Manages a collection of items and their quantities for a player.

    Attributes:
        items (dict): Dictionary storing item names and their quantities.
    """
    def __init__(self):
        """
        Initializes an empty inventory.
        """
        self.items = {}  # Store items as {item_name: quantity}

    def add_item(self, item, quantity=1):
        """
        Adds a specified quantity of an item to the inventory.

        Args:
            item (str): The name of the item to add.
            quantity (int, optional): The quantity to add. Must be a non-negative integer.

        Returns:
            None
        """
        if not isinstance(quantity, int) or quantity < 0:
            print("Cannot add non-integer or negative quantity.")
            return
        self.items[item] = self.items.get(item, 0) + quantity
        print(f"Added {quantity}x {item} to inventory.")

    def remove_item(self, item, quantity=1):
        """
        Removes a specified quantity of an item from the inventory.

        Args:
            item (str): The name of the item to remove.
            quantity (int, optional): The quantity to remove. Must be a non-negative integer.

        Returns:
            None
        """
        if not isinstance(quantity, int) or quantity < 0:
            print("Cannot remove non-integer or negative quantity.")
            return
        if item in self.items:
            if self.items[item] >= quantity:
                self.items[item] -= quantity
                if self.items[item] == 0:
                    del self.items[item]
                print(f"Removed {quantity}x {item} from inventory.")
            else:
                print(f"Not enough {item} to remove.")
        else:
            print(f"{item} not found in inventory.")

    def show_inventory(self):
        """
        Prints the inventory contents and their quantities.

        Returns:
            None
        """
        if not self.items:
            print("Inventory is empty.")
        else:
            print("Inventory:")
            for item, qty in self.items.items():
                print(f"  {item}: {qty}")

    def get_inventory(self):
        """
        Returns a copy of the inventory dictionary.

        Returns:
            dict: The inventory items and their quantities.
        """
        return dict(self.items)

    def clear_inventory(self):
        """
        Removes all items from the inventory.

        Returns:
            None
        """
        self.items.clear()
        print("Inventory cleared.")

    def has_item(self, item):
        """
        Checks if an item exists in the inventory.

        Args:
            item (str): The name of the item to check.

        Returns:
            bool: True if the item exists, False otherwise.
        """
        return item in self.items

    def get_quantity(self, item):
        """
        Gets the quantity of a specific item in the inventory.

        Args:
            item (str): The name of the item.

        Returns:
            int: The quantity of the item, or 0 if not present.
        """
        return self.items.get(item, 0)
