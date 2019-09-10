#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <vector>

class TexturePacker {
private:
	sf::Texture& target;
	std::vector<sf::IntRect> occupied;
	int x, y;

	bool is_free(sf::IntRect& area);
public:
	TexturePacker(sf::Texture& target_image);

	sf::IntRect pack(sf::Texture& subimage);
};
