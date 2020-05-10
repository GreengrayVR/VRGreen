#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine
{
	struct Collider : UnityEngine::Component 
	{ 
		NOIMPLEMENT(Collider);
	
		void SetEnabled(bool value);
	};




}