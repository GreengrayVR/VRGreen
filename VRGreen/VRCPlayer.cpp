#include "VRCPlayer.hpp"

#include "IL2CPP/IL2CPP.hpp"

#include "VRC/Player.h"

VRCPlayer* VRCPlayer::GetCurrentVRCPlayer()
{
	return (VRCPlayer*)IL2CPP::GetField(VRC::Player::CurrentPlayer(), "VRCPlayer");
}

VRC::Player* VRCPlayer::getPlayer()
{
	using func_t = VRC::Player* (*)(VRCPlayer* vrcPlayer);

	func_t func = GetMethod<func_t>(PLAYER_FROM_VRCPLAYER);

	return func(this);
}

long long VRCPlayer::get_steamId()
{
	using func_t = long long (*)(VRCPlayer* vrcPlayer);

	func_t func = GetMethod<func_t>(GETSTEAMID);

	return func(this);
}

VRC::Core::ApiAvatar* VRCPlayer::GetApiAvatar()
{
	if (this == nullptr)
		return nullptr;

	using func_t = VRC::Core::ApiAvatar* (*)(VRCPlayer* _this);

	func_t func = GetMethod<func_t>(GETAPIAVATAR);

	return func(this);
}
