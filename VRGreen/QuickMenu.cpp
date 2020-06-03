#include "QuickMenu.hpp"

#include "IL2CPP/IL2CPP.hpp"

QuickMenu* QuickMenu::Instance()
{
	using func_t = QuickMenu * (*)();

	func_t func = GetMethod<func_t>(QUICKMENU);

	return func();
}

VRC::Core::APIUser* QuickMenu::SelectedUser()
{
	return (VRC::Core::APIUser*)IL2CPP::GetField(this, "VRC.Core.APIUser");
}

void QuickMenu::OnPlayerSelectedByLaser(VRCPlayer* vrcplayer)
{
	using func_t = void (*)(QuickMenu* _this, VRCPlayer* vrcplayer);

	func_t func = GetMethod<func_t>(0x1F516D0);

	func(this, vrcplayer);
}
