#include "Material.hpp"

void UnityEngine::Material::SetColor(std::string name, Color* value)
{
	using func_t = void(*)(Material* _this, std::string name, Color* value);

	func_t func = GetMethod<func_t>(0x1971A00);

	func(this, name, value);
}
