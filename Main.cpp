#include "Engine.h"
#include "DynamicArray.h"
#include "Vector.h"
#include "World.h"
#include "Actor.h"

//container
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

#include <algorithm>

int main(int argc, char* argv[])
{
	TDynamicArray<int> TDA;
	TDA.GetSize();

	for (int i = 1; i <= 100; ++i)
	{
		TDA.PushBack(i);
	}

	for (int i = 0; i < 100; ++i)
	{
		std::cout << TDA[i] << std::endl;
	}

	std::cout << "SIZE : " << TDA.GetSize() << std::endl;

	FVector2D A(10, 10);
	FVector2D B(20, 20);
	//FVector2D N = (A + B);
	FVector2D N = A.operator+(B);

	{
		std::vector<int> V;
		V.push_back(1);
		V.push_back(2);
		V.push_back(3);

		std::sort(V.begin(), V.end());
		std::find(V.begin(), V.end(), 3);

		//[][][]
		//for (std::vector<int>::iterator i = V.begin() ; i != V.end(); ++i)
		for (auto i = V.begin(); i != V.end(); ++i)
		{
			std::cout << *i << ", ";
		}
		std::cout << std::endl;

		std::list<int> L;
		L.push_back(1);
		L.push_back(2);
		L.push_back(3);

		L.sort();
		//std::find(L.begin(), L.end(), 3);

		//c++ 14 -> c++ 17
		//for (std::list<int>::iterator i = L.begin(); i != L.end(); ++i)
		for (auto Data : L)
		{
			std::cout << Data << ", ";
		}
		std::cout << std::endl;
	}

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	delete GEngine;

	return 0;
}