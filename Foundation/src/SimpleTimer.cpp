#include "SimpleTimer.hpp"
#include <assert.h>

namespace fd
{
	SimpleTimer::SimpleTimer(const long long timeInterval, std::function<void(SimpleTimer&)> closure)
		: closure(closure), timeInterval(timeInterval)
	{
	}

	SimpleTimer::~SimpleTimer()
	{

	}

	void SimpleTimer::fire() noexcept
	{
		assert(token == false);
		token = true;
		std::thread([this]()
		{
			lastClockTime = getCurrentClockTime();
			while (getIsValid())
			{
				const long long now = getCurrentClockTime();
				setDuration(now - lastClockTime);
				lastClockTime = now;
				if (getIsPause() == false)
				{
					closure(*this);
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(timeInterval));
			}
		}).detach();
	}

	void SimpleTimer::invalidate() noexcept
	{
		std::lock_guard<std::mutex> lockg(lock);
		isValid = false;
	}

	long long SimpleTimer::getDuration() const noexcept
	{
		std::lock_guard<std::mutex> lockg(lock);
		return duration;
	}

	void SimpleTimer::setIsPause(bool flag) noexcept
	{
		std::lock_guard<std::mutex> lockg(lock);
		isPause = flag;
	}

	bool SimpleTimer::getIsPause() const noexcept
	{
		std::lock_guard<std::mutex> lockg(lock);
		return isPause;
	}

	bool SimpleTimer::getIsValid() const noexcept
	{
		std::lock_guard<std::mutex> lockg(lock);
		return isValid;
	}

	long long SimpleTimer::getCurrentClockTime() const noexcept
	{
		std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
		return std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	}

	void SimpleTimer::setDuration(long long value) noexcept
	{
		std::lock_guard<std::mutex> lockg(lock);
		duration = value;
	}
}