#pragma once

#include "Common.hpp"
#include "UnityEngine/Vector3.hpp"

namespace UnityEngine
{
	struct Ray
	{
		NOIMPLEMENT(Ray);

		static Ray* ctor(Vector3 origin, Vector3 direction);
	};
}