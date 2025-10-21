#include "Engine.h"
#include "DynamicArray.h"

int main(int argc, char* argv[])
{
	TDynamicArray TDA;

	for (int i = 1; i <= 20; ++i)
	{
		TDA.PushBack(i);
	}

	TDA.PrintOut();

	//GEngine->Init();
	//GEngine->Run();
	//GEngine->Term();

	//delete GEngine;

	return 0;
}