#include "VRCUiShadowPlate.hpp"
#include "HardOffsets.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "Text.hpp"

UnityEngine::Color* VRCUiShadowPlate::GetColor()
{
	using func_t = UnityEngine::Color * (*)(VRCUiShadowPlate* _this);

	func_t func = GetMethod<func_t>(UISHADOWPLATECOLOR);

	return func(this);
}

void VRCUiShadowPlate::Show()
{
	this->getMainText()->get_gameObject()->SetActive(true);
	this->getDropShadow()->get_gameObject()->SetActive(true);
}

inline static int32_t mainTextOffset = -3;

UnityEngine::UI::Text* VRCUiShadowPlate::getMainText()
{
	if (mainTextOffset == -3)
		mainTextOffset = IL2CPP::ResolveFieldOffset(this, "mainText");

	return GetField<UnityEngine::UI::Text*>(this, mainTextOffset);
}

inline static int32_t dropShadowOffset = -3;

UnityEngine::UI::Text* VRCUiShadowPlate::getDropShadow()
{
	if (dropShadowOffset == -3)
		dropShadowOffset = IL2CPP::ResolveFieldOffset(this, "dropShadow");

	return GetField<UnityEngine::UI::Text*>(this, dropShadowOffset);
}
