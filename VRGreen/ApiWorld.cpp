#include "ApiWorld.hpp"

#include "IL2CPP/IL2CPP.hpp"

std::string VRC::Core::ApiWorld::GetName()
{
	if (this == nullptr)
		return "Loading";

	using func_t = IL2CPP::String* (*)(ApiWorld* _this);

	func_t func = GetMethod<func_t>(APIWORLDNAME);

	return IL2CPP::StringChars(func(this));
}

std::string VRC::Core::ApiWorld::assetUrl()
{
	using func_t = IL2CPP::String* (*)(ApiWorld* _this);

	func_t func = GetMethod<func_t>(0x484430);

	return IL2CPP::StringChars(func(this));
}

int VRC::Core::ApiWorld::GetCapacity()
{
	using func_t = int (*)(ApiWorld* _this);

	func_t func = GetMethod<func_t>(0x44E370);

	return func(this);
}
