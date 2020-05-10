#pragma once

#include "UnityEngine/Component.hpp"

struct VRCUiManager : UnityEngine::Component 
{
	NOIMPLEMENT(VRCUiManager); 

	static VRCUiManager* VRCUiManagerInstance();

	static VRCUiManager* VRCUiManagerInstance2();

	void HudMsg(std::string text);

	void HudMsg2(std::string text);
};

