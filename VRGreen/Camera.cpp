#include "Camera.hpp"

#include "Common.hpp"

UnityEngine::Camera* UnityEngine::Camera::MainCamera()
{
	using func_t = Camera * (*)();

	func_t func = GetMethod<func_t>(0x19F2400);

	return func();
}
