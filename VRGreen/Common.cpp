#include "Common.hpp"

HMODULE GameAssemblyHandle = nullptr;

void *GetMethod(std::ptrdiff_t Offset)
{
	return GetMethod<void *>(Offset);
}

void *GetMethod(std::ptrdiff_t Offset, const char* assemblyName)
{
	return GetMethod<void *>(Offset, assemblyName);
}