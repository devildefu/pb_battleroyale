#include <helpers.hpp>

bool Helpers::FileExists(const char* fname) {
	struct stat buffer;
	return (stat(fname, &buffer) == 0);
}
