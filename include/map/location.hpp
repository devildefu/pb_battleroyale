#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <algorithm>
#include <iterator>
#include <vector>

#include "obstacle.hpp"
#include <spdlog/spdlog.h>

#define MAP_WIDTH  32
#define MAP_HEIGHT 18

class Location {
private:
    Obstacle* obstacles[MAP_WIDTH * MAP_HEIGHT];
public:
    Location();

    ~Location();

    /**
     *  Sets the block type in the array
     */
    void set_obstacle(int x, int y, Obstacle* obstacle);

    void run(sf::RenderWindow* window);

    void update();
};

#endif