#include <Foundation/Foundation.hpp>
#include <spdlog/spdlog.h>
#include <iostream>
#include <string>

int main(int args, char** argv)
{
	fd::Application::Init(args, argv);

	spdlog::info(fd::Application::getAppDir());
	spdlog::info(fd::Application::getAppPath());
	spdlog::info(fd::Application::getResourceDir());


	std::cin >> std::string();

    return 0;
}