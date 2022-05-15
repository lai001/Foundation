#ifndef FOUNDATIONUTIL_HPP
#define FOUNDATIONUTIL_HPP

#include <vector>
#include <functional>
#include <array>
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
}

namespace ks
{
	namespace os
	{
		std::string Foundation_API runCommand(const std::string& cmd, bool* status) noexcept;
	}
}

#endif // !FOUNDATIONUTIL_HPP
