#pragma once

#include "Type.hpp"
#include "SystemList.hpp"
#include "ArrayList.hpp"
#include "ConsoleUtils.hpp"

template <typename T>
class SystemList
{
public:
	SystemList()
	{
		System::Type* type = System::Type::GetType(std::string("System.Collections.Generic.List`1[") + T::SystemTypeName + "]");
		if (type == nullptr)
		{
			ConsoleUtils::Log("Failed to create a list ", T::SystemTypeName);
			return;
		}
		System::ConstructorInfo* ctorInfo = type->GetConstructor(System::Type::EmptyTypes());
		systemList = ctorInfo->Invoke(System::Collections::ArrayList::ctor()->ToArray());
	}

	SystemList(void* listObject)
	{
		systemList = listObject;
	}

	T* operator[](int index)
	{
		Object* boxedInteger = IL2CPP::ValueBox("System.Int32", &index);
		return (T*)System::Type::GetType(systemList)
			->GetMethod("get_Item")
			->Invoke(systemList, System::Collections::CreateObjectArray(boxedInteger));
	}

	T *GetItem(int index)
	{
		Object* boxedInteger = IL2CPP::ValueBox("System.Int32", &index);
		return (T*)System::Type::GetType(systemList)
			->GetMethod("get_Item")
			->Invoke(systemList, System::Collections::CreateObjectArray(boxedInteger));
	}

	void Add(T* obj)
	{
		System::Type::GetType(systemList)->GetMethod("Add")->Invoke(systemList, System::Collections::CreateObjectArray((Object*)obj));
	}

	void* GetListObject()
	{
		return systemList;
	}

private:
	void* systemList;
};