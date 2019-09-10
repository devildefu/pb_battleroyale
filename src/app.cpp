#include <app.hpp>

App::App()
	: window(new sf::RenderWindow(sf::VideoMode(1280, 720), "Perypetie Boba Battle Royale")) {
	this->window->setView(sf::View(sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(320, 180))));
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

			case sf::Event::Resized:
				{
					sf::View window_view = window->getView();
					float window_ratio = window->getSize().x / (float) window->getSize().y;
					float view_ratio = window_view.getSize().x / (float) window_view.getSize().y;

					float size_x = 1;
					float size_y = 1;
					float pos_x = 0;
					float pos_y = 0;

					bool horizontal_spacing = true;
					if(window_ratio < view_ratio) {
						horizontal_spacing = false;
					}

					if(horizontal_spacing) {
						size_x = view_ratio / window_ratio;
						pos_x = (1 - size_x) / 2.f;
					} else {
						size_y = window_ratio / view_ratio;
						pos_y = (1 - size_y) / 2.f;
					}

					window_view.setViewport(sf::FloatRect(pos_x, pos_y, size_x, size_y));
					window->setView(window_view);
				}
				break;

			default:
				break;
		}
	}
}

void App::update() {
	if(current_handler)
		current_handler->update(window);
}

void App::draw() {
	if(current_handler)
		current_handler->draw(window);
}
