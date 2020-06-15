#include "Text.hpp"
#include "IL2CPP/IL2CPP.hpp"


void UnityEngine::UI::Text::SetText(const std::string& value)
{
	using func_t = void (*)(UnityEngine::UI::Text* _this, IL2CPP::String* value);

	func_t func = GetMethod<func_t>(SET_TEXT);

	func(this, IL2CPP::StringNew(value));
}

std::string UnityEngine::UI::Text::GetText()
{
	using func_t = IL2CPP::String* (*)(UnityEngine::UI::Text* _this);

	func_t func = GetMethod<func_t>(0x17D24D0);

	return IL2CPP::StringChars(func(this));
}
