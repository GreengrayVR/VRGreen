#pragma once

#include <vector>

#include "ButtonAPI.hpp"

namespace VRCQuickMenu
{
	inline std::vector<ButtonBase*> QuickMenuButtons;

	void ShowUserInteractMenu1();

	void ShowUIElements2();

	void ShowUIElements1();

	void SetupButtons();

	void SetupVRGreenText();

	void VRPlayerListUpdate();

	void PlayerListCounterUpdate();

	void InitVRDebug();

	void VRDebugUpdate();

	void ClearInterface();
}