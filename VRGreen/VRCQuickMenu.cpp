#include "VRCQuickMenu.hpp"

#include "Variables.hpp"
#include "VRCPlayer.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "Collider.hpp"
#include "Misc.hpp"
#include "UnityEngine/GameObject.hpp"
#include "Text.hpp"
#include "VRC/PlayerManager.hpp"
#include "ConsoleUtils.hpp"
#include "Image.hpp"
#include "VRC/SDKBase/Networking.hpp"
#include "VRC/Core/APIUser.hpp"
#include "VRC/Player.h"

using namespace UnityEngine;

inline std::string FormatMyName2(VRC::Player* player)
{
	auto apiuser = player->GetAPIUser();
	auto userid = apiuser->getId();
	bool isFriend = VRC::Core::APIUser::isFriendsWith(userid);

	if (userid == VRC::Core::APIUser::currentUser()->getId())
		return std::string("<color=#ee82ee>" + apiuser->displayName() + "</color>");
	else if (isFriend)
		return std::string("<color=yellow>" + apiuser->displayName() + "</color>");
	else
		return apiuser->displayName();
}

void VRCQuickMenu::ShowUserInteractMenu1()
{
	Variables::userInteractMenu1 = !Variables::userInteractMenu1;
	
	if (Variables::userInteractMenu1)
	{
		Vector3 v{ 1,1,1 };
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAvatarStatsButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAuthorButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewPlaylistsButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/CloneAvatarButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ReportAbuseButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ReportAbuseButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/SingleButton2220(2,-1)")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/SingleButton2210(0,-2)")->SetLocalScale(&v);

		Vector3 v2{ 0,0,0 };
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/FriendButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/DetailsButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/BlockButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewAvatarThreeToggle")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/MuteButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/KickButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/WarnButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/SingleButton2120(3,-1)")->SetLocalScale(&v2);
	}
	else
	{
		Vector3 v{ 0,0,0 };
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAvatarStatsButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAuthorButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewPlaylistsButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/CloneAvatarButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ReportAbuseButton")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/SingleButton2220(2,-1)")->SetLocalScale(&v);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/SingleButton2210(0,-2)")->SetLocalScale(&v);

		Vector3 v2{ 1,1,1 };
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/FriendButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/DetailsButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/BlockButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewAvatarThreeToggle")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/MuteButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/KickButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/WarnButton")->SetLocalScale(&v2);
		QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/SingleButton2120(3,-1)")->SetLocalScale(&v2);
	}
}

