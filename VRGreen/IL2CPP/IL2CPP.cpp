#include "IL2CPP.hpp"
#include "ConsoleUtils.hpp"

using namespace IL2CPP;


void IL2CPP::Free(void* memory)
{
	using func_t = void(*)(void* memory);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_free");

	return func(memory);
}

IL2CPP::String* IL2CPP::StringNew(std::string str)
{
	using func_t = String * (*)(const char* str_t);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_string_new");

	return func(str.c_str());
}

std::string IL2CPP::utf16_to_utf8(std::u16string str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convertor;
	return convertor.to_bytes(str);
}

std::string IL2CPP::StringChars(String* str)
{
	if (str == nullptr)
	{
		ConsoleUtils::Log(red, "stringchars nullptr");
		return "stringchars nullptr";
	}

	using GetCharsFunc_t = const char16_t* (*)(String* str_t);

	GetCharsFunc_t GetCharsFunc = (GetCharsFunc_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_string_chars"); // _0 possibly

	return utf16_to_utf8(GetCharsFunc(str));
}

void* IL2CPP::ResolveCall(const char* name) // il2cpp_resolve_icall
{
	using func_t = void* (*)(const char* str);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_resolve_icall");

	return func(name);
}

IL2CPP::Image* IL2CPP::GetCorLib()
{
	using func_t = Image * (*)();

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_get_corlib");

	return func();
}

Assembly* IL2CPP::ImageGetAssembly(Image* image) // il2cpp_resolve_icall
{
	using func_t = Assembly * (*)(Image* image);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_image_get_assembly");

	return func(image);
}

Type* IL2CPP::GetType(std::string name)
{
	using func_t = Type * (*)(String* name);

	func_t func = GetMethod<func_t>(GETTYPE);

	return func(StringNew(name));
}

Type* IL2CPP::GetType(std::string name, bool throwOnError, bool ignoreCase)
{
	using func_t = Type * (*)(String* name, bool throwOnError, bool ignoreCase);

	func_t func = GetMethod<func_t>(GETTYPE_TYPE_BOOL_BOOL);

	return func(StringNew(name), throwOnError, ignoreCase);
}

IL2CPP::Array* IL2CPP::GetTypes(Assembly* assembly)
{
	using func_t = Array * (*)(Assembly* assembly);

	func_t func = GetMethod<func_t>(GETTYPES);

	return func(assembly);
}

std::string IL2CPP::TypeToString(Type* t)
{
	using func_t = String * (*)(Type* t);

	func_t func = GetMethod<func_t>(TYPETOSTRING);

	return StringChars(func(t));
}

Type* IL2CPP::ClassGetType(Class* klass)
{
	using func_t = Type * (*)(Class* klass);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_get_type");

	return func(klass);
}

size_t IL2CPP::ImageGetClassCount(Image* image)
{
	using func_t = size_t(*)(Image* image);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_image_get_class_count");

	return func(image);
}

Class* IL2CPP::ImageGetClass(Image* image, size_t index)
{
	using func_t = Class * (*)(Image* image, size_t index);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_image_get_class");

	return func(image, index);
}

char* IL2CPP::TypeGetName(Type* type)
{
	if (type == nullptr)
	{
		ConsoleUtils::Log("TypeGetName nullptr");
		return nullptr;
	}

	using func_t = char* (*)(Type* type);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_type_get_name");

	return func(type);
}

const char* IL2CPP::ImageGetName(Image* image)
{
	using func_t = const char* (*)(Image* image);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_image_get_name");

	return func(image);
}

Image* IL2CPP::ClassGetImage(Class* klass)
{
	using func_t = Image * (*)(Class* klass);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_get_image");

	return func(klass);
}

Domain* IL2CPP::CurrentDomain()
{
	using func_t = Domain * (*)();

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_domain_get");

	return func();
}

Assembly** IL2CPP::DomainGetAssemblies(Domain* domain, size_t* size)
{
	using func_t = Assembly * *(*)(Domain* domain, size_t* size);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_domain_get_assemblies");

	return func(domain, size);
}

Assembly* IL2CPP::DomainAssemblyOpen(Domain* domain, const char* name)
{
	using func_t = Assembly * (*)(Domain* domain, const char* name);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_domain_assembly_open");

	return func(domain, name);
}

void IL2CPP::SetField(Object* obj, Object* value, const char* name, bool isField /*= false*/)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("SetField is nullptr");
		return;
	}

	IL2CPP::Class* objClass = IL2CPP::ObjectGetClass(obj);

	void* iter = nullptr;

	if (isField)
	{
		while (auto field = IL2CPP::GetFields(objClass, &iter))
		{
			const char* fieldName = IL2CPP::FieldGetName(field);

			ConsoleUtils::Log(fieldName);

			if (std::string(fieldName) == name)
				IL2CPP::FieldSetValueObject(obj, field, value);
		}
	}
	else
	{
		while (auto field = IL2CPP::GetFields(objClass, &iter))
		{
			IL2CPP::Type* fieldType = IL2CPP::FieldGetType(field);

			char* fieldTypeName = IL2CPP::TypeGetName(fieldType);

			if (std::string(fieldTypeName) == name)
			{
				IL2CPP::Free(fieldTypeName);

				IL2CPP::FieldSetValueObject(obj, field, value);
			}
			else
			{
				IL2CPP::Free(fieldTypeName);
			}
		}
	}
}

void IL2CPP::SetFieldsTesting(Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("SetFieldsTesting is nullptr");
		return;
	}


	IL2CPP::Class* objClass = IL2CPP::ObjectGetClass(obj);

	void* iter = nullptr;

	ConsoleUtils::Log("-----------");
	ConsoleUtils::Log("Fields:");
	int i = 0;

	while (auto field = IL2CPP::GetFields(objClass, &iter))
	{
		auto fieldType = IL2CPP::FieldGetType(field);

		char* fieldTypeName = IL2CPP::TypeGetName(fieldType);
		const char* fieldName = IL2CPP::FieldGetName(field);


		if (std::string(fieldTypeName) == "System.Single")
		{
			i++;
			if (i == 3)
			{
				ConsoleUtils::Log("NIGGER");
				IL2CPP::FieldSetValue(obj, field, 10.f);
				break;
			}
		}

		ConsoleUtils::Log(fieldTypeName, ": ", fieldName, " | ", (size_t)IL2CPP::FieldGetValueObject(field, obj));

		IL2CPP::Free(fieldTypeName);
		//IL2CPP::Free(fieldName); ???????

	}

	ConsoleUtils::Log("-----------");
}

void IL2CPP::GetFields(Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("GetFields is nullptr");
		return;
	}

	IL2CPP::Class* objClass = IL2CPP::ObjectGetClass(obj);

	void* iter = nullptr;

	ConsoleUtils::Log("-----------");
	ConsoleUtils::Log("Fields:");

	while (auto field = IL2CPP::GetFields(objClass, &iter))
	{
		auto fieldType = IL2CPP::FieldGetType(field);

		char* fieldTypeName = IL2CPP::TypeGetName(fieldType);
		const char* fieldName = IL2CPP::FieldGetName(field);

		ConsoleUtils::Log(fieldTypeName, ": ", fieldName, " | ", (size_t)IL2CPP::FieldGetValueObject(field, obj));

		IL2CPP::Free(fieldTypeName);
		//IL2CPP::Free(fieldName); ???????

	}

	ConsoleUtils::Log("-----------");
}

FieldInfo* IL2CPP::ClassGetFieldFromName(Object* obj, const char* name)
{
	IL2CPP::Class* objClass = IL2CPP::ObjectGetClass(obj);

	using func_t = FieldInfo * (*)(Class* klass, const char* name);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_get_field_from_name");

	return func(objClass, name);
}

FieldInfo* IL2CPP::ClassGetFieldFromNameT(Class* klass, const char* name)
{
	using func_t = FieldInfo * (*)(Class* klass, const char* name);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_get_field_from_name");

	return func(klass, name);
}

Class* IL2CPP::FieldGetParent(FieldInfo* field)
{
	// il2cpp_field_get_parent
	using func_t = Class * (*)(FieldInfo* field);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_get_parent");

	return func(field);
}

char* IL2CPP::GetObjectTypeName(Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("GetObjectTypeName is nullptr");
		return nullptr;
	}

	return IL2CPP::TypeGetName(IL2CPP::ClassGetType(IL2CPP::ObjectGetClass(obj)));
}

Type* IL2CPP::GetObjectType(Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("GetObjectType is nullptr");
		return nullptr;
	}

	return IL2CPP::ClassGetType(IL2CPP::ObjectGetClass(obj));
}

Object* IL2CPP::ObjectNew(Class* klass)
{
	if (klass == nullptr)
	{
		ConsoleUtils::Log("ObjectNew is nullptr");
		return nullptr;
	}

	using func_t = Object * (*)(Class* klass);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_object_new");

	return func(klass);
}

Class* IL2CPP::ClassFromSystemType(Type* t)
{
	if (t == nullptr)
	{
		ConsoleUtils::Log("ClassFromSystemType returns nullptr");
		return nullptr;
	}

	using func_t = Class * (*)(Type* t);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_from_system_type");

	return func(t);
}

Class* IL2CPP::ClassFromType(Type* t)
{
	if (t == nullptr)
	{
		ConsoleUtils::Log("ClassFromType returns nullptr");
		return nullptr;
	}

	using func_t = Class * (*)(Type* t);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_from_il2cpp_type");

	return func(t);
}

std::string IL2CPP::GetHWID()
{
	using func_t = String * (*)();

	func_t func = GetMethod<func_t>(GETHWID);

	auto str = func();

	if (str == nullptr)
		return "ERROR";
	else
		return StringChars(str);
}

Object* IL2CPP::NewObject(std::string name)
{
	Type* type = IL2CPP::GetType(name);
	if (type == nullptr)
		ConsoleUtils::Log("Type is nullptr");
	Class* klass = IL2CPP::ClassFromSystemType(type);
	if (klass == nullptr)
		ConsoleUtils::Log("Class is nullptr");
	return IL2CPP::ObjectNew(klass);
}

Object* IL2CPP::NewObject(Type* type, bool isSystem)
{
	Class* klass;

	if (type == nullptr)
	{
		ConsoleUtils::Log("Type is nullptr");
		return nullptr;
	}

	if (isSystem)
		klass = IL2CPP::ClassFromSystemType(type);
	else
		klass = IL2CPP::ClassFromType(type);

	if (klass == nullptr)
	{
		ConsoleUtils::Log("Class is nullptr");
		return nullptr;
	}

	return IL2CPP::ObjectNew(klass);
}

Object* IL2CPP::NewObjectFromObject(Object* obj, bool systemType /*= false*/)
{
	return IL2CPP::NewObject(IL2CPP::GetObjectType(obj), systemType);
}

IL2CPP::Array* IL2CPP::ArrayNew(Class* elementTypeInfo, size_t length)
{
	using func_t = Array * (*)(Class* elementTypeInfo, size_t length);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_array_new");

	return func(elementTypeInfo, length);
}

Object* IL2CPP::ValueBox(std::string type, void* data)
{
	auto klass = IL2CPP::ClassFromSystemType(IL2CPP::GetType(type));

	using func_t = Object * (*)(Class* klass, void* data);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_value_box");

	return func(klass, data);
}

Object* IL2CPP::GetField(Object* obj, const char* name, bool AAAAAAAAAAAAAAAAAAAAAAAAAA /*= false*/)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("GetField is nullptr");
		return nullptr;
	}

	IL2CPP::Class* objClass = IL2CPP::ObjectGetClass(obj);

	void* iter = nullptr;

	while (auto field = IL2CPP::GetFields(objClass, &iter))
	{
		const char* fieldName = IL2CPP::FieldGetName(field);

		IL2CPP::Type* fieldType = IL2CPP::FieldGetType(field);
		char* fieldTypeName = IL2CPP::TypeGetName(fieldType);
		//ConsoleUtils::Log(fieldName);

		if (std::string(fieldName) == name || std::string(fieldTypeName) == name)
			return IL2CPP::FieldGetValueObject(field, obj);
	}

	return NULL;
}

void IL2CPP::SetField(Object* obj, const char* name, int pos, void* value)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("SetField is nullptr");
		return;
	}

	IL2CPP::Class* objClass = IL2CPP::ObjectGetClass(obj);
	void* iter = nullptr;
	int i = 0;
	while (auto field = IL2CPP::GetFields(objClass, &iter))
	{
		auto fieldType = IL2CPP::FieldGetType(field);

		char* fieldtypename = IL2CPP::TypeGetName(fieldType);


		if (std::string(fieldtypename) == name)
		{

			i++;
			if (i == pos)
			{
				IL2CPP::FieldSetValue(obj, field, value);
				IL2CPP::Free(fieldtypename);
				break;
			}
		}
		IL2CPP::Free(fieldtypename);

	}
}

