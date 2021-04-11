//
//  main.c
//  UsefulHeap
//
//  Created by 서희찬 on 2021/04/11.
//

#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
    return ch2 - ch1;
}
int main(void)
{
    PQueue pq;
    PQueueInit(&pq,DataPriorityComp);
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'A');
    printf("%c \n",PDequeue(&pq));
    
    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));
    
    return 0;
}
//void PQueueInit(PQueue * ppq, PriorityComp pc);
// - 우선순위 큐의 초기화를 진행한다.
// - 우선순위 큐 생성후 제일 먼저 호출되어야 하는 함수이다.
//
//int PQIsEmpty(PQueue * ppq);
// - 우선순위 큐가 빈 경우 True(1) 그렇지 않은 경우 FALSE(0) 을 반환한다.template
//
//void PEnqueue(PQueue * pqq, PQData data);
// - 우선순위 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.template
//
//PQData PDequeue(PQueue * ppq);
// - 우선순위가 가장 높은 데이터를 삭제한다.
// - 삭제된 데이터는 반환된다.
// - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야한다.
