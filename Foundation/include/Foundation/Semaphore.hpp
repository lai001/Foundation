#ifndef Foundation_Semaphore_hpp
#define Foundation_Semaphore_hpp

#include <thread>
#include <mutex>
#include <condition_variable>
#include "defs.hpp"

namespace ks
{
	class Foundation_API Semaphore
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

#endif // !Foundation_Semaphore_hpp