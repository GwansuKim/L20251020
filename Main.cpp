#include "Engine.h"
#include "DynamicArray.h"

int main(int argc, char* argv[])
{
	TDynamicArray TDA;
	TDA.PrintSize();

	for (int i = 1; i <= 100; ++i)
	{
		TDA.PushBack(i);
	}

	TDA.PrintOut();
	TDA.PrintSize();

	//GEngine->Init();
	//GEngine->Run();
	//GEngine->Term();

	//delete GEngine;

	return 0;
}