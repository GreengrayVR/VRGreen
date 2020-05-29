#include "Material.hpp"
#include "Utils/Offsets.h"

void UnityEngine::Material::SetColor(std::string name, Color* value)
{
	using func_t = void(*)(Material* _this, std::string name, Color* value);

	func_t func = GetMethod<func_t>(SETCOLOR_MATERIAL);

	func(this, name, value);
}
