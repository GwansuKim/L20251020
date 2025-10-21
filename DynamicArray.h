#pragma once
class TDynamicArray
{
public:
	TDynamicArray();
	virtual ~TDynamicArray();

	int* Data;

	int Size = 10;

	int Index = 0;

	void PushBack(int Value);

	void PrintOut();

	int PrintSize();
};

