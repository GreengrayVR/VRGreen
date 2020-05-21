#include "API.hpp"

#include "IL2CPP/IL2CPP.hpp";

void VRC::Core::API::SendRequest(std::string endpoint, int HTTPMethods, void* responseContainer, void* requestParams, bool authenticationRequired, bool disableCache, float cacheLifetime, int retryCount, void* credentials)
{
	using func_t = decltype(&VRC::Core::API::SendRequest);

	func_t func = GetMethod<func_t>(0x750BC0);

	func(endpoint, HTTPMethods, responseContainer, requestParams, authenticationRequired, disableCache, cacheLifetime, retryCount, credentials);
}
