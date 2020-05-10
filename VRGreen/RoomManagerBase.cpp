#include "RoomManagerBase.hpp"

#include "HardOffsets.hpp"
#include "IL2CPP/IL2CPP.hpp"

std::string RoomManagerBase::GetRoomId()
{
	using func_t = IL2CPP::String* (*)();

	func_t func = GetMethod<func_t>(GETROOMID);


	return IL2CPP::StringChars(func());
}

std::string RoomManagerBase::GetRoomCreatorUserId()
{
	using func_t = IL2CPP::String* (*)();

	func_t func = GetMethod<func_t>(0x2DE7AB0);


	return IL2CPP::StringChars(func());
}
