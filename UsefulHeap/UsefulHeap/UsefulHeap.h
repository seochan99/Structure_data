//
//  UsefulHeap.h
//  UsefulHeap
//
//  Created by 서희찬 on 2021/04/11.
//

#ifndef UsefulHeap_h
#define UsefulHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int PriorityComp(HData d1,HData d2);

typedef struct _heap
{
    PriorityComp * comp;
    int numOfData;
    HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif /* UsefulHeap_h */
