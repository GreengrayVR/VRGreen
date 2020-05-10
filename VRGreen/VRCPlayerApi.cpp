#include "VRCPlayerApi.h"

#include "ConsoleUtils.hpp"

VRC::SDKBase::VRCPlayerApi* VRC::SDKBase::VRCPlayerApi::GetCurrentVRCPlayerApi()
{
	auto currentPlayer = VRC::Player::CurrentPlayer();

	using func_t = VRC::SDKBase::VRCPlayerApi* (*)(VRC::Player* player);

	func_t func = GetMethod<func_t>(GETVRCPLAYERAPI);

	return func(currentPlayer);
}

inline int VRC::SDKBase::VRCPlayerApi::PlayerId()
{
	using func_t = int(*)(VRCPlayerApi* vrcplayerapi);

	func_t func = GetMethod<func_t>(GETPLAYERID);

	return func(this);
}

inline UnityEngine::Vector3* VRC::SDKBase::VRCPlayerApi::GetPosition()
{
	using func_t = UnityEngine::Vector3* (*)(VRCPlayerApi* vrcplayerapi);

	func_t func = GetMethod<func_t>(GETPLAYERPOSITION);

	return func(this);
}

inline UnityEngine::Quaternion* VRC::SDKBase::VRCPlayerApi::GetRotation()
{
	using func_t = UnityEngine::Quaternion* (*)(VRCPlayerApi* vrcplayerapi);

	func_t func = GetMethod<func_t>(GETPLAYERROTATION);

	return func(this);
}

inline void VRC::SDKBase::VRCPlayerApi::TeleportTo(VRC::SDKBase::VRCPlayerApi* who, VRC::SDKBase::VRCPlayerApi* to)
{
	using get_position = UnityEngine::Vector3(*)(__int64);
	get_position pos = GetMethod<get_position>(GETPLAYERPOSITION);

	using get_rotation = UnityEngine::Quaternion(*)(__int64);
	get_rotation rot = GetMethod<get_rotation>(GETPLAYERROTATION);

	using teleport_fn = void(*)(__int64, UnityEngine::Vector3, UnityEngine::Quaternion);
	teleport_fn function = GetMethod<teleport_fn>(TELEPORTTO);

	__try
	{

		auto position = pos((__int64)to);
		auto rotation = rot((__int64)to);

		function((__int64)who, position, rotation);

	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		ConsoleUtils::Log("__try EXCEPTION");
		return;
	}
}

void VRC::SDKBase::VRCPlayerApi::TeleportTo(VRC::SDKBase::VRCPlayerApi* player)
{
	using get_position = UnityEngine::Vector3(*)(__int64);
	get_position pos = GetMethod<get_position>(GETPLAYERPOSITION);

	using get_rotation = UnityEngine::Quaternion(*)(__int64);
	get_rotation rot = GetMethod<get_rotation>(GETPLAYERROTATION);

	using teleport_fn = void(*)(__int64, UnityEngine::Vector3, UnityEngine::Quaternion);
	teleport_fn function = GetMethod<teleport_fn>(TELEPORTTO);

	auto position = pos((__int64)player);
	auto rotation = rot((__int64)player);

	if (&position == nullptr || &rotation == nullptr)
		return;

	function((__int64)this, position, rotation);
}

void VRC::SDKBase::VRCPlayerApi::SetRunSpeed(float speed)
{
	using func_t = void(*)(VRCPlayerApi* vrcplayerapi, float speed);

	func_t func = GetMethod<func_t>(SETRUNSPEED);

	func(this, speed);
}

void VRC::SDKBase::VRCPlayerApi::SetWalkSpeed(float speed)
{
	using func_t = void(*)(VRCPlayerApi* vrcplayerapi, float speed);

	func_t func = GetMethod<func_t>(SETWALKSPEED);

	func(this, speed);
}

void VRC::SDKBase::VRCPlayerApi::SetJumpImpulse(float impulse)
{
	using func_t = void(*)(VRCPlayerApi* vrcplayerapi, float impulse);

	func_t func = GetMethod<func_t>(SETJUMPIMPULSE);

	func(this, impulse);
}

void VRC::SDKBase::VRCPlayerApi::SetNamePlateColor(UnityEngine::Color* col)
{
	using func_t = void(*)(VRCPlayerApi* vrcplayerapi, UnityEngine::Color* col);

	func_t func = GetMethod<func_t>(SETNAMEPLATECOLOR);

	func(this, col);
}

void VRC::SDKBase::VRCPlayerApi::SetMuteStatus(bool canSpeak, bool canHear)
{
	using func_t = void(*)(VRCPlayerApi* vrcplayerapi, bool canSpeak, bool canHear);

	func_t func = GetMethod<func_t>(SETMUTESTATUS);

	func(this, canSpeak, canHear);
}

