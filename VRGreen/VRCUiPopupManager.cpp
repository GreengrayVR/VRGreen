#include "VRCUiPopupManager.hpp"



VRCUiPopupManager* VRCUiPopupManager::VRCUiPopupManagerInstance()
{
	using func_t = VRCUiPopupManager * (*)();

	func_t func = GetMethod<func_t>(VRCUIPOPUPMANAGER);

	return func();
}

void VRCUiPopupManager::ShowAlert(std::string str1, std::string str2, float delay)
{
	using func_t = void(*)(VRCUiPopupManager* _this, IL2CPP::String* str1, IL2CPP::String* str2, float delay);

	func_t func = GetMethod<func_t>(SHOWALERT);

	func(this, IL2CPP::StringNew(str1), IL2CPP::StringNew(str2), delay);
}
