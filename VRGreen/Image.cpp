#include "Image.hpp"
#include "Color.hpp"

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

UnityEngine::UI::Material* UnityEngine::UI::Image::GetMaterial()
{
	using func_t = UnityEngine::UI::Material* (*)(Image* _this);

	func_t func = GetMethod<func_t>(0x169BFE0);

	return func(this);
}

void UnityEngine::UI::Image::SetMaterial(Material* value)
{
	using func_t = UnityEngine::UI::Material* (*)(Image* _this, Material* value);

	func_t func = GetMethod<func_t>(0x1692610);

	func(this, value);
}

UnityEngine::Color UnityEngine::UI::Image::GetColor()
{
	using func_t = Color (*)(Image* _this);

	func_t func = GetMethod<func_t>(0x13F04F0);

	return func(this); 
}
