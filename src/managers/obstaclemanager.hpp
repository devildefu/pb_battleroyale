#pragma once

#include <map>
#include <filesystem>

#include <managers/texturemanager.hpp>
#include <map/obstacle.hpp>

namespace impl {
class ObstacleManager {
public:
	ObstacleManager(const ObstacleManager&) = delete;
	ObstacleManager(ObstacleManager&&) = delete;
	ObstacleManager& operator=(ObstacleManager&&) = delete;

	static ObstacleManager& instance() {
		static ObstacleManager singleton;
		return singleton;
	}

	void clear();
	bool add(Obstacle obstacle);
	Obstacle& get(int id);
private:
	ObstacleManager();
	~ObstacleManager();

	std::map<int, Obstacle*> obstacles;
};
};

inline impl::ObstacleManager& ObstacleManager() {
	return impl::ObstacleManager::instance();
}