#include <helpers.hpp>

bool Helpers::file_exists(const char* fname) {
	struct stat buffer;
	return (stat(fname, &buffer) == 0);
}
