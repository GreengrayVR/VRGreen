#include "Ray.hpp"
#include "IL2CPP/IL2CPP.hpp"


UnityEngine::Ray* UnityEngine::Ray::ctor(Vector3 origin, Vector3 direction)
{
	auto ret = (Ray*)IL2CPP::NewObject("UnityEngine.Ray, UnityEngine.CoreModule");
	using func_t = void (*)(Ray* _this, Vector3 origin, Vector3 direction);
	func_t func = GetMethod<func_t>(0x32BE0);
	func(ret, origin, direction);
	return ret;
}
