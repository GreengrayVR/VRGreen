#include "ModerationManager.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "HardOffsets.hpp"

ModerationManager* ModerationManager::Instance()
{
	using func_t = ModerationManager*(*)();
	func_t func = GetMethod<func_t>(MODERATIONMANAGER_INSTANCE);
	return func();
}

bool ModerationManager::IsBlockedEitherWay(IL2CPP::String* userid)
{
	using func_t = bool(*)(Object* _this, IL2CPP::String* user_id);
	func_t func = GetMethod<func_t>(BLOCKEITHERWAY);
	return func(this, userid);
}

bool ModerationManager::IsBlockedEitherWay(const std::string& userid)
{
	return IsBlockedEitherWay(IL2CPP::StringNew(userid));
}


