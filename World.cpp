#include "World.h"
#include "Actor.h"
#include <algorithm>

bool Compare(AActor* A, AActor* B)
{
	return (A->GetZOrder() < B->GetZOrder());
}

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

std::vector<AActor*> UWorld::GetAllActors() const
{
	return Actors;
}

AActor* UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);

	return NewActor;
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SortActor()
{
	std::sort(Actors.begin(), Actors.end(), Compare);
	//for (int i = 0; i < Actors.size(); ++i)
	//{
	//	for (int j = i; j < Actors.size(); ++j)
	//	{
	//		if (Actors[i]->GetZOrder() < Actors[j]->GetZOrder())
	//		{
	//			AActor* Temp = Actors[i];
	//			Actors[i] = Actors[j];
	//			Actors[j] = Temp;
	//		}
	//	}
	//}


}
