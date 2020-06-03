#pragma once

#include "Common.hpp"
#include <string>

namespace VRC::Core
{
	struct API
	{
		NOIMPLEMENT(API);

		static void SendRequest(std::string endpoint, int HTTPMethods, void* responseContainer, void* requestParams, bool authenticationRequired, bool disableCache, float cacheLifetime, int retryCount, void* credentials);

		static void SendPostRequest(std::string target, void* responseContainer, void* Dictionary_string_object, void* credentials);
	};



}