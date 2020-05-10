#include "Networking.hpp"

#include "IL2CPP/IL2CPP.hpp"

bool VRC::SDKBase::Networking::GoToRoom(std::string roomID)
{
	using GoToRoomFunc_t = bool(*)(IL2CPP::String* roomID);

	GoToRoomFunc_t func = GetMethod<GoToRoomFunc_t>(GOTOROOM);


	return func(IL2CPP::StringNew(roomID.c_str()));
}

UnityEngine::GameObject* VRC::SDKBase::Networking::Instantiate(int broadcast, std::string prefabPathOrDynamicPrefabName, UnityEngine::Vector3 position, UnityEngine::Quaternion rotation)
{
	using func_t = UnityEngine::GameObject* (*)(int broadcast, IL2CPP::String* methodName, UnityEngine::Vector3 position, UnityEngine::Quaternion rotation);

	func_t func = GetMethod<func_t>(0x16D2C50);

	return func(broadcast, IL2CPP::StringNew(prefabPathOrDynamicPrefabName), position, rotation);
}

void VRC::SDKBase::Networking::RPC(int targetClients, UnityEngine::GameObject* targetObject, std::string methodName, ObjectArray* parameters)
{
	using func_t = void(*)(int targetClients, UnityEngine::GameObject* targetObject, IL2CPP::String* methodName, ObjectArray* parameters);

	func_t func = GetMethod<func_t>(0x16D3060);

	func(targetClients, targetObject, IL2CPP::StringNew(methodName), parameters);
}
