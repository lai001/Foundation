#include "Util.hpp"
#include <algorithm>
#include <cctype>

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

	bool isPowerOfTwo(unsigned long x) noexcept
	{
		return (x != 0) && ((x & (x - 1)) == 0);
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

namespace ks
{
	namespace stringop
	{
		bool Foundation_API isContains(const std::string& str, const std::string& substring)
		{
			return str.find(substring) != std::string::npos;
		}

		bool Foundation_API isStartWith(const std::string & str, const std::string & substring)
		{
			return str.rfind(substring, 0) == 0;
		}

		bool Foundation_API isEndWith(const std::string & str, const std::string & substring)
		{
			if (str.length() >= substring.length()) 
			{
				return (0 == str.compare(str.length() - substring.length(), substring.length(), substring));
			}
			else
			{
				return false;
			}
		}

		std::string Foundation_API replaceAllOccurrences(std::string str, const std::string & from, const std::string & to)
		{
			size_t start_pos = 0;
			while ((start_pos = str.find(from, start_pos)) != std::string::npos) 
			{
				str.replace(start_pos, from.length(), to);
				start_pos += to.length();
			}
			return str;
		}
	}
}