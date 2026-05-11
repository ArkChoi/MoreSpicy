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
			if (Child + 1 <= VectorSize && HeapVector[Child + 1] < HeapVector[Child]) //오른쪽 자식이 배열 안인가? (예외처리) + 왼쪽 자식보다 오른쪽 자식이 작은가?
			{
				Child++; //오른쪽 자식 선택
			}
			if (HeapVector[i] <= HeapVector[Child]) //부모가 자식보다 작거나 같으면 종료
			{
				break;
			}
			Swap(&HeapVector[i], &HeapVector[Child]);
			i = Child;
		}
	}
}

void Heap::heappush(int InKey)
{
	if (HeapVector.empty()) //0번칸 NULL 예외처리
	{
		HeapVector.push_back(NULL);
	}
	HeapVector.push_back(InKey); // 마지막 노드에 key 값을 삽입
	int i = HeapVector.size() - 1;
	int Parent = i / 2; //부모노드 탐색
	while (HeapVector.size() > 2 && HeapVector[i] < HeapVector[Parent]) //부모보다 작으면
	{
		Swap(&HeapVector[i], &HeapVector[Parent]);
		i = Parent; //부모로 이동
		Parent = i / 2; //부모 재계산 
		if (Parent == 0) //0번 인덱스 예외처리
		{
			break;
		}
	}
}

int Heap::heappop()
{
	int n = HeapVector.size() - 1;
	int MaxBalue = -1;

	if (n > 0)
	{
		MaxBalue = HeapVector[1]; //루트값 저장

		Swap(&HeapVector[1], &HeapVector[n]); //마지막 원소를 루트로 이동
		//힙 줄이기.. 백터 어떻게 줄이냐?
		HeapVector.resize(n--); //메모리는 나두고 사이즈만 줄이는 방법
		//HeapVector.shrink_to_fit(); //메모리 공간까지 사이즈를 줄이기

		int i = 1; //루트부터 시작
		while (2 * i < n)
		{
			int Child = 2 * i; //왼쪽 자식
			if (Child + 1 <= n && HeapVector[Child + 1] < HeapVector[Child])
			{
				Child++; //오른쪽 자식이 더 작으면 선택
			}
			if (HeapVector[i] <= HeapVector[Child])
			{
				break; //부모가 자식보다 작거나 같으면 완료
			}
			Swap(&HeapVector[i], &HeapVector[Child]);
			i = Child; //자식으로 이동
		}
	}

    return MaxBalue; //삭제한 최대값 반환
}

int Heap::heapfront()
{
	return HeapVector[1];;
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
