#pragma once
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	int* Data = new int[Size];

	int Size = 10;

	int Index = 0;

	void PushBack(int Value);

	void PrintOut();
};

