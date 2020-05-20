#pragma once

#include <codecvt>
#include <string>
#include "../Utils/Offsets.h"

#include "Common.hpp"

extern HMODULE GameAssemblyHandle;

//typedef 

namespace IL2CPP
{
	struct String : Object { NOIMPLEMENT(String); };

	struct Type;

	struct Image;

	struct Assembly;

	struct Class;

	struct Domain;

	struct FieldInfo;

	struct PropertyInfo;

	struct Array : Object { NOIMPLEMENT(Array); };

	// https://gitlab.thecdm.ca/xr_lab/smallStage/blob/bcaff16f5ea880a034e41a8a711b80b2d15c0a0c/Vuforia_iOS/AndySmallStageMay15v1/Libraries/libil2cpp/include/codegen/il2cpp-codegen-il2cpp.h
	void Free(void* memory);

	// https://git.kpi.fei.tuke.sk/tg206vc/liveitprojects/-/blob/283bff797d9dc1cf3ae0b5bc12830233b3c19250/Il2CppOutputProject/IL2CPP/libil2cpp/il2cpp-api.cpp#L1049
	String *StringNew(std::string str);
	

	// https://git.kpi.fei.tuke.sk/tg206vc/liveitprojects/-/blob/283bff797d9dc1cf3ae0b5bc12830233b3c19250/Il2CppOutputProject/IL2CPP/libil2cpp/il2cpp-api.cpp#L1049
	//String *StringNew(const char* str);

	std::string utf16_to_utf8(std::u16string str);

	// https://git.kpi.fei.tuke.sk/tg206vc/liveitprojects/-/blob/283bff797d9dc1cf3ae0b5bc12830233b3c19250/Il2CppOutputProject/IL2CPP/libil2cpp/il2cpp-api.cpp#L1043
	std::string StringChars(String *str);

	void* ResolveCall(const char* name); // il2cpp_resolve_icall

	Image* GetCorLib();

	Assembly* ImageGetAssembly(Image* image); // il2cpp_resolve_icall

	// Reflection
	Type* GetType(std::string name);

	Type* GetType(std::string name, bool throwOnError, bool ignoreCase)
;
	Array* GetTypes(Assembly* assembly);

	std::string TypeToString(Type* t);

	Type* ClassGetType(Class* klass);

	size_t ImageGetClassCount(Image* image);

	Class* ImageGetClass(Image* image, size_t index);

	char* TypeGetName(Type* type);

	const char* ImageGetName(Image* image);

	Image* ClassGetImage(Class* klass);

	Domain* CurrentDomain();

	Assembly** DomainGetAssemblies(Domain* domain, size_t* size);

	Assembly* DomainAssemblyOpen(Domain* domain, const char* name);

	FieldInfo* GetFields(void* klass, void* *iter);

	Type* FieldGetType(FieldInfo* field);

	const char* FieldGetName(FieldInfo* field);

	Class* ObjectGetClass(Object* obj);

	PropertyInfo* ClassGetPropertyFromName(Class* klass, const char* name);

	void FieldSetValueObject(Object* objectInstance, FieldInfo* field, Object* value);

	void FieldSetValue(Object* objectInstance, FieldInfo* field, void* value);

	void FieldSetValue(Object* objectInstance, FieldInfo* field, float value);

	Object* FieldGetValueObject(FieldInfo* field, Object* obj);

	uint32_t ObjectGetSize(Object* obj);

	uint32_t ArrayGetByteLength(Array* arr);

	uint32_t ArrayLength(Array* arr);

	void MonitorEnter(Object* obj);

	void MonitorExit(Object* obj);

	void SetField(Object* obj, Object* value, const char* name, bool isField = false);

	Object* GetField(Object* obj, const char* name, bool AAAAAAAAAAAAAAAAAAAAAAAAAA = false);

	void SetField(Object* obj, const char* name, int pos, void* value);

	void SetFieldsTesting(Object* obj);

	void GetFields(Object* obj);

	FieldInfo* ClassGetFieldFromName(Object* obj, const char* name);

	FieldInfo* ClassGetFieldFromNameT(Class* klass, const char* name);

	Class* FieldGetParent(FieldInfo* field);

	char* GetObjectTypeName(Object* obj);

	Type* GetObjectType(Object* obj);

	Object* ObjectNew(Class* klass);

	Class* ClassFromSystemType(Type* t);

	Class* ClassFromType(Type* t);

	std::string GetHWID();

	Object* NewObject(std::string name);

	Object* NewObject(Type* type, bool isSystem);

	Object* NewObjectFromObject(Object* obj, bool systemType = false);

	Array* ArrayNew(Class* elementTypeInfo, size_t length);

	Object* ValueBox(std::string type, void* data);
}