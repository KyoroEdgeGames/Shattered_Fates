// C++ replacement for unreal_export.py (requires nlohmann/json.hpp)
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using json = nlohmann::json;

static void ensure_dirs(const fs::path& dt, const fs::path& jj) {
	fs::create_directories(dt);
	fs::create_directories(jj);
}

static json read_json(const fs::path& p) {
	json j;
	std::ifstream f(p);
	if (!f.good()) return json();
	try { f >> j; } catch (...) { return json(); }
	return j;
}

static void write_json(const fs::path& p, const json& j) {
	fs::create_directories(p.parent_path());
	std::ofstream f(p);
	f << j.dump(2);
}

static void write_csv(const fs::path& p, const std::vector<std::unordered_map<std::string, std::string>>& rows) {
	if (rows.empty()) return;
	std::set<std::string> header_set;
	for (auto const& r : rows) for (auto const& kv : r) header_set.insert(kv.first);
	std::vector<std::string> header(header_set.begin(), header_set.end());
	fs::create_directories(p.parent_path());
	std::ofstream f(p);
	// header
	for (size_t i = 0; i < header.size(); ++i) {
		if (i) f << ",";
		f << header[i];
	}
	f << "\n";
	// rows
	for (auto const& r : rows) {
		for (size_t i = 0; i < header.size(); ++i) {
			if (i) f << ",";
			auto it = r.find(header[i]);
			if (it != r.end()) {
				// naive CSV escaping
				std::string v = it->second;
				bool needs_quote = v.find_first_of(",\"\n") != std::string::npos;
				if (needs_quote) {
					std::string q; q.reserve(v.size() + 2);
					q.push_back('"');
					for (char c : v) { if (c == '"') q += "\"\""; else q.push_back(c); }
					q.push_back('"');
					f << q;
				} else {
					f << v;
				}
			}
		}
		f << "\n";
	}
}

static std::string serialize_map(const json& m) {
	if (!m.is_object()) return "";
	std::vector<std::string> kvs;
	for (auto it = m.begin(); it != m.end(); ++it) {
		kvs.emplace_back(it.key() + ":" + it.value().dump());
	}
	std::sort(kvs.begin(), kvs.end());
	std::string out;
	for (size_t i = 0; i < kvs.size(); ++i) {
		if (i) out += ";";
		out += kvs[i];
	}
	return out;
}

static std::string serialize_list(const json& arr) {
	if (!arr.is_array()) return "";
	std::string out;
	for (size_t i = 0; i < arr.size(); ++i) {
		if (i) out += ";";
		out += arr[i].dump();
	}
	return out;
}

// Exporters (mirror Python structure; tolerate missing files)
static void export_characters(const fs::path& base, const fs::path& dt, const fs::path& jj) {
	auto data = read_json(base / "data" / "Characters" / "characters.json");
	std::vector<std::unordered_map<std::string, std::string>> rows;
	for (auto const& c : data) {
		std::unordered_map<std::string, std::string> row;
		row["name"] = c.value("name", "");
		row["playable"] = c.value("playable", false) ? "true" : "false";
		row["clan"] = c.value("clan", "");
		row["age_stage"] = c.value("age_stage", "");
		row["story_arc"] = c.value("story_arc", "");
		row["alignment_tendency"] = c.value("alignment_tendency", "");
		row["skills"] = serialize_list(c.value("skills", json::array()));
		row["traits_flat"] = serialize_map(c.value("traits", json::object()));
		rows.emplace_back(std::move(row));
	}
	write_csv(dt / "Characters.csv", rows);
	write_json(jj / "Characters.json", json{ {"type","characters"}, {"rows", data} });
}

static void export_quests(const fs::path& base, const fs::path& dt, const fs::path& jj) {
	auto data = read_json(base / "data" / "Quests" / "quests.json");
	std::vector<std::unordered_map<std::string, std::string>> rows;
	for (auto const& q : data) {
		json rewards = q.value("rewards", json::object());
		std::unordered_map<std::string, std::string> row;
		row["id"] = q.value("id", "");
		row["name"] = q.value("name", "");
		row["description"] = q.value("description", "");
		row["required_age"] = q.value("required_age", "");
		row["alignment"] = q.value("alignment", "");
		row["story_arc"] = q.value("story_arc", "");
		row["story_stage"] = std::to_string(q.value("story_stage", 0));
		row["rewards_xp"] = std::to_string(rewards.value("xp", 0));
		row["rewards_skill_unlock"] = rewards.value("skill_unlock", "");
		row["rewards_alignment_shift"] = rewards.value("alignment_shift", "");
		row["rewards_alignment_choice"] = serialize_list(rewards.value("alignment_choice", json::array()));
		row["rewards_reputation_gain"] = serialize_map(rewards.value("reputation_gain", json::object()));
		row["npc_involved"] = serialize_list(q.value("npc_involved", json::array()));
		rows.emplace_back(std::move(row));
	}
	write_csv(dt / "Quests.csv", rows);
	write_json(jj / "Quests.json", json{ {"type","quests"}, {"rows", data} });
}

