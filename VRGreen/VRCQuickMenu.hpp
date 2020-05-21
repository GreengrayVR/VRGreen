#pragma once

#include <vector>

#include "ButtonAPI.hpp"

namespace VRCQuickMenu
{
	inline std::vector<ButtonBase*> QuickMenuButtons;

	void ShowUIElements1();

	void SetupButtons();

	void SetupVRGreenText();

	void VRPlayerListUpdate();

	void PlayerListCounterUpdate();

	void InitVRDebug();

	void VRDebugUpdate();

	void ClearInterface();
}