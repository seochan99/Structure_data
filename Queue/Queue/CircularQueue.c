//
//  CircularQueue.c
//  Queue
//
//  Created by 서희찬 on 2021/04/04.
//
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq) // 텅 빈 경우 front와 rear은 동일 위치 가리킴
{
    pq->fornt = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq)
{
    if(pq->fornt == pq->rear) //큐가 텅 비었을 때
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) // 핵심 함수 ! 회전을 돕는 함수이다.
{
    if(pos==QUE_LEN-1) //배열의 마지막 요소의 인덱스 값이라면
        return 0; // 0을 반환한다
    else
        return pos+1; //아니면 그냥 다음 인덱스 값을 전달해준다
}

void Enqueue(Queue * pq, Data data)
{
    if(NextPosIdx(pq->rear) == pq->fornt) //큐가 꽉 찼다면
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    pq->rear = NextPosIdx(pq->rear); // rear 한 칸 이동
    pq->queArr[pq->rear] = data; // rear 이 가리키는 곳에 데이터 저장
}

Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    pq->fornt = NextPosIdx(pq->fornt); //fornt 1칸 이동
    return pq->queArr[pq->fornt]; //front가 가리키는 데이터 반환
}

Data Qpeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    return pq->queArr[NextPosIdx(pq->fornt)]; //맨 앞 데이터 알려주기 front = 비었으니 인덱스 알려준다 
}
