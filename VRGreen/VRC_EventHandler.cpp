#include "VRC_EventHandler.hpp"

#include "Common.hpp"

int VRC::SDKBase::VRC_EventHandler::GetNetworkID()
{
	using func_t = int(*)(VRC_EventHandler* _this);

	func_t func = GetMethod<func_t>(0x4E4980);

	return func(this);
}
