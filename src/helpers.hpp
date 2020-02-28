#pragma once

#include <string>
#include <fmt/format.h>

#ifdef _MSC_VER
// MSVC doesn't have a unistd.h header
#include <windows.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#endif

#include <map/mapmanager.hpp>

namespace helpers {
	bool file_exists(const std::string& fname);
	std::string location_path(int x, int y);
}
