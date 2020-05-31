#pragma once

#include "UnityEngine/Component.hpp"

namespace VRC::Core
{
	struct ApiWorld : UnityEngine::Component 
	{
		NOIMPLEMENT(ApiWorld); 

		std::string GetName();

		std::string assetUrl();
	};
}