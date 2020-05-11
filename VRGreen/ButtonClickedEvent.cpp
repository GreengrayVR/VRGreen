#include "ButtonClickedEvent.h"

#include "QuickMenu.hpp"
#include "Button.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "UnityEngine/Transform.hpp"
#include "ConsoleUtils.hpp"
#include "UnityEngine/Object.hpp"

using namespace UnityEngine::UI;

ButtonClickedEvent* ButtonClickedEvent::ctor()
{
	auto onclickTemplate = QuickMenu::QuickMenuInstance()->get_transform()->Find("ShortcutMenu/WorldsButton")->GetComponent("UnityEngine.UI.Button");

	auto buttonClickedEvent = (ButtonClickedEvent*)IL2CPP::NewObjectFromObject(((Button*)onclickTemplate)->GetOnClick(), false);

	using func_t = void (*)(ButtonClickedEvent* _this);
	func_t func = GetMethod<func_t>(0x14B7810);
	func(buttonClickedEvent);

	return buttonClickedEvent;
}
