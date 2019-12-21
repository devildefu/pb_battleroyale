#pragma once

#include "location.hpp"
#include <spdlog/spdlog.h>

// It is useful for reducing the use of RAM
constexpr uint16_t MAXIMUM_LOCATIONS = 1000;

class MapManager {
private:
	uint16_t location_x = 0;
	uint16_t location_y = 0;

	Location* locations[MAXIMUM_LOCATIONS * MAXIMUM_LOCATIONS];

public:
	MapManager() {
		// An empty array can have data from RAM, so we need to fill it with something
		std::fill(locations, locations + (MAXIMUM_LOCATIONS * MAXIMUM_LOCATIONS), nullptr);
	}

	~MapManager() {}

	/**
     *  Return location X
     */
	int get_location_x() { return location_x; }

	/**
     *  Return location Y
     */
	int get_location_y() { return location_y; }

	/**
     *  Set location X and location Y
     */
	void set_location(int location_x, int location_y) {
		if(location_x > -1)
			this->location_x = location_x;
		if(location_y > -1)
			this->location_y = location_y;
	}

	/**
     *  Add Location object to array
     */
	void add_location_to_array(int x, int y, Location* location);

	void update_location(sf::RenderWindow* window);
};