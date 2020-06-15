#include "ApiAvatar.hpp"
#include "VRCPlayer.hpp"
#include "Utils/Offsets.h"
#include "IL2CPP/IL2CPP.hpp"
#include "ConsoleUtils.hpp"
#include "VRC/Core/APIUser.hpp"

VRC::Core::ApiAvatar* VRC::Core::ApiAvatar::ctor()
{
	auto ret = (VRC::Core::ApiAvatar*)IL2CPP::NewObject("VRC.Core.ApiAvatar, VRCCore-Standalone");
	using func_t = void (*)(Object* _this);
	func_t func = GetMethod<func_t>(APIAVATARCTOR);
	func(ret);
	return ret;
}

std::string VRC::Core::ApiAvatar::GetAssetURL()
{
	if (this == nullptr)
		return "Asset URL is null";

	using func_t = IL2CPP::String* (*)(ApiAvatar* _this);

	func_t func = GetMethod<func_t>(GETASSETURL);

	auto x = func(this);

	if (x == nullptr)
		return "WTF";

	return IL2CPP::StringChars(x);
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

std::string VRC::Core::ApiAvatar::Id() // TODO: proper inheritance with ApiModel
{
	return ((VRC::Core::APIUser*)this)->getId();
}

void VRC::Core::ApiAvatar::SetId(const std::string& id) // TODO: proper inheritance with ApiModel
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("ApiAvatar is nullptr");
		return;
	}

	using func_t = void (*)(ApiAvatar* _this, IL2CPP::String* id);
	func_t func = GetMethod<func_t>(APIMODELSETID);
	func(this, IL2CPP::StringNew(id));
}
