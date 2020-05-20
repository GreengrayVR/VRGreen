#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine
{
	struct Renderer : Component
	{
		void SetEnabled(bool value);
	};
}