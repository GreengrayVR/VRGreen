#include "Time.hpp"

#include "Common.hpp"
#include <Utils\Offsets.h>

float Time::deltaTime()
{
	using func_t = float(*)();

	func_t func = GetMethod<func_t>(DELTATIME);

	return func();
}

float Time::time()
{
	using func_t = float(*)();

	func_t func = GetMethod<func_t>(0x1830F20);

	return func();
}
