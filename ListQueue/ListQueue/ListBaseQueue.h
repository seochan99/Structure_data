//
//  ListBaseQueue.h
//  ListQueue
//
//  Created by 서희찬 on 2021/04/04.
//

#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
    Data data;
    struct _node *next;
}Node;

typedef struct _LQueue{
    Node *front;
    Node *rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue*pq);
int QIsEmpty(Queue*pq);

void Enqueue(Queue*pq,Data data); // enqueue 연산 담당 함수
Data Dequeue(Queue*pq); //dequeue 연산 담당 함수
Data QPeek(Queue*pq);

#endif /* ListBaseQueue_h */
