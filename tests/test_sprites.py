import os
import pytest

from main import list_sprites, sprite_path, load_sprite, SPRITE_DIR


def test_list_sprites_nonempty():
    lst = list_sprites()
    assert isinstance(lst, list)
    assert len(lst) > 0


def test_sprite_path_exists():
    sprites = list_sprites()
    assert sprites
    p = sprite_path(sprites[0])
    assert p and os.path.exists(p)


def test_load_sprite_returns_value():
    sprites = list_sprites()
    if not sprites:
        pytest.skip("no sprites available in project")
    res = load_sprite(sprites[0])
    # Should return either a path string or an arcade texture object; at minimum not None
    assert res is not None
