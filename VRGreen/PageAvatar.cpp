#include "PageAvatar.hpp"
#include "IL2CPP/IL2CPP.hpp"

//VRC::UI::PageAvatar* VRC::UI::PageAvatar::ctor()
//{
//	auto ret = (VRC::UI::PageAvatar*)IL2CPP::NewObject("VRC.UI.VRCUiPage, Assembly-CSharp");
//	using func_t = VRC::UI::PageAvatar * (*)(Object* _this);
//	func_t func = GetMethod<func_t>(0/x1EA1C60);
//	func(ret);
//	return ret;
//}

void VRC::UI::PageAvatar::ChangeToSelectedAvatar()
{
	using func_t = void (*)(PageAvatar* _this);
	func_t func = GetMethod<func_t>(CHANGETOSELECTEDAVATAR);
	func(this);
}
