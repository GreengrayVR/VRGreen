#include "Transform.hpp"

#include "ConsoleUtils.hpp"
#include "UnityEngine/Object.hpp"

UnityEngine::Transform* UnityEngine::Transform::Find(IL2CPP::String* str)
{
	using FindFunc_t = Transform * (*)(Transform* transform_t, IL2CPP::String* str_t);

	FindFunc_t FindFunc = (FindFunc_t)GetMethod<FindFunc_t>(TRANSFORM_FIND);
	return FindFunc(this, str);
}

void UnityEngine::Transform::SetParent(Transform* parent, bool worldPositionStays)
{
	using SetParentFunc_t = Transform * (*)(Transform* _this, Transform* parent, bool worldPositionStays); // TODO: Change return to void

	SetParentFunc_t SetParentFunc = (SetParentFunc_t)GetMethod<SetParentFunc_t>(SETPARENTBOOL);

	SetParentFunc(this, parent, worldPositionStays);
}

void UnityEngine::Transform::SetLocalPosition(Vector3* value)
{
	using func_t = void(*)(Transform* _this, Vector3* value);

	func_t func = GetMethod<func_t>(SETLOCALPOSITION);

	func(this, value);
}

UnityEngine::Vector3 UnityEngine::Transform::GetLocalPosition()
{
	using func_t = Vector3 (*)(Transform* _this);

	func_t func = GetMethod<func_t>(GETLOCALPOS);

	return func(this);
}/*

UnityEngine::Vector3 UnityEngine::Transform::GetLocalPosition()
{
	Vector3 retstr;

	using func_t = Vector3 * (*)(Vector3* retstr, Transform* _this);

	func_t func = GetMethod<func_t>(GETLOCALPOS);

	auto temp = func((Vector3*)(&retstr), this);

	return retstr;
}*/

void UnityEngine::Transform::SetLocalScale(Vector3* value)
{
	using func_t = void(*)(Transform* _this, Vector3* value);

	func_t func = GetMethod<func_t>(SETLOCALSCALE);

	func(this, value);
}

UnityEngine::Transform* UnityEngine::Transform::GetChild(int index)
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("GetChild (Transform) is nullptr");
		return nullptr;
	}

	using func_t = Transform * (*)(Transform* _this, int index);

	func_t func = GetMethod<func_t>(GETCHILD);

	return func(this, index);
}

int UnityEngine::Transform::ChildCount()
{
	if (this == nullptr)
	{
		ConsoleUtils::Log("ChildCount (Transform) is nullptr");
		return NULL;
	}

	using func_t = int (*)(Transform* _this);

	func_t func = GetMethod<func_t>(GETCHILDCOUNT);

	return func(this);
}

void UnityEngine::Transform::GetAllChildren(int& deepCount)
{
	int childCount = this->ChildCount();

	std::string text = "";

	deepCount++;

	for (size_t i = 0; i < childCount; i++)
		text += "-";

	ConsoleUtils::Log((deepCount - 1), " ", text, " ", UnityEngine::GetName(this));

	for (size_t i = 0; i < childCount; i++)
	{

		if (UnityEngine::GetName(this->GetChild(i)) == std::string("Text"))
		{
			//auto button = (UI::Text*)this->GetChild(i)->GetComponent("UnityEngine.UI.Text");

			//auto m_Text = IL2CPP::ClassGetFieldFromName(button, "m_Text");
			//auto str = IL2CPP::FieldGetValueObject(m_Text, button);
			//ConsoleUtils::Log(text, " Text: ", IL2CPP::StringChars((IL2CPP::String*)str));
		}

		//GetAllChildren(GetChild(transform, i), deepCount);
	}
}

UnityEngine::Vector3 UnityEngine::Transform::GetForward()
{
	using func_t = Vector3(*)(Transform* transform);

	func_t func = GetMethod<func_t>(0x1AC8750);

	return func(this);
}

UnityEngine::Vector3 UnityEngine::Transform::GetRight()
{
	using func_t = Vector3(*)(Transform* transform);

	func_t func = GetMethod<func_t>(0x1AC90A0);

	return func(this);
}

UnityEngine::Vector3 UnityEngine::Transform::GetUp()
{
	using func_t = Vector3(*)(Transform* transform);

	func_t func = GetMethod<func_t>(0x1AC9300);

	return func(this);
}

UnityEngine::Vector3 UnityEngine::Transform::GetPosition()
{
	using func_t = UnityEngine::Vector3(*)(__int64);

	func_t func = GetMethod<func_t>(GETPOSITION_TRANSFORM);

	return func((__int64)this);
}

void UnityEngine::Transform::SetPosition(Vector3 value)
{
	using func_t = void (*)(Transform* _this, Vector3 value);

	func_t func = GetMethod<func_t>(SETPOSITION_TRANSFORM);

	return func(this, value);
}

void UnityEngine::Transform::GetAllChildren(Transform* transform)
{
	int i = 0;
	//GetAllChildren(transform, i);
	ConsoleUtils::Log("Transforms found: ", i);
}

void UnityEngine::Transform::SetParent(Transform* to)
{
	using SetParentFunc_t = Transform * (*)(Transform* _this_t, Transform* to_t);

	SetParentFunc_t SetParentFunc = (SetParentFunc_t)GetMethod<SetParentFunc_t>(TRANSFORM_SETPARENT);

	SetParentFunc(this, to);
}

UnityEngine::Transform* UnityEngine::Transform::Find(std::string str)
{
	using FindFunc_t = Transform * (*)(Transform* transform_t, IL2CPP::String* str_t);

	FindFunc_t FindFunc = (FindFunc_t)GetMethod<FindFunc_t>(TRANSFORM_FIND);
	return FindFunc(this, IL2CPP::StringNew(str));
}
