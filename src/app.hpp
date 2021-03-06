#pragma once

#include <SFML/Graphics.hpp>
#include <ini.h>
#include <map>
#include <spdlog/spdlog.h>
#include <string>

#include <eventhandler.hpp>
#include <managers/texturemanager.hpp>
#include <managers/musicmanager.hpp>
#include <helpers.hpp>

typedef struct {
	uint8_t fps;
	uint32_t window_width;
	uint32_t window_height;
	bool music;
} config;

class App {
public:
	App();
	~App();

	void init();
	int run();

	void add_handler(const std::string& name, EventHandler* handler) {
		SPDLOG_INFO("Adding a new handler. Name: {}", name);
		handlers.insert({ name, handler });
	}

	void set_current_eventhandler(const std::string& name) {
		SPDLOG_INFO("Changing current handler to {}", name);
		EventHandler* handler = handlers.find(name)->second;

		if(handler) {
			if(current_handler) current_handler->clear();
			current_handler = handler;
			current_handler->init(window);
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