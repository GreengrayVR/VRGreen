#include "Button.hpp"

using namespace UnityEngine::UI;

ButtonClickedEvent* Button::GetOnClick()
{
	using func_t = ButtonClickedEvent * (*)(Button* _this);

	func_t func = GetMethod<func_t>(0x14B7AA0);

	return func(this);
}

void Button::SetOnClick(ButtonClickedEvent* value)
{
	using func_t = void (*)(Button* _this, ButtonClickedEvent* value);

	func_t func = GetMethod<func_t>(0x7309C0);

	func(this, value);
}
