#include <map/mapmanager.hpp>

void MapManager::update_location(sf::RenderWindow* window) {
	// TODO: Make that the rendering was similar to PB

	uint32_t id = location_y * MAXIMUM_LOCATIONS + location_x;
	Location* current_location = locations[id];

	if(!current_location) {
		SPDLOG_ERROR("There's no location on the location array, x: {}, y: {}!", location_x, location_y);
	} else {
		window->draw(*current_location);
	}
}

void MapManager::add_location_to_array(int x, int y, Location* location) {
	if(!location) {
		SPDLOG_ERROR("location is undefined! Aborting.");
		return;
	}

	uint32_t id = y * MAXIMUM_LOCATIONS + x;

	if(locations[id]) {
		SPDLOG_WARN("Trying to override Location object! x: {}, y: {}", x, y);
		locations[id] = location;
	} else {
		SPDLOG_INFO("Adding location to array... x: {}, y: {}", x, y);
		locations[id] = location;
	}
}