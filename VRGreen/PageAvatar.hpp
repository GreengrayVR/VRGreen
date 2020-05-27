#pragma once

#include "UnityEngine/Component.hpp"

namespace VRC::UI
{
	struct PageAvatar : UnityEngine::Component
	{
		NOIMPLEMENT(PageAvatar);

		static PageAvatar* ctor();

		void ChangeToSelectedAvatar();
	};
}