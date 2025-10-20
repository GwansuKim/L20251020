#pragma once


//구조체(C++) : Data 저장용
//문법적으로 Class와 큰차이 없음
struct FVector2D
{
public:
	FVector2D(int InX = 0, int InY = 0) :
		X(InX), Y(InY)
	{

	}

	virtual ~FVector2D()
	{

	}

	int X;
	int Y;
};