#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine::UI
{
	struct Text : Component 
	{ 
		NOIMPLEMENT(Text);

		void SetText(std::string value);
	
	};
}