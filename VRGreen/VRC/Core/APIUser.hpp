#pragma once

#include "Common.hpp"
#include <string>

namespace IL2CPP
{
	struct String;
}

namespace VRC::Core
{
	struct APIUser : Object 
	{
		NOIMPLEMENT(APIUser); 
	
		static bool isFriendsWith(IL2CPP::String* userId); // isFriendsWith

		static bool isFriendsWith(const std::string& userId); // isFriendsWith

		bool hasTag(const std::string& userId); // hasTag(string tag)

		static APIUser* currentUser(); // public static APIUser get_CurrentUser

		std::string displayName(); // get_displayName()

		std::string getId();

		std::string getVRCA();

	
	};

}