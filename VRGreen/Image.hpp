#pragma once

#include "Common.hpp"

namespace UnityEngine { struct Color; }

namespace UnityEngine::UI
{
	struct Sprite;

	struct Material;

	struct Image
	{
		NOIMPLEMENT(Image);

		Sprite* GetSprite();

		void SetSprite(Sprite* value);

		Material* GetMaterial();

		void SetMaterial(Material* value);

		UnityEngine::Color GetColor();

	};
}