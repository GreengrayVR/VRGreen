#include "Button.hpp"

using namespace UnityEngine::UI;

ButtonClickedEvent* Button::GetOnClick()
{
	using func_t = ButtonClickedEvent * (*)(Button* _this);

	func_t func = GetMethod<func_t>(GETONCLICK);

	return func(this);
}

void Button::SetOnClick(ButtonClickedEvent* value)
{
	using func_t = void (*)(Button* _this, ButtonClickedEvent* value);

	func_t func = GetMethod<func_t>(SETONCLICK);

	func(this, value);
}
