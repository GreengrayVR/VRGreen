#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine::UI
{

	struct ButtonClickedEvent : UnityEngine::Component
	{
		NOIMPLEMENT(ButtonClickedEvent);

		void ButtonClickedEvent_ctor();
	};
}