//
//  CircularQueue.h
//  Queue
//
//  Created by 서희찬 on 2021/04/04.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
    int fornt; // f
    int rear; // r
    Data queArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue*pq); //초기화
int QIsEmpty(Queue*pq); //비었는지 체크
 
void Enqueue(Queue*pq,Data data); // 삽입
Data Dequeue(Queue * pq); //삭제
Data QPeek(Queue * pq); // 확인
 
#endif /* CircularQueue_h */
