#pragma once

#include "location.hpp"
#include <spdlog/spdlog.h>

const int MAXIMUM_LOCATIONS = 1000;

class MapManager {
private:
	int location_x = 0;
	int location_y = 0;

	Location* locations[MAXIMUM_LOCATIONS][MAXIMUM_LOCATIONS];

public:
	MapManager() {}
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
	void add_location_to_array(int x, int y, Location* location) {
		if(!location) {
			SPDLOG_ERROR("location is undefined! Aborting.");
			return;
		}

		if(locations[x][y]) {
			SPDLOG_WARN("Trying to override Location object! x: " + std::to_string(x) + " y: " + std::to_string(y));
			locations[x][y] = location;
		} else {
			SPDLOG_INFO("Adding location to array... x: " + std::to_string(x) + " y: " + std::to_string(y));
			locations[x][y] = location;
		}
	}

	void update_location(sf::RenderWindow* window);
};