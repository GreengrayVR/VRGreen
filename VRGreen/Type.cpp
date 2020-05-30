#include "Type.hpp"
#include "Common.hpp"

namespace IL2CPP { struct Array; }

List<System::MethodInfo*> System::Type::GetMethods()
{
	using func_t = IL2CPP::Array* (*)(Type* _this);

	func_t func = ::GetMethod<func_t>(0x186BA00);

	List<System::MethodInfo*> _list(func(this));

	return _list;
}

System::Type* System::Type::GetType(void* object)
{
	using func_t = Type* (*)(void* _this);

	func_t func = ::GetMethod<func_t>(0x30DC0E0);

	return func(object);
}

System::MethodInfo* System::Type::GetMethod(const std::string& name)
{
	using func_t = MethodInfo * (*)(Type* _this, IL2CPP::String* name);

	func_t func = ::GetMethod<func_t>(0x186B950);

	return func(this, IL2CPP::StringNew(name));
}

std::string System::Type::ToString(void* object)
{
	if (object == nullptr)
	{
		return "ey men what are u doin";
	}

	using func_t = IL2CPP::String* (*)(void* object);

	func_t func = ::GetMethod<func_t>(0x30DC100);

	return IL2CPP::StringChars(func(object));
}

System::Type* System::Type::GetType(const std::string& typeName)
{
	using func_t = Type * (*)(IL2CPP::String* _this);

	func_t func = ::GetMethod<func_t>(0x186C500);

	return func(IL2CPP::StringNew(typeName));
}

std::string System::ReflectionUtils::PropGetName(MethodInfo* methodInfo)
{
	auto methods = Type::GetType("System.Reflection.MemberInfo")->GetMethod("get_Name");

	return IL2CPP::StringChars((IL2CPP::String*)methods->Invoke(methodInfo, nullptr));
}

List<System::ParameterInfo*> System::MethodInfo::GetParams()
{
	auto arr = (IL2CPP::Array*)Type::GetType("System.Reflection.MethodBase")->GetMethod("GetParameters")->Invoke(this, nullptr);
	List<System::ParameterInfo*> params(arr);
	return params;
}

void* System::MethodInfo::Invoke(void* obj, void* parameters)
{
	using func_t = void * (*)(MethodInfo* _this, void* obj, void* parameters);

	func_t func = ::GetMethod<func_t>(0x35306D0);

	return func(this, obj, parameters);
}

std::string System::ParameterInfo::Name()
{
	using func_t = IL2CPP::String* (*)(ParameterInfo* _this);

	func_t func = ::GetMethod<func_t>(0x42E600);

	return IL2CPP::StringChars(func(this));
}
