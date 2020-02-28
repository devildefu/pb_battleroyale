#include <helpers.hpp>

bool helpers::file_exists(const std::string& fname) {
	#ifdef _MSC_VER
		DWORD attr = GetFileAttributesA(fname.c_str());
		return (attr != INVALID_FILE_ATTRIBUTES);
	#else
		struct stat buffer;
		return (stat(fname.c_str(), &buffer) == 0);
	#endif
}

std::string helpers::location_path(int x, int y) {
	return fmt::format("{}/{},{}.{}", LOCATION_PATH, x, y, LOCATION_EXT);
}
