#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>

namespace fd
{
	static long long getCurrentMillisecondsTime() noexcept
	{
		std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
		long long currentMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
		return currentMilliseconds;
	}
}

#endif // !TIME_HPP