#include "VRCUiManager.hpp"



VRCUiManager* VRCUiManager::VRCUiManagerInstance()
{
	using func_t = VRCUiManager * (*)();

	func_t func = GetMethod<func_t>(VRCUIMANAGER);

	return func();
}

//VRCUiManager* VRCUiManager::VRCUiManagerInstance2()
//{
//	using func_t = VRCUiManager * (*)();
//
//	func_t func = GetMethod<func_t>(0/x/2C2E2F0);
//
//	return func();
//}

void VRCUiManager::HudMsg(std::string text)
{
	using func_t = void (*)(VRCUiManager* _this, IL2CPP::String* text);

	func_t func = GetMethod<func_t>(HUDMSG);

	func(this, IL2CPP::StringNew(text));
}

//void VRCUiManager::HudMsg2(std::string text)
//{
//	using func_t = void (*)(VRCUiManager* _this, IL2CPP::String* text);
//
//	func_t func = GetMethod<func_t>(0//x2//C2C550);
//
//	func(this, IL2CPP::StringNew(text));
//}
