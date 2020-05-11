#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine::Events
{
	struct UnityAction;

	struct UnityEvent : UnityEngine::Component
	{
		void AddListener(UnityAction* call);
	};
}