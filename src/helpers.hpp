#pragma once
#ifdef _MSC_VER
// MSVC doesn't have a unistd.h header
#include <windows.h>
#else
#include <unistd.h>
#include <sys/stat.h>
#endif

namespace Helpers {
	bool file_exists(const char* fname);
}
