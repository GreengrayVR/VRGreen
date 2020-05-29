#include "Renderer.hpp"

#include "Common.hpp"
#include <Utils\Offsets.h>

void UnityEngine::Renderer::SetEnabled(bool value)
{
	using func_t = void(*)(Renderer* _this, bool value);

	func_t func = GetMethod<func_t>(SETENABLED_RENDERER);

	func(this, value);
}

//UnityEngine::Material* UnityEngine::Renderer::SharedMaterial()
//{
//	using func_t = Material * (*)(Renderer* _this);
//
//	func_t func = GetMethod<func_t>(0Ax391F630);
//
//	return func(this);
//}
