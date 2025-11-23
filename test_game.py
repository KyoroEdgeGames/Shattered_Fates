# pyright: reportAttributeAccessIssue=false

try:
    import arcade  # type: ignore[import]
except ImportError:
    # Minimal fallback stub so this file can be opened, type-checked,
    # and run in environments without the `arcade` package installed.
    # The stub implements only the attributes used below.
    import types

    class _Color:
        ASH_GREY = (178, 190, 181)
        RED = (255, 0, 0)

    class _Window:
        def __init__(self, width, height, title):
            self.width = width
            self.height = height
            self.title = title

        # The real `arcade.Window` calls `on_draw` when rendering; provide
        # a no-op run loop that calls `on_draw` once for convenience.
        def show(self):
            if hasattr(self, 'on_draw'):
                self.on_draw()

    def set_background_color(_):
        return None

    def start_render():
        return None

    def draw_rectangle_filled(x, y, width, height, color):
        # Simple text output so the stub does something visible in console.
        print(f"[arcade stub] draw_rectangle_filled: x={x}, y={y}, w={width}, h={height}, color={color}")

    def run():
        print("[arcade stub] run() called — exiting (no GUI available)")

    arcade = types.SimpleNamespace(Window=_Window,
                                   set_background_color=set_background_color,
                                   start_render=start_render,
                                   draw_rectangle_filled=draw_rectangle_filled,
                                   run=run,
                                   color=_Color)


SCREEN_HEIGHT = 600
SCREEN_TITLE = "Cat Game Test"


# Provide a stable base class alias to avoid static analysis issues when
# type stubs for `arcade` define abstract methods on Window.
BaseWindow = getattr(arcade, "Window", object)


class MyGame(BaseWindow):  # type: ignore
    def __init__(self):
        super().__init__(800, SCREEN_HEIGHT, SCREEN_TITLE)
        arcade.set_background_color(arcade.color.ASH_GREY)

    def on_draw(self):
        arcade.start_render()
        arcade.draw_rectangle_filled(400, 300, 50, 50, arcade.color.RED)
        # rest of your code


if __name__ == "__main__":
    game = MyGame()
    # If using the real arcade, `arcade.run()` starts the event loop. For
    # the stub we still call it so scripts behave consistently.
    arcade.run()
