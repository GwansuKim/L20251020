#include "Engine.h"
#include "Wall.h"
#include "World.h"
#include "Player.h"
#include "Floor.h"
#include "Monster.h"
#include "Goal.h"

#include <iostream>
#include <fstream>
#include <conio.h>
#include <algorithm>

FEngine* FEngine::Instance = 0;

FEngine::FEngine() :
	World(nullptr)
{
}

FEngine::~FEngine()
{
}

bool cmp(AActor* A, AActor* B)
{
	return (A->GetZOrder() < B->GetZOrder());
}

void FEngine::Init()
{
	World = new UWorld();

	std::ifstream MapFile("Level01.map");

	if (MapFile.is_open()) {
		char Buffer[100] = { 0, };
		int Y = 0;
		while (MapFile.getline(Buffer, 100))
		{
			std::string Line = Buffer;
			for (int X = 0; X < Line.size(); ++X)
			{
				
				{
					AActor* NewActor = new AFloor();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape(' ');
					World->SpawnActor(NewActor);
				}
				
				if (Line[X] == '*')
				{
					AActor* NewActor = new AWall();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape('*');
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'P')
				{
					AActor* NewActor = new APlayer();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape('P');
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'M')
				{
					AActor* NewActor = new AMonster();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape('M');
					World->SpawnActor(NewActor);
				}
				else if (Line[X] == 'G')
				{
					AActor* NewActor = new AGoal();
					NewActor->SetActorLocation(FVector2D(X, Y));
					NewActor->SetShape('G');
					World->SpawnActor(NewActor);
				}
			}
			Y++;
		}
	}

	//1.
	//std::sort(World->GetAllActors().begin(), World->GetAllActors().end(), cmp);

	//2. 정렬 로직 자체 구현
	for (int i = 0; i < World->GetAllActors().size() - 1; ++i)
	{
		if (World->GetAllActors()[i]->GetZOrder() > World->GetAllActors()[i + 1]->GetZOrder())
		{
			std::cout << World->GetAllActors()[i] << std::endl;
			AActor* temp = World->GetAllActors()[i];
			std::cout << temp << std::endl;

			World->GetAllActors()[i] = World->GetAllActors()[i + 1];
			std::cout << World->GetAllActors()[i] << std::endl;
			World->GetAllActors()[i + 1] = temp;
			std::cout << World->GetAllActors()[i + 1] << std::endl;

			i -= 2;
		}
	}
	

	MapFile.close();
}

void FEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void FEngine::Term()
{
}

void FEngine::Input()
{
	KeyCode = _getch();
}

void FEngine::Tick()
{
	GetWorld()->Tick();
}

void FEngine::Render()
{
	GetWorld()->Render();
}
