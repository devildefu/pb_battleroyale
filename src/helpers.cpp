#include <helpers.hpp>

bool Helpers::file_exists(const char* fname) {
	#ifdef _MSC_VER
		DWORD attr = GetFileAttributesA(fname);
		return (attr != INVALID_FILE_ATTRIBUTES);
	#else
		struct stat buffer;
		return (stat(fname, &buffer) == 0);
	#endif
}
