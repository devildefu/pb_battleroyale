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

	bool load(const std::string& name, const std::string& filename);
	bool play(const std::string& name);
	bool exists(const std::string& name);
	void clear();

	void stop();
	void pause();
	void resume();
	void set_volume(float volume);
private:
	MusicManager() { SPDLOG_INFO("Initialized MusicManager"); }
	~MusicManager();

	std::map<std::string, sf::Music*> musics;
	sf::Music* current_music = nullptr;
	float volume;
};
};

inline impl::MusicManager& MusicManager() {
	return impl::MusicManager::instance();
}