#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>

//template���� class�ۼ��� cpp�� �ۼ� �Ұ�
//header�� �ҽ� ��� �ۼ��ؾ���
//compile�ɶ� �ʿ��� �ڷ����� ���� �ڵ带 �����ϴµ� cpp���� ������ �� ���� ����
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


	//&�� ������ ������ ���� �����ؼ� ����, &�� ���̸� �ּҰ��� ����
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
			//memcpy(��ǥ, ����, ũ��(byte)), memmove(��ǥ, ����, ũ��(byte))
			Data[Index] = Value;

			delete[] Temp;
			Temp = nullptr;

			Index++;
		}
	}
};