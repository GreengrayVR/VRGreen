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

UnityEngine::Transform* VRCSocialMenu::FindInVRCUiManager(std::string str)
{
	return VRCUiManager::VRCUiManagerInstance()->get_transform()->Find(str);
}

void VRCSocialMenu::SetAction(Transform* transform, CDetour* action)
{
	UI::Button* L_0 = (UI::Button*)transform->GetComponent("UnityEngine.UI.Button");
	auto L_1 = (UI::ButtonClickedEvent*)IL2CPP::NewObjectFromObject((Object*)L_0->GetOnClick(), false);
	L_1->ButtonClickedEvent_ctor();
	L_0->SetOnClick(L_1);

	auto L_4 = (Events::UnityAction*)IL2CPP::NewObject("UnityEngine.Events.UnityAction, UnityEngine");
	Events::UnityAction::ctor(L_4, nullptr, (intptr_t)FindInVRCUiManager);
	using func_t = void(*)();
	*((func_t*)L_4 + 2) = action->GetFuncPointer();

	auto cacaca = ((UI::Button*)transform->GetComponent("UnityEngine.UI.Button"));
	auto unityevent = (Events::UnityEvent*)cacaca->GetOnClick();
	unityevent->AddListener(L_4);
}

VRC::Core::APIUser* VRCSocialMenu::CurrentUser()
{
	return (VRC::Core::APIUser*)IL2CPP::GetField((Object*)VRCUiPage::GetPage("UserInterface/MenuContent/Screens/UserInfo"), "VRC.Core.APIUser");
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
	{
		TeleportButton = InstantiateGameobject("block");
		Vector3 v; v.x = -80; v.y = -625; v.z = 0;
		TeleportButton->SetLocalPosition(&v);
		auto text = (UI::Text*)TeleportButton->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("Teleport");
		TeleportButton->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(TeleportButton, new CDetour([=]()
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
						auto vrcplayerapi = players[i]->GetVRCPlayerApi();
						if (vrcplayerapi == nullptr)
							return;
						VRC::SDKBase::VRCPlayerApi::GetCurrentVRCPlayerApi()->TeleportTo(vrcplayerapi);

						return;
					}
				}
			}));
	}
	{
		DownloadVRCAButton = InstantiateGameobject("block");
		Vector3 v; v.x = -80; v.y = -550; v.z = 0;
		DownloadVRCAButton->SetLocalPosition(&v);
		auto text = (UI::Text*)DownloadVRCAButton->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("Download\nVRCA");
		DownloadVRCAButton->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(DownloadVRCAButton, new CDetour([=]()
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
			}));
	}
	{
		VRChatProfileButton = InstantiateGameobject("block");
		Vector3 v; v.x = -235; v.y = -550; v.z = 0;
		VRChatProfileButton->SetLocalPosition(&v);
		auto text = (UI::Text*)VRChatProfileButton->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("VRChat.net\nProfile");
		VRChatProfileButton->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(VRChatProfileButton, new CDetour([=]()
			{
				std::string url = "https://vrchat.com/home/user/" + CurrentUser()->getId();
				ShellExecute(0, 0, Misc::wchar_t_ptr(url), 0, 0, SW_SHOW);
			}));
		SetAction(VRChatProfileButton, new CDetour([=]() {}));
	}
	{
		TeleportPickupsButton = InstantiateGameobject("block");
		Vector3 v; v.x = -235; v.y = -625; v.z = 0;  // TODO: change to {}
		TeleportPickupsButton->SetLocalPosition(&v);
		auto text = (UI::Text*)TeleportPickupsButton->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("Teleport\npickups");
		TeleportPickupsButton->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(TeleportPickupsButton, new CDetour([=]() {}));
	}
	{
		SteamPageButton = InstantiateGameobject("block");
		Vector3 v; v.x = -390; v.y = -625; v.z = 0; // TODO: change to {}
		SteamPageButton->SetLocalPosition(&v);
		auto text = (UI::Text*)SteamPageButton->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("Steam\nPage");
		SteamPageButton->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(SteamPageButton, new CDetour([=]()
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
			}));
	}
	{
		WhiteListButton = InstantiateGameobject("block");
		Vector3 v; v.x = -545; v.y = -625; v.z = 0;
		WhiteListButton->SetLocalPosition(&v);
		auto text = (UI::Text*)WhiteListButton->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("White List");
		WhiteListButton->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(WhiteListButton, new CDetour([=]()
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
			}));
	}
	{
		DropPortalOnPlayer = InstantiateGameobject("block");
		Vector3 v; v.x = -700; v.y = -625; v.z = 0;
		DropPortalOnPlayer->SetLocalPosition(&v);
		auto text = (UI::Text*)DropPortalOnPlayer->GetChild(0)->GetChild(0)->GetComponent("UnityEngine.UI.Text");
		text->SetText("Drop Portal");
		DropPortalOnPlayer->SetParent(FindInVRCUiManager("MenuContent/Screens/UserInfo/User Panel/"), false);
		SetAction(DropPortalOnPlayer, new CDetour([=]()
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
			}));
	}
}

void VRCSocialMenu::ClearInterface()
{
	Destroy(TeleportButton->get_gameObject(), 0.f);
	Destroy(DownloadVRCAButton->get_gameObject(), 0.f);
	Destroy(VRChatProfileButton->get_gameObject(), 0.f);
	Destroy(TeleportPickupsButton->get_gameObject(), 0.f);
	Destroy(SteamPageButton->get_gameObject(), 0.f);
	Destroy(WhiteListButton->get_gameObject(), 0.f);
	Destroy(DropPortalOnPlayer->get_gameObject(), 0.f);
}
