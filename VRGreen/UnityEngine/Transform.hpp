#pragma once

#include "Common.hpp"
#include "Component.hpp"
#include "Utils/Offsets.h"

//struct Misc { static bool Contains(std::string text, std::string contains); };

namespace IL2CPP { struct String; }

namespace UnityEngine
{
	struct Vector3;

	//0x1837B20 Transform Find
	struct Transform : Component 
	{
		NOIMPLEMENT(Transform); 
	
		Transform* Find(IL2CPP::String* str);

		Transform* Find(std::string str);

		void SetParent(Transform* parent, bool worldPositionStays);

		void SetParent(Transform* to);

		void SetLocalPosition(Vector3* value);

		Vector3 GetLocalPosition();

		void SetLocalScale(Vector3* value);

		Transform* GetChild( int index);

		int ChildCount();

		void GetAllChildren(int& deepCount);

		static void GetAllChildren(Transform* transform);

		UnityEngine::Vector3 GetForward();

		UnityEngine::Vector3 GetRight();

		UnityEngine::Vector3 GetUp();

		UnityEngine::Vector3 GetPosition();

		void SetPosition(Vector3 value);
	};
}