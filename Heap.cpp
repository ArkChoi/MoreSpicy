#include "Heap.h"
#include <iostream>

Heap::Heap()
{
}

Heap::Heap(std::vector<int> &InVector)
{
    Heap::heapify(InVector);
}

Heap::~Heap()
{
}

void Heap::heapify(std::vector<int> &InVector)
{
	//init 작업
	int VectorSize = InVector.size();

	HeapVector.push_back(NULL); //heap 에서 0번 인덱스는 비워둬야 계산이 쉽기에 NULL(0) 처리
	for (int i = 0; i < VectorSize; i++) //0번 제외하고 vector 옮기기
	{
		HeapVector.push_back(InVector[i]);
	}

	//heapify 연산
	for (int i = VectorSize /2; 0 < i; i--)
	{
		while (2*i <= VectorSize) //자식이 있는 동안 반복
		{
			int Child = 2 * i; //왼쪽 자식 저장
			if (Child + 1 <= VectorSize && HeapVector[Child + 1] > HeapVector[Child]) //오른쪽 자식이 배열 안인가? (예외처리) + 왼쪽 자식보다 오른쪽 자식이 큰가?
			{
				Child++; //오른쪽 자식 선택
			}
			if (HeapVector[i] >= HeapVector[Child]) //부모가 자식보다 크거나 같으면 종료
			{
				break;
			}
			Swap(&HeapVector[i], &HeapVector[Child]);
			i = Child;
		}
	}
}

void Heap::heappush(int InNumber)
{
}

int Heap::heappop()
{
    return 0;
}

void Heap::PrintHeap()
{
	for (int i = 0; i < HeapVector.size(); i++)
	{
		std::cout << i << " : " << HeapVector[i] << " | ";
	}
}

void Heap::Swap(int* FirstInt, int* SecondInt)
{
	int Temp = *FirstInt;
	*FirstInt  = *SecondInt;
	*SecondInt = Temp;
}
