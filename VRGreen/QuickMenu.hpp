#pragma once

#include "UnityEngine/Component.hpp"
 
struct QuickMenu : UnityEngine::Component 
{
	NOIMPLEMENT(QuickMenu);

	static QuickMenu* QuickMenuInstance();
};
