//
//  ListBaseQueue.c
//  ListQueue
//
//  Created by 서희찬 on 2021/04/04.
//
#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
    pq -> front = NULL;
    pq -> rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL) //F에 Null이 저장되어 있다면
        return TRUE; //큐가 텅 빈 것이니 True를 반환한다 !
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node)); // Newnode 동적할당
    newNode->next = NULL;
    newNode->data = data;
    
    if(QIsEmpty(pq)) //Queue가 비었을때
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode; //pq->rear->next 는 마지막노드가 가리키는 다음 노드
        pq->rear = newNode; // 꼬리가 새노드를 가리키게 한다.
    }
}

Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;
    
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    delNode = pq->front; //삭제할 노드의 주소 값 저장(first를 먼저 삭제하니깐 !!)
    retData = delNode->data;
    pq->front = pq->front->next;
    
    free(delNode);
    return retData;
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    return pq->front->data;
}
