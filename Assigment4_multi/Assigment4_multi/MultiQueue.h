#ifndef MultiQueue_h
#define MultiQueue_h

#include <stdio.h>

#define TRUE    1
#define FALSE    0

typedef char name[100];

typedef struct _node
{
    Data name;
    struct _node * next;
} Node;

typedef struct _lQueue
{
    Node * front;
    Node * rear;
    int numOfNode;
    int numOfQueue;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq); // 큐 초기화 , 베리어도 ..?

int QIsEmpty(Queue * pq); // 빈 상태 - >


void EnBarrier(Queue * pq, int num); // 베리어 삽입

void Enqueue(Queue * pq, Data name); // 큐 삽입
Data Dequeue(Queue * pq); // 큐 삭제

#endif




#endif /* MultiQueue_h */
