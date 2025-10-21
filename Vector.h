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

	FVector2D operator+(const FVector2D& RHS)
	{
		return FVector2D(this->X + RHS.X, this->Y + RHS.Y);
	}

	FVector2D operator-(const FVector2D& RHS)
	{
		return FVector2D(this->X - RHS.X, this->Y - RHS.Y);
	}

	int X;
	int Y;
};