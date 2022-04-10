#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <thread>
#include <mutex>
#include <condition_variable>

namespace fd
{
	class Semaphore
	{
	public:
		explicit Semaphore(int count);

		void signal() noexcept;

		void wait() noexcept;

	private:
		std::mutex lock;

		std::condition_variable cv;

		int count;
	};
}

#endif // !SEMAPHORE_HPP