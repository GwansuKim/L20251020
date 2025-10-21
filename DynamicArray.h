#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>

//template으로 class작성시 cpp에 작성 불가
//header에 소스 모두 작성해야함
//compile될때 필요한 자료형에 따라 코드를 생성하는데 cpp까지 가져올 수 없기 때문
template<typename T>
class TDynamicArray
{
public:
	TDynamicArray() {}
	virtual ~TDynamicArray()
	{
		if (Data)
		{
			delete[] Data;
		}
	}

protected:
	T* Data = nullptr;

	size_t Size = 0;

	size_t Index = 0;

public:
	size_t GetCapacity()
	{
		return Size;
	}

	size_t GetSize()
	{
		return Index;
	}


	//&를 붙이지 않으면 값을 복사해서 전달, &를 붙이면 주소값을 전달
	T& operator[](size_t _Index)
	{
		return Data[_Index];
	}

	void PushBack(T Value)
	{
		if (Data == nullptr)
		{
			Size++;
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
			std::move(Temp, &(Temp[Index + 1]), Data);
			//c language
			//memcpy(목표, 원본, 크기(byte)), memmove(목표, 원본, 크기(byte))
			Data[Index] = Value;

			delete[] Temp;
			Temp = nullptr;

			Index++;
		}
	}
};