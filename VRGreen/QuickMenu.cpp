#include "QuickMenu.hpp"

#include "IL2CPP/IL2CPP.hpp"

QuickMenu* QuickMenu::QuickMenuInstance() // TODO: delete QuickMenu from func name
{
	using func_t = QuickMenu * (*)();

	func_t func = GetMethod<func_t>(QUICKMENU);

	return func();
}

VRC::Core::APIUser* QuickMenu::SelectedUser()
{
	return (VRC::Core::APIUser*)IL2CPP::GetField(QuickMenuInstance(), "VRC.Core.APIUser");
}
