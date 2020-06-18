#include "QuickMenu.hpp"

#include "IL2CPP/IL2CPP.hpp"

QuickMenu* QuickMenu::Instance()
{
	using func_t = QuickMenu * (*)();

	func_t func = GetMethod<func_t>(QUICKMENU);

	return func();
}

inline static int32_t quickmenuAPIUserOffset = -3;

VRC::Core::APIUser* QuickMenu::SelectedUser()
{
	if (quickmenuAPIUserOffset == -3)
		quickmenuAPIUserOffset = IL2CPP::ResolveFieldOffset(this, "VRC.Core.APIUser");

	return GetField<VRC::Core::APIUser*>(this, quickmenuAPIUserOffset);
}

void QuickMenu::OnPlayerSelectedByLaser(VRCPlayer* vrcplayer)
{
	using func_t = void (*)(QuickMenu* _this, VRCPlayer* vrcplayer);

	func_t func = GetMethod<func_t>(SELECTYOURSELF2);

	func(this, vrcplayer);
}