FieldInfo* IL2CPP::GetFields(void* klass, void** iter)
{
	using func_t = FieldInfo * (*)(void* klass, void** iter);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_get_fields");

	return func(klass, iter);
}

Type* IL2CPP::FieldGetType(FieldInfo* field)
{
	if (field == nullptr)
	{
		ConsoleUtils::Log("FieldGetType is nullptr");
		return nullptr;
	}

	using func_t = Type * (*)(FieldInfo* field);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_get_type");

	return func(field);
}

const char* IL2CPP::FieldGetName(FieldInfo* field)
{
	if (field == nullptr)
	{
		ConsoleUtils::Log("FieldGetName is nullptr");
		return nullptr;
	}

	using func_t = const char* (*)(FieldInfo* field);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_get_name");

	return func(field);
}

Class* IL2CPP::ObjectGetClass(Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("ObjectGetClass is nullptr");
		return nullptr;
	}

	using func_t = Class * (*)(Object* obj);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_object_get_class");

	return func(obj);
}

PropertyInfo* IL2CPP::ClassGetPropertyFromName(Class* klass, const char* name)
{
	if (klass == nullptr)
	{
		ConsoleUtils::Log("ClassGetPropertyFromName is nullptr");
		return nullptr;
	}

	using func_t = PropertyInfo * (*)(Class* klass, const char* name);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_class_get_property_from_name");

	return func(klass, name);
}

void IL2CPP::FieldSetValueObject(Object* objectInstance, FieldInfo* field, Object* value)
{
	if (objectInstance == nullptr)
	{
		ConsoleUtils::Log("FieldSetValueObject is nullptr");
		return;
	}

	using func_t = void(*)(Object* objectInstance, FieldInfo* field, Object* value);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_set_value_object");

	func(objectInstance, field, value);
}

void IL2CPP::FieldSetValue(Object* objectInstance, FieldInfo* field, void* value)
{
	if (objectInstance == nullptr)
	{
		ConsoleUtils::Log("FieldSetValue is nullptr");
		return;
	}

	using func_t = void(*)(Object* objectInstance, FieldInfo* field, void* value);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_set_value");

	func(objectInstance, field, value);
}

Object* IL2CPP::FieldGetValueObject(FieldInfo* field, Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("FieldGetValueObject is nullptr");
		return nullptr;
	}

	using func_t = Object * (*)(FieldInfo* field, Object* obj);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_get_value_object");

	return func(field, obj);
}

uint32_t IL2CPP::ObjectGetSize(Object* obj)
{
	if (obj == nullptr)
	{
		ConsoleUtils::Log("ObjectGetSize is nullptr");
		return NULL;
	}

	using func_t = uint32_t(*)(Object* obj);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_object_get_size");

	return func(obj);
}

uint32_t IL2CPP::ArrayGetByteLength(Array* arr)
{
	using func_t = uint32_t(*)(Array* arr);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_array_get_byte_length");

	return func(arr);
}

uint32_t IL2CPP::ArrayLength(Array* arr)
{
	using func_t = uint32_t(*)(Array* arr);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_array_length");

	return func(arr);
}

void IL2CPP::MonitorEnter(Object* obj)
{
	using func_t = void(*)(Object* obj);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_monitor_enter");

	func(obj);
}

void IL2CPP::MonitorExit(Object* obj)
{
	using func_t = void(*)(Object* obj);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_monitor_exit");

	func(obj);
}

void IL2CPP::FieldSetValue(Object* objectInstance, FieldInfo* field, float value)
{
	if (objectInstance == nullptr)
	{
		ConsoleUtils::Log("FieldSetValue is nullptr");
		return;
	}

	using func_t = void(*)(Object* objectInstance, FieldInfo* field, float value);

	func_t func = (func_t)GetProcAddress(::GameAssemblyHandle, "il2cpp_field_set_value");

	func(objectInstance, field, value);
}