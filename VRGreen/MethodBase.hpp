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
		static MethodInfo* GetMethodInfo(Delegate* self);

		static Type* GetType(Object* _this);

		static PropertyInfo* GetProperty(Type* _this, std::string name); // TODO: change everything to const string&

		static MethodInfo* GetGetMethod(PropertyInfo* _this);

		static Object* Invoke(void* _this, Object* obj, void* parameters);

		static intptr_t GetFunctionPointerForDelegate(Object* d);
	};
}