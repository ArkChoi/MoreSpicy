//프로그래머스 : 더 맵게 (Lv. 2)
//힙을 사용하는 문제 (힙 자체 제작 버전)
//유사 문제 : 파일 병합 문제
#include <iostream>
#include <string>
#include <vector>
#include "Heap.h"

void VectorInput(std::vector<int>* InScoville);
int MaxScovilleInput();
int solution(std::vector<int> scoville, int K);

int main()
{
    std::vector<int> Scoville;
    int MaxScoville;
    int TempResult;

    VectorInput(&Scoville);
    MaxScoville = MaxScovilleInput();

    TempResult = solution(Scoville, MaxScoville);
    std::cout << TempResult;

    return 0;
}

void VectorInput(std::vector<int>* InScoville)
{
    std::cout << "VectorInputSize : ";
    int TempLoop = 0;
    std::cin >> TempLoop;
    for (int i = 0; i < TempLoop; i++)
    {
        std::cout << "VectorInputNum : ";
        int TempNumber = 0;
        std::cin >> TempNumber;
        InScoville->push_back(TempNumber);
    }
}

int MaxScovilleInput()
{
    std::cout << "MaxScovilleInput : ";
    int TempBudget = 0;
    std::cin >> TempBudget;
    return TempBudget;
}

int solution(std::vector<int> scoville, int K)
{
    int answer = 0;

    Heap scovilleHeap = Heap();
    //scovilleHeap.heapify(scoville);
    for (int i = 0; i < scoville.size(); i++)
    {
        scovilleHeap.heappush(scoville[i]);
    }
    scovilleHeap.PrintHeap();

    return answer;
}
