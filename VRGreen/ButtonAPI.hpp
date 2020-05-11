#pragma once

#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Transform.hpp"
#include "QuickMenu.hpp"
#include "Types.hpp"
#include "UnityAction.hpp"
#include "Button.hpp"
#include "MethodBase.hpp"
#include "CDetour.hpp"
#include "Color.hpp"

#include <unordered_map>



class ButtonBase
{
protected:
	UnityEngine::GameObject* button;
	std::string btnQMLoc;
	std::string btnType;
	std::string btnTag;
	int initShift[2] = { 0, 2 };

public:
	using lambda_t = void(*)();

	UnityEngine::GameObject* getGameObject();

	void setActive(bool isActive);

	void setLocation(int buttonXLoc, int buttonYLoc);

	void setToolTip(std::string buttonToolTip);

	static UnityEngine::Transform* FindInQuickMenu(std::string str);

private:
	static UnityEngine::Transform* InstantiateGameobject(std::string type);

	static UnityEngine::Transform* CreateButton(std::string name, std::string type, std::string text, std::string tooltip, float x_pos, float y_pos, UnityEngine::Transform* parent, lambda_t action);
};

class SingleButton : public ButtonBase
{
public:
	SingleButton(std::string btnMenu, int btnXLocation, int btnYLocation, std::string btnText, CDetour* btnAction, std::string btnToolTip, UnityEngine::Color* btnBackgroundColor = nullptr, UnityEngine::Color* btnTextColor = nullptr);

	void setButtonText(std::string buttonText);

	void setAction(CDetour* buttonAction);

	void setBackgroundColor(UnityEngine::Color* buttonBackgroundColor);

	void setTextColor(UnityEngine::Color* buttonTextColor);

private:
	void initButton(int btnXLocation, int btnYLocation, std::string btnText, CDetour* btnAction, std::string btnToolTip, UnityEngine::Color* btnBackgroundColor = nullptr, UnityEngine::Color* btnTextColor = nullptr);
};

class ToggleButton : public ButtonBase
{
public:
	UnityEngine::GameObject* btnOn;
	UnityEngine::GameObject* btnOff;

	ToggleButton(std::string btnMenu, int btnXLocation, int btnYLocation, std::string btnTextOn, CDetour* btnActionOn, std::string btnTextOff, CDetour* btnActionOff, std::string btnToolTip, UnityEngine::Color* btnBackgroundColor = nullptr, UnityEngine::Color* btnTextColor = nullptr);;

	void setAction(CDetour* buttonOnAction, CDetour* buttonOffAction);

	void setOnText(std::string buttonOnText);

	void setOffText(std::string buttonOffText);

	void setBackgroundColor(UnityEngine::Color* buttonBackgroundColor);

	void setTextColor(UnityEngine::Color* buttonTextColor);

private:
	void initButton(int btnXLocation, int btnYLocation, std::string btnTextOn, CDetour* btnActionOn, std::string btnTextOff, CDetour* btnActionOff, std::string btnToolTip, UnityEngine::Color* btnBackgroundColor = nullptr, UnityEngine::Color* btnTextColor = nullptr);
	
	bool toggleState;
};

class NestedButton
{
protected:
	SingleButton* mainButton;
	SingleButton* backButton;
	std::string menuName;
	std::string btnQMLoc;
	std::string btnType;

public:
	NestedButton(std::string btnMenu, int btnXLocation, int btnYLocation, std::string btnText, std::string btnToolTip, UnityEngine::Color* btnBackgroundColor = nullptr, UnityEngine::Color* btnTextColor = nullptr, UnityEngine::Color* backbtnBackgroundColor = nullptr, UnityEngine::Color* backbtnTextColor = nullptr);

	std::string getMenuName();

	SingleButton* getMainButton();

	SingleButton* getBackButton();

private:
	void initButton(int btnXLocation, int btnYLocation, std::string btnText, std::string btnToolTip, UnityEngine::Color* btnBackgroundColor = nullptr, UnityEngine::Color* btnTextColor = nullptr, UnityEngine::Color* backbtnBackgroundColor = nullptr, UnityEngine::Color* backbtnTextColor = nullptr);

	void ShowQuickmenuPage(std::string pagename);
};	
