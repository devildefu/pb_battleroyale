#include <handlers/mainhandler.hpp>

Location* location;
sf::Texture texture;

void MainHandler::init() {
	int doggos[7] = {1, 2, 0, 4, 3, 2, 1};
	location = new Location(TextureManager().get("assets/backgrounds/19"), TextureManager().get_obstacles(), doggos, 7);
	location->set_obstacle(1, 1, &ObstacleManager().get(0));
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