#include <map/location.hpp>

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

    for(auto obstacle : custom_obstacles) {
        if(obstacle) {
            delete obstacle;
        }
    }
    custom_obstacles.clear();
}

void Location::set_obstacle(int x, int y, Obstacle* obstacle) {
    uint16_t pos = x * MAP_HEIGHT + y;

    if(obstacle) {
        obstacles[pos] = obstacle;
    } else {
        //logError("Obstacle is undefined!");
    }
}

void Location::set_collision(int x, int y, bool state) {
    /*
    bool* ptr = (bool*)COLLISION_START;

	for(int i = 0; i < x * MAP_HEIGHT + y; i++) {
		ptr += 0x00000001;
	}

	*ptr = state;
    */
}

void Location::set_shadow(int x, int y, bool state)  {
    /*
    bool* ptr = (bool*)SHADOWS_START;

	for(int i = 0; i < x * MAP_HEIGHT + y; i++) {
		ptr += 0x00000001;
	}

	*ptr = state;
    */
}

void Location::place_obstacle(int x, int y, Obstacle* obstacle) {
    /*
    if(!obstacle) {
        logWarn("Trying to place undefined obstacle! Aborting...");
        return;
    }

    if(obstacle->GetId() > -1) {
        uint16_t* ptr = (uint16_t*)MAP_START;

	    for(int i = 0; i < x * MAP_HEIGHT + y; i++) {
		    ptr += 0x00000001;
	    }

	    *ptr = obstacle->GetId();

        SetCollision(x, y, obstacle->GetCollisionState());
        SetShadow(x, y, obstacle->GetShadowState());
    } else {
        if(!obstacle->GetTexture()) {
            logError("Obstacle's texture is undefined! Aborting.");
            return;
        }

        obstacle->SetPosition(x, y);
        custom_obstacles.push_back(obstacle);

        SetCollision(x, y, obstacle->GetCollisionState());
        SetShadow(x, y, obstacle->GetShadowState());
    }
    */
}

void Location::run() {
    /*
    render = true;

    for(int i=0; i<MAP_WIDTH; i++) {
        for(int j=0; j<MAP_HEIGHT; j++) {
            Obstacle* obstacle = obstacles[i * MAP_HEIGHT + j];

            if(obstacle) {
                PlaceObstacle(i, j, obstacle);
            }
        } 
    }
    */
}

void Location::update() {
    /*
    if(!render) {
        return;
    }

    for(auto obstacle : custom_obstacles) {
        SDL_Rect rect;
        rect.x = obstacle->GetPosition().x * BLOCK_RESOLUTION;
        rect.y = obstacle->GetPosition().y * BLOCK_RESOLUTION;
        rect.w = BLOCK_RESOLUTION;
        rect.h = BLOCK_RESOLUTION;

        detour_UpdateTexture->GetOriginalFunction()(globalTexture, &rect, obstacle->GetTexture()->pixels, obstacle->GetTexture()->pitch);
    }
    */
}