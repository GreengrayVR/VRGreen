#include "VRC/Player.h"
#include "IL2CPP/IL2CPP.hpp"
#include "UnityEngine/Transform.hpp"
#include "ConsoleUtils.hpp"

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
	using func_t = Player * (*)();

	func_t func = GetMethod<func_t>(PLAYERCURRENTUSER);

	return func();
}

VRC::Core::APIUser* VRC::Player::GetAPIUser()
{
	return (Core::APIUser*)IL2CPP::GetField(this, "VRC.Core.APIUser");
}

VRCPlayer* VRC::Player::GetVRCPlayer()
{
	return (VRCPlayer*)IL2CPP::GetField(this, "VRCPlayer");
}

UnityEngine::Transform* VRC::Player::BoneTransform()
{
	Object* animator = IL2CPP::GetField((Object*)this->GetVRCPlayer(), "UnityEngine.Animator");

	if (animator == nullptr)
	{
		ConsoleUtils::Log("nullptr");
		return nullptr;
	}

	using func_t = UnityEngine::Transform * (*)(Object* animator, int humanBoneId);
	func_t func = GetMethod<func_t>(0x1D47E20);
	return func(animator, 10)->get_transform();
}

VRC::SDKBase::VRCPlayerApi* VRC::Player::GetVRCPlayerApi()
{
	if (this == nullptr)
		return nullptr;

	using func_t = SDKBase::VRCPlayerApi* (*)(Player* player);

	func_t func = GetMethod<func_t>(GETVRCPLAYERAPI);

	return func(this);
}
