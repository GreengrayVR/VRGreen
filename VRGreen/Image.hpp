#pragma once

#include "Common.hpp"

namespace UnityEngine::UI
{
	struct Sprite;

	struct Image
	{
		NOIMPLEMENT(Image);

		Sprite* GetSprite();

		void SetSprite(Sprite* value);
	};
}