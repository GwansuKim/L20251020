#pragma once

#include "Vector.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();

	//virtual function table -> vftbl
	//override
	virtual void Tick(); // 자식이 재정의 할 수도 있다
	virtual void Render();
	
	//__forceinline : 일반 함수와는 달리 호출 부분을 함수 전체 코드로 치환하여 컴파일
	__forceinline FVector2D GetActorLocation() const
	{
		return Location;
	}

	void SetActorLocation(FVector2D Value)
	{
		Location.X = Value.X;
		Location.Y = Value.Y;
	}

	__forceinline char GetShape() const
	{
		return Shape;
	}

	void SetShape(char Value)
	{
		Shape = Value;
	}

	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

protected:
	FVector2D Location;
	char Shape;
	int ZOrder;
};

