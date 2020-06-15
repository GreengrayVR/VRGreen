#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine { struct Color; }
namespace UnityEngine::UI { struct Text; }

struct VRCUiShadowPlate : UnityEngine::Component 
{
	NOIMPLEMENT(VRCUiShadowPlate); 

	UnityEngine::Color* GetColor();

	void Show();

	UnityEngine::UI::Text* getMainText();

	UnityEngine::UI::Text* getDropShadow();
};