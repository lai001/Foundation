#ifndef Foundation_SimpleTimer_hpp
#define Foundation_SimpleTimer_hpp

#include <thread>
#include <mutex>
#include <chrono>
#include <functional>
#include "noncopyable.hpp"
#include "defs.hpp"

namespace ks
{
	class Foundation_API SimpleTimer :public noncopyable
	{
	public:
		SimpleTimer(const long long timeInterval, std::function<void(SimpleTimer&)> closure);

		~SimpleTimer();

		void fire() noexcept;

		void invalidate() noexcept;

		long long getDuration() const noexcept;

		void setIsPause(bool flag) noexcept;

		bool getIsPause() const noexcept;

		bool getIsValid() const noexcept;

	private:
		std::function<void(SimpleTimer&)> closure;

		const long long timeInterval;

		long long getCurrentClockTime() const noexcept;

		long long lastClockTime = 0;

		long long duration = 0;

		void setDuration(long long value) noexcept;

		bool isPause = false;

		bool isValid = true;

		bool token = false;

		mutable std::mutex lock;
	};
}

#endif // !Foundation_SimpleTimer_hpp