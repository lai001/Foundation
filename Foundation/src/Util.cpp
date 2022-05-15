#include "Util.hpp"

namespace ks
{
	std::function<double()> measue(bool fps) noexcept
	{
		double begin = getCurrentTime();
		return [begin, fps] {
			double duration = getCurrentTime() - begin;
			if (fps)
			{
				return 1.0 / duration;
			}
			return duration;
		};
	}

	size_t Foundation_API alignment(const size_t n, const size_t align) noexcept
	{
		return (((n)+(align)-1)&~((align)-1));
	}
}

namespace ks
{
	namespace os
	{
		std::string runCommand(const std::string & cmd, bool * status) noexcept
		{
			FILE *ptr = nullptr;
			constexpr int bufferSize = 128;
			std::array<char, bufferSize> buffer;
			std::string result;
			if ((ptr = _popen(cmd.c_str(), "r")) != nullptr)
			{
				while (fgets(buffer.data(), bufferSize, ptr) != nullptr) {
					result += buffer.data();
				}
				_pclose(ptr);
				if (status)
				{
					*status = true;
				}
			}
			else
			{
				if (status)
				{
					*status = false;
				}
			}
			return result;
		}
	}
}