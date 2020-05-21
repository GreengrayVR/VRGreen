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

using namespace UnityEngine;

void VRCQuickMenu::SetupButtons()
{
	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", -2, -1, "Force Mute", CreateDetour([=]()
	{
		Variables::forceMute = true; // TODO: move to Hack.cpp

	}), "OFF", CreateDetour([=]()
	{
		Variables::forceMute = false;

	}), "kill youserlf fag"));

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", 0, 0, "Speed Hack", CreateDetour([=]()
	{
		Variables::speedHack = true;

	}), "NO", CreateDetour([=]()
	{

		Variables::speedHack = false;

	}), "find me a gf"));

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", -3, -1, "Auto Destroy", CreateDetour([=]()
	{
		Variables::autoDestroy = true;

	}), "OFF", CreateDetour([=]()
	{

		Variables::autoDestroy = false;

	}), "gray is a cunt"));

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", -1, -1, "World Triggers", CreateDetour([=]()
	{
		Variables::worldTriggers = true;

	}), "OFF", CreateDetour([=]()
	{

		Variables::worldTriggers = false;

	}), "kiwi is stupid"));

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", -1, 0, "Fly", CreateDetour([=]()
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

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", 0, -1, "OFF", CreateDetour([=]()
	{
		Variables::g_Discord->Shutdown();

	}), "DiscordRPC", CreateDetour([=]()
	{

		Variables::g_Discord->Initalize();

	}), "why do you even read this?"));

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", -3, -2, "OFF", CreateDetour([=]()
	{
		Variables::antiPortal = false;
	}), "Anti-Portal", CreateDetour([=]()
	{
		Variables::antiPortal = true;
	}), "nigger"));

	QuickMenuButtons.push_back(new ToggleButton("UIElementsMenu", -1, -2, "Offline", CreateDetour([=]()
	{
		Variables::offlineMode = true;
	}), "OFF", CreateDetour([=]()
	{
		Variables::offlineMode = false;
	}), "nigger"));

	QuickMenuButtons.push_back(new SingleButton("UIElementsMenu", 1, -2, "Destroy\nPortals", CreateDetour([=]()
	{
		Misc::DestroyPortals();
	}), "dont play this trash game"));
}

void VRCQuickMenu::SetupVRGreenText()
{
	UnityEngine::Vector3 v;
	v.x = 15.f;
	v.y = 20.f;
	v.z = 0.f;

	
	//UnityEngine::Transform* posInHier = UnityEngine::Find(UnityEngine::get_transform(QuickMenuInstance()), IL2CPP::StringNew("ShortcutMenu"));
	UnityEngine::Transform* posInHier = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu");

	//UnityEngine::Transform* EAText = UnityEngine::Find(UnityEngine::get_transform(QuickMenuInstance()), IL2CPP::StringNew("ShortcutMenu/EarlyAccessText"));
	UnityEngine::Transform* EAText = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

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

			auto PlayerText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew(playerString));

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
			UnityEngine::Transform* posInHier = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu");

			UnityEngine::Transform* EAText = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

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

		auto PlayerText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew(playerString));

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
		UnityEngine::Transform* posInHier = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu");

		UnityEngine::Transform* EAText = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

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
	auto PlayerText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/PlayersInRoom"));

	if (PlayerText != nullptr)
		Destroy(PlayerText->get_gameObject(), 0.f);

	UnityEngine::Transform* posInHier = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu");

	UnityEngine::Transform* EAText = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

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
		UnityEngine::Transform* posInHier = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu");

		UnityEngine::Transform* EAText = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

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
		UnityEngine::Transform* posInHier = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu");

		UnityEngine::Transform* EAText = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/EarlyAccessText");

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

		auto PlayerText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew(playerString));

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

		auto PlayerText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew(playerString));

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
	Destroy(QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/VRGreenTitle"))->get_gameObject(), 0.f);

	// Delete Players in room text
	Destroy(QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew("ShortcutMenu/PlayersInRoom"))->get_gameObject(), 0.f);

	// Delete VR Debug Text
	for (size_t i = 0; i < 150; i++)
	{
		std::string debugString = "ShortcutMenu/debugString" + std::to_string(i);

		auto debugText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew(debugString));

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

		auto debugText = QuickMenu::QuickMenuInstance()->get_transform()->Find(IL2CPP::StringNew(debugString));

		if (debugText != nullptr)
		{
			Destroy(debugText->get_gameObject(), 0.f);
		}
		else
		{
			break;
		}
	}

	// Delete Quick Menu buttons
	for (auto& button : QuickMenuButtons)
	{
		Destroy(button->getGameObject(), 0.f);
	}
	QuickMenuButtons.clear();
}
