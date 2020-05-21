#include "HighlightsFX.hpp"

HighlightsFX* HighlightsFX::Instance()
{
	using func_t = HighlightsFX * (*)();

	func_t func = GetMethod<func_t>(0x35B16F0);

	return func();
}

void HighlightsFX::EnableOutline(UnityEngine::Renderer* renderer, bool value)
{
	using func_t = HighlightsFX * (*)(UnityEngine::Renderer* renderer, bool value);

	func_t func = GetMethod<func_t>(0x35B1880);

	func(renderer, value);
}
