#pragma once

#include <string>

struct Object;

namespace System::Reflection
{
	struct MethodBase;
	struct MethodInfo;
	struct PropertyInfo;
	struct Delegate;
	struct Type;

	struct MethodBase
	{
		static MethodInfo* GetMethodInfo(Delegate* self); // 0x187A810

		static Type* GetType(Object* _this);

		// RVA: 0x1AE4DA0 Offset: 0x1AE37A0 VA: 0x181AE4DA0 Slot: 59
		static PropertyInfo* GetProperty(Type* _this, std::string name); // TODO: change everything to const string&

		// RVA: 0x1A9E870 Offset: 0x1A9D270 VA: 0x181A9E870 Slot: 22
		static MethodInfo* GetGetMethod(PropertyInfo* _this);

		// RVA: 0x1A96910 Offset: 0x1A95310 VA: 0x181A96910 Slot: 29
		static Object* Invoke(void* _this, Object* obj, void* parameters);

		// RVA: 0x2BA1EA0 Offset: 0x2BA08A0 VA: 0x182BA1EA0
		static intptr_t GetFunctionPointerForDelegate(Object* d);
	};
}