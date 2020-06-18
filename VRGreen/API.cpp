#include "API.hpp"

#include "IL2CPP/IL2CPP.hpp";

void VRC::Core::API::SendRequest(std::string endpoint, int HTTPMethods, void* responseContainer, void* requestParams, bool authenticationRequired, bool disableCache, float cacheLifetime, int retryCount, void* credentials)
{
	using func_t = void (*)(IL2CPP::String*, int, void*, void*, bool, bool, float, int, void*);

	func_t func = GetMethod<func_t>(SENDREQUEST);

	func(IL2CPP::StringNew(endpoint), HTTPMethods, responseContainer, requestParams, authenticationRequired, disableCache, cacheLifetime, retryCount, credentials);
}

void VRC::Core::API::SendPostRequest(std::string endpoint, void* responseContainer, void* Dictionary_string_object, void* credentials)
{
	using func_t = void (*)(IL2CPP::String*, void*, void*, void*);

	func_t func = GetMethod<func_t>(0x4D2530);

	func(IL2CPP::StringNew(endpoint), responseContainer, Dictionary_string_object, credentials);
}
