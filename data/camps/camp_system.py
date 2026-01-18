// camp_system.cpp
/** camp_system.cpp

Handles clan camp management and kit generation for the Shattered Fates game.
Includes functionality for reading/writing character data, managing camp layout,
and spawning new kits with randomized attributes.
*/

#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using json = nlohmann::json;

static json read_json(const fs::path& p) {
	std::ifstream f(p);
	if (!f.good()) return json::object();
	json j; try { f >> j; } catch (...) { return json::object(); }
	return j;
}
static void write_json(const fs::path& p, const json& j) {
	fs::create_directories(p.parent_path());
	std::ofstream f(p); f << j.dump(2);
}

struct Camp {
	std::string clan_name;
	fs::path structure_file;
	json layout;
	std::vector<std::string> nursery;

	explicit Camp(std::string name)
	    : clan_name(std::move(name)),
	      structure_file(fs::current_path() / "Data" / "Camps" / "camp_structure.json") {
		auto all = read_json(structure_file);
		if (all.contains(clan_name)) layout = all[clan_name];
		else layout = json::object();
		if (layout.contains("Nursery") && layout["Nursery"].is_array()) {
			for (auto const& k : layout["Nursery"]) nursery.push_back(k.get<std::string>());
		}
	}
	json get_space(const std::string& space_name) const {
		if (layout.contains(space_name)) return layout[space_name];
		return json();
	}
	void add_kit_to_nursery(const json& kit_data) {
		const fs::path char_dir = fs::current_path() / "Data" / "Characters";
		const fs::path kit_path = char_dir / (kit_data.value("name", "") + ".json");
		write_json(kit_path, kit_data);
		nursery.push_back(kit_data.value("name", ""));
		std::cout << "Kit " << kit_data.value("name","") << " added to " << clan_name << " nursery.\n";
	}
	std::vector<std::string> list_nursery() const { return nursery; }
};

static std::string generate_kit_name(const std::string& parent1, const std::string& parent2) {
	std::string p1 = parent1.substr(0, std::max<size_t>(1, parent1.size() / 2));
	std::string p2 = parent2.substr(parent2.size() / 2);
	auto now = std::chrono::system_clock::now().time_since_epoch();
	auto us = std::chrono::duration_cast<std::chrono::microseconds>(now).count() % 1000;
	return p1 + p2 + std::to_string(us);
}

static std::vector<std::string> generate_kits(const std::string& mother,
                                              const std::string& father,
                                              const std::string& clan,
                                              int num_kits = 2,
                                              const std::vector<std::string>& sexes = {}) {
	if (num_kits <= 0) throw std::invalid_argument("num_kits must be >= 1");
	if (mother.empty() || father.empty()) throw std::invalid_argument("mother/father required");

	Camp camp(clan);
	std::vector<std::string> out;
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> coin(0, 1);

	for (int i = 0; i < num_kits; ++i) {
		std::string kit_name = generate_kit_name(mother, father);
		std::string sex = (!sexes.empty() && i < (int)sexes.size())
		                    ? sexes[i]
		                    : (coin(rng) ? "male" : "female");
		json kit{
			{"name", kit_name},
			{"clan", clan},
			{"role", "Kit"},
			{"age_stage", "kit"},
			{"sex", sex},
			{"mate", nullptr},
			{"children", json::array()},
			{"romance_flags", json::object()}
		};
		camp.add_kit_to_nursery(kit);
		out.push_back(kit_name);
	}
	// Persist layout nursery
	json structure = read_json(camp.structure_file);
	structure[clan] = camp.layout;
	structure[clan]["Nursery"] = camp.nursery;
	write_json(camp.structure_file, structure);
	return out;
}

int main() {
	auto kits = generate_kits("Ivyclaw", "Brambleheart", "Bloodclan", 2);
	std::cout << "Generated kits:";
	for (auto const& k : kits) std::cout << " " << k;
	std::cout << "\n";
	return 0;
}
