//
//  ALGraph.c
//  Graph
//
//  Created by 서희찬 on 2021/04/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "ALGraph.h"

int WhoIsPrecede(int data1,int data2);

void GraphInit(ALGraph * pg, int nv) // 그래프의 초기화
{
    int i;
    
    // 정점의 수에 해당하는 길이의 리스트 배열을 생성하낟.
    pg->adjList = (List*)malloc(sizeof(List)*nv); // 간선정보를 저장할 리스트 생성
    
    pg->numV = nv; // 정점의 수는 nv에 저장된 값으로 결정
    pg->numE=0;// 초기의 간선수는 0개
    
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
