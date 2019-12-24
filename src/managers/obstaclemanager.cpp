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

	//SPDLOG_INFO("Adding obstacle, id: {}", id);

	if(obstacles.find(id) == obstacles.end()) {
		obstacles.emplace(id, new Obstacle(obstacle));
		return true;
	}
	return false;
}

Obstacle* impl::ObstacleManager::get(int id) {
	if(obstacles.find(id) != obstacles.end()) {
		return obstacles.at(id);
	}
	SPDLOG_INFO("Obstacle id {} not found", id);
	return nullptr;
}
