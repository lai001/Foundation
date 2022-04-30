#ifndef DEFER_HPP
#define DEFER_HPP
#include <functional>
#include "noncopyable.hpp"
#include "defs.hpp"

class Foundation_API _Defer: public boost::noncopyable
{
public:
	~_Defer()
	{
		closure();
	}
	std::function<void()> closure;
};

#define _Defer_CONCATENATE_IMPL(s1, s2) s1##s2
#define _Defer_CONCATENATE(s1, s2) _Defer_CONCATENATE_IMPL(s1, s2)
#define defer _Defer _Defer_CONCATENATE(__Defer, __LINE__); _Defer_CONCATENATE(__Defer, __LINE__).closure = [&]()
				

#endif // !DEFER_HPP
