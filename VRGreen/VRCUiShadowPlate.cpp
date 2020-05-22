#include "VRCUiShadowPlate.hpp"
#include "HardOffsets.hpp"

UnityEngine::Color* VRCUiShadowPlate::GetColor()
{
	using func_t = UnityEngine::Color * (*)(VRCUiShadowPlate* _this);

	func_t func = GetMethod<func_t>(0x263A6B0);

	return func(this);
}

void VRCUiShadowPlate::Show()
{
	using func_t = void(*)(VRCUiShadowPlate* _this);

	func_t func = GetMethod<func_t>(VIPPLATESHOW);

	func(this);
}
