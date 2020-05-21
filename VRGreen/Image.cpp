#include "Image.hpp"


UnityEngine::UI::Sprite* UnityEngine::UI::Image::GetSprite()
{
	using func_t = UnityEngine::UI::Sprite* (*)(Image* _this);

	func_t func = GetMethod<func_t>(0x169C5A0);

	return func(this);
}

void UnityEngine::UI::Image::SetSprite(Sprite* value)
{
	using func_t = UnityEngine::UI::Sprite* (*)(Image* _this, Sprite* value);

	func_t func = GetMethod<func_t>(0x169C940);

	func(this, value);
}
