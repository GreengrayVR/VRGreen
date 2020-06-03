#include "APIUser.hpp"

#include "IL2CPP/IL2CPP.hpp"

bool VRC::Core::APIUser::isFriendsWith(IL2CPP::String* userId) // isFriendsWith
{
	using IsFriendsFunc_t = bool(*)(IL2CPP::String* userId);

	IsFriendsFunc_t isFriendsFunc = GetMethod<IsFriendsFunc_t>(ISFRIENDSWITH);

	return isFriendsFunc(userId);
}

bool VRC::Core::APIUser::isFriendsWith(const std::string& userId) // isFriendsWith
{
	return isFriendsWith(IL2CPP::StringNew(userId.c_str()));
}

bool VRC::Core::APIUser::hasTag(const std::string& userId) // hasTag(string tag)
{
	if (this == nullptr)
	{
		return false;
	}

	using HasTagFunc_t = bool(*)(APIUser* user, IL2CPP::String* userId);

	HasTagFunc_t hasTagFunc = GetMethod<HasTagFunc_t>(HASTAG);

	return hasTagFunc(this, IL2CPP::StringNew(userId.c_str()));
}

VRC::Core::APIUser* VRC::Core::APIUser::currentUser() // public static APIUser get_CurrentUser
{
	using currentUser_t = APIUser * (*)();

	currentUser_t currentUserFunc = GetMethod<currentUser_t>(CURRENTUSER);

	return currentUserFunc();
}

std::string VRC::Core::APIUser::displayName() // get_displayName()
{
	if (this == nullptr)
	{
		return "give me money";
	}

	using displayNameFunc_t = IL2CPP::String* (*)(APIUser* apiuser);

	displayNameFunc_t displayNameFunc = GetMethod<displayNameFunc_t>(DISPLAYNAME); //

	return IL2CPP::StringChars(displayNameFunc(this));
}

std::string VRC::Core::APIUser::getId()
{
	if (this == nullptr)
	{
		return "VRChat is retarded";
	}

	using func_t = IL2CPP::String* (*)(APIUser* apiuser);

	func_t displayNameFunc = GetMethod<func_t>(GETID); //

	return IL2CPP::StringChars(displayNameFunc(this));
}

std::string VRC::Core::APIUser::getVRCA()
{
	if (this == nullptr)
	{
		return "kill me pls";
	}

	using func_t = IL2CPP::String* (*)(VRC::Core::APIUser* apiuser);

	func_t func = GetMethod<func_t>(VRCAURL);

	return IL2CPP::StringChars(func(this));
}

std::string VRC::Core::APIUser::getLocation()
{
	using func_t = IL2CPP::String* (*)(VRC::Core::APIUser* apiuser);

	func_t func = GetMethod<func_t>(0x5121E0);

	return IL2CPP::StringChars(func(this));
}
