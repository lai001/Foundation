#include "Semaphore.hpp"

namespace fd
{
	Semaphore::Semaphore(int count)
		:count(count)
	{
	}

	void Semaphore::signal() noexcept
	{
		std::unique_lock<std::mutex> lockg(lock);
		++count;
		cv.notify_one();
	}

	void Semaphore::wait() noexcept
	{
		std::unique_lock<std::mutex> lockg(lock);
		cv.wait(lockg, [=] { return count > 0; });
		--count;
	}
}