#include "VRC/Player.h"
#include "IL2CPP/IL2CPP.hpp"

std::string VRC::Player::ToString() // public override string ToString()
{
	if (this == nullptr) // TODO: delete this plz
		return "'ERROR'";

	using ToStringFunc_t = IL2CPP::String* (*)(Player* player);

	ToStringFunc_t ToStringFunc = GetMethod<ToStringFunc_t>(PLAYERTOSTRING);

	return IL2CPP::StringChars(ToStringFunc(this));
}

VRC::Player* VRC::Player::CurrentPlayer()
{
	// 
	using func_t = Player * (*)();

	func_t func = GetMethod<func_t>(PLAYERCURRENTUSER);

	return func();
}

VRC::Core::APIUser* VRC::Player::GetAPIUser()// class Player : MonoBehaviour
{
	return (Core::APIUser*)IL2CPP::GetField(this, "VRC.Core.APIUser");
}

VRCPlayer* VRC::Player::GetVRCPlayer()
{
	return (VRCPlayer*)IL2CPP::GetField(this, "VRCPlayer");
}

VRC::SDKBase::VRCPlayerApi* VRC::Player::GetVRCPlayerApi()
{
	if (this == nullptr)
		return nullptr;

	using func_t = SDKBase::VRCPlayerApi* (*)(Player* player);

	func_t func = GetMethod<func_t>(GETVRCPLAYERAPI);

	return func(this);
}
