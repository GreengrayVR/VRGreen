#include "Color.hpp"

#include "Utils/Offsets.h"

UnityEngine::Color* UnityEngine::GetCyan()
{
	UnknownType retstr;

	using func_t = Color * (*)(UnknownType* retstr);

	func_t func = GetMethod<func_t>(GETCYAN);

	return func((UnknownType*)(&retstr));
}

UnityEngine::Color UnityEngine::GetRed()
{
	return { 1.f, 0.f, 0.f, 1.f };
}
