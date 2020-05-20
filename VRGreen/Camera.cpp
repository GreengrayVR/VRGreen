#include "Camera.hpp"

#include "Common.hpp"
#include <Utils\Offsets.h>

UnityEngine::Camera* UnityEngine::Camera::MainCamera()
{
	using func_t = Camera * (*)();

	func_t func = GetMethod<func_t>(CAMERA_GET_MAIN);

	return func();
}
