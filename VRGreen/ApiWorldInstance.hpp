#pragma once

#include "UnityEngine/Component.hpp"

namespace VRC::Core
{
	struct ApiWorldInstance : UnityEngine::Component 
    { 
        NOIMPLEMENT(ApiWorldInstance);

		std::string GetAccessType();
    };
}