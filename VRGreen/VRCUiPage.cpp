#include "VRCUiPage.hpp"

#include "IL2CPP/IL2CPP.hpp"

#include "Assembly-CSharp/VRCUiManager.hpp"
#include "HardOffsets.hpp"


VRCUiPage* VRCUiPage::GetPage(std::string path)
{
	using func_t = VRCUiPage * (*)(VRCUiManager* _this, IL2CPP::String* path);

	func_t func = GetMethod<func_t>(GETVRCUIPAGE);

	return func(VRCUiManager::VRCUiManagerInstance(), IL2CPP::StringNew(path));
}
