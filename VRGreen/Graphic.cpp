#include "Graphic.hpp"

void UnityEngine::UI::Graphic::SetColor(Color* value)
{
	using func_t = void(*)(Graphic* _this, Color* value);

	func_t func = GetMethod<func_t>(SETCOLOR);

	func(this, value);
}
