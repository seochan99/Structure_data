//
//  PriorityQueue.c
//  UsefulHeap
//
//  Created by 서희찬 on 2021/04/11.
//

#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue * ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}
int PQIsEmpty(PQueue * ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue * ppq, PQData data)
{
    HInsert(ppq, data);
}

PQData PDequeue(PQueue * ppq)
{
    return HDelete(ppq);
}
