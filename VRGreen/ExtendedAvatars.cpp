#include "ExtendedAvatars.hpp"
#include "UnityEngine/Object.hpp"
#include "UnityEngine/Transform.hpp"
#include "Button.hpp"
#include "ButtonClickedEvent.h"
#include "UnityAction.hpp"
#include "CDetour.hpp"
#include "PageAvatar.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "ConsoleUtils.hpp"
#include "Text.hpp"
#include "Graphic.hpp"
#include "Color.hpp"
#include "ApiAvatar.hpp"
#include "List.hpp"

using namespace UnityEngine;
using namespace UnityEngine::UI;

ExtendedAvatars::ExtendedAvatars()
{
	this->pageAvatar = GameObject::Find("/UserInterface/MenuContent/Screens/Avatar");
	this->FavoriteButton = GameObject::Find("/UserInterface/MenuContent/Screens/Avatar/Favorite Button");
	this->FavoriteButtonNew = (UnityEngine::GameObject*)Instantiate(this->FavoriteButton, GameObject::Find("/UserInterface/MenuContent/Screens/Avatar/")->GetTransform());
	((Button*)this->FavoriteButtonNew->GetComponent("UnityEngine.UI.Button"))->SetOnClick(UI::ButtonClickedEvent::ctor());
	((Button*)this->FavoriteButtonNew->GetComponent("UnityEngine.UI.Button"))->GetOnClick()->AddListener(Events::UnityAction::ctor(new CDetour([=]() 
		{

		})));
	Vector3 v{ 0,0,0 };
	this->FavoriteButton->GetTransform()->SetLocalScale(&v);
	this->TitleText = GameObject::Find("/UserInterface/MenuContent/Screens/Avatar/TitlePanel (1)/TitleText");
	this->PublicAvatarList = GameObject::Find("/UserInterface/MenuContent/Screens/Avatar/Vertical Scroll View/Viewport/Content/Public Avatar List");
	((Text*)this->TitleText->GetComponent("UnityEngine.UI.Text"))->SetText("<color=purple>VR</color><color=green>Green</color>");

}

void ExtendedAvatars::Update()
{
	auto type = System::Type::GetType("UiVRCList, Assembly-CSharp");

	if (type == nullptr)
		return;

	auto methods = type->GetMethods();
	int j = 0;
	for (size_t i = 0; i < methods.arrayLength; i++)
	{
		if (methods[i]->GetParams().arrayLength == 3)
		{
			j++;
			if (j == 0)
				continue;
			auto compon = PublicAvatarList->GetComponent("UiAvatarList, Assembly-CSharp");
			int aaa = 0;
			bool bbbb = true;

			methods[i]->Invoke(
				compon,
				System::Collections::CreateObjectArray
				(
					(Object*)MyList.GetListObject(),
					IL2CPP::ValueBox("System.Int32", &aaa),
					IL2CPP::ValueBox("System.Boolean", &bbbb)
				));
			ConsoleUtils::Log(1);
		}
	}
}

std::vector<std::string>* ExtendedAvatars::ReadAllLines(const std::string& path)
{
	auto vecOfStrs = new std::vector<std::string>{};
	std::ifstream in(path.c_str());

	// Check if object is valid
	if (!in)
	{
		std::cerr << "Cannot open the File : " << path << std::endl;
		return nullptr;
	}

	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
			vecOfStrs->push_back(str);
	}
	//Close The File
	in.close();
	return vecOfStrs;
}