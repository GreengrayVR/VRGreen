#pragma once

#include "IL2CPP/IL2CPP.hpp"

template <typename T>
class List
{
public:
	List(IL2CPP::Array* arr);

public:
	T& operator[](int index)
	{
		if (index > (int)arrayLength)
		{
			return  *(T*)((((uint8_t*)(arr)) + arrayObjSize) + ((arrayElemSize) * (0)));
		}

		return *(T*)((((uint8_t*)(arr)) + arrayObjSize) + ((arrayElemSize) * (index)));
	}
	
	uint32_t arrayLength;
private:
	IL2CPP::Array* arr;
	uint32_t arrayObjTotalSize;
	uint32_t arraySize;
	uint32_t arrayElemSize;
	uint32_t arrayObjSize;
	using lambda_t = void(*)();
};

template <typename T>
List<T>::List(IL2CPP::Array* arr)
{
	this->arr = arr;

	this->arrayObjTotalSize = IL2CPP::ObjectGetSize(arr);
	this->arraySize = IL2CPP::ArrayGetByteLength(arr);
	this->arrayLength = IL2CPP::ArrayLength(arr);
	this->arrayElemSize = arrayLength ? arraySize / arrayLength : 0;

	this->arrayObjSize = arrayObjTotalSize - arraySize;
}