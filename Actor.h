#pragma once

#include "Vector.h"

class AActor
{
public:
	AActor();
	virtual ~AActor();

	//virtual function table -> vftbl
	//override
	virtual void Tick(); // �ڽ��� ������ �� ���� �ִ�
	virtual void Render();
	
	//__forceinline : �Ϲ� �Լ��ʹ� �޸� ȣ�� �κ��� �Լ� ��ü �ڵ�� ġȯ�Ͽ� ������
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

