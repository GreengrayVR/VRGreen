#include "ProperBitConverter.hpp"



int VRC::Udon::Serialization::OdinSerializer::ProperBitConverter::ToInt32(long long arr, int index) // public static uint ToUInt32(byte[] buffer, int index)
{
	using ToInt32_t = int(*)(long long, int);
	ToInt32_t ToInt32 = GetMethod<ToInt32_t>(0x1541E40);

	return ToInt32(arr, index);
}
