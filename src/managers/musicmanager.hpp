#pragma once

#include <map>
#include <SFML/Audio.hpp>
#include <spdlog/spdlog.h>

namespace impl {
class MusicManager {
public:
	MusicManager(const MusicManager&) = delete;
	MusicManager(MusicManager&&) = delete;
	MusicManager& operator=(MusicManager&&) = delete;

	static MusicManager& instance() {
		static MusicManager singleton;
		return singleton;
	}

	void load(const std::string& name, const std::string& filename);
	void play(const std::string& name);
private:
	MusicManager() { SPDLOG_INFO("Initialized MusicManager"); }
	~MusicManager();

	std::map<std::string, sf::Music*> musics;
};
};

inline impl::MusicManager& MusicManager() {
	return impl::MusicManager::instance();
}