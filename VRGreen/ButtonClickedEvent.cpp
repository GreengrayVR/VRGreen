#include "ButtonClickedEvent.h"

void UnityEngine::UI::ButtonClickedEvent::ButtonClickedEvent_ctor()
{
	using func_t = void (*)(UnityEngine::UI::ButtonClickedEvent* _this);

	func_t func = GetMethod<func_t>(0x14B7810);

	func(this);
}
