#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <spdlog/spdlog.h>
#include <ini.h>

#include <eventhandler.hpp>

typedef struct {
	uint8_t fps;
	uint32_t window_width;
	uint32_t window_height;
} config;

class App {
public:
	App();
	~App();

	int run();

	void add_handler(const std::string& name, EventHandler* handler) {
		SPDLOG_INFO("Adding a new handler. Name: {}", name);
		handlers.insert({name, handler});
	}

	void set_current_eventhandler(const std::string& name) {
		SPDLOG_INFO("Changing current handler to {}", name);
		EventHandler* handler = handlers.find(name)->second;
		
		if(handler) {
			if(current_handler) current_handler->clear();
			current_handler = handler;
			current_handler->init();
			if(current_handler == NULL) {
				SPDLOG_INFO("aaa");
			}
		} else {
			SPDLOG_INFO("Handler doesn't exist");
		}
	}
private:
	void handle_events();
	void update();
	void draw();

	sf::RenderWindow* window = nullptr;
	std::map<std::string, EventHandler*> handlers;
	EventHandler* current_handler = nullptr;
};