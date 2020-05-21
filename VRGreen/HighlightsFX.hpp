#pragma once

#include "Common.hpp"

namespace UnityEngine { struct Renderer; }

struct HighlightsFX : Object
{
	NOIMPLEMENT(HighlightsFX);

	static HighlightsFX* Instance();

	static void EnableOutline(UnityEngine::Renderer* renderer, bool value);
};
