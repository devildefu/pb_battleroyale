#pragma once

#include <sys/stat.h>
#include <unistd.h>

namespace Helpers {
	bool FileExists(const char* fname);
}
