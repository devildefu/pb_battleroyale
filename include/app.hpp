#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#include <eventhandler.hpp>

class App {
public:
	App();
	~App();

	int run();

	void add_handler(const std::string& name, EventHandler* handler) {
		handlers.insert({name, handler});
	}

	void set_current_eventhandler(const std::string& name) {
		EventHandler* handler = handlers.find(name)->second;
		
		if(handler) {
			if(current_handler) current_handler->clear();
			current_handler = handler;
			current_handler->init();
		} else {
			// Error
		}
	}
private:
	void handle_events();
	void update();
	void draw();

	sf::RenderWindow* window = NULL;
	std::map<std::string, EventHandler*> handlers;
	EventHandler* current_handler = NULL;
};