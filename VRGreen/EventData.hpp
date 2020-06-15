#pragma once

#include "UnityEngine/Component.hpp"

struct EventData : UnityEngine::Component
{
	NOIMPLEMENT(EventData);

	int GetCode();

	void* GetParameters();
};