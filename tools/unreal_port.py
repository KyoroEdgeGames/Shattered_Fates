// C++ replacement for unreal_port.py
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

static std::vector<std::string> find_files(const fs::path& folder, const std::vector<std::string>& exts) {
	std::vector<std::string> out;
	if (!fs::exists(folder) || !fs::is_directory(folder)) return out;
	for (auto const& entry : fs::recursive_directory_iterator(folder)) {
		if (!entry.is_regular_file()) continue;
		std::string name = entry.path().filename().string();
		std::string lower = name;
		for (auto& c : lower) c = (char)std::tolower(c);
		for (auto const& e : exts) {
			if (lower.size() >= e.size() && lower.rfind(e) == lower.size() - e.size()) {
				out.emplace_back(entry.path().string());
				break;
			}
		}
	}
	return out;
}

static void write_manifest(const fs::path& out_path,
                           const std::vector<std::string>& sprites,
                           const std::vector<std::string>& music,
                           const std::vector<std::string>& sfx) {
	fs::create_directories(out_path.parent_path());
	std::ofstream fh(out_path);
	fh << "{\n";
	auto write_array = [&](const char* key, const std::vector<std::string>& arr, bool last) {
		fh << "  \"" << key << "\": [\n";
		for (size_t i = 0; i < arr.size(); ++i) {
			fh << "    " << "\"" << arr[i] << "\"";
			if (i + 1 < arr.size()) fh << ",";
			fh << "\n";
		}
		fh << "  ]" << (last ? "\n" : ",\n");
	};
	write_array("sprites", sprites, false);
	write_array("music", music, false);
	write_array("sfx", sfx, true);
	fh << "}\n";
}

int main() {
	const fs::path base = fs::current_path();
	const fs::path assets = base / "assets";
	const fs::path sprites = base / "sprites";
	const fs::path music = assets / "Audio" / "music";
	const fs::path sfx = assets / "Audio" / "SFX";
	const fs::path out_dir = base / "export_unreal";
	const fs::path manifest = out_dir / "unreal_manifest.json";

	auto sprites_list = find_files(sprites, {".png", ".jpg", ".jpeg"});
	auto music_list = find_files(music, {".mp3", ".ogg", ".wav", ".flac"});
	auto sfx_list = find_files(sfx, {".mp3", ".ogg", ".wav"});

	write_manifest(manifest, sprites_list, music_list, sfx_list);
	std::cout << "Wrote Unreal manifest to: " << manifest.string() << "\n";
	return 0;
}
