#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine { struct Color; struct GameObject; }

struct VRCUiShadowPlate : UnityEngine::GameObject 
{
	NOIMPLEMENT(VRCUiShadowPlate); 

	UnityEngine::Color* GetColor();

	void Show();
};