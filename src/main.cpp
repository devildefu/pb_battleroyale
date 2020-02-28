#include <app.hpp>
#include <handlers/mainhandler.hpp>
#include <spdlog/spdlog.h>

/* 320x180 */

int main(int argc, char* argv[]) {
#ifndef NDEBUG
	spdlog::set_pattern("[%^%l%$] (%@) %v");
#else
	spdlog::set_level(spdlog::level::off);
#endif
	App app;
	app.init();
	app.add_handler("main", new MainHandler);
	app.set_current_eventhandler("main");
	return app.run();
}