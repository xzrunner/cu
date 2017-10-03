#ifndef _CLASS_UTILITY_UNCOPYABLE_H_
#define _CLASS_UTILITY_UNCOPYABLE_H_

namespace cu
{

class Uncopyable
{
protected:
	Uncopyable() = default;
	~Uncopyable() = default;

	Uncopyable(const Uncopyable&) = delete;
	Uncopyable& operator = (const Uncopyable&) = delete;

}; // Uncopyable

}

#endif // _CLASS_UTILITY_UNCOPYABLE_H_