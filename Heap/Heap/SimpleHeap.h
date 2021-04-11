//
//  SimpleHeap.h
//  Heap
//
//  Created by 서희찬 on 2021/04/11.
//

#ifndef SimpleHeap_h
#define SimpleHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
    Priority pr; // 값이 작을수록 높은 우선순위
    HData data;
}HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
}Heap;

//typedef struct _heap{
//    PriorityComp *comp; // typedef int (*PriorityComp)(HData d1,HData d2);
//    int numOfData;
//    HData heapArr[HEAP_LEN]; // typedef char HData
//};

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);

#endif /* SimpleHeap_h */
