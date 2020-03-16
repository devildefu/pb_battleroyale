#include <handlers/mainhandler.hpp>

Location* location;
sf::Texture texture;

void MainHandler::init(sf::RenderWindow* window) {
	std::string first_loc = helpers::location_path(0, 0);
	if(!helpers::file_exists(first_loc)) {
		SPDLOG_INFO("Map file not found, creating...");

		uint16_t map[LOCATION_BLOCKS_NUMBER];
		std::fill(map, map + LOCATION_BLOCKS_NUMBER, 1);
		location->save(first_loc.c_str(), map);
	}

	if(map.init()) {
		exit(1);
	}
}

void MainHandler::draw(sf::RenderWindow* window) {
	window->clear();

	for(auto&& object : this->objects)
		object->draw(*window);

	map.render(window);

	window->display();
}

void MainHandler::update(sf::RenderWindow* window) {
	for(auto&& object : this->objects)
		object->update();

	map.update(window);
}
void MainHandler::clear() {
	for(auto&& object : this->objects)
		delete object;
}
