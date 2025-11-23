"""
Small helper to export asset metadata for Unreal Engine import.
Writes a JSON manifest with source file paths and suggested import names.
"""
from __future__ import annotations

import json
import os
from typing import Dict, List

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASSETS = os.path.join(BASE_DIR, "assets")
SPRITES = os.path.join(BASE_DIR, "sprites")
MUSIC = os.path.join(ASSETS, "Audio", "music")
SFX = os.path.join(ASSETS, "Audio", "SFX")
OUT = os.path.join(BASE_DIR, "export_unreal")


def find_files(folder: str, exts: List[str]) -> List[str]:
    out: List[str] = []
    if not os.path.isdir(folder):
        return out
    for root, _dirs, files in os.walk(folder):
        for f in files:
            if any(f.lower().endswith(e) for e in exts):
                out.append(os.path.join(root, f))
    return out


def build_manifest() -> Dict[str, List[str]]:
    os.makedirs(OUT, exist_ok=True)
    sprites = find_files(SPRITES, [".png", ".jpg", ".jpeg"])
    music = find_files(MUSIC, [".mp3", ".ogg", ".wav", ".flac"])
    sfx = find_files(SFX, [".mp3", ".ogg", ".wav"]) 
    return {"sprites": sprites, "music": music, "sfx": sfx}


def write_manifest(manifest: Dict[str, List[str]]) -> str:
    path = os.path.join(OUT, "unreal_manifest.json")
    with open(path, "w", encoding="utf-8") as fh:
        json.dump(manifest, fh, indent=2)
    return path


if __name__ == "__main__":
    m = build_manifest()
    p = write_manifest(m)
    print("Wrote Unreal manifest to:", p)
