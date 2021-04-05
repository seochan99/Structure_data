//
//  DequeBaseQueue.h
//  DequeBaseQueue
//
//  Created by 서희찬 on 2021/04/05.
//

#ifndef DequeBaseQueue_h
#define DequeBaseQueue_h

#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif /* DequeBaseQueue_h */
