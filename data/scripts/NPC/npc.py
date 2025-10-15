"""
NPC module for Shattered Fates.

Defines the NPC class, which manages non-player character attributes,
dialogue, and quest offerings.
"""

class NPC:
    """
    Represents a non-player character in the game.

    Attributes:
        name (str): The NPC's name.
        clan (str): The NPC's clan.
        quests (list): List of quests offered by the NPC.
    """
    def __init__(self, name, clan, quests=None):
        """
        Initializes a new NPC instance.

        Args:
            name (str): The NPC's name.
            clan (str): The NPC's clan.
            quests (list, optional): List of quests. Defaults to empty list.
        """
        self.name = name
        self.clan = clan
        self.quests = quests if quests is not None else []

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
            print(f"{self.name} has no quests for you right now.")
            return
        for quest in self.quests:
            print(f"{self.name} offers quest: {quest['name']}")
