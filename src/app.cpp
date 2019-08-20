#include <app.hpp>

App::App() 
	: window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Perypetie Boba Battle Royale")) { 
	SPDLOG_INFO("Initializing game");
}

App::~App() {
	SPDLOG_INFO("Cleaning");

	for(auto handler : handlers) {
		delete handler.second;
	}
	handlers.clear();

	if(window)
		delete window;
}

int App::run() {
	while(window->isOpen()) {
		handle_events();

		update();
		draw();
	}

	return 0;
}

void App::handle_events() {
	sf::Event e;
	if(window->pollEvent(e)) {
		switch(e.type) {
			case sf::Event::Closed:
				SPDLOG_INFO("Received window close event");
				if(current_handler) 
					current_handler->event_quit(window);
				else
					window->close();
				break;

			default:
				break;
		}
	}
}

void App::update() {
	if(current_handler)
		current_handler->update();
}

void App::draw() {
	if(current_handler)
		current_handler->draw();
}
