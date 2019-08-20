#include <app.hpp>
#include <spdlog/spdlog.h>
#include <handlers/mainhandler.hpp>

/* 320x180 */

int main(int argc, char* argv[]) {
	spdlog::set_pattern("[%^%l%$] (%@) %v");
	App app;
	app.add_handler("main", new MainHandler);
	app.set_current_eventhandler("main");
	return app.run();
}