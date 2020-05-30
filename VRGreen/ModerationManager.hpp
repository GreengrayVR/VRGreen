#pragma once

#include "UnityEngine/Component.hpp"

namespace IL2CPP { struct String; }

struct ModerationManager : UnityEngine::Component
{
	NOIMPLEMENT(ModerationManager);

	static ModerationManager* Instance();

	bool IsBlockedEitherWay(IL2CPP::String* userid);

	bool IsBlockedEitherWay(const std::string& userid);
};
