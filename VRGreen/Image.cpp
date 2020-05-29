#include "Image.hpp"
#include "Color.hpp"

#include "Utils/Offsets.h"

UnityEngine::UI::Sprite* UnityEngine::UI::Image::GetSprite()
{
	using func_t = UnityEngine::UI::Sprite* (*)(Image* _this);

	func_t func = GetMethod<func_t>(GETSPRITEIMAGE);

	return func(this);
}

void UnityEngine::UI::Image::SetSprite(Sprite* value)
{
	using func_t = UnityEngine::UI::Sprite* (*)(Image* _this, Sprite* value);

	func_t func = GetMethod<func_t>(SETSPRITEIMAGE);

	func(this, value);
}

UnityEngine::UI::Material* UnityEngine::UI::Image::GetMaterial()
{
	using func_t = UnityEngine::UI::Material* (*)(Image* _this);

	func_t func = GetMethod<func_t>(GETMATERIALIMAGE);

	return func(this);
}

void UnityEngine::UI::Image::SetMaterial(Material* value)
{
	using func_t = UnityEngine::UI::Material* (*)(Image* _this, Material* value);

	func_t func = GetMethod<func_t>(SETMATERIALIMAGE);

	func(this, value);
}

UnityEngine::Color UnityEngine::UI::Image::GetColor()
{
	using func_t = Color (*)(Image* _this);

	func_t func = GetMethod<func_t>(GRAPHICGETCOLOR);

	return func(this); 
}
