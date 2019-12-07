#include <handlers/mainhandler.hpp>

Location* location;
sf::Texture texture;

void MainHandler::init() {
	// Check if we have map.bin, if not create it
	if(!Helpers::file_exists("map.bin")) {
		SPDLOG_INFO("Map file not found, creating...");
		uint16_t map[MAP_BLOCKS_NUMBER];
		std::fill(map, map+MAP_BLOCKS_NUMBER, 1);
		location->save("map.bin", map);
	}

	location = new Location(TextureManager().get("assets/backgrounds/19"), TextureManager().get_obstacles(), "map.bin");
	map.add_location_to_array(0, 0, location);
}

void MainHandler::draw(sf::RenderWindow* window) {
	window->clear();

	for(auto&& object : this->objects)
		object->draw(*window);

	map.update_location(window);

	window->display();
}

void MainHandler::update(sf::RenderWindow* window) {
	for(auto&& object : this->objects)
		object->update();
}
void MainHandler::clear() {
	for(auto&& object : this->objects)
		delete object;
}
