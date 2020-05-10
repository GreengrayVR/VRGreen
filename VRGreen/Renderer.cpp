#include "Renderer.hpp"

#include "Common.hpp"
#include <Utils\Offsets.h>

void UnityEngine::Renderer::SetEnabled(bool value)
{
	using func_t = void(*)(Renderer* _this, bool value);

	func_t func = GetMethod<func_t>(SETENABLED_RENDERER);

	func(this, value);
}
