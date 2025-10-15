# pyright: reportAttributeAccessIssue=false

import arcade

SCREEN_HEIGHT = 600
SCREEN_TITLE = "Cat Game Test"

class MyGame(arcade.Window):
    def __init__(self):
        super().__init__(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE)
        arcade.set_background_color(arcade.color.ASH_GREY)

    def on_draw(self):
        arcade.start_render()
        arcade.draw_rectangle_filled(400, 300, 50, 50, arcade.color.RED)


if __name__ == "__main__":
    game = MyGame()
    arcade.run()
