#pragma once

#include "Common.hpp"
#include "GameObject.hpp"
#include <string>
#include "UnityEngine/Vector3.hpp"

namespace IL2CPP { struct Array; struct String; String* StringNew(std::string str); }

namespace UnityEngine
{
	struct Transform;



	struct Component : Object 
	{ 
		NOIMPLEMENT(Component); 

		Transform* get_transform();

		GameObject* get_gameObject();

		Object* GetComponent(const std::string& type);

		Object* GetComponent(IL2CPP::Type* type);

		Object* GetComponentInChildren(const std::string& type);

		static IL2CPP::Array* FindObjectsOfTypeAll(IL2CPP::Type* type);
	};
	

}