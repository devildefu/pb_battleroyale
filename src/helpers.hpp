#pragma once

#include <sys/stat.h>
#include <unistd.h>

namespace Helpers {
	bool file_exists(const char* fname);
}
