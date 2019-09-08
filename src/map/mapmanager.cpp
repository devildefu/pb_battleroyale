#include <map/mapmanager.hpp>

void MapManager::update_location(sf::RenderWindow* window) {
    // TODO: Make that the rendering was similar to PB

    Location* current_location = locations[location_x][location_y];

    if(!current_location) {
        // TODO: zmień z polskiego na angielski
        SPDLOG_ERROR("Nie ma w tablicy lokacji x: " + std::to_string(location_x) + " y: " + std::to_string(location_y) + "!");
    } else {
        window->draw(*current_location);
    }
}