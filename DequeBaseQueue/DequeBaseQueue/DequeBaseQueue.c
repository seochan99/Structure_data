//
//  DequeBaseQueue.c
//  DequeBaseQueue
//
//  Created by 서희찬 on 2021/04/05.
//

#include "DequeBaseQueue.h"

void QueInit(Queue * pq)
{
    DequeInit(pq);
}

int QIsEmpty(Queue * pq)
{
    return DQIsEmpty(pq);
}

void Enqueue(Queue*pq,Data data)
{
    DQAddLast(pq, data);
}

Data Dequeue(Queue * pq)
{
    return DQRemoveFirst(pq);
}

Data QPeek(Queue * pq)
{
    return DQGetFirst(pq);
}