void VRCQuickMenu::ShowUIElements2()
{
	Variables::uiElementsPage2 = !Variables::uiElementsPage2;

	for (auto btn : QuickMenuButtons)
	{
		auto btnName = GetName(btn->getGameObject());

		if (btnName == "ToggleButton137(-2,-2)" ||btnName == "ToggleButton136(-3,-2)" ||btnName == "SingleButton135(0,-1)" ||btnName == "ToggleButton134(-1,0)" ||btnName == "ToggleButton133(-2,0)" ||btnName == "ToggleButton132(-1,-1)" ||btnName == "ToggleButton131(-2,-1)" ||btnName == "SingleButton1130(3,-1)" || btnName == "ToggleButton123(-3,0)" || btnName == "SingleButton1120(3,-1)" || btnName == "SingleButton116(1,-2)" || btnName == "ToggleButton115(-1,-2)" || btnName == "ToggleButton114(-3,-2)" || btnName == "ToggleButton113(-1,0)" || btnName == "ToggleButton112(-1,-1)" || btnName == "ToggleButton111(-3,-1)" || btnName == "ToggleButton110(-2,-1)" || btnName == "ToggleButton121(-1,0)" || btnName == "ToggleButton122(-2,0)")
		{
			if (Variables::uiElementsPage2)
			{
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1130(3,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1110(3,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton121(-1,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton122(-2,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton123(-3,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton124(0,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton125(-2,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton126(-1,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton127(-3,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton128(-2,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton129(-1,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton130(-3,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton131(-2,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton132(-1,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton133(-2,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton134(-1,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton135(0,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton136(-3,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton137(-2,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1140(3,0)")->get_gameObject()->SetActive(true);
			}
			else
			{

				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1130(3,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1110(3,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton121(-1,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton122(-2,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton123(-3,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton124(0,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton125(-2,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton126(-1,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton127(-3,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton128(-2,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton129(-1,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton130(-3,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton131(-2,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton132(-1,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton133(-2,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton134(-1,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton135(0,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton136(-3,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton137(-2,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1140(3,0)")->get_gameObject()->SetActive(false);
			}
		}
	}
}

void VRCQuickMenu::ShowUIElements1()
{
	Variables::uiElementsPage1 = !Variables::uiElementsPage1;

	for (auto btn : QuickMenuButtons)
	{
		auto btnName = GetName(btn->getGameObject());

		//ConsoleUtils::Log(btnName);
		if (btnName == "SingleButton1130(3,-1)" ||btnName == "ToggleButton123(-3,0)" || btnName == "SingleButton1120(3,-1)" || btnName == "SingleButton116(1,-2)" || btnName == "ToggleButton115(-1,-2)" || btnName == "ToggleButton114(-3,-2)" || btnName == "ToggleButton113(-1,0)" || btnName == "ToggleButton112(-1,-1)" || btnName == "ToggleButton111(-3,-1)" || btnName == "ToggleButton110(-2,-1)" || btnName == "ToggleButton121(-1,0)" || btnName == "ToggleButton122(-2,0)")
		{
			if (Variables::uiElementsPage1)
			{
				btn->setActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1110(3,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1130(3,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton121(-1,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton122(-2,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton123(-3,0)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton124(0,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton125(-2,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton126(-1,-1)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton127(-3,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton128(-2,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton129(-1,-2)")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleHUDButton")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleNameplatesButton")->get_gameObject()->SetActive(false);
			}
			else
			{
				btn->setActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1110(3,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton1130(3,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton121(-1,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton122(-2,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton123(-3,0)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/SingleButton124(0,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton125(-2,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton126(-1,-1)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton127(-3,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton128(-2,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleButton129(-1,-2)")->get_gameObject()->SetActive(false);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleHUDButton")->get_gameObject()->SetActive(true);
				QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleNameplatesButton")->get_gameObject()->SetActive(true);
			}
		}
	}
}

void VRCQuickMenu::SetupButtons()
{
#pragma region NestedButtons
	Variables::uiElementsPage1 = false;
	Variables::uiElementsPage2 = false;

	auto buttonUp1 = new SingleButton("UIElementsMenu", 1110, 3, 0, "", CreateDetour([=]() { ShowUIElements1(); }), "");
	((UI::Image*)buttonUp1->getGameObject()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UI::Image*)QuickMenu::Instance()->get_transform()->Find("EmojiMenu/PageUp")->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	QuickMenuButtons.push_back(buttonUp1);
	buttonUp1->setActive(false);

	auto buttonDown1 = new SingleButton("UIElementsMenu", 1120, 3, -1, "", CreateDetour([=]() { ShowUIElements1(); }), "");
	((UI::Image*)buttonDown1->getGameObject()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UI::Image*)QuickMenu::Instance()->get_transform()->Find("EmojiMenu/PageDown")->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	QuickMenuButtons.push_back(buttonDown1);

	auto buttonDown2 = new SingleButton("UIElementsMenu", 1130, 3, -1, "", CreateDetour([=]() { ShowUIElements2(); }), "");
	((UI::Image*)buttonDown2->getGameObject()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UI::Image*)QuickMenu::Instance()->get_transform()->Find("EmojiMenu/PageDown")->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	QuickMenuButtons.push_back(buttonDown2);
	buttonDown2->setActive(false);

	auto buttonUp2 = new SingleButton("UIElementsMenu", 1140, 3, 0, "", CreateDetour([=]() { ShowUIElements2(); }), "");
	((UI::Image*)buttonUp2->getGameObject()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UI::Image*)QuickMenu::Instance()->get_transform()->Find("EmojiMenu/PageUp")->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	QuickMenuButtons.push_back(buttonUp2);
	buttonUp2->setActive(false);
#pragma endregion

#pragma region Page1
	auto forceMuteButton = new ToggleButton("UIElementsMenu", 110, -2, -1, "Force Mute", CreateDetour([=]()
	{
		Variables::forceMute = true; // TODO: move to Hack.cpp

	}), "OFF", CreateDetour([=]()
	{
		Variables::forceMute = false;

	}), "kill youserlf fag");
	QuickMenuButtons.push_back(forceMuteButton);
	forceMuteButton->btnOn->SetActive(true);
	forceMuteButton->btnOff->SetActive(false);

	auto autoDestroyButton = new ToggleButton("UIElementsMenu", 111, -3, -1, "Auto Destroy", CreateDetour([=]()
	{
		Variables::autoDestroy = true;

	}), "OFF", CreateDetour([=]()
	{

		Variables::autoDestroy = false;

	}), "gray is a cunt");
	QuickMenuButtons.push_back(autoDestroyButton);
	autoDestroyButton->btnOn->SetActive(true);
	autoDestroyButton->btnOff->SetActive(false);
	
	auto worldTriggersButton = new ToggleButton("UIElementsMenu", 112, -1, -1, "World Triggers", CreateDetour([=]()
	{
		Variables::worldTriggers = true;

	}), "OFF", CreateDetour([=]()
	{

		Variables::worldTriggers = false;

	}), "kiwi is stupid");
	QuickMenuButtons.push_back(worldTriggersButton);
	worldTriggersButton->btnOn->SetActive(true);
	worldTriggersButton->btnOff->SetActive(false);

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", 113, -1, 0, "Fly", CreateDetour([=]()
	{
		{
			Variables::fly = !Variables::fly;
			auto collider = (UnityEngine::Collider*)VRCPlayer::GetCurrentVRCPlayer()->get_gameObject()->GetComponent(IL2CPP::GetType("UnityEngine.CharacterController, UnityEngine.PhysicsModule"));
			collider->SetEnabled(!Variables::fly);
		}
	}), "OFF", CreateDetour([=]()
	{
		{
			Variables::fly = !Variables::fly;
			auto collider = (UnityEngine::Collider*)VRCPlayer::GetCurrentVRCPlayer()->get_gameObject()->GetComponent(IL2CPP::GetType("UnityEngine.CharacterController, UnityEngine.PhysicsModule"));
			collider->SetEnabled(!Variables::fly);
		}
	}), "nigger"));

	auto antiPortalButton = new ToggleButton("UIElementsMenu", 114, -3, -2, "Anti-Portal", CreateDetour([=]()
	{
		Variables::antiPortal = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::antiPortal = false;
	}), "nigger");
	QuickMenuButtons.push_back(antiPortalButton);
	antiPortalButton->btnOn->SetActive(true);
	antiPortalButton->btnOff->SetActive(false);

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", 115, -1, -2, "Offline", CreateDetour([=]()
	{
		Variables::offlineMode = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::offlineMode = false;
	}), "nigger"));

	QuickMenuButtons.push_back(new SingleButton("UIElementsMenu", 116, 1, -2, "Destroy\nPortals", CreateDetour([=]()
	{
		Misc::DestroyPortals();
	}), "dont play this trash game"));
#pragma endregion

#pragma region Page2
	auto speedHackButton = new ToggleButton("UIElementsMenu", 121, -1, 0, "Speed Hack", CreateDetour([=]()
	{
		Variables::speedHack = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::speedHack = false;
	}), "find me a gf");
	QuickMenuButtons.push_back(speedHackButton);
	speedHackButton->setActive(false);

	auto discordRPCButton = new ToggleButton("UIElementsMenu", 122, -2, 0, "DiscordRPC", CreateDetour([=]()
	{
		Variables::g_Discord->Initalize();
	}), "OFF", CreateDetour([=]()
	{
		Variables::g_Discord->Shutdown();
	}), "why do you even read this?");
	QuickMenuButtons.push_back(discordRPCButton);
	discordRPCButton->setActive(false);
	discordRPCButton->btnOn->SetActive(true);
	discordRPCButton->btnOff->SetActive(false);

	auto emojiSpamButton = new ToggleButton("UIElementsMenu", 123, -3, 0, "Emoji Spam", CreateDetour([=]()
	{
		Variables::spamEmoji = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::spamEmoji = false;
	}), "if ur a girl u get the cliennt fofree");
	QuickMenuButtons.push_back(emojiSpamButton);
	emojiSpamButton->setActive(false);

	auto changePedistalsButton = new SingleButton("UIElementsMenu", 124, 0, -1, "Change\nPedestals", CreateDetour([=]()
	{
		Misc::ChangeAllPedistals();
	}), "cant be sober");
	QuickMenuButtons.push_back(changePedistalsButton);
	changePedistalsButton->setActive(false);


	auto instaneLockButton = new ToggleButton("UIElementsMenu", 125, -2, -1, "Instance Lock", CreateDetour([=]()
	{
		Variables::instanceLock = true;
	}), "OFF", CreateDetour([=]()
		{
			Variables::instanceLock = false;
		}), "i beat my dick to lolis");
	QuickMenuButtons.push_back(instaneLockButton);
	instaneLockButton->setActive(false);

	auto worldDesyncButton = new ToggleButton("UIElementsMenu", 126, -1, -1, "World Desync", CreateDetour([=]()
	{
		if (VRC::SDKBase::Networking::GoToRoom(RoomManagerBase::GetRoomId()))
			Variables::portalLag = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::portalLag = false;
	}), "glory to ukraine");
	QuickMenuButtons.push_back(worldDesyncButton);
	worldDesyncButton->setActive(false);

	auto serializeButton = new ToggleButton("UIElementsMenu", 127, -3, -2, "Serialize", CreateDetour([=]()
	{
		Variables::serialize = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::serialize = false;
	}), "glory to ukraine");
	QuickMenuButtons.push_back(serializeButton);
	serializeButton->setActive(false);

	auto antiWorldTriggersButton = new ToggleButton("UIElementsMenu", 128, -2, -2, "Anti\nWorld Triggers", CreateDetour([=]()
	{
		Variables::antiWorldTriggers = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::antiWorldTriggers = false;
	}), "sup4ik autist");
	QuickMenuButtons.push_back(antiWorldTriggersButton);
	antiWorldTriggersButton->setActive(false);
	antiWorldTriggersButton->btnOn->SetActive(true);
	antiWorldTriggersButton->btnOff->SetActive(false);

	auto worldCrashButton = new ToggleButton("UIElementsMenu", 129, -1, -2, "World\nCrash", CreateDetour([=]()
	{
		Misc::ChangeAvatar("avtr_0be90e0a-3f0a-462c-8b0d-97b8b178e53e");
	}), "OFF", CreateDetour([=]()
	{
		Misc::ChangeAvatar("avtr_61bb01ab-8363-4f12-9cda-3b6931dd2c43");
	}), "");
	QuickMenuButtons.push_back(worldCrashButton);
	worldCrashButton->setActive(false);
#pragma endregion

#pragma region Page3
	auto pickupButton = new ToggleButton("UIElementsMenu", 130, -3, 0, "Hide\nPickups", CreateDetour([=]()
	{
		Misc::SetPickups(false);

	}), "OFF", CreateDetour([=]()
	{
		Misc::SetPickups(true);
	}), "yaekith pls stop flexing with ur shit nobody cares");
	QuickMenuButtons.push_back(pickupButton);
	pickupButton->setActive(false);

	auto rpcBlockNonFriendsButton = new ToggleButton("UIElementsMenu", 131, -2, -1, "RPC-Block\nNon-Friends", CreateDetour([=]()
	{
		Variables::rpcBlockNonFriends = true;
		//Misc::SerializeAll();

	}), "OFF", CreateDetour([=]()
	{
		Variables::rpcBlockNonFriends = false;
		//Misc::SerializeAll();
	}), "my ass");
	QuickMenuButtons.push_back(rpcBlockNonFriendsButton);
	rpcBlockNonFriendsButton->setActive(false);

	auto rpcBlockButton = new ToggleButton("UIElementsMenu", 132, -1, -1, "RPC-Block", CreateDetour([=]()
	{
		Variables::blockRPCs = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::blockRPCs = false;
	}), "i wanna die");
	QuickMenuButtons.push_back(rpcBlockButton);
	rpcBlockButton->setActive(false);

	auto fakePingButton = new ToggleButton("UIElementsMenu", 133, -2, 0, "Fake Ping", CreateDetour([=]()
	{
		Variables::fakePing = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::fakePing = false;
	}), "take my heart");
	QuickMenuButtons.push_back(fakePingButton);
	fakePingButton->setActive(false);
	fakePingButton->btnOn->SetActive(true);
	fakePingButton->btnOff->SetActive(false);

	auto audioCrashBtn = new ToggleButton("UIElementsMenu", 134, -1, 0, "Audio\nCrash", CreateDetour([=]()
	{
		Misc::ChangeAvatar("avtr_a9219b9e-b5ad-47b8-9135-09e9d1666dbc");
	}), "OFF", CreateDetour([=]()
	{
		Misc::ChangeAvatar("avtr_61bb01ab-8363-4f12-9cda-3b6931dd2c43");
	}), "suck my fat weiner");
	QuickMenuButtons.push_back(audioCrashBtn);
	audioCrashBtn->setActive(false);

	auto selectYourselfButton = new SingleButton("UIElementsMenu", 135, 0, -1, "Select\nYourself", CreateDetour([=]()
	{
		Misc::SelectYourself();
	}), "fuck theres a lot of buttons idk what to say");
	QuickMenuButtons.push_back(selectYourselfButton);
	selectYourselfButton->setActive(false);

	auto disablePlayersButton = new ToggleButton("UIElementsMenu", 136, -3, -2, "Disable\nPlayers", CreateDetour([=]()
	{
		Misc::SerializeAll();
	}), "OFF", CreateDetour([=]()
	{
		Misc::SerializeAll();
	}), "head hurts");
	QuickMenuButtons.push_back(disablePlayersButton);
	disablePlayersButton->setActive(false);

	auto portalKOSButton = new ToggleButton("UIElementsMenu", 137, -2, -2, "Portal\nKOS", CreateDetour([=]() // TODO: Fix bug with uninitialized buttons in quickmenu
	{
		Variables::portalKOS = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::portalKOS = false;
	}), "Sup4ik#1111 <- add him uwu");
	QuickMenuButtons.push_back(portalKOSButton);
	portalKOSButton->setActive(false);
	portalKOSButton->btnOn->SetActive(true);
	portalKOSButton->btnOff->SetActive(false);
#pragma endregion


#pragma region UserInteractMenuSetup
	Vector3 v{ 0, 0, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/MicOffButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAvatarStatsButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAuthorButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ReportAbuseButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewPlaylistsButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/CloneAvatarButton")->SetLocalScale(&v);
	Vector3 blockbtn{ 210,  1470, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/BlockButton")->SetLocalPosition(&blockbtn);
	Vector3 detailsbtn{ -630, 630, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/DetailsButton")->SetLocalPosition(&detailsbtn);
	Vector3 clonebtn{ 210, 1470, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/CloneAvatarButton")->SetLocalPosition(&clonebtn);
	Vector3 avatarauthorbtn{ -210, 1050, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAvatarStatsButton")->SetLocalPosition(&avatarauthorbtn);
	Vector3 showauthorbtn{ -630, 1050, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAuthorButton")->SetLocalPosition(&showauthorbtn);
	Vector3 playlistbtn{ -210, 1470, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewPlaylistsButton")->SetLocalPosition(&playlistbtn);
	Vector3 reportbtn{ -630, 1470, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ReportAbuseButton")->SetLocalPosition(&reportbtn);
	Vector3 backbtn{ 630, 630, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/BackButton")->SetLocalPosition(&backbtn);

	auto buttonUserUp1 = new SingleButton("UserInteractMenu", 2110, 3, 0, "", CreateDetour([=]() { ShowUserInteractMenu1(); }), "");
	((UI::Image*)buttonUserUp1->getGameObject()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UI::Image*)QuickMenu::Instance()->get_transform()->Find("EmojiMenu/PageUp")->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	QuickMenuButtons.push_back(buttonUserUp1);

	auto buttonUserDown1 = new SingleButton("UserInteractMenu", 2120, 3, -1, "", CreateDetour([=]() { ShowUserInteractMenu1(); }), "");
	((UI::Image*)buttonUserDown1->getGameObject()->GetComponent("UnityEngine.UI.Image"))->SetSprite(((UI::Image*)QuickMenu::Instance()->get_transform()->Find("EmojiMenu/PageDown")->GetComponent("UnityEngine.UI.Image"))->GetSprite());
	QuickMenuButtons.push_back(buttonUserDown1);

	auto soundVolumeUp = new SingleButton("UserInteractMenu", 12345, -1, 0, "Volume\nUP", CreateDetour([=]()
	{
		auto apiuser = QuickMenu::Instance()->SelectedUser();

		if (apiuser == nullptr)
			return;

		auto uspeaker = VRC::PlayerManager::GetPlayer(apiuser->getId())->GetComponentInChildren("USpeaker, Assembly-CSharp");
		float speakerVolume = *(float*)IL2CPP::ObjectUnbox(IL2CPP::GetField(uspeaker, "SpeakerVolume"));

		speakerVolume += 0.1f;
		if (speakerVolume <= 0.f || speakerVolume >= 1.f)
			return;
		IL2CPP::SetField(uspeaker, "System.Single", "SpeakerVolume", &speakerVolume);
		ConsoleUtils::Log(apiuser->displayName(), " valume is now ", std::to_string(speakerVolume));
		ConsoleUtils::VRLog(apiuser->displayName() + " valume is now " + std::to_string(speakerVolume));
	}), "why does it hurt");
	QuickMenuButtons.push_back(soundVolumeUp);

	auto soundVolumeDown = new SingleButton("UserInteractMenu", 123456, -1, -1, "Volume\nDOWN", CreateDetour([=]()
	{
		auto apiuser = QuickMenu::Instance()->SelectedUser();

		if (apiuser == nullptr)
			return;

		auto uspeaker = VRC::PlayerManager::GetPlayer(apiuser->getId())->GetComponentInChildren("USpeaker, Assembly-CSharp");
		float speakerVolume = *(float*)IL2CPP::ObjectUnbox(IL2CPP::GetField(uspeaker, "SpeakerVolume"));

		speakerVolume -= 0.1f;
		if (speakerVolume <= 0.f || speakerVolume >= 1.f)
			return;
		IL2CPP::SetField(uspeaker, "System.Single", "SpeakerVolume", &speakerVolume);
		ConsoleUtils::Log(apiuser->displayName(), " valume is now ", std::to_string(speakerVolume));
		ConsoleUtils::VRLog(apiuser->displayName() + " valume is now " + std::to_string(speakerVolume));
	}), "so much");
	QuickMenuButtons.push_back(soundVolumeDown);

	auto ButtonAddPortalKOS = new SingleButton("UserInteractMenu", 2220, 2, -1, "Add to\nPortal KOS", CreateDetour([=]()
		{
			auto apiuser = QuickMenu::Instance()->SelectedUser();
			std::string displayName = apiuser->displayName();
			std::string userid = apiuser->getId();

			if (Variables::portalKOSList.find(userid) == Variables::portalKOSList.end())
			{
				Variables::portalKOSList.insert(userid);
				ConsoleUtils::Log(red, displayName, " added to Portal KOS");
				ConsoleUtils::VRLog(FormatMyName2(VRC::PlayerManager::GetPlayer(userid)) + " <color=red>added to Portal KOS</color>");
			}
			else
			{
				Variables::portalKOSList.erase(userid);
				ConsoleUtils::Log(green, displayName, " removed from Portal KOS");
				ConsoleUtils::VRLog(FormatMyName2(VRC::PlayerManager::GetPlayer(userid)) + " <color=red>removed from Portal KOS</color>");
			}
		}), "fuck niggas");
	QuickMenuButtons.push_back(ButtonAddPortalKOS);
	v = { 0,0,0 };
	ButtonAddPortalKOS->getGameObject()->GetTransform()->SetLocalScale(&v);

	auto ButtonLogout = new SingleButton("UserInteractMenu", 2210, 0, -2, "Logout", CreateDetour([=]()
		{
			Misc::LogoutWithAPI(QuickMenu::Instance()->SelectedUser());
		
		}), "call greengray");
	QuickMenuButtons.push_back(ButtonLogout);
	v = { 0,0,0 };
	ButtonLogout->getGameObject()->GetTransform()->SetLocalScale(&v);
#pragma endregion
}

void VRCQuickMenu::SetupVRGreenText()
{
	UnityEngine::Vector3 v;
	v.x = 15.f;
	v.y = 20.f;
	v.z = 0.f;

	
	//UnityEngine::Transform* posInHier = UnityEngine::Find(UnityEngine::get_transform(QuickMenuInstance()), IL2CPP::StringNew("ShortcutMenu"));
	UnityEngine::Transform* posInHier = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu");

	//UnityEngine::Transform* EAText = UnityEngine::Find(UnityEngine::get_transform(QuickMenuInstance()), IL2CPP::StringNew("ShortcutMenu/EarlyAccessText"));
	UnityEngine::Transform* EAText = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

	auto gameObject = (GameObject*)Instantiate(EAText->get_gameObject(), posInHier, true);
	auto textTemplate = gameObject->GetTransform();


	gameObject->AddComponent("UnityEngine.UI.Outline, UnityEngine.UI");
	textTemplate->SetLocalPosition(&v);
	auto component = (UnityEngine::UI::Text*)textTemplate->GetComponent("UnityEngine.UI.Text");
	
	// TODO: random string
	component->SetText("<color=purple>we fell in love in october</color>"); // Make my heart bleed // i'll make a cup of coffee for your head

	UnityEngine::Vector3 v2;
	v2.x = 1.45f;
	v2.y = 1.45f;
	v2.z = 1.45f;

	textTemplate->SetLocalScale(&v2);


	SetName(textTemplate, "VRGreenTitle");
}

void VRCQuickMenu::VRPlayerListUpdate()
{
	{// Shadow Text
		for (size_t i = 0; i < 150; i++)
		{
			std::string playerString = "ShortcutMenu/playerListStringShadow" + std::to_string(i);

			auto PlayerText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew(playerString));

			if (PlayerText != nullptr)
			{
				Destroy(PlayerText->get_gameObject(), 0.f);
			}
			else
			{
				break;
			}
		}

		float position = 2075.f;

		List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

		for (size_t i = 0; i < players.arrayLength; i++)
		{
			UnityEngine::Transform* posInHier = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu");

			UnityEngine::Transform* EAText = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

			auto instantiate = Instantiate(EAText->get_gameObject(), posInHier, true);

			auto playerString1 = ((GameObject*)instantiate)->GetTransform();

			auto component = (UnityEngine::UI::Text*)((Component*)playerString1)->GetComponent("UnityEngine.UI.Text");

			((GameObject*)instantiate)->AddComponent("UnityEngine.UI.Outline, UnityEngine.UI");

			std::string playerTextUI = Misc::GetSocialRankForPlayerListShadow(players[i]);

			component->SetText(playerTextUI);

			std::string name = "playerListStringShadow" + std::to_string(i);

			SetName(playerString1, name);

			UnityEngine::Vector3 v2;
			v2.x = -1550.75f;
			v2.y = position-3.5f;
			v2.z = 5.75f;

			playerString1->SetLocalPosition(&v2);

			position -= 75.f;
		}
	}
	{// Text
	for (size_t i = 0; i < 150; i++)
	{
		std::string playerString = "ShortcutMenu/playerListString" + std::to_string(i);

		auto PlayerText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew(playerString));

		if (PlayerText != nullptr)
		{
			Destroy(PlayerText->get_gameObject(), 0.f);
		}
		else
		{
			break;
		}
	}

	float position = 2075.f;

	List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

	for (size_t i = 0; i < players.arrayLength; i++)
	{
		UnityEngine::Transform* posInHier = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu");

		UnityEngine::Transform* EAText = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

		auto instantiate = Instantiate(EAText->get_gameObject(), posInHier, true);

		auto playerString1 = ((GameObject*)instantiate)->GetTransform();

		auto component = (UnityEngine::UI::Text*)((Component*)playerString1)->GetComponent("UnityEngine.UI.Text");

		((GameObject*)instantiate)->AddComponent("UnityEngine.UI.Outline, UnityEngine.UI");

		std::string playerTextUI = Misc::GetSocialRankForPlayerList(players[i]);

		component->SetText(playerTextUI);

		std::string name = "playerListString" + std::to_string(i);

		SetName(playerString1, name);

		UnityEngine::Vector3 v2;
		v2.x = -1555.75f;
		v2.y = position;
		v2.z = 5.75f;

		playerString1->SetLocalPosition(&v2);

		position -= 75.f;
	}
	}
}

void VRCQuickMenu::PlayerListCounterUpdate()
{
	auto PlayerText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/PlayersInRoom"));

	if (PlayerText != nullptr)
		Destroy(PlayerText->get_gameObject(), 0.f);

	UnityEngine::Transform* posInHier = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu");

	UnityEngine::Transform* EAText = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

	auto instantiate = Instantiate(EAText->get_gameObject(), posInHier, true);

	auto transform = ((GameObject*)instantiate)->GetTransform();

	auto component = (UnityEngine::UI::Text*)((Component*)transform)->GetComponent("UnityEngine.UI.Text");


	List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());
	std::string playerCounter = "<color=cyan>Players: " + std::to_string(players.arrayLength) + "</color>";


	component->SetText(playerCounter);

	UnityEngine::Vector3 v;
	v.x = 690.f;
	v.y = 200.f;
	v.z = 0.f;
	transform->SetLocalPosition(&v);

	SetName(transform, "PlayersInRoom");
}

void VRCQuickMenu::InitVRDebug()
{
	for (size_t i = 0; i < ConsoleUtils::MaxDebugLines; i++)
	{
		ConsoleUtils::LogList.push_back({});
	}

	float position = 2075.f;

	// Create Shadow Text
	for (size_t i = 0; i < ConsoleUtils::MaxDebugLines; i++)
	{
		UnityEngine::Transform* posInHier = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu");

		UnityEngine::Transform* EAText = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

		auto instantiate = Instantiate(EAText->get_gameObject(), posInHier, true);

		auto playerString1 = ((GameObject*)instantiate)->GetTransform();

		auto component = (UnityEngine::UI::Text*)((Component*)playerString1)->GetComponent("UnityEngine.UI.Text");

		component->SetText(ConsoleUtils::LogList[i].text);

		((GameObject*)instantiate)->AddComponent("UnityEngine.UI.Outline, UnityEngine.UI");

		std::string name = "debugStringShadow" + std::to_string(i);

		SetName(playerString1, name);

		UnityEngine::Vector3 v2;
		v2.x = 1485.f;
		v2.y = position - 3.5f;
		v2.z = 0.f;

		playerString1->SetLocalPosition(&v2);

		position -= 75.f;
	}


	position = 2075.f;

	// Create Text
	for (size_t i = 0; i < ConsoleUtils::MaxDebugLines; i++)
	{
		UnityEngine::Transform* posInHier = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu");

		UnityEngine::Transform* EAText = QuickMenu::Instance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

		auto instantiate = Instantiate(EAText->get_gameObject(), posInHier, true);

		auto playerString1 = ((GameObject*)instantiate)->GetTransform();

		auto component = (UnityEngine::UI::Text*)((Component*)playerString1)->GetComponent("UnityEngine.UI.Text");

		component->SetText(ConsoleUtils::LogList[i].text);

		((GameObject*)instantiate)->AddComponent("UnityEngine.UI.Outline, UnityEngine.UI");

		std::string name = "debugString" + std::to_string(i);

		SetName(playerString1, name);

		UnityEngine::Vector3 v2;
		v2.x = 1480.f;
		v2.y = position;
		v2.z = 0.f;

		playerString1->SetLocalPosition(&v2);

		position -= 75.f;
	}
}

void VRCQuickMenu::VRDebugUpdate()
{
	int line = 0;
	for (int i = ConsoleUtils::LogListIndex; i >= 0; i--)
	{
		ConsoleUtils::LogList[i].Update(line);
		ConsoleUtils::LogList[i].UpdateShadow(line);
		line++;
	}

	for (int i = ConsoleUtils::MaxDebugLines - 1; i > ConsoleUtils::LogListIndex; i--)
	{
		ConsoleUtils::LogList[i].Update(line);
		ConsoleUtils::LogList[i].UpdateShadow(line);
		line++;
	}
}

void VRCQuickMenu::ClearInterface()
{
	// Delete Player List Text
	for (size_t i = 0; i < 1337; i++)
	{
		std::string playerString = "ShortcutMenu/playerListString" + std::to_string(i);

		auto PlayerText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew(playerString));

		if (PlayerText != nullptr)
		{
			Destroy(PlayerText->get_gameObject(), 0.f);
		}
		else
		{
			break;
		}
	}

	// Delete Player List Shadow Text
	for (size_t i = 0; i < 1337; i++)
	{
		std::string playerString = "ShortcutMenu/playerListStringShadow" + std::to_string(i);

		auto PlayerText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew(playerString));

		if (PlayerText != nullptr)
		{
			Destroy(PlayerText->get_gameObject(), 0.f);
		}
		else
		{
			break;
		}
	}

	// Delete VRGreen text
	Destroy(QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/VRGreenTitle"))->get_gameObject(), 0.f);

	// Delete Players in room text
	Destroy(QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/PlayersInRoom"))->get_gameObject(), 0.f);

	// Delete VR Debug Text
	for (size_t i = 0; i < 150; i++)
	{
		std::string debugString = "ShortcutMenu/debugString" + std::to_string(i);

		auto debugText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew(debugString));

		if (debugText != nullptr)
		{
			Destroy(debugText->get_gameObject(), 0.f);
		}
		else
		{
			break;
		}
	}

	// Delete VR Debug Shadow Text
	for (size_t i = 0; i < 150; i++)
	{
		std::string debugString = "ShortcutMenu/debugStringShadow" + std::to_string(i);

		auto debugText = QuickMenu::Instance()->get_transform()->Find(IL2CPP::StringNew(debugString));

		if (debugText != nullptr)
		{
			Destroy(debugText->get_gameObject(), 0.f);
		}
		else
		{
			break;
		}
	}

	// Restore default buttons
	QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleHUDButton")->get_gameObject()->SetActive(true);
	QuickMenu::Instance()->get_transform()->Find("UIElementsMenu/ToggleNameplatesButton")->get_gameObject()->SetActive(true);

	// Delete Quick Menu buttons
	for (auto& button : QuickMenuButtons)
	{
		Destroy(button->getGameObject(), 0.f);
	}
	QuickMenuButtons.clear();

	// Reset UserInteractMenu Buttons
	Vector3 v{ 1, 1, 1 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAvatarStatsButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ShowAuthorButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewAvatarThreeToggle")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ReportAbuseButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/ViewPlaylistsButton")->SetLocalScale(&v);
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/CloneAvatarButton")->SetLocalScale(&v);
	Vector3 blockbtn{ 630,  1470, 0 };
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/BlockButton")->SetLocalPosition(&blockbtn);
	Vector3 detailsbtn{ 210,  1470, 0 }; 
	QuickMenu::Instance()->get_transform()->Find("UserInteractMenu/DetailsButton")->SetLocalPosition(&detailsbtn);
}

void VRCQuickMenu::UpdateUSpeaker()
{
	auto apiuser = QuickMenu::Instance()->SelectedUser();

	if (apiuser == nullptr)
		return;

	

	auto uspeaker = VRC::PlayerManager::GetPlayer(apiuser->getId())->GetComponentInChildren("USpeaker, Assembly-CSharp");
	float speakerVolume = *(float*)IL2CPP::ObjectUnbox(IL2CPP::GetField(uspeaker, "SpeakerVolume"));

	ConsoleUtils::Log(speakerVolume);
	//IL2CPP::GetField(uspeaker, "SpeakerVolume");

}