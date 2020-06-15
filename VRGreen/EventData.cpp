#include "EventData.hpp"
#include "IL2CPP/IL2CPP.hpp"

inline static int32_t getCodeOffset = -3;

int EventData::GetCode()
{
	if (getCodeOffset == -3)
		getCodeOffset = IL2CPP::ResolveFieldOffset(this, "Code");

	return GetField<int>(this, getCodeOffset);
}

inline static int32_t getParametersOffset = -3;

void* EventData::GetParameters()
{
	if (getParametersOffset == -3)
		getParametersOffset = IL2CPP::ResolveFieldOffset(this, "Parameters");

	return GetField<void*>(this, getParametersOffset);
}
