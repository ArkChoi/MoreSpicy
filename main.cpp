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
int Mix(Heap* InScovilleHeap);

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
    scovilleHeap.heapify(scoville);

    while (scovilleHeap.heapfront() < K)
    {
        if (Mix(&scovilleHeap)) //Mix 함수 사용, 인자값으로 1개 남았는지 체크까지 진행
        {
            answer++;
        }
        else
        {
            answer = -1;
            break;
        }
    }

    return answer;
}

int Mix(Heap* InScovilleHeap)
{
    //섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
    int FirstScoville = InScovilleHeap->heappop();
    int SecondScoville = InScovilleHeap->heappop();

    if (SecondScoville == -1) //만일 모든 음식을 섞어 1개만 남았는데 섞는 행위를 하는 예외처리
    {
        return 0; //false
    }

    int MixScoville = FirstScoville + (SecondScoville * 2);
    InScovilleHeap->heappush(MixScoville);

    return 1; //true
}
