#include "Component.hpp"

#include "ConsoleUtils.hpp"

UnityEngine::Transform* UnityEngine::Component::get_transform()
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("get_transform is nullptr");
		return nullptr;
	}

	using func_t = Transform * (*)(Component* component);

	func_t func = GetMethod<func_t>(GETTRANSFORM_COMPONENT);

	return func(this);
}

UnityEngine::GameObject* UnityEngine::Component::get_gameObject()
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("get_gameObject is nullptr");
		return nullptr;
	}

	using func_t = GameObject * (*)(Component* component);

	func_t func = GetMethod<func_t>(GETGAMEOBJECT);

	return func(this);
}

Object* UnityEngine::Component::GetComponent(std::string type)
{
	using func_t = Object * (*)(Component* component, IL2CPP::String* type);

	func_t func = GetMethod<func_t>(GETCOMPONENT_COMPONENT);

	return func(this, IL2CPP::StringNew(type));
}

Object* UnityEngine::Component::GetComponent(IL2CPP::Type* type)
{
	using func_t = Object * (*)(Component* _this, IL2CPP::Type* type);

	func_t func = GetMethod<func_t>(0x19F6FE0);

	return func(this, type);
}

Object* UnityEngine::Component::GetComponentInChildren()
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("GetComponentInChildren (Component is nullptr)");
		return nullptr;
	}

	using func_t = Object * (*)(Component* _this);

	func_t func = GetMethod<func_t>(COMPONENTINCHILDREN); // or 0x29D2850

	return func(this);
}
//
//UnityEngine::Vector3 UnityEngine::Component::GetLocalPosition()
//{
//	Vector3_Nig retstr;
//
//	using func_t = Vector3 * (*)(Vector3_Nig* retstr, Transform* _this);
//
//	func_t func = GetMethod<func_t>(GETLOCALPOS);
//
//	auto temp = func((Vector3_Nig*)(&retstr), this);
//
//	return retstr;
//}

IL2CPP::Array* UnityEngine::Component::FindObjectsOfTypeAll(IL2CPP::Type* type)
{
	if (type == nullptr)
	{
		ConsoleUtils::Log("FindObjectsOfTypeAll is nullptr");
		return nullptr;
	}

	using func_t = IL2CPP::Array* (*)(IL2CPP::Type* type);

	func_t func = GetMethod<func_t>(FINDOBJECTSOFTYPEALL);

	return func(type);
}
