#include "ApiAvatar.hpp"
#include "VRCPlayer.hpp"
#include "Utils/Offsets.h"
#include "IL2CPP/IL2CPP.hpp"
#include "ConsoleUtils.hpp"


std::string VRC::Core::ApiAvatar::GetAssetURL()
{
	using func_t = IL2CPP::String* (*)(ApiAvatar* _this);

	func_t func = GetMethod<func_t>(GETASSETURL);

	return IL2CPP::StringChars(func(this));
}

std::string VRC::Core::ApiAvatar::GetName()
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("ApiAvatar is nullptr");
		return "ERROR";
	}

	using func_t = IL2CPP::String* (*)(ApiAvatar* _this);

	func_t func = GetMethod<func_t>(APIAVATARNAME);

	auto str = func(this);

	if (str == nullptr)
	{
		ConsoleUtils::Log("GetAuthorName is nullptr");
		return "ERROR";
	}
	else
	{
		return IL2CPP::StringChars(str);
	}
}

std::string VRC::Core::ApiAvatar::GetAuthorName()
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("ApiAvatar is nullptr");
		return "ERROR";
	}

	using func_t = IL2CPP::String* (*)(ApiAvatar* _this);

	func_t func = GetMethod<func_t>(AUTHORNAME);

	auto str = func(this);

	if (str == nullptr)
	{
		ConsoleUtils::Log("GetAuthorName is nullptr");
		return "ERROR";
	}
	else
	{
		return IL2CPP::StringChars(str);
	}
}
