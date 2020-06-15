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

inline static int32_t apiuserOffset = -3;

VRC::Core::APIUser* VRC::Player::GetAPIUser()
{
	if (this == nullptr) return nullptr;

	if (apiuserOffset == -3)
		apiuserOffset = IL2CPP::ResolveFieldOffset(this, "VRC.Core.APIUser");

	return GetField<VRC::Core::APIUser*>(this, apiuserOffset);
}

inline static int32_t vrcplayerOffset = -3;

VRCPlayer* VRC::Player::GetVRCPlayer()
{
	if (this == nullptr) return nullptr;

	if (vrcplayerOffset == -3)
		vrcplayerOffset = IL2CPP::ResolveFieldOffset(this, "VRCPlayer");

	return GetField<VRCPlayer*>(this, vrcplayerOffset);
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
	func_t func = GetMethod<func_t>(GETBONETRANSFORM);
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
