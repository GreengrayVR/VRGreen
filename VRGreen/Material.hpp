#pragma once

#include "Common.hpp"
#include <Color.hpp>
#include <string>

namespace UnityEngine
{
	struct Material : Object
	{
		NOIMPLEMENT(Material);

		void SetColor(std::string name, Color* value);
	};
}