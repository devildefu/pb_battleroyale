#include <app.hpp>
#include <spdlog/spdlog.h>

/* 320x180 */

int main(int argc, char* argv[]) {
	spdlog::set_pattern("[%^%l%$] (%@) %v");
	App app;
	return app.run();
}