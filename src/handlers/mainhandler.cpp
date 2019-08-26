#include <handlers/mainhandler.hpp>

Location* location;
sf::Texture texture;

void MainHandler::init() {
	location = new Location;
	Obstacle* ob = new Obstacle(TextureManager().get("test"), false, false);
	location->set_obstacle(0, 0, ob);
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