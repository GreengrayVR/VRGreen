#pragma once

#include "Common.hpp"
#include "Utils/Offsets.h"

namespace UnityEngine
{
	struct Color
	{
		float r;
		float g;
		float b;
		float a;
	};

	Color* GetCyan();

	Color GetRed();
}