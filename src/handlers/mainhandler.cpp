#include <handlers/mainhandler.hpp>

Location* location;
sf::Texture texture;

void MainHandler::init() {
	TextureManager().load_obstacle("assets/obstacles/1");
	TextureManager().load_obstacle("assets/obstacles/4");

	location = new Location(TextureManager().get("assets/backgrounds/19"), TextureManager().get_obstacles());
	Obstacle* ob = new Obstacle(0, false, false);
	Obstacle* ob2 = new Obstacle(1, false, false);
	location->set_obstacle(0, 0, ob);
	location->set_obstacle(1, 0, ob2);
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