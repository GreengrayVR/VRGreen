#include "HighlightsFX.hpp"

HighlightsFX* HighlightsFX::Instance()
{
	using func_t = HighlightsFX * (*)();

	func_t func = GetMethod<func_t>(0x35B16F0);

	return func();
}
