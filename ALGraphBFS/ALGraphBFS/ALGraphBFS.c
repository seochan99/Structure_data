//
//  ALGraphBFS.c
//  ALGraphBFS
//
//  Created by 서희찬 on 2021/04/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ALGraphBFS.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1,int data2);

void GraphInit(ALGraph * pg, int nv) // 그래프의 초기화
{
    int i;
    
    // 정점의 수에 해당하는 길이의 리스트 배열을 생성하낟.
    pg->adjList = (List*)malloc(sizeof(List)*nv); // 간선정보를 저장할 리스트 생성
    pg->visitInfo = (int*)malloc(sizeof(int)*pg->numV); // 정점의 수를 길이로 하여 배열을 할당
    
    pg->numV = nv; // 정점의 수는 nv에 저장된 값으로 결정
    pg->numE=0;// 초기의 간선수는 0개
    memset(pg->visitInfo,0,sizeof(int)*pg->numV);
    
    // 정점의 수만큼 생성된 리스트들을 초기화한다.
    for(i=0;i<nv;i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede); //정렬기준유도
        
    }
    
}

void GraphDestroy(ALGraph * pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList); // 동적으로 할당된 연결 리스트의 소멸
    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV )
{
    // 정점 form V의 연결 리스트에 정점 toV 의 정보 추가
    LInsert(&(pg->adjList[fromV]), toV);
    
    // 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE+=1;
    
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
    int i;
    int vx;
    
    for (i=0; i<pg->numV; i++) { // for 문을 돌면서 리스트의 모든 키에 접근한다.
        printf("%c 와 연결된 정점 : ",i + 65); // 아스키코드로 !
        
        if(LFirst(&(pg->adjList[i]), &vx)) //vx에 저장된다.
        {
            printf("%c ",vx+65);
            
            while(LNext(&(pg->adjList[i]), &vx)) // 연결된 노드가 있다면 출력
                printf("%c ",vx+65);
        }
        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1<data2)
        return 0;
    else
        return 1;
}

int VisitVertex(ALGraph * pg, int visitV)
{
    if(pg->visitInfo[visitV]==0) // visitV에 처음 방문일 때 '참' 인 이프문
    {
        pg->visitInfo[visitV] = 1; // 방문한것으로 기록
        printf("%c ", visitV+65); //방문 정점 이름 출력
        return TRUE; // 방문 성공
    }
    return FALSE; // 방문 실패
}

// DFS -> 정점의 정보 출력
void BFShowGraphVertex(ALGraph * pg, int startV)
{
    Queue queue;
    int visitV = startV;
    int nextV;
    
    QueueInit(&queue);
    
    VisitVertex(pg, visitV); // 시작 정점을 탐색한다.
    
    // 아래의 반복문에서는 visitV와 연결된 모든 정점에 방문한다.
    while(LFirst(&(pg->adjList[visitV]), &nextV)==TRUE)
    {
        if(VisitVertex(pg, nextV)==TRUE)
            Enqueue(&queue, nextV); // nextV에 방문했으니 큐에 저장
        
        while (LNext(&(pg->adjList[visitV]), &nextV)==TRUE)
        {
            if(VisitVertex(pg, nextV)==TRUE)
                Enqueue(&queue, nextV);  // nextV에 방문했으니 큐에 저장
        }
        
        if(QIsEmpty(&queue) == TRUE) // 큐가 비었다~ 종료 !
            break;
        else
            visitV = Dequeue(&queue); // 큐에서 하나 꺼내서 다시 반복문 시작!~
    }

    memset(pg->visitInfo, 0, sizeof(int)*pg->numV); // 탐색 정보 초기화
}

