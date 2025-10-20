#include "Player.h"
#include "Engine.h"

#include <iostream>

APlayer::APlayer()
{
	ZOrder = 4;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	char KeyCode = GEngine->GetKeyCode();

	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		Location.X--;
	}
	if (KeyCode == 'd')
	{
		Location.X++;
	}
}
