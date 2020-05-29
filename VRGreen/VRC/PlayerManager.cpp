#include "PlayerManager.hpp"

#include "IL2CPP/IL2CPP.hpp"
#include "HardOffsets.hpp"


VRC::Player* VRC::PlayerManager::GetPlayer(IL2CPP::String* userId)
{
	using func_t = Player * (*)(IL2CPP::String* userId);

	func_t func = GetMethod<func_t>(PLAYERGETPLAYER);

	return func(userId);
}

IL2CPP::Array* VRC::PlayerManager::GetPlayers()
{
	using func_t = IL2CPP::Array* (*)();

	func_t func = GetMethod<func_t>(GETALLPLAYERS); // or 0/x29854B0

	return func();
}

//VRC::Player* VRC::PlayerManager::GetPlayer(int photonId)
//{
//	using func_t = Player * (*)(int photonId);
//
//	func_t func = GetMethod<func_t>(0/x2989D50); // 0/x2989D50
//
//	return func(photonId);
//}

VRC::Player* VRC::PlayerManager::GetPlayer(std::string userId)
{
	using func_t = Player * (*)(IL2CPP::String* userId);

	func_t func = GetMethod<func_t>(PLAYERGETPLAYER);

	return func(IL2CPP::StringNew(userId));
}
