#pragma once


#include <string>

struct Object;


namespace UnityEngine
{
	struct Transform;

	Object* Instantiate(Object* original);

	Object* Instantiate(Object* original, Object* paremt);

	Object* Instantiate(Object* original, Transform* parent, bool instantiateInWorldSpace);

	std::string GetName(Object* _this);

	void SetName(Object* _this, std::string value);

	void Destroy(Object* obj, float t);
}