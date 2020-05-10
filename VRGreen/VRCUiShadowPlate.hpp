#pragma once

#include "Common.hpp"

struct VRCUiShadowPlate : UnityEngine::Component { NOIMPLEMENT(VRCUiShadowPlate); };

// 40 53 48 83 ec ? 33 d2 48 8b d9 e8 ? ? ? ? 48 85 c0 74 ? 45 33 c0 b2 ? 48 8b c8 e8 ? ? ? ? 48 8b 4b ? 48 85 c9 74 ? 33 d2 e8 ? ? ? ? 48 85 c0 74 ? 45 33 c0 b2 ? 48 8b c8 e8 ? ? ? ? 48 8b 4b ? 48 85 c9 74 ? 33 d2 e8 ? ? ? ? 48 85 c0 74 ? 45 33 c0 b2
inline void Show(VRCUiShadowPlate* _this)
{
	using func_t = void(*)(VRCUiShadowPlate* _this);

	func_t func = GetMethod<func_t>(VIPPLATESHOW);

	func(_this);
}
