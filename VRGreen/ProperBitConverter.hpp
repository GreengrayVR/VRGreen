#pragma once
#include "IL2CPP/IL2CPP.hpp"

namespace VRC::Udon::Serialization::OdinSerializer
{
	struct ProperBitConverter
	{
		static int ToInt32(long long arr, int index); // public static uint ToUInt32(byte[] buffer, int index)
	};
}