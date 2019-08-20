#include <handlers/mainhandler.hpp>

void MainHandler::draw(sf::RenderWindow* window) {
	window->clear();
	SPDLOG_INFO("aaa");
	window->display();
}