#include "Application.hpp"
#include "Common.hpp"
#include "Utils/Offsets.h"

bool IsFocused()
{
	using func_t = bool(*)();

	func_t func = GetMethod<func_t>(ISFOCUSED);

	return func();
}
