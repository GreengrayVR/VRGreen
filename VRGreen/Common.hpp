#pragma once

#include <cstddef>
#include <cinttypes>
#include <Windows.h>

#define NOIMPLEMENT(_CLASS) \
    _CLASS() = delete; \
    ~_CLASS() = delete; \
    _CLASS(const _CLASS &) = delete; \
    _CLASS &operator = (const _CLASS &) = delete; \
    _CLASS(_CLASS &&) = delete; \
    _CLASS &operator = (_CLASS &&) = delete



#define load_array_elema(arr, idx, size) ((((uint8_t*)(arr)) + kIl2CppSizeOfArray) + ((size) * (idx)))

struct UnknownType {};

extern HMODULE GameAssemblyHandle;

struct Object { NOIMPLEMENT(Object); };
struct ObjectArray { NOIMPLEMENT(ObjectArray); };

namespace IL2CPP { extern void MonitorEnter(Object* object); }
namespace IL2CPP { extern void MonitorExit(Object* object); }

class UniqueLock
{
private:

    Object* object_;

public:

    UniqueLock(const UniqueLock&) = delete;
    UniqueLock& operator = (const UniqueLock&) = delete;

    UniqueLock(UniqueLock&&) = delete;
    UniqueLock& operator = (UniqueLock&&) = delete;

    UniqueLock(Object* object) :
        object_(object)
    {
        IL2CPP::MonitorEnter(object_);
    }

    ~UniqueLock()
    {
        IL2CPP::MonitorExit(object_);
    }
};

template <typename T>
inline T GetMethod(std::ptrdiff_t Offset)
{
	return (T)((uint8_t*)GameAssemblyHandle + Offset);
}

template <typename T>
inline T GetMethod(std::ptrdiff_t Offset, const char* assemblyName)
{
	return (T)((uint8_t*)GetModuleHandleA(assemblyName) + Offset);
}

template <typename returnType, typename Param>
inline returnType DoMethod(ptrdiff_t offset, Param* param1)
{
	using methodFunc_T = returnType(*)(Param* param1);
	methodFunc_T doMethod = GetMethod<methodFunc_T>(offset);
	return doMethod(param1);
}

void *GetMethod(std::ptrdiff_t Offset);

void *GetMethod(std::ptrdiff_t Offset, const char* assemblyName);


