#include "MethodBase.hpp"

#include "IL2CPP/IL2CPP.hpp"
#include "Common.hpp"

//System::Reflection::MethodInfo* System::Reflection::MethodBase::GetMethodInfo(Delegate* self) // 0/x187A810
//{
//	using func_t = MethodInfo * (*)(Delegate* self);
//
//	func_t func = GetMethod<func_t>(0|x2841C00);
//									 |
//	return func(self);				 |
//}									 |
//									 |
//System::Reflection::Type* System::R|eflection::MethodBase::GetType(Object* _this)
//{									 |
//	using func_t = Type * (*)(Object*| _this);
//									 |
//	func_t func = GetMethod<func_t>(0|x1884C10);
//									 |
//	return func(_this);				 |
//}									 |
//									 |
//System::Reflection::PropertyInfo* S|ystem::Reflection::MethodBase::GetProperty(Type* _this, std::string name)
//{									 |
//	using func_t = PropertyInfo * (*)|(Type* _this, IL2CPP::String* name);
//									 |
//	func_t func = GetMethod<func_t>(0|x1AE4DA0);
//									 |
//	return func(_this, IL2CPP::String|New(name));
//}									 |
//									 |
//System::Reflection::MethodInfo* Sys|tem::Reflection::MethodBase::GetGetMethod(PropertyInfo* _this)
//{									 |
//	using func_t = MethodInfo * (*)(P|ropertyInfo* _this);
//									 |
//	func_t func = GetMethod<func_t>(0|x1A9E870);
//									 |
//	return func(_this);				 |
//}									 |
//									 |
//Object* System::Reflection::MethodB|ase::Invoke(void* _this, Object* obj, void* parameters)
//{									 |
//	using func_t = Object * (*)(void*| _this, Object* obj, void* parameters);
//									 |
//	func_t func = GetMethod<func_t>(0|x1A9E870);
//									 |
//	return func(_this, obj, parameter|s);
//}									 |
//									 |
//intptr_t System::Reflection::Method|Base::GetFunctionPointerForDelegate(Object* d)
//{									 |
//	using func_t = intptr_t(*)(Object|* d);
//									 |
//	func_t func = GetMethod<func_t>(0|x2BA1EA0);
//
//	return func(d);
//}
