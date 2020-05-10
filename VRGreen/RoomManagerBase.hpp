#pragma once

#include "UnityEngine/Component.hpp"

struct RoomManagerBase : UnityEngine::Component 
{
	NOIMPLEMENT(RoomManagerBase); 

	static std::string GetRoomId();

	static std::string GetRoomCreatorUserId();
};

