#include "ButtonAPI.hpp"

#include "IL2CPP/IL2CPP.hpp"
#include "UnityEvent.h"
#include "ButtonClickedEvent.h"
#include "Text.hpp"
#include "ConsoleUtils.hpp"

using namespace UnityEngine;


UnityEngine::GameObject* ButtonBase::getGameObject()
{
	return button;
}

void ButtonBase::setActive(bool isActive)
{
	getGameObject()->SetActive(isActive);
}

void ButtonBase::setLocation(int buttonXLoc, int buttonYLoc)
{
	auto quickMenu = QuickMenu::QuickMenuInstance();



	auto v1 = quickMenu->get_transform()->Find("UserInteractMenu/ForceLogoutButton")->GetLocalPosition().x; // TODO: DELETE THIS
	auto v2 = quickMenu->get_transform()->Find("UserInteractMenu/ForceLogoutButton")->GetLocalPosition().x;
	float num = v1 - v2;
	float num2 = v1 - v2;

	auto transform = getGameObject()->GetTransform();
	Vector3 transformVector;
	transformVector.x = transform->GetLocalPosition().x + num * buttonXLoc;
	transformVector.y = transform->GetLocalPosition().y + num2 * buttonYLoc;
	transformVector.z = transform->GetLocalPosition().z;

	transform->SetLocalPosition(&transformVector);


	btnTag = "(" + std::to_string(buttonXLoc) + std::string(",") + std::to_string(buttonYLoc) + ")";
	SetName(button, btnQMLoc + "/" + btnType + btnTag);

	
	SetName(transform->GetComponent("UnityEngine.UI.Button"), btnType + btnTag);
}

void ButtonBase::setToolTip(std::string buttonToolTip)
{
	auto type = IL2CPP::GetType("UiTooltip, Assembly-CSharp");
	auto component = button->GetComponent(type);

	auto text = IL2CPP::ClassGetFieldFromName(component, "text");
	auto alternateTooltip = IL2CPP::ClassGetFieldFromName(component, "alternateText");

	IL2CPP::FieldSetValueObject(component, text, IL2CPP::StringNew("<color=red>" + buttonToolTip + "</color>"));
	IL2CPP::FieldSetValueObject(component, alternateTooltip, IL2CPP::StringNew("<color=red>" + buttonToolTip + "</color>"));
}

UnityEngine::Transform* ButtonBase::FindInQuickMenu(std::string str)
{
	return QuickMenu::QuickMenuInstance()->get_transform()->Find(str);
}

void ButtonBase::TestFunc()
{
	ConsoleUtils::Log("nigger");
}

