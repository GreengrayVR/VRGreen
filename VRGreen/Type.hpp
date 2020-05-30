#pragma once

#include <string>
#include "List.hpp"
#include "IL2CPP/IL2CPP.hpp"

namespace System
{
	struct ParameterInfo
	{
		std::string Name();
	};

	struct MemberInfo
	{

	};

	struct MethodInfo
	{
		List<ParameterInfo*> GetParams();

		void* Invoke(void* obj, void* parameters);
	};

	struct MethodBase : MemberInfo
	{
	};

	struct Type : MemberInfo
	{
		List<MethodInfo*> GetMethods();

		static Type* GetType(void* object);

		static Type* GetType(const std::string& typeName);

		MethodInfo* GetMethod(const std::string& name);

		static std::string ToString(void* object);

		
	};

	struct ReflectionUtils
	{
		static std::string PropGetName(MethodInfo* methodInfo);
	};
}