#include "texturepacker.hpp"

TexturePacker::TexturePacker(sf::Texture& target_image)
	: target(target_image), occupied(), x(0), y(0) {}

bool TexturePacker::is_free(sf::IntRect& area) {
	for(int i = occupied.size() - 1; i > 0; --i) {
		if(area.intersects(occupied.at(i))) {
			return false;
		}
	}
	return true;
}

sf::IntRect TexturePacker::pack(sf::Texture &subimage) {
	while(y <= target.getSize().y - subimage.getSize().y) {
		while(x <= target.getSize().x - subimage.getSize().x) {
			bool skip = false;
			for(auto &area : occupied) {
				if(area.contains(x, y)) {
					x = area.left + area.width;
					skip = true;
					break;
				}
			}
			if(!skip) {
				sf::IntRect area(x, y, subimage.getSize().x, subimage.getSize().y);
				if(is_free(area)) {
					target.update(subimage, x, y);
					occupied.push_back(area);
					return area;
				}
				++x;
			}
		}
		x = 0;
		++y;
	}
	if(y > target.getSize().y - subimage.getSize().y) {
		x = 0;
		y = 0;
	}
}
