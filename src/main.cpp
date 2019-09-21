#include <app.hpp>
#include <handlers/mainhandler.hpp>
#include <spdlog/spdlog.h>

/* 320x180 */

int main(int argc, char* argv[]) {
	spdlog::set_pattern("[%^%l%$] (%@) %v");
	App app;
	app.add_handler("main", new MainHandler);
	app.set_current_eventhandler("main");
	return app.run();
}