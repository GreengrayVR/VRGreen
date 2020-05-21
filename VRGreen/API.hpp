#pragma once

#include "Common.hpp"
#include <string>

namespace VRC::Core
{
	struct API
	{
		NOIMPLEMENT(API);

		// RVA: 0x750BC0 Offset: 0x74FDC0 VA: 0x180750BC0
		static void SendRequest(std::string endpoint, int HTTPMethods, void* responseContainer, void* requestParams, bool authenticationRequired, bool disableCache, float cacheLifetime, int retryCount, void* credentials);

	};



}