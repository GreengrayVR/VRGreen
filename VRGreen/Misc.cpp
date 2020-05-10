#include "Misc.hpp"

#include "UnityEngine/Quaternion.hpp"
#include "ApiAvatar.hpp"
#include "VRC/SDKBase/Networking.hpp"
#include "VRCPlayer.hpp"
#include "VRC/PlayerManager.hpp"
#include "VRC/Core/APIUser.hpp"
#include "VRCPlayerApi.h"
#include "ConsoleUtils.hpp"

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

void Misc::DropPortal(VRC::Player* player)
{
	std::string world = "wrld_5eef3063-6226-4ea3-b727-7b3478e85c23";
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
		auto apiuser = players[i]->GetAPIUser();
		auto vrcplayerapi = players[i]->GetVRCPlayerApi();

		if (apiuser->getId() != VRC::Core::APIUser::currentUser()->getId())
		{
			vrcplayerapi->TeleportTo(VRC::SDKBase::VRCPlayerApi::GetCurrentVRCPlayerApi());
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


	//IL2CPP::Class* playerClass = IL2CPP::ObjectGetClass(players[0]);

	//ConsoleUtils::Log("1");

	//IL2CPP::Type* playerType = IL2CPP::ClassGetType(playerClass);

	//ConsoleUtils::Log("2");
	//ConsoleUtils::Log(IL2CPP::TypeToString(playerType));

	////ConsoleUtils::Log("3");


	//IL2CPP::GetFields(roomManagerBase);
	// 




	/*auto typeString = IL2CPP::TypeToString(int32type);

	ConsoleUtils::Log(typeString);*/




	std::cout
		<< cyan << "Current World Id:\n" << RoomManagerBase::GetRoomId() << blue
		<< "\nVRCA URL:\n" << VRC::Core::APIUser::currentUser()->getVRCA() << "\n"
		<< "\nPlayers in world: " << players.arrayLength << "\n";




	for (size_t i = 0; i < players.arrayLength; i++)
	{
		auto apiuser = players[i]->GetAPIUser();
		auto rank = GetUserRankName(apiuser);
		bool friends = VRC::Core::APIUser::isFriendsWith(apiuser->getId());
		auto vrcplayer = (VRCPlayer*)IL2CPP::GetField(players[i], "VRCPlayer", false);




		if (apiuser->hasTag("admin"))
			std::cout << red << "[ADMIN] " << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_legend"))
			std::cout << red << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_legend"))
			std::cout << yellow << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_veteran"))
			std::cout << magenta << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_trusted"))
			std::cout << darkmagenta << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_known"))
			std::cout << green << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else if (apiuser->hasTag("system_trust_basic"))
			std::cout << blue << (friends ? "[F]" : "") << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << " [" << vrcplayer->get_steamId() << "]" << "\n" << vrcplayer->GetApiAvatar()->GetAssetURL() << "\n";
		else
			std::cout << white << apiuser->displayName() << " " << white << "[" << apiuser->getId() << "]" << "\n";
	}
	std::cout << white;
}

std::string Misc::GetSocialRankForPlayerList(VRC::Player* player)
{
	auto vrcplayer = (VRCPlayer*)IL2CPP::GetField(player, "VRCPlayer", false);
	auto apiuser = player->GetAPIUser();

	std::string text = "<color=red><b>";

	text += (vrcplayer->get_steamId() == 0 ? "[H]" : "");
	text += (VRC::Core::APIUser::isFriendsWith(apiuser->getId()) ? "[F]" : "");
	text += "</b></color> ";

	text += GetUserRank(apiuser);

	return text;
}

std::string Misc::GetSocialRankForPlayerListShadow(VRC::Player* player)
{
	auto vrcplayer = (VRCPlayer*)IL2CPP::GetField(player, "VRCPlayer", false);
	auto apiuser = player->GetAPIUser();

	std::string text = "<color=black><b>";

	text += (vrcplayer->get_steamId() == 0 ? "[H]" : "");
	text += (VRC::Core::APIUser::isFriendsWith(apiuser->getId()) ? "[F]" : "");
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
	std::string displayName = apiuser->displayName();

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
