#include "UnityAction.hpp"
#include <Utils\Offsets.h>



void UnityEngine::Events::UnityAction::ctor(UnityAction* obj, void* pass_nullptr, intptr_t RuntimeMethod)
{
	using func_t = void (*)(UnityAction* t, void* pass_nullptr, intptr_t RuntimeMethod);

	func_t func = GetMethod<func_t>(UNITYACTIONCTOR);

	func(obj, pass_nullptr, RuntimeMethod);
}
