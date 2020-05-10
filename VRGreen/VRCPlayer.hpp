#pragma once

#include "UnityEngine/Component.hpp"

namespace VRC { struct Player; }
namespace VRC::Core { struct ApiAvatar; }

struct VRCPlayer : UnityEngine::Component 
{
	NOIMPLEMENT(VRCPlayer); 

	static VRCPlayer* GetCurrentVRCPlayer();

	VRC::Player* getPlayer();

	long long get_steamId();

	VRC::Core::ApiAvatar* GetApiAvatar(); // TODO: move in VRCPlayer

};

struct USpeaker : Object { NOIMPLEMENT(USpeaker); };


