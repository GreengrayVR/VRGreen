#pragma once

#include "UnityEngine/Component.hpp"
#include "VRCPlayer.hpp"

namespace VRC::Core { struct APIUser; }

struct QuickMenu : UnityEngine::Component 
{
	NOIMPLEMENT(QuickMenu);

	static QuickMenu* Instance();

	VRC::Core::APIUser* SelectedUser();

	void OnPlayerSelectedByLaser(VRCPlayer* vrcplayer);
};
