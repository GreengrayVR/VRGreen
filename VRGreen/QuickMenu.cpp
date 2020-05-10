#include "QuickMenu.hpp"



QuickMenu* QuickMenu::QuickMenuInstance() // TODO: delete QuickMenu from func name
{
	using func_t = QuickMenu * (*)();

	func_t func = GetMethod<func_t>(QUICKMENU);

	return func();
}
