#pragma once

#include "UnityEngine/Component.hpp"

struct VRCUiPopupManager : UnityEngine::Component 
{ 
	NOIMPLEMENT(VRCUiPopupManager); 

	static VRCUiPopupManager* VRCUiPopupManagerInstance();

	void ShowAlert(std::string str1, std::string str2, float delay);
};

