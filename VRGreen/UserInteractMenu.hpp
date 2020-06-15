#pragma once


#include "Common.hpp"

#include "UnityEngine/Component.hpp"
namespace UnityEngine::UI { struct Button; struct Text; }

struct UserInteractMenu : UnityEngine::Component 
{
    NOIMPLEMENT(UserInteractMenu); 

    UnityEngine::UI::Button* getCloneAvatarButton();

    UnityEngine::UI::Text* getCloneAvatarButtonText();
};


