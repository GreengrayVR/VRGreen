#pragma once

#include "UnityEvent.h"

namespace UnityEngine::UI
{

	struct ButtonClickedEvent : UnityEngine::Events::UnityEvent
	{
		NOIMPLEMENT(ButtonClickedEvent);

		static ButtonClickedEvent* ctor();
	};
}