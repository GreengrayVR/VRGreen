#pragma once

#include "UnityEngine/Component.hpp"

namespace UnityEngine
{
	struct Camera : Component
	{
		static Camera* MainCamera();
	};
}