#include "Discord.hpp"

#include "IL2CPP/IL2CPP.hpp"

#include "ApiWorldInstance.hpp"
#include "ApiWorld.hpp"
#include "ApiAvatar.hpp"
#include "VRC/PlayerManager.hpp"
#include "List.hpp"
#include "VRC/Core/APIUser.hpp"
#include "VRCPlayer.hpp"



namespace VRC
{
	struct Player;
}

void Discord::Initalize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize("646253963519197185", &Handle, 1, NULL);
}

void Discord::Update()
{
	auto roomManagerBase = IL2CPP::NewObject("RoomManagerBase, Assembly-CSharp");

	auto apiWorld = (VRC::Core::ApiWorld*)IL2CPP::GetField(roomManagerBase, "VRC.Core.ApiWorld");
	auto apiWorldInstance = (VRC::Core::ApiWorldInstance*)IL2CPP::GetField(roomManagerBase, "VRC.Core.ApiWorldInstance");

	if (apiWorld == nullptr || apiWorldInstance == nullptr)
	{

		return;
	}

	List<VRC::Player*> players(VRC::PlayerManager::GetPlayers());

	std::string state = "In " + std::string(apiWorld->GetName()) + "";

	std::string state2 = apiWorldInstance->GetAccessType()
		+ " [Players: " + std::to_string((int)players.arrayLength) + "]";

	std::string avatar =
		"in [" + VRCPlayer::GetCurrentVRCPlayer()->GetApiAvatar()->GetName() + "] made by ["
		+ VRCPlayer::GetCurrentVRCPlayer()->GetApiAvatar()->GetAuthorName() + "]";

	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.state = state2.c_str();
	discordPresence.details = state.c_str();
	discordPresence.startTimestamp = eptime;
	discordPresence.endTimestamp = NULL;
	discordPresence.largeImageKey = "iypop8j";
	discordPresence.largeImageText = std::string("as [" + VRC::Core::APIUser::currentUser()->displayName() + "]").c_str();
	discordPresence.smallImageKey = "smallimage";
	discordPresence.smallImageText = avatar.c_str();
	discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
	//discordPresence.partySize = (int)players.arrayLength;
	//discordPresence.partyMax = 1337;
	discordPresence.joinSecret = "MTI4NzM0OjFpMmhuZToxMjMxMjM= ";
	Discord_UpdatePresence(&discordPresence);
}

void Discord::Shutdown()
{
	Discord_Shutdown();
}

std::string Discord::GetLargeImageKey()
{
	if (imageCounter >= 14)
		imageCounter = 0;
	return "image0" + std::to_string(imageCounter++);
}
