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

		static ApiAvatar* ctor();

		std::string GetAssetURL();

		std::string GetName();

		std::string GetAuthorName();

		std::string Id();

		void SetId(const std::string& id);
	};
}