#include <app.hpp>
#include <spdlog/spdlog.h>

/* 320x180 */

int main(int argc, char* argv[]) {
	App app;
	spdlog::set_pattern("[%^%l%$] (%@) %v");
	return app.run();
}