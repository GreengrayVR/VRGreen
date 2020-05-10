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
