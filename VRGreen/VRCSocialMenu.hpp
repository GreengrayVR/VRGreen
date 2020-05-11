#pragma once

#include <string>
#include <vector>

namespace UnityEngine { struct Transform; }
namespace VRC::Core { struct APIUser; }
struct CDetour;

namespace VRCSocialMenu
{
	inline std::vector<UnityEngine::Transform*> SocialButtons;

	static UnityEngine::Transform* InstantiateGameobject(std::string type);

	VRC::Core::APIUser* CurrentUser();

	UnityEngine::Transform* CreateButton(std::string btnText, int btnXLocation, int btnYLocation, CDetour* btnAction);

	void SetupButtons();

	void ClearInterface();
}