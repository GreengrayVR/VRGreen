#pragma once

#include "UnityEngine/Component.hpp"



namespace UnityEngine::UI
{
	struct ButtonClickedEvent;

	struct Button : UnityEngine::Component 
	{
		NOIMPLEMENT(Button);

		ButtonClickedEvent* GetOnClick();

		void SetOnClick(ButtonClickedEvent* value);
	};
}
