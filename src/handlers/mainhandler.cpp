#include <handlers/mainhandler.hpp>
#include <SFML/Graphics.hpp>
#include <texturemanager.hpp>

void MainHandler::init() {
	
}

void MainHandler::draw(sf::RenderWindow* window) {
	window->clear();

	objects[0]->draw(*window);
	for (auto&& object : this->objects)
		object->draw(*window);

	window->display();
}

void MainHandler::update(sf::RenderWindow* window) {
	for (auto&& object : this->objects)
		object->update();
}
void MainHandler::clear() {
	for (auto&& object : this->objects)
		delete object;
}