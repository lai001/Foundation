#include <Foundation/Foundation.hpp>
#include <spdlog/spdlog.h>
#include <iostream>
#include <string>

struct MFlag: public ks::BitFlag<int, MFlag>
{
	static const MFlag A;
	static const MFlag B;
	explicit MFlag(int v) :ks::BitFlag<int, MFlag>(v) {}
};

const MFlag MFlag::A = MFlag(1 << 0);
const MFlag MFlag::B = MFlag(1 << 1);

int main(int args, char** argv)
{
	ks::Application::Init(args, argv);

	spdlog::info(ks::Application::getAppDir());
	spdlog::info(ks::Application::getAppPath());
	spdlog::info(ks::Application::getResourceDir());

	MFlag flag = MFlag(0);
	assert(flag.isContains(MFlag::A) == false);

	flag = flag.insert(MFlag::A);
	assert(flag.isContains(MFlag::A));

	flag = MFlag::B;
	assert(flag.isContains(MFlag::B));

	long long time = ks::getCurrentMillisecondsTime();
	spdlog::info(time);

	std::cin >> std::string();

    return 0;
}