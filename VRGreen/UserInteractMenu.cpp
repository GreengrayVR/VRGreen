#include "UserInteractMenu.hpp"
#include "IL2CPP/IL2CPP.hpp"

inline static int32_t cloneAvatarButtonOffset = -3;

UnityEngine::UI::Button* UserInteractMenu::getCloneAvatarButton()
{
	if (cloneAvatarButtonOffset == -3)
		cloneAvatarButtonOffset = IL2CPP::ResolveFieldOffset(this, "cloneAvatarButton");

	return GetField<UnityEngine::UI::Button*>(this, cloneAvatarButtonOffset);
}

inline static int32_t cloneAvatarButtonTextOffset = -3;

UnityEngine::UI::Text* UserInteractMenu::getCloneAvatarButtonText()
{
	if (cloneAvatarButtonTextOffset == -3)
		cloneAvatarButtonTextOffset = IL2CPP::ResolveFieldOffset(this, "cloneAvatarButtonText");

	return GetField<UnityEngine::UI::Text*>(this, cloneAvatarButtonTextOffset);
}
