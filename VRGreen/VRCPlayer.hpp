#pragma once

#include "UnityEngine/Component.hpp"

namespace VRC { struct Player; }
namespace VRC::Core { struct ApiAvatar; }

struct VRCUiShadowPlate;

struct VRCPlayer : UnityEngine::Component 
{
	NOIMPLEMENT(VRCPlayer); 

	static VRCPlayer* GetCurrentVRCPlayer();

	VRC::Player* getPlayer();

	long long get_steamId();

	UnityEngine::GameObject* namePlate();

	UnityEngine::GameObject* vipPlate();

	VRC::Core::ApiAvatar* GetApiAvatar(); // TODO: move in VRCPlayer

};

struct USpeaker : Object { NOIMPLEMENT(USpeaker); };


