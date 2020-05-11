#pragma once

#include "Common.hpp"

struct CDetour;

namespace UnityEngine::Events
{
	struct UnityAction : Object
	{ 
		NOIMPLEMENT(UnityAction); 

		static UnityAction* ctor(CDetour* action);

		static void RunTimeMethod();
	};;

	

	


}
