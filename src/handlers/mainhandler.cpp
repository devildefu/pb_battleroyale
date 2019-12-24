#include <handlers/mainhandler.hpp>

Location* location;
sf::Texture texture;

void MainHandler::init() {
	if(map.init()) {
		exit(1);
	}

	if(!Helpers::file_exists("assets/locations/0,0.pbmap")) {
		SPDLOG_INFO("Map file not found, creating...");

		uint16_t map[LOCATION_BLOCKS_NUMBER];
		std::fill(map, map + LOCATION_BLOCKS_NUMBER, 1);
		location->save("assets/locations/0,0.pbmap", map);
	}
}

void MainHandler::draw(sf::RenderWindow* window) {
	window->clear();

	for(auto&& object : this->objects)
		object->draw(*window);

	map.render_location(window);

	window->display();
}

void MainHandler::update(sf::RenderWindow* window) {
	for(auto&& object : this->objects)
		object->update();

	map.update_location(window);
}
void MainHandler::clear() {
	for(auto&& object : this->objects)
		delete object;
}
