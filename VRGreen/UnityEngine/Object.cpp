#include "Object.hpp"

#include "Common.hpp"
#include "IL2CPP/IL2CPP.hpp"
#include "ConsoleUtils.hpp"

Object* UnityEngine::Instantiate(Object* original)
{
	using func_t = Object * (*)(Object* original);

	func_t func = GetMethod<func_t>(INSTANTIATE1);

	return func(original);
}

std::string UnityEngine::GetName(Object* _this)
{
	using func_t = IL2CPP::String* (*)(Object* _this);

	func_t func = GetMethod<func_t>(GETOBJECTNAME);

	return IL2CPP::StringChars(func(_this));
}

void UnityEngine::SetName(Object* _this, std::string value)
{
	using func_t = void (*)(Object* _this, IL2CPP::String* value);

	func_t func = GetMethod<func_t>(OBJECTSETNAME);

	func(_this, IL2CPP::StringNew(value));
}

void UnityEngine::Destroy(Object* obj, float t)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("Destroy is nullptr");
		return;
	}

	using func_t = void (*)(Object* obj, float t);

	func_t func = GetMethod<func_t>(DESTROY);

	func(obj, t);
}

Object* UnityEngine::Instantiate(Object* original, Transform* parent, bool instantiateInWorldSpace)
{
	using func_t = Object * (*)(Object* original, Transform* parent, bool instantiateInWorldSpace);

	func_t func = GetMethod<func_t>(INSTANTIATE2);

	return func(original, parent, instantiateInWorldSpace);
}

Object* UnityEngine::Instantiate(Object* original, Object* paremt)
{
	using func_t = Object * (*)(Object* original, Object* paremt);

	func_t func = GetMethod<func_t>(0x2073470);

	return func(original, paremt);
}
