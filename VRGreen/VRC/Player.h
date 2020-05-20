#pragma once
#include <string>

#include "UnityEngine/Component.hpp"

namespace VRC::SDKBase { struct VRCPlayerApi; }
struct VRCPlayer;
namespace VRC::Core { struct APIUser; }

namespace VRC
{
	struct Player : UnityEngine::Component 
	{ 
		NOIMPLEMENT(Player);

		SDKBase::VRCPlayerApi* GetVRCPlayerApi();
	
		std::string ToString();

		static Player* CurrentPlayer();

		Core::APIUser* GetAPIUser();

		VRCPlayer* GetVRCPlayer();
	};

}