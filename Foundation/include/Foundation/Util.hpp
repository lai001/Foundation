#ifndef FOUNDATIONUTIL_HPP
#define FOUNDATIONUTIL_HPP

#include <vector>
#include <functional>
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

	std::function<double()> measue(bool fps = false) noexcept;
}


#endif // !FOUNDATIONUTIL_HPP
