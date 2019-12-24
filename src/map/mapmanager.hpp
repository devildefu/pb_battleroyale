#pragma once

#include <filesystem>
#include <fstream>
#include <cstdio>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include <helpers.hpp>
#include <managers/texturemanager.hpp>
#include "location.hpp"

// It is useful for reducing the use of RAM
constexpr uint16_t MAXIMUM_LOCATIONS = 1000;

static char LOCATION_PATH[] = "assets/locations/";
static char LOCATION_EXT[] = "pbmap";
static char LOCATION_DEFAULT_BACKGROUND[] = "assets/backgrounds/19";

// Calculates offset from beginning of the array
#define LOC_POS(x, y) y * MAXIMUM_LOCATIONS + x;

namespace fs = std::filesystem;

class MapManager {
public:
	MapManager() {
		// An empty array can have data from RAM, so we need to fill it with something
		std::fill(locations, locations + (MAXIMUM_LOCATIONS * MAXIMUM_LOCATIONS), nullptr);
	}

	~MapManager() {}

	bool init();

	int get_location_x() { return location_x; }
	int get_location_y() { return location_y; }

	void set_location(int location_x, int location_y) {
		if(location_x > -1)
			this->location_x = location_x;
		if(location_y > -1)
			this->location_y = location_y;
	}

	bool load_location(int x, int y, const std::string& path, sf::Texture& background);
	void add_location_to_array(int x, int y, Location* location);

	void update_location(sf::RenderWindow* window);
	void render_location(sf::RenderWindow* window);
private:
	uint16_t location_x = 0;
	uint16_t location_y = 0;

	Location* locations[MAXIMUM_LOCATIONS * MAXIMUM_LOCATIONS];
};