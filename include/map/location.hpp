#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <algorithm>
#include <iterator>
#include <vector>

#include <map/obstacle.hpp>

#define MAP_WIDTH  32
#define MAP_HEIGHT 18

class Location {
private:
    Obstacle* obstacles[MAP_WIDTH * MAP_HEIGHT - 1];
    std::vector<Obstacle*> custom_obstacles;

    bool render = false;

    void set_collision(int x, int y, bool state);
    void set_shadow(int x, int y, bool state);
public:
    Location();

    ~Location();
    
    /**
     *  Sets the block type in the array
     */
    void set_obstacle(int x, int y, Obstacle* obstacle);
    
    void place_obstacle(int x, int y, Obstacle* obstacle);

    /**
     *  Modify current location
     */
    void run();

    void update();

    void set_render_state(bool state) { render = state; }
};

#endif