#pragma once


//VRCPlayer* GetCurrentVRCPlayer();
#include "Common.hpp"
#include <string>

struct VRCPlayer;

namespace VRC::Core
{
	struct ApiAvatar : Object 
	{ 
		NOIMPLEMENT(ApiAvatar); 

		std::string GetAssetURL();

		std::string GetName();

		std::string GetAuthorName();

	};

	

}