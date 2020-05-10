#pragma once

namespace UnityEngine::Events
{
	struct UnityAction;

	struct UnityEvent
	{
		void AddListener(UnityAction* call);
	};
}