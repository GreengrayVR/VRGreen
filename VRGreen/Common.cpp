#include "Common.hpp"
#include "IL2CPP/IL2CPP.hpp"

HMODULE GameAssemblyHandle = nullptr;

void *GetMethod(std::ptrdiff_t Offset)
{
	return GetMethod<void *>(Offset);
}

void *GetMethod(std::ptrdiff_t Offset, const char* assemblyName)
{
	return GetMethod<void *>(Offset, assemblyName);
}

Object* Object::ctor()
{
	auto ret = (Object*)IL2CPP::NewObject("System.Object");
	using func_t = void (*)(Object* _this);
	func_t func = GetMethod<func_t>(0x439670);
	func(ret);
	return ret;
}
