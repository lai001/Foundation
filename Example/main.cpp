#include <Foundation/Foundation.hpp>
#include <spdlog/spdlog.h>
#include <iostream>
#include <string>

struct MFlag: public fd::BitFlag<int, MFlag>
{
	static const MFlag A;
	static const MFlag B;
	explicit MFlag(int v) :fd::BitFlag<int, MFlag>(v) {}
};

const MFlag MFlag::A = MFlag(1 << 0);
const MFlag MFlag::B = MFlag(1 << 1);

int main(int args, char** argv)
{
	fd::Application::Init(args, argv);

	spdlog::info(fd::Application::getAppDir());
	spdlog::info(fd::Application::getAppPath());
	spdlog::info(fd::Application::getResourceDir());

	MFlag flag = MFlag(0);
	assert(flag.isContains(MFlag::A) == false);

	flag = flag.insert(MFlag::A);
	assert(flag.isContains(MFlag::A));

	flag = MFlag::B;
	assert(flag.isContains(MFlag::B));

	std::cin >> std::string();

    return 0;
}