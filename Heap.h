#pragma once
#include <vector>

class Heap
{
private:
    std::vector<int> HeapVector;

public:
    Heap();
    Heap(std::vector<int> &InVector);

    ~Heap();

    //정적 배열을 힙으로 만들기 
    void heapify(std::vector<int> &InVector);
    //동적 삽입 (sift-up) 연산 
    void heappush(int InKey);
    //삭제(remove = sift-down) 연산
    int  heappop();

    //단순 내용 출력 함수 본래 존재하면 안됨
    void PrintHeap();

private:
    //이름 그대로 Swap 함수 int 만 가능
    void Swap(int* FirstInt, int* SecondInt);

};


