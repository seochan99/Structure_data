//
//  PriorityQueue.h
//  UsefulHeap
//
//  Created by 서희찬 on 2021/04/11.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue * ppq, PriorityComp pc);
int PQIsEmpty(PQueue * ppq);

void PEnqueue(PQueue * ppq, PQData data);
PQData PDequeue(PQueue * ppq);

#endif /* PriorityQueue_h */
