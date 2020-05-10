#include "ApiWorldInstance.hpp"



std::string VRC::Core::ApiWorldInstance::GetAccessType()
{
	if (this == nullptr)
		return "";

	using func_t = uint32_t * (*)(ApiWorldInstance* _this);

	func_t func = GetMethod<func_t>(GETACCESSTYPE);

	auto accesstype = func(this);

	if (accesstype == nullptr)
		return "";

	switch ((int)accesstype)
	{
	case 0:
		return "Public";
	case 1:
		return "Friends of Guests";
	case 2:
		return "Friends Only";
	case 3:
		return "Invite Only";
	case 4:
		return "Invite+";
	case 5:
		return "Counter";
	default:
		return "none";
	}
}
