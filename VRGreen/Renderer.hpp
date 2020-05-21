#pragma once

#include "UnityEngine/Component.hpp"




namespace UnityEngine
{
	struct Material;

	struct Renderer : Component
	{
		void SetEnabled(bool value);

		Material* SharedMaterial();
	};
}