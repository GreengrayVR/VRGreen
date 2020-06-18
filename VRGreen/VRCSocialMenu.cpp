#include "VRCSocialMenu.hpp"

#include "UnityEngine/Transform.hpp"
#include "UnityEngine/Object.hpp"
#include "Button.hpp"
#include "Assembly-CSharp/VRCUiManager.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "ButtonClickedEvent.h"
#include "UnityAction.hpp"
#include "UnityEvent.h"
#include "CDetour.hpp"
#include "VRCUiPage.hpp"
#include "Text.hpp"
#include "List.hpp"
#include "VRC/Player.h"
#include "VRC/PlayerManager.hpp"
#include "VRC/Core/APIUser.hpp"
#include "VRCPlayerApi.h"
#include "Misc.hpp"
#include "ApiAvatar.hpp"
#include "VRCPlayer.hpp"
#include "Variables.hpp"
#include "ConsoleUtils.hpp"

using namespace UnityEngine;

VRC::Core::APIUser* VRCSocialMenu::CurrentUser()
{
	return (VRC::Core::APIUser*)IL2CPP::GetField((Object*)VRCUiPage::GetPage("UserInterface/MenuContent/Screens/UserInfo"), "VRC.Core.APIUser");
}

UnityEngine::Transform* VRCSocialMenu::CreateButton(std::string btnText, int btnXLocation, int btnYLocation, CDetour* btnAction)
{
	Transform* transform = InstantiateGameobject("block");
	Vector3 v{ v.x = btnXLocation, v.y = btnYLocation, v.z = 0};
	transform->SetLocalPosition(&v);
	((UI::Text*)transform->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text"))->SetText(btnText);
	transform->SetParent(VRCUiManager::VRCUiManagerInstance()->get_transform()->Find("MenuContent/Screens/UserInfo/User Panel/"), false);
	((UI::Button*)transform->GetComponent("UnityEngine.UI.Button"))->SetOnClick(UI::ButtonClickedEvent::ctor());
	((UI::Button*)transform->GetComponent("UnityEngine.UI.Button"))->GetOnClick()->AddListener(Events::UnityAction::ctor(btnAction));
	return transform;
}

UnityEngine::Transform* VRCSocialMenu::InstantiateGameobject(std::string type)
{
	const static std::unordered_map<std::string, int> string_to_case{
	   {"block",				1},
	   {"nameplates",			2},
	   {"block1",				3},
	   {"next",					4},
	   {"prev",					5},
	   {"emojimenu",			6},
	   {"userinteractmenu",		7},
	   {"block",				8},
	   {"menu",					9}
	};

	auto quickMenu = VRCUiManager::VRCUiManagerInstance(); // TODO: delete VRCUIManager out of instance name

	switch (string_to_case.at(type))
	{
	case 1:
	{
		auto nig = quickMenu->get_transform()->Find("MenuContent/Screens/UserInfo/User Panel/OnlineFriend/Actions/Block")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 2:
	{
		auto nig = quickMenu->get_transform()->Find("UIElementsMenu/ToggleNameplatesButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 3:
	{
		auto nig = quickMenu->get_transform()->Find("NotificationInteractMenu/BlockButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 4:
	{
		auto nig = quickMenu->get_transform()->Find("QuickMenu_NewElements/_CONTEXT/QM_Context_User_Selected/NextArrow_Button")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 5:
	{
		auto nig = quickMenu->get_transform()->Find("QuickMenu_NewElements/_CONTEXT/QM_Context_User_Selected/PreviousArrow_Button")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 6:
	{
		auto nig = quickMenu->get_transform()->Find("EmojiMenu")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 7:
	{
		auto nig = quickMenu->get_transform()->Find("UserInteractMenu")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 8:
	{
		auto nig = quickMenu->get_transform()->Find("UserInteractMenu/BlockButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 9:
	{
		auto nig = quickMenu->get_transform()->Find("CameraMenu")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	}
	return nullptr;
}

void VRCSocialMenu::SetupButtons()
{
	/*
	x += 155
	y 550 is up
	y 625 is down
	*/
	SocialButtons.push_back(CreateButton("Teleport", -80, -625, new CDetour([=]()
	{
		auto currentSelectedUser = CurrentUser();
		if (currentSelectedUser == nullptr)
		{
			ConsoleUtils::Log("this APIUser is in africa");
			return;
		}

		List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

		for (size_t i = 0; i < players.arrayLength; i++)
		{
			auto apiuser = players[i]->GetAPIUser();
			if (apiuser->getId() == currentSelectedUser->getId())
			{
				auto vrcplayerapi = players[i]->GetVRCPlayerApi();
				if (vrcplayerapi == nullptr)
					return;
				VRC::SDKBase::VRCPlayerApi::GetCurrentVRCPlayerApi()->TeleportTo(vrcplayerapi);

				return;
			}
		}
	})));

	SocialButtons.push_back(CreateButton("Download\nVRCA", -80, -550, new CDetour([=]()
	{
		auto currentSelectedUser = CurrentUser();
		if (currentSelectedUser == nullptr)
			return;

		List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

		for (size_t i = 0; i < players.arrayLength; i++)
		{
			auto apiuser = players[i]->GetAPIUser();
			if (apiuser->getId() == currentSelectedUser->getId())
			{
								
				auto url = players[i]->GetVRCPlayer()->GetApiAvatar()->GetAssetURL().c_str();
				std::cout << white << apiuser->displayName() << " VRCA Download URL:\n" << url << '\n';
				ShellExecute(0, 0, Misc::wchar_t_ptr(url), 0, 0, SW_SHOW);

				return;
			}
		}
	})));

	SocialButtons.push_back(CreateButton("VRChat.net\nProfile", -235, -550, new CDetour([=]()
	{
		std::string url = "https://vrchat.com/home/user/" + CurrentUser()->getId();
		ShellExecute(0, 0, Misc::wchar_t_ptr(url), 0, 0, SW_SHOW);
	})));

	SocialButtons.push_back(CreateButton("Teleport\npickups", -235, -625, new CDetour([=]()
	{
	
	})));

	SocialButtons.push_back(CreateButton("Steam\nPage", -390, -625, new CDetour([=]()
	{
		auto currentSelectedUser = CurrentUser();
		if (currentSelectedUser == nullptr)
			return;

		List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

		for (size_t i = 0; i < players.arrayLength; i++)
		{
			auto apiuser = players[i]->GetAPIUser();
			if (apiuser->getId() == currentSelectedUser->getId())
			{
				std::string url = "https://steamcommunity.com/profiles/" + std::to_string(players[i]->GetVRCPlayer()->get_steamId());
				ShellExecute(0, 0, Misc::wchar_t_ptr(url), 0, 0, SW_SHOW);

				return;
			}
		}
	})));

	SocialButtons.push_back(CreateButton("White List", -545, -625, new CDetour([=]()
	{
		auto userid = CurrentUser()->getId();
		if (Misc::contains(Variables::whiteList, userid))
		{
			Variables::whiteList.push_back(userid);
			ConsoleUtils::Log(CurrentUser()->displayName(), " added to white list");
			ConsoleUtils::VRLog(CurrentUser()->displayName() + " added to white list");
		}
		else
		{
			Variables::whiteList.remove(userid);
			ConsoleUtils::Log(CurrentUser()->displayName(), " removed from white list");
			ConsoleUtils::VRLog(CurrentUser()->displayName() + " removed from white list");
		}
	})));

	SocialButtons.push_back(CreateButton("Drop Portal", -700, -625, new CDetour([=]()
	{
		auto currentSelectedUser = CurrentUser();
		if (currentSelectedUser == nullptr)
			return;

		List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

		for (size_t i = 0; i < players.arrayLength; i++)
		{
			auto apiuser = players[i]->GetAPIUser();
			if (apiuser->getId() == currentSelectedUser->getId())
			{
				Misc::DropPortal(players[i]);
				return;
			}
		}
	})));

	SocialButtons.push_back(CreateButton("Drop Portal\nTo Instance", -700, -550, new CDetour([=]()
	{
		auto apiuser = CurrentUser();
		std::string location = apiuser->getLocation();

		if (location.empty())
			VRCUiManager::VRCUiManagerInstance()->HudMsg(apiuser->displayName() + " has no valid location");
		if(location == "private")
			VRCUiManager::VRCUiManagerInstance()->HudMsg(apiuser->displayName() + " location is private");

		Misc::DropPortal(location);

	})));
}

void VRCSocialMenu::ClearInterface()
{
	for (auto buttonTransform : SocialButtons)
	{
		Destroy(buttonTransform->get_gameObject(), 0.f);
	}
}
