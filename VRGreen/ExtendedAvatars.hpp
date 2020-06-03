#pragma once

#include <string>
#include <vector>
#include "SystemList.hpp"
#include "UnityEngine/GameObject.hpp"
#include "ApiAvatar.hpp"

class ExtendedAvatars
{
public:
	ExtendedAvatars();

	void Update();

	SystemList<VRC::Core::ApiAvatar> MyList;

	UnityEngine::GameObject* PublicAvatarList;
	UnityEngine::GameObject* TitleText;
	UnityEngine::GameObject* FavoriteButton;
	UnityEngine::GameObject* FavoriteButtonNew;
	UnityEngine::GameObject* pageAvatar;
private:
	std::string path = "VRChat_Data\\Managed\\VRLoader\\Modules\\AvatarList.txt";

	std::vector<std::string>* ReadAllLines(const std::string& path);

};

