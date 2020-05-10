#pragma once
#include "../Common.hpp"
#include <string>



namespace VRC::SDKBase { struct VRCPlayerApi; }
struct VRCPlayer;
namespace VRC::Core { struct APIUser; }

namespace VRC
{
	struct Player : Object 
	{ 
		NOIMPLEMENT(Player);

		SDKBase::VRCPlayerApi* GetVRCPlayerApi();
	
		std::string ToString();

		static Player* CurrentPlayer();

		Core::APIUser* GetAPIUser();

		VRCPlayer* GetVRCPlayer();
	};

}