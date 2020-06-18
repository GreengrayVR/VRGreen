#pragma once

#include "UnityEngine/Component.hpp"
#include "Graphic.hpp"

namespace UnityEngine::UI
{
	struct Text : Graphic 
	{ 
		NOIMPLEMENT(Text);

		void SetText(const std::string& value);
	
		std::string GetText();

		void SetSupportRichText(const bool& value);
	};
}