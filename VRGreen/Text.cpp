#include "Text.hpp"



void UnityEngine::UI::Text::SetText(std::string value)
{
	using func_t = void (*)(UnityEngine::UI::Text* _this, IL2CPP::String* value);

	func_t func = GetMethod<func_t>(0x19B6000);

	func(this, IL2CPP::StringNew(value));
}
