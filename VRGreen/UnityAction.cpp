#include "UnityAction.hpp"
#include <Utils\Offsets.h>

#include "IL2CPP/IL2CPP.hpp"
#include "CDetour.hpp"

using namespace UnityEngine::Events;

UnityEngine::Events::UnityAction* UnityAction::ctor(CDetour* action)
{
	auto obj = (UnityAction*)IL2CPP::NewObject("UnityEngine.Events.UnityAction, UnityEngine");

	using func_t = void (*)(UnityAction* t, void* pass_nullptr, intptr_t RuntimeMethod);

	func_t func = GetMethod<func_t>(UNITYACTIONCTOR);

	func(obj, nullptr, (intptr_t)RunTimeMethod);

	using funcpointer_t = void(*)();
	*((funcpointer_t*)obj + 2) = action->GetFuncPointer();

	return obj;
}

void UnityEngine::Events::UnityAction::RunTimeMethod()
{
	// This is just for RuntimeMethod address, this isnt usable
}
