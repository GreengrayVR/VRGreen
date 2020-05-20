#include "Collider.hpp"



void UnityEngine::Collider::SetEnabled(bool value)
{
	using func_t = void(*)(Collider* _this, bool value);

	func_t func = GetMethod<func_t>(SETENABLED_COLLIDER);

	func(this, value);
}
