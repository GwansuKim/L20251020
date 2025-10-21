#include "DynamicArray.h"
#include <iostream>
#include <algorithm>
#include <iterator>

TDynamicArray::TDynamicArray()
{
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (Data == nullptr)
	{
		Data = new int[Size];
	}

	if (Index < Size)
	{
		Data[Index] = Value;
		Index++;
	}
	else
	{
		Size <<= 1;
		int* Temp = Data;

		Data = new int[Size];
		std::copy(Temp, &(Temp[Index + 1]), Data);
		Data[Index] = Value;

		delete[] Temp;
		Temp = nullptr;

		Index++;
	}
}

void TDynamicArray::PrintOut()
{
	for(int i = 0; i < Index; ++i)
	{
		std::cout << Data[i] << std::endl;
	}
}

int TDynamicArray::PrintSize()
{
	std::cout << "Size : " << Index << std::endl;
	return Index;
}
