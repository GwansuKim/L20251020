#include "DynamicArray.h"
#include <iostream>
#include <algorithm>
#include <iterator>

TDynamicArray::TDynamicArray() :
	Data(new int[Size])
{
}

TDynamicArray::~TDynamicArray()
{
}

void TDynamicArray::PushBack(int Value)
{
	if (Index < Size)
	{
		Data[Index] = Value;
		Index++;
	}
	else
	{
		Size++;
		int* Temp = new int[Size];

		std::copy(Data, &(Data[Size - 1]), Temp);
		Temp[Index] = Value;

		Data = new int[Size];
		std::copy(Temp, &(Temp[Size]), Data);

		delete[] Temp;
		Temp = nullptr;

		Index++;
	}
}

void TDynamicArray::PrintOut()
{
	for(int i = 0; i < Size; ++i)
	{
		std::cout << Data[i] << std::endl;
	}
}
