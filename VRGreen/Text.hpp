#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine::UI
{
	struct Text : Component 
	{ 
		NOIMPLEMENT(Text);

		void SetText(const std::string& value);
	
	};
}