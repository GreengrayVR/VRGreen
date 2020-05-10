#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine
{
	struct Color;
}

namespace UnityEngine::UI
{
	struct Graphic : UnityEngine::Component 
	{
		NOIMPLEMENT(Graphic); 

		void SetColor(Color* value);
	};

}