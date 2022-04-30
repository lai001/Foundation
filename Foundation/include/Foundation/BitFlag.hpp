#ifndef BITFLAG_HPP
#define BITFLAG_HPP
#include "defs.hpp"

namespace ks
{
	template<typename T, typename U>
	struct BitFlag
	{
		T value;
		explicit BitFlag(const T v) : value(v) { }

		bool isContains(const U& r) const
		{
			return (value & r.value) == r.value;
		}

		bool isNotContains(const U& r) const
		{
			return isContains(r) == false;
		}

		U insert(const U& r) const
		{
			return U(value | r.value);
		}

		U remove(const U& r) const
		{
			return U(value & ~r.value);
		}

		bool operator !=(const U& r) const
		{
			return r.value != value;
		}

		bool operator ==(const U& r) const
		{
			return r.value == value;
		}

		U operator |(const U& r) const
		{
			return U(value | r.value);
		}
	};
}

#endif // BITFLAG_HPP