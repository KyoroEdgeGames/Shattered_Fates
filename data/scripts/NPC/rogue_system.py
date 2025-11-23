"""
Rogue trader system for Shattered Fates.

Defines the RogueTrader class, which allows players to buy items from a trader NPC.
"""


class RogueTrader:
    """
    Represents a rogue trader NPC who sells items to the player.

    Attributes:
        name (str): The trader's name.
        items_for_sale (dict): Items for sale with their prices and stock quantities.
    """

    def __init__(self, name="Wandering Rogue"):
        """
        Initializes the RogueTrader with a name and items for sale.
        """
        self.name = name
        # Now each item is a tuple: (price, stock)
        self.items_for_sale = {
            "Herb": [5, 10],
            "Mouse Tail": [3, 5],
            "Stone Claw": [8, 2],
        }

    def display_stock(self):
        """
        Displays the items currently for sale.

        Returns:
            None
        """
        print(f"{self.name} offers items:")
        for item, (price, stock) in self.items_for_sale.items():
            print(f"  {item} - {price} coins (Stock: {stock})")

    def restock_item(self, item, price, quantity):
        """
        Adds or updates an item in the trader's stock.

        Args:
            item (str): The item name.
            price (int): The price per item.
            quantity (int): The quantity to restock.

        Returns:
            None
        """
        if not isinstance(price, int) or price < 0:
            print("Price must be a non-negative integer.")
            return
        if not isinstance(quantity, int) or quantity < 0:
            print("Quantity must be a non-negative integer.")
            return
        self.items_for_sale[item] = [price, quantity]
        print(f"{item} restocked at {price} coins, quantity: {quantity}.")

    def trade(self, player):
        """
        Facilitates trading between the rogue trader and the player.

        Args:
            player: The player object.
                Expected to have:
                - an inventory dictionary
                - a 'currency' attribute

        Returns:
            None
        """
        # Check for inventory attribute
        if not hasattr(player, "inventory"):
            print("Player does not have an inventory attribute.")
            return
        if not isinstance(player.inventory, dict):
            print("Player inventory must be a dictionary.")
            return

        # Check for currency attribute
        if not hasattr(player, "currency"):
            print("Player does not have a currency attribute.")
            return
        if not isinstance(player.currency, int):
            print("Player currency must be an integer.")
            return

        while True:
            self.display_stock()
            print(f"Your inventory: {player.inventory}")
            print(f"Your coins: {player.currency}")

            choice = input("Enter item you want to buy " "(or 'exit'): ").strip()
            if choice.lower() == "exit":
                print("Exiting trade...")
                break

            if choice in self.items_for_sale:
                price, stock = self.items_for_sale[choice]
                if player.currency < price:
                    print("Not enough coins to buy this item.")
                    continue

                # Ask for quantity
                try:
                    quantity = int(input(f"How many {choice}s do you want to buy? "))
                    if quantity < 1:
                        print("Quantity must be at least 1.")
                        continue
                except ValueError:
                    print("Invalid quantity.")
                    continue

                if quantity > stock:
                    print(f"Not enough stock. Only {stock} available.")
                    continue

                total_cost = price * quantity
                if player.currency < total_cost:
                    print("Not enough coins for that quantity.")
                    continue

                # Add item(s) to inventory
                player.inventory[choice] = player.inventory.get(choice, 0) + quantity
                player.currency -= total_cost
                self.items_for_sale[choice][1] -= quantity
                print(
                    f"{quantity}x {choice} added to inventory "
                    f"for {total_cost} coins!"
                )

                # Remove item from trader's stock if out of stock
                if self.items_for_sale[choice][1] == 0:
                    del self.items_for_sale[choice]

            else:
                print("Item not available. " "Please choose from the listed items.")


class NPC:
    """
    Represents a non-player character in the game.

    Attributes:
        name (str): The NPC's name.
        clan (str): The NPC's clan.
        role (str): The NPC's role.
        age_stage (str): The NPC's age stage.
        sex (str): The NPC's sex.
        mate (str or None): The NPC's mate.
        children (list): The NPC's children.
        quests (list): Quests offered by the NPC.
        data (dict): Raw data dictionary.
    """

    def __init__(self, data):
        # data can be dict loaded from character JSON
        self.name = data.get("name")
        self.clan = data.get("clan")
        self.role = data.get("role", "Warrior")
        self.age_stage = data.get("age_stage", "warrior")
        self.sex = data.get("sex", "female")
        self.mate = data.get("mate", None)
        self.children = data.get("children", [])
        self.quests = data.get("quests", [])
        self.data = data

    def talk(self):
        """
        Prints a greeting from the NPC.

        Returns:
            None
        """
        print(f"{self.name} of {self.clan} says: Hello, traveler!")

    def offer_quests(self):
        """
        Displays the quests offered by the NPC.

        Returns:
            None
        """
        if not self.quests:
            print(f"{self.name} has no quests right now.")
            return
        for q in self.quests:
            print(f"{self.name} offers: {q['name']}")

    def can_have_kits(self):
        """
        Determines if the NPC is eligible to have kits (children).

        Returns:
            bool: True if the NPC can have kits, False otherwise.
        """
        return self.age_stage in ("warrior", "elder") and self.role != "Medicine Cat"
        # optional rule
