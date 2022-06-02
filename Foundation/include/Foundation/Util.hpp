#ifndef Foundation_Util_hpp
#define Foundation_Util_hpp

#include <vector>
#include <functional>
#include <array>
#include <string>
#include "defs.hpp"
#include "Time.hpp"

namespace ks
{
	template<class T>
	std::vector<T> bufferToVector(const char* buffer, const unsigned int count) noexcept
	{
		std::vector<T> tmp(count);
		const size_t bytesSize = sizeof(T) * count;
		memcpy(tmp.data(), buffer, bytesSize);
		return tmp;
	}

	std::function<double()> Foundation_API measue(bool fps = false) noexcept;

	size_t Foundation_API alignment(const size_t n, const size_t align) noexcept;

	bool Foundation_API isPowerOfTwo(unsigned long x) noexcept;
}

namespace ks
{
	namespace os
	{
		std::string Foundation_API runCommand(const std::string& cmd, bool* status) noexcept;
	}
}

namespace ks
{
	namespace stringop
	{
		bool Foundation_API isContains(const std::string& str, const std::string& substring);
		bool Foundation_API isStartWith(const std::string& str, const std::string& substring);
		bool Foundation_API isEndWith(const std::string& str, const std::string& substring);
		std::string Foundation_API replaceAllOccurrences(std::string str, const std::string& from, const std::string& to);
	}
}

#endif // !Foundation_Util_hpp