static void export_clans(const fs::path& base, const fs::path& dt, const fs::path& jj) {
	auto data = read_json(base / "data" / "Clans" / "clans.json");
	std::vector<std::unordered_map<std::string, std::string>> rows;
	if (data.is_object()) {
		for (auto it = data.begin(); it != data.end(); ++it) {
			const std::string& name = it.key();
			const json& c = it.value();
			std::unordered_map<std::string, std::string> row;
			row["name"] = name;
			row["leader"] = c.value("leader", "");
			row["medicine_cat"] = c.value("medicine_cat", "");
			row["warriors"] = serialize_list(c.value("warriors", json::array()));
			row["territory"] = c.value("territory", "");
			row["traits_flat"] = serialize_map(c.value("traits", json::object()));
			rows.emplace_back(std::move(row));
		}
	}
	write_csv(dt / "Clans.csv", rows);
	write_json(jj / "Clans.json", json{ {"type","clans"}, {"rows", data} });
}

static void export_items(const fs::path& base, const fs::path& dt, const fs::path& jj) {
	auto data = read_json(base / "data" / "scripts" / "Inventory" / "items.json");
	std::vector<std::unordered_map<std::string, std::string>> rows;
	for (auto const& it : data) {
		std::unordered_map<std::string, std::string> row;
		row["id"] = it.value("id", it.value("name", ""));
		row["name"] = it.value("name", "");
		row["type"] = it.value("type", "");
		row["description"] = it.value("description", "");
		row["value"] = std::to_string(it.value("value", 0));
		row["attack"] = std::to_string(it.value("attack", 0));
		row["durability"] = std::to_string(it.value("durability", 0));
		json effect = it.value("effect", json());
		row["effect_flat"] = effect.is_object() ? serialize_map(effect) : effect.dump();
		rows.emplace_back(std::move(row));
	}
	write_csv(dt / "Items.csv", rows);
	write_json(jj / "Items.json", json{ {"type","items"}, {"rows", data} });
}

static void export_herbs(const fs::path& base, const fs::path& dt, const fs::path& jj) {
	auto data = read_json(base / "data" / "scripts" / "Inventory" / "Herbs.json");
	std::vector<std::unordered_map<std::string, std::string>> rows;
	for (auto const& h : data) {
		std::unordered_map<std::string, std::string> row;
		row["id"] = h.value("id", h.value("name", ""));
		row["name"] = h.value("name", "");
		row["description"] = h.value("description", "");
		row["rarity"] = h.value("rarity", "");
		row["effects_flat"] = serialize_map(h.value("effects", json::object()));
		rows.emplace_back(std::move(row));
	}
	write_csv(dt / "Herbs.csv", rows);
	write_json(jj / "Herbs.json", json{ {"type","herbs"}, {"rows", data} });
}

static void export_skills(const fs::path& base, const fs::path& dt, const fs::path& jj) {
	auto data = read_json(base / "data" / "Skills" / "skills.json");
	std::vector<std::unordered_map<std::string, std::string>> rows;
	for (auto const& s : data) {
		std::unordered_map<std::string, std::string> row;
		row["name"] = s.value("name", "");
		row["level_required"] = std::to_string(s.value("level_required", 0));
		row["effect"] = s.value("effect", "");
		rows.emplace_back(std::move(row));
	}
	write_csv(dt / "Skills.csv", rows);
	write_json(jj / "Skills.json", json{ {"type","skills"}, {"rows", data} });
}

static void export_asset_manifest(const fs::path& base, const fs::path& out_dir) {
	const fs::path assets = base / "assets";
	const fs::path sprites = base / "sprites";
	const fs::path music = assets / "Audio" / "music";
	const fs::path sfx = assets / "Audio" / "SFX";

	auto find_files = [](const fs::path& folder, const std::vector<std::string>& exts) {
		std::vector<std::string> out;
		if (!fs::exists(folder)) return out;
		for (auto const& e : fs::recursive_directory_iterator(folder)) {
			if (!e.is_regular_file()) continue;
			std::string name = e.path().filename().string();
			std::string lower = name;
			for (auto& c : lower) c = (char)std::tolower(c);
			for (auto const& ext : exts) {
				if (lower.size() >= ext.size() && lower.rfind(ext) == lower.size() - ext.size()) {
					out.emplace_back(e.path().string());
					break;
				}
			}
		}
		return out;
	};

	json manifest{
		{"sprites", find_files(sprites, {".png", ".jpg", ".jpeg"})},
		{"music", find_files(music, {".mp3", ".ogg", ".wav", ".flac"})},
		{"sfx", find_files(sfx, {".mp3", ".ogg", ".wav"})},
	};
	write_json(out_dir / "unreal_manifest.json", manifest);
}

int main() {
	const fs::path base = fs::current_path();
	const fs::path out_dir = base / "export_unreal";
	const fs::path dt_dir = out_dir / "data_tables";
	const fs::path jj_dir = out_dir / "json";
	ensure_dirs(dt_dir, jj_dir);

	export_characters(base, dt_dir, jj_dir);
	export_quests(base, dt_dir, jj_dir);
	export_clans(base, dt_dir, jj_dir);
	export_items(base, dt_dir, jj_dir);
	export_herbs(base, dt_dir, jj_dir);
	export_skills(base, dt_dir, jj_dir);
	export_asset_manifest(base, out_dir);

	std::cout << "Unreal export complete.\n";
	return 0;
}