UnityEngine::Transform* ButtonBase::InstantiateGameobject(std::string type)
{
	const static std::unordered_map<std::string, int> string_to_case{
	   {"back",					1},
	   {"nameplates",			2},
	   {"block1",				3},
	   {"next",					4},
	   {"prev",					5},
	   {"emojimenu",			6},
	   {"userinteractmenu",		7},
	   {"block",				8},
	   {"menu",					9}
	};

	auto quickMenu = QuickMenu::QuickMenuInstance();

	switch (string_to_case.at(type))
	{
	case 1:
	{
		auto nig = quickMenu->get_transform()->Find("CameraMenu/BackButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 2:
	{
		auto nig = quickMenu->get_transform()->Find("UIElementsMenu/ToggleNameplatesButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 3:
	{
		auto nig = quickMenu->get_transform()->Find("NotificationInteractMenu/BlockButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 4:
	{
		auto nig = quickMenu->get_transform()->Find("QuickMenu_NewElements/_CONTEXT/QM_Context_User_Selected/NextArrow_Button")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 5:
	{
		auto nig = quickMenu->get_transform()->Find("QuickMenu_NewElements/_CONTEXT/QM_Context_User_Selected/PreviousArrow_Button")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 6:
	{
		auto nig = quickMenu->get_transform()->Find("EmojiMenu")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 7:
	{
		auto nig = quickMenu->get_transform()->Find("UserInteractMenu")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 8:
	{
		auto nig = quickMenu->get_transform()->Find("UserInteractMenu/BlockButton")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	case 9:
	{
		auto nig = quickMenu->get_transform()->Find("CameraMenu")->get_gameObject();
		auto gameObject = (UnityEngine::GameObject*)Instantiate(nig);
		return gameObject->GetTransform();
		break;
	}
	return nullptr;
	}
}

UnityEngine::Transform* ButtonBase::CreateButton(std::string name, std::string type, std::string text, std::string tooltip, float x_pos, float y_pos, Transform* parent, lambda_t action)
{
	Transform* transform = InstantiateGameobject(type);
	auto quickMenu = QuickMenu::QuickMenuInstance();

	
	auto v1 = quickMenu->get_transform()->Find("UserInteractMenu/ForceLogoutButton")->GetLocalPosition().x; // TODO: change local position
	auto v2 = quickMenu->get_transform()->Find("UserInteractMenu/ForceLogoutButton")->GetLocalPosition().x;
	float num = v1 - v2;
	float num2 = v1 - v2;

	SetName(transform, name);

	Vector3 transformVector;
	transformVector.x = transform->GetLocalPosition().x + num * x_pos;
	transformVector.y = transform->GetLocalPosition().y + num2 * y_pos;
	transformVector.z = transform->GetLocalPosition().z;

	transform->SetLocalPosition(&transformVector);
	transform->SetParent(parent, false);

	{
		auto component = transform->GetChild(0)->GetComponent("UnityEngine.UI.Text"); // TODO: Change to SetText()
		auto m_Text = IL2CPP::ClassGetFieldFromName(component, "m_Text");
		IL2CPP::FieldSetValueObject(component, m_Text, IL2CPP::StringNew(text));
	}

	{
		UI::Button* L_0 = (UI::Button*)transform->GetComponent("UnityEngine.UI.Button");
		auto L_1 = (UI::ButtonClickedEvent*)IL2CPP::NewObjectFromObject(L_0->GetOnClick(), false);
		L_1->ButtonClickedEvent_ctor();
		L_0->SetOnClick(L_1);
	}

	{
		UI::Button* L_2 = (UI::Button*)transform->GetComponent("UnityEngine.UI.Button");
		UI::ButtonClickedEvent* L_3 = L_2->GetOnClick();
		auto L_4 = (Events::UnityAction*)IL2CPP::NewObject("UnityEngine.Events.UnityAction, UnityEngine"); // TODO: put this inside of the struct
		Events::UnityAction::ctor(L_4, nullptr, (intptr_t)TestFunc);
		using func_t = void(*)();
		*((func_t*)L_4 + 2) = action;

		auto unityeven = (Events::UnityEvent*)L_3;
		unityeven->AddListener(L_4);
	}

	return transform;
}

SingleButton::SingleButton(std::string btnMenu, int btnXLocation, int btnYLocation, std::string btnText, CDetour* btnAction, std::string btnToolTip, Color* btnBackgroundColor /*= nullptr*/, Color* btnTextColor /*= nullptr*/)
{
	btnQMLoc = btnMenu;
	btnType = "SingleButton";
	initButton(btnXLocation, btnYLocation, btnText, btnAction, btnToolTip, btnBackgroundColor, btnTextColor);
}

void SingleButton::setButtonText(std::string buttonText)
{
	auto component = (UI::Text*)getGameObject()->GetTransform()->GetChild(0)->GetComponent("UnityEngine.UI.Text");
	component->SetText(buttonText);
}

void SingleButton::setAction(CDetour* buttonAction)
{
	// button.GetComponent<Button>().onClick = new Button.ButtonClickedEvent();
	{
		auto L_0 = (UI::Button*)getGameObject()->GetTransform()->GetComponent("UnityEngine.UI.Button");
		
		auto L_1 = (UI::ButtonClickedEvent*)IL2CPP::NewObjectFromObject(L_0->GetOnClick(), false);
		L_1->ButtonClickedEvent_ctor();
		L_0->SetOnClick(L_1);
	}
	//button.GetComponent<Button>().onClick.AddListener(buttonAction);
	{
		UI::Button* L_2 = (UI::Button*)getGameObject()->GetTransform()->GetComponent("UnityEngine.UI.Button");
		UI::ButtonClickedEvent* L_3 = L_2->GetOnClick();
		auto L_4 = (Events::UnityAction*)IL2CPP::NewObject("UnityEngine.Events.UnityAction, UnityEngine");
		Events::UnityAction::ctor(L_4, nullptr, (intptr_t)TestFunc);
		using func_t = void(*)();
		*((func_t*)L_4 + 2) = buttonAction->GetFuncPointer();
		auto unityevent = (Events::UnityEvent*)L_3;
		unityevent->AddListener(L_4);
	}
}

void SingleButton::setBackgroundColor(Color* buttonBackgroundColor)
{
	//button.GetComponentInChildren<UnityEngine.UI.Image>().color = buttonBackgroundColor;
}

void SingleButton::setTextColor(Color* buttonTextColor)
{
	//button.GetComponentInChildren<Text>().color = buttonTextColor;
}

void SingleButton::initButton(int btnXLocation, int btnYLocation, std::string btnText, CDetour* btnAction, std::string btnToolTip, Color* btnBackgroundColor /*= nullptr*/, Color* btnTextColor /*= nullptr*/)
{
	Transform* btnTemplate = FindInQuickMenu("ShortcutMenu/WorldsButton");

	button = (GameObject*)Instantiate(btnTemplate->get_gameObject(), FindInQuickMenu(btnQMLoc), true);

	initShift[0] = -1;
	initShift[1] = 0;
	setLocation(btnXLocation, btnYLocation);
	setButtonText(btnText);
	setToolTip(btnToolTip);
	setAction(btnAction);
	setActive(true);

	if (btnBackgroundColor != nullptr)
		setBackgroundColor(btnBackgroundColor);
	if (btnTextColor != nullptr)
		setTextColor(btnTextColor);
}

ToggleButton::ToggleButton(std::string btnMenu, int btnXLocation, int btnYLocation, std::string btnTextOn, CDetour* btnActionOn, std::string btnTextOff, CDetour* btnActionOff, std::string btnToolTip, Color* btnBackgroundColor /*= nullptr*/, Color* btnTextColor /*= nullptr*/)
{
	btnQMLoc = btnMenu;
	btnType = "ToggleButton";
	initButton(btnXLocation, btnYLocation, btnTextOn, btnActionOn, btnTextOff, btnActionOff, btnToolTip, btnBackgroundColor, btnTextColor);
}

void ToggleButton::setAction(CDetour* buttonOnAction, CDetour* buttonOffAction)
{
	//button.GetComponent<Button>().onClick = new Button.ButtonClickedEvent();
	{
		UI::Button* L_0 = (UI::Button*)getGameObject()->GetTransform()->GetComponent("UnityEngine.UI.Button");
		auto L_1 = (UI::ButtonClickedEvent*)IL2CPP::NewObjectFromObject(L_0->GetOnClick(), false);
		L_1->ButtonClickedEvent_ctor();
		L_0->SetOnClick(L_1);
	}

	{
		UI::Button* L_2 = (UI::Button*)getGameObject()->GetTransform()->GetComponent("UnityEngine.UI.Button");
		UI::ButtonClickedEvent* L_3 = L_2->GetOnClick();
		auto L_4 = (Events::UnityAction*)IL2CPP::NewObject("UnityEngine.Events.UnityAction, UnityEngine");
		Events::UnityAction::ctor(L_4, nullptr, (intptr_t)TestFunc);


		auto detour = new CDetour([=]()
			{
				if (btnOn->GetActiveSelf())
				{
					buttonOnAction->GetFuncPointer()();
					btnOn->SetActive(false);
					btnOff->SetActive(true);
				}
				else
				{
					buttonOffAction->GetFuncPointer()();
					btnOff->SetActive(false);
					btnOn->SetActive(true);
				}
			});
		auto func = detour->GetFuncPointer();

		using func_t = void(*)();
		*((func_t*)L_4 + 2) = func;
		auto unityevent = (Events::UnityEvent*)L_3;
		unityevent->AddListener(L_4);
	}
}

void ToggleButton::setOnText(std::string buttonOnText)
{
	auto a = (UI::Text*)btnOn->GetTransform()->GetChild(0)->GetComponent("UnityEngine.UI.Text");
	a->SetText(buttonOnText);
	auto b = (UI::Text*)btnOff->GetTransform()->GetChild(0)->GetComponent("UnityEngine.UI.Text");
	b->SetText(buttonOnText);
	//UI::SetText((UI::Text*)GetComponent(((GetChild(GetTransform(btnOff), 0))), "UnityEngine.UI.Text"), buttonOnText);
}

void ToggleButton::setOffText(std::string buttonOffText)
{
	auto a = (UI::Text*)btnOn->GetTransform()->GetChild(1)->GetComponent("UnityEngine.UI.Text");
	a->SetText(buttonOffText);
	auto b = (UI::Text*)btnOff->GetTransform()->GetChild(1)->GetComponent("UnityEngine.UI.Text");
	b->SetText(buttonOffText);
	//UI::SetText((UI::Text*)GetComponent(((GetChild(GetTransform(btnOn), 1))), "UnityEngine.UI.Text"), buttonOffText);
	//UI::SetText((UI::Text*)GetComponent(((GetChild(GetTransform(btnOff), 1))), "UnityEngine.UI.Text"), buttonOffText);
}

void ToggleButton::setBackgroundColor(Color* buttonBackgroundColor)
{
	//UnityEngine.UI.Image[] btnBgColorList = ((btnOn.GetComponentsInChildren<UnityEngine.UI.Image>()).Concat(btnOff.GetComponentsInChildren<UnityEngine.UI.Image>()).ToArray()).Concat(button.GetComponentsInChildren<UnityEngine.UI.Image>()).ToArray();
	//foreach(UnityEngine.UI.Image btnBackground in btnBgColorList) btnBackground.color = buttonBackgroundColor;
}

void ToggleButton::setTextColor(Color* buttonTextColor)
{
	//Text[] btnTxtColorList = (btnOn.GetComponentsInChildren<Text>()).Concat(btnOff.GetComponentsInChildren<Text>()).ToArray();
	//foreach(Text btnText in btnTxtColorList) btnText.color = buttonTextColor;
}

void ToggleButton::initButton(int btnXLocation, int btnYLocation, std::string btnTextOn, CDetour* btnActionOn, std::string btnTextOff, CDetour* btnActionOff, std::string btnToolTip, Color* btnBackgroundColor /*= nullptr*/, Color* btnTextColor /*= nullptr*/)
{
	Transform* btnTemplate = FindInQuickMenu("UserInteractMenu/BlockButton");
	
	button = (GameObject*)Instantiate(btnTemplate->get_gameObject(), FindInQuickMenu(btnQMLoc), true);

	btnOn = button->GetTransform()->Find("Toggle_States_Visible/ON")->get_gameObject();
	btnOff = button->GetTransform()->Find("Toggle_States_Visible/OFF")->get_gameObject();

	initShift[0] = -4;
	initShift[1] = 0;
	setLocation(btnXLocation, btnYLocation);

	setOnText(btnTextOn);
	setOffText(btnTextOff);
	/*Text[] btnTextsOn = btnOn.GetComponentsInChildren<Text>();
	btnTextsOn[0].name = "Text_ON";
	btnTextsOn[1].name = "Text_OFF";
	Text[] btnTextsOff = btnOff.GetComponentsInChildren<Text>();
	btnTextsOff[0].name = "Text_ON";
	btnTextsOff[1].name = "Text_OFF";*/

	setToolTip(btnToolTip);
	//button.transform.GetComponentInChildren<UiTooltip>().SetToolTipBasedOnToggle();

	setAction(btnActionOff, btnActionOn);
	btnOn->SetActive(false);
	btnOff->SetActive(true);

	if (btnBackgroundColor != nullptr)
		setBackgroundColor(btnBackgroundColor);

	if (btnTextColor != nullptr)
		setTextColor(btnTextColor);

	setActive(true);
}

NestedButton::NestedButton(std::string btnMenu, int btnXLocation, int btnYLocation, std::string btnText, std::string btnToolTip, Color* btnBackgroundColor /*= nullptr*/, Color* btnTextColor /*= nullptr*/, Color* backbtnBackgroundColor /*= nullptr*/, Color* backbtnTextColor /*= nullptr*/)
{
	btnQMLoc = btnMenu;
	btnType = "NestedButton";
	initButton(btnXLocation, btnYLocation, btnText, btnToolTip, btnBackgroundColor, btnTextColor, backbtnBackgroundColor, backbtnTextColor);
}

std::string NestedButton::getMenuName()
{
	return menuName;
}

SingleButton* NestedButton::getMainButton()
{
	return mainButton;
}

SingleButton* NestedButton::getBackButton()
{
	return backButton;
}

void NestedButton::initButton(int btnXLocation, int btnYLocation, std::string btnText, std::string btnToolTip, Color* btnBackgroundColor /*= nullptr*/, Color* btnTextColor /*= nullptr*/, Color* backbtnBackgroundColor /*= nullptr*/, Color* backbtnTextColor /*= nullptr*/)
{
	
	Transform* menu = (Transform*)Instantiate(QuickMenu::QuickMenuInstance()->get_transform()->Find("CameraMenu"), QuickMenu::QuickMenuInstance()->get_transform(), true); // MB FALSE/////////////////////////////////////////////////////////////////////////////////////////////////
	menuName = "CustomMenu" + btnQMLoc + "_" + std::to_string(btnXLocation) + "_" + std::to_string(btnYLocation);
	SetName(menu, menuName);

	mainButton = new SingleButton(btnQMLoc, btnXLocation, btnYLocation, btnText, new CDetour([=]() { ShowQuickmenuPage(menuName); }), btnToolTip, btnBackgroundColor, btnTextColor);
}

void NestedButton::ShowQuickmenuPage(std::string pagename)
{

}
