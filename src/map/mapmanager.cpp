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