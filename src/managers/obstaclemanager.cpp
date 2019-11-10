#include "obstaclemanager.hpp"

impl::ObstacleManager::ObstacleManager() {
	SPDLOG_INFO("Initialized ObstacleManager");
}

impl::ObstacleManager::~ObstacleManager() {
	SPDLOG_INFO("Cleaning obstacles");
	clear();
}

void impl::ObstacleManager::clear() {
	for(auto&& [key, val] : this->obstacles) {
		delete val;
	}
}

bool impl::ObstacleManager::add(Obstacle obstacle) {
	int id = obstacle.get_id();

	SPDLOG_INFO("Adding obstacle, id: {}", id);

	if(obstacles.find(id) == obstacles.end()) {
		obstacles[id] = new Obstacle(obstacle);
	} else {
		return true;
	}
}

Obstacle& impl::ObstacleManager::get(int id) {
	if(obstacles.find(id) != obstacles.end()) {
		return *obstacles[id];
	}
}