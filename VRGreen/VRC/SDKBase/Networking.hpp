#pragma once

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Quaternion.hpp"

namespace VRC::SDKBase
{
	struct Networking
	{
		static bool GoToRoom(std::string roomID);

		static UnityEngine::GameObject* Instantiate(int broadcast, std::string prefabPathOrDynamicPrefabName, UnityEngine::Vector3 position, UnityEngine::Quaternion rotation);

		static void RPC(int targetClients, UnityEngine::GameObject* targetObject, std::string methodName, ObjectArray* parameters);
	};
}