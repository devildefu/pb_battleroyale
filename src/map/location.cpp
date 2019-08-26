#include <map/location.hpp>
#include <cstring>
#include <texturemanager.hpp>

Location::Location() {
    /* Fill everything with NULL */
    memset(obstacles, NULL, sizeof(obstacles));
}

Location::~Location() {
    /* Remove from memory and set to NULL */
    for(Obstacle* obstacle : obstacles) {
        if(obstacle) {
            delete obstacle;
        }
    }

    memset(obstacles, NULL, sizeof(obstacles));
}

void Location::set_obstacle(int x, int y, Obstacle* obstacle) {
    uint16_t pos = x * MAP_HEIGHT + y;

    if(obstacle) {
        obstacles[pos] = obstacle;
    } else {
        SPDLOG_ERROR("Obstacle is undefined!");
    }
}

void Location::run(sf::RenderWindow* window) {
    for(int i=0; i<MAP_WIDTH; i++) {
        for(int j=0; j<MAP_HEIGHT; j++) {
            Obstacle* obstacle = obstacles[i * MAP_HEIGHT + j];

            if(obstacle) {
                sf::Sprite sprite = obstacle->get_sprite();
                if(window) window->draw(sprite);
            }
        }
    }
}

void Location::update() {

}