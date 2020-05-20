#include "UnityEvent.h"

#include "Common.hpp"

void UnityEngine::Events::UnityEvent::AddListener(UnityEngine::Events::UnityAction* call)
{
	using func_t = void (*)(UnityEngine::Events::UnityEvent* _this, UnityEngine::Events::UnityAction* call);

	func_t func = GetMethod<func_t>(ADDLISTENER);

	func(this, call);
}