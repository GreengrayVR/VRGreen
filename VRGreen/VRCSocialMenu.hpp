#pragma once

#include <string>

namespace UnityEngine { struct Transform; }
namespace VRC::Core { struct APIUser; }
struct CDetour;

namespace VRCSocialMenu
{
	static UnityEngine::Transform* FindInVRCUiManager(std::string str);

	void SetAction(UnityEngine::Transform* transform, CDetour* action);

	VRC::Core::APIUser* CurrentUser();

	static UnityEngine::Transform* InstantiateGameobject(std::string type);

	inline UnityEngine::Transform* TeleportButton;
	inline UnityEngine::Transform* DownloadVRCAButton;
	inline UnityEngine::Transform* VRChatProfileButton;
	inline UnityEngine::Transform* TeleportPickupsButton;
	inline UnityEngine::Transform* SteamPageButton;
	inline UnityEngine::Transform* WhiteListButton;
	inline UnityEngine::Transform* DropPortalOnPlayer;

	void SetupButtons();

	void ClearInterface();
}