#pragma once

#include <string>

#include "../Utils/Offsets.h"

namespace IL2CPP { struct String; struct Type; struct Array; }
namespace UnityEngine { struct Component; }

#include "Common.hpp"

namespace UnityEngine
{
	struct Transform;

	struct GameObject : Object 
	{ 
		NOIMPLEMENT(GameObject); 
	
		void SetActive(bool value);

		Transform* GetTransform();

		UnityEngine::Component* AddComponent(std::string type);

		Object* GetComponent(std::string type);

		Object* GetComponent(IL2CPP::Type* type);

		static GameObject* CreatePrimitive(int32_t type);

		Object* GetComponentInChildren(const std::string& type);

		IL2CPP::Array* GetComponentsInChildren(IL2CPP::Type* type);

		bool GetActiveSelf();

		static GameObject* Find(std::string name);

	};
}