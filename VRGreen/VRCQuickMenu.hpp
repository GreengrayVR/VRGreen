#pragma once

#include <vector>

#include "ButtonAPI.hpp"

namespace VRCQuickMenu
{
	inline std::vector<ButtonBase*> QuickMenuButtons;
	inline float delta_x;
	inline float delta_y;

	void SetupButtons();

	void SetupVRGreenText();

	void VRPlayerListUpdate();

	void PlayerListCounterUpdate();

	void InitVRDebug();

	void VRDebugUpdate();

	void ClearInterface();
}