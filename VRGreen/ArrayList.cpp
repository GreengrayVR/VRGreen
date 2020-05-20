#include "ArrayList.hpp"

#include "IL2CPP/IL2CPP.hpp"

System::Collections::ArrayList* System::Collections::ArrayList::ctor()
{
	auto ret = (ArrayList*)IL2CPP::NewObject("System.Collections.ArrayList");
	using func_t = void (*)(ArrayList* _this);
	func_t func = GetMethod<func_t>(ARRAYLIST_CTOR);
	func(ret);
	return ret;
}

int System::Collections::ArrayList::Add(Object* value)
{
	using func_t = int (*)(ArrayList* _this, Object* value);
	func_t func = GetMethod<func_t>(ARRAYLIST_ADD);
	return func(this, value);
}

ObjectArray* System::Collections::ArrayList::ToArray()
{
	using func_t = ObjectArray * (*)(ArrayList* _this);
	func_t func = GetMethod<func_t>(ARRAYLIST_TOARRAY);
	return func(this);
}
