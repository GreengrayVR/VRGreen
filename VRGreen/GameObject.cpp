#include "UnityEngine/GameObject.hpp"

#include "IL2CPP/IL2CPP.hpp"
#include "Type.hpp"

void UnityEngine::GameObject::SetActive(bool value)
{
	using func_t = void(*)(GameObject* gameObject, bool value);

	func_t func = GetMethod<func_t>(SETACTIVE);

	func(this, value);
}

UnityEngine::Transform* UnityEngine::GameObject::GetTransform()
{
	using func_t = Transform * (*)(GameObject* gameObject);

	func_t func = GetMethod<func_t>(GETTRANSFORM_GAMEOBJECT);

	return func(this);
}

// Converts string type with IL2CPP::GetType
UnityEngine::Component* UnityEngine::GameObject::AddComponent(std::string type)
{
	using func_t = UnityEngine::Component* (*)(GameObject* component, IL2CPP::Type* type);

	func_t func = GetMethod<func_t>(ADDCOMPONENT);

	return func(this, IL2CPP::GetType(type));
}

Object* UnityEngine::GameObject::GetComponent(std::string type)
{
	using func_t = Object * (*)(GameObject* component, IL2CPP::String* type);

	func_t func = GetMethod<func_t>(GETCOMPONENT_GAMEOBJECT);

	return func(this, IL2CPP::StringNew(type));
}

UnityEngine::GameObject* UnityEngine::GameObject::CreatePrimitive(int32_t type)
{
	using func_t = GameObject * (*)(int32_t type_t);

	func_t func = GetMethod<func_t>(CREATEPRIMITIVE);

	return func(type);
}

Object* UnityEngine::GameObject::GetComponentInChildren(const std::string& type)
{
	if (this == nullptr)
	{
		//ConsoleUtils::Log("GetComponentInChildren (Component is nullptr)");
		return nullptr;
	}

	using func_t = Object * (*)(GameObject* _this, System::Type* type);

	func_t func = GetMethod<func_t>(GETCOMPONENTINCHILDREN_GAMEOBJECT);

	return func(this, System::Type::GetType(type));
}

//IL2CPP::Array* UnityEngine::GameObject::GetComponentsInChildren(IL2CPP::Type* type)
//{
//	using func_t = IL2CPP::Array* (*)(GameObject* _this, IL2CPP::Type* type);
//
//	func_t func = GetMethod<func_t>(0ax1C9A920);
//
//	return func(this, type);
//}

bool UnityEngine::GameObject::GetActiveSelf()
{
	using func_t = bool (*)(GameObject* _this);

	func_t func = GetMethod<func_t>(GET_ACTIVESELF);

	return func(this);
}

UnityEngine::GameObject* UnityEngine::GameObject::Find(std::string name)
{
	using func_t = GameObject * (*)(IL2CPP::String* _this);

	func_t func = GetMethod<func_t>(GAMEOBJECT_FIND);

	return func(IL2CPP::StringNew(name));
}

Object* UnityEngine::GameObject::GetComponent(IL2CPP::Type* type)
{
	using func_t = Object * (*)(GameObject* _this, IL2CPP::Type* type);

	func_t func = GetMethod<func_t>(GAMEOBJECT_GETCOMPONENT);

	return func(this, type);
}
