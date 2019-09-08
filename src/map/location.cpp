#include <map/location.hpp>
#include <cstring>
#include <texturemanager.hpp>

Location::Location() {
    
}

Location::Location(sf::Texture& background, sf::Texture& tileset)
    : background(background),
      tileset(tileset) {
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(MAP_WIDTH * MAP_HEIGHT * 4);
}

void Location::set_obstacle(int x, int y, Obstacle* obstacle) {
    sf::Vertex* quad = &vertices[(x * MAP_WIDTH + y) * 4];
    quad[0].position = sf::Vector2f(x * 10, y * 10);
    quad[1].position = sf::Vector2f((x+1) * 10, y * 10);
    quad[2].position = sf::Vector2f((x+1) * 10, (y+1) * 10);
    quad[3].position = sf::Vector2f(x * 10, (y+1) * 10);

    // TODO: Rework
    quad[0].texCoords = sf::Vector2f(0, 0);
    quad[1].texCoords = sf::Vector2f(32, 0);
    quad[2].texCoords = sf::Vector2f(32, 32);
    quad[3].texCoords = sf::Vector2f(0, 32);
}