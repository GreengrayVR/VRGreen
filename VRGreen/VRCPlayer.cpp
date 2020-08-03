#include "VRCPlayer.hpp"

#include "IL2CPP/IL2CPP.hpp"
#include "UnityEngine/Transform.hpp"
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

int VRCPlayer::GetPing()
{
	using func_t = short (*)(VRCPlayer* _this);

	func_t func = GetMethod<func_t>(0x185D460); // or 0x185D460

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

inline static int32_t forceMuteOffset = -3;

void VRCPlayer::ForceMute(bool value)
{
	if (forceMuteOffset == -3)
		forceMuteOffset = IL2CPP::ResolveFieldOffset(this, "System.Boolean", 10);

	SetField(this, forceMuteOffset, !value);
}

inline static int32_t namePlateOffset = -3;

VRCUiShadowPlate* VRCPlayer::getNamePlate()
{
	if (namePlateOffset == -3)
		namePlateOffset = IL2CPP::ResolveFieldOffset(this, "namePlate");

	return GetField<VRCUiShadowPlate*>(this, namePlateOffset);
}

inline static int32_t vipPlateOffset = -3;

VRCUiShadowPlate* VRCPlayer::getVipPlate()
{
	if (vipPlateOffset == -3)
		vipPlateOffset = IL2CPP::ResolveFieldOffset(this, "vipPlate");

	return GetField<VRCUiShadowPlate*>(this, vipPlateOffset);
}
