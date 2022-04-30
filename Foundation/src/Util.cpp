#include "Util.hpp"

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
}
