#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Perypetie Boba Battle Royale");

	while(window.isOpen()) {
		sf::Event e;
		while(window.pollEvent(e)) {
			if(e.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
}