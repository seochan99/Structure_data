//
//  ALGraphKruskal.c
//  ALGraphKruskal
//
//  Created by 서희찬 on 2021/04/25.
//

#include "ALGraphKruskal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ArrayBaseStack.h"



void RemoveWayEdge(ALGraph * pg, int fromV, int toV) // 한쪽 방향의 간선 소멸
{
    int edge;
    
    if(LFirst(&(pg->adjList[fromV]), &edge))
    {
        if(edge==toV)
        {
            LRemove(&(pg->adjList[fromV]));
            return;
        }
        while(LNext(&(pg->adjList[fromV]), &edge))
        {
            if(edge==toV){
                LRemove(&(pg->adjList[fromV]));
                return;
            }
        }
    }
}

void RemoveEdge(ALGraph * pg, int fromV, int toV) // 간선의 소멸
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}


int WhoIsPrecede(int data1,int data2);

int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}



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
    
    //우선 순위 큐의 초기화
    PQueueInit(&(pg->pqueue), PQWeightComp);
    
}

void GraphDestroy(ALGraph * pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList); // 동적으로 할당된 연결 리스트의 소멸
    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV,int weight)
{
    Edge edge = {fromV, toV, weight}; // 간선의 가중치 정보를 담음
    
    // 정점 form V의 연결 리스트에 정점 toV 의 정보 추가
    LInsert(&(pg->adjList[fromV]), toV);
    
    // 정점 toV의 연결 리스트에 정점 fromV의 정보 추가
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE+=1;
    
    // 간선의 가중치 정보를 우선순의 큐에 저장 
    PEnqueue(&(pg->pqueue), edge);
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
        //printf("%c ", visitV+65); //방문 정점 이름 출력
        return TRUE; // 방문 성공
    }
    return FALSE; // 방문 실패
}

// DFS -> 정점의 정보 출력
void DFShowGraphVertex(ALGraph * pg, int startV)
{
    // 시작 정점의 방문이 일어난다 !
    Stack stack;
    int visitV = startV;
    int nextV;
    
    StackInit(&stack); // DFS를 위한 스택의 초기화
    VisitVertex(pg, visitV); // 시작 정점을 방문
    SPush(&stack, visitV); // 시작 정점의 정보를 스택으로 !
    
    
    // visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while 문
    while(LFirst(&(pg->adjList[visitV]), &nextV)== TRUE)
        // LFirst 를 통해서 visitV에 연결된 정점 하나를 얻는다.
        // 이렇게 해서 얻은 정점의 정보는 nextV에 저장된다.
        
    {
        // visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
        int visitFlag = FALSE;
        
        // nextV에 담긴 정점의 정보를 가지고 방문을 시도한다.
        if(VisitVertex(pg, nextV)== TRUE) // 방문에 성공했다면
        {
            // 방문 성공했으니 visitV의 정보는 스택에 푸쉬
            SPush(&stack, visitV); // visitV 담긴 내용을 PUSH
            // nextV에 담긴 정보를. visitV 에 담고 다시 반복문
            // 반복문을 다시 시작하는 것은 또 다른 정점의 방문을 시도하는 것 !
            visitV = nextV;
            visitFlag = TRUE;
        }
        // LFirst 함수를 통해서 얻은 정점의 방문에 실패한 경우 이하 실행
        else // 방문 실패.. 연결된 다른 정점들을 찾는다.
        {
            //아래의 반목은 visitV에 연결된 정점을 찾을 때 까지 반복된다.
            while(LNext(&(pg->adjList[visitV]), &nextV)== TRUE)
            {
                //LNext 함수의 호출을 통해서 visitV에 연결된 정점 하나를 얻는다.
                // 이렇게 얻은 정점의 정보는 nextV에 저장된다.
                
                // 이 정보를 바탕으로 방문을 시도한다.
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV); // 방문 성공했으니 푸쉬
                    visitV = nextV; // 담고 브레윀!
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        // 정점 방문에 실패했다면 그에 따른 처리를 진행한다.
        if(visitFlag == FALSE) // 추가로 방문한 정점이 없었다면
        {
            // 길을 되돌아 가거나 시작 위치로 되돌아와서 프로그램을 종료하거나
            if(SIsEmpty(&stack)== TRUE) // 시작점으로 되돌아 왔음
                break;
            else
                visitV = SPop(&stack); // 길을 되돌아간다
        }
    }
    
    // 이후의 탐색을 위해서 탐색 정보 초기화
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

int IsConnVertex(ALGraph * pg, int v1, int v2)
{
    // 시작 정점의 방문이 일어난다 !
    Stack stack;
    int visitV = v1; // 1
    int nextV;
    
    StackInit(&stack); // DFS를 위한 스택의 초기화
    VisitVertex(pg, visitV); // 시작 정점을 방문
    SPush(&stack, visitV); // 시작 정점의 정보를 스택으로 !
    
    
    // visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while 문
    while(LFirst(&(pg->adjList[visitV]), &nextV)== TRUE)
        // LFirst 를 통해서 visitV에 연결된 정점 하나를 얻는다.
        // 이렇게 해서 얻은 정점의 정보는 nextV에 저장된다.
    {
        // visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행
        int visitFlag = FALSE;
        
        // 정점을 돌아다니는 도중에 목표를 찾는다면 트루를 반환
        if(nextV == v2)
        {
            // 함수가 반환되기 전에 초기화 진행
            memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
            return TRUE; // 목표 찾았으니 트루 반환
        }
        

        
        // nextV에 담긴 정점의 정보를 가지고 방문을 시도한다.
        if(VisitVertex(pg, nextV)== TRUE) // 방문에 성공했다면
        {
            // 방문 성공했으니 visitV의 정보는 스택에 푸쉬
            SPush(&stack, visitV); // visitV 담긴 내용을 PUSH
            // nextV에 담긴 정보를. visitV 에 담고 다시 반복문
            // 반복문을 다시 시작하는 것은 또 다른 정점의 방문을 시도하는 것 !
            visitV = nextV;
            visitFlag = TRUE;
        }
        // LFirst 함수를 통해서 얻은 정점의 방문에 실패한 경우 이하 실행
        else // 방문 실패.. 연결된 다른 정점들을 찾는다.
        {
            //아래의 반목은 visitV에 연결된 정점을 찾을 때 까지 반복된다.
            while(LNext(&(pg->adjList[visitV]), &nextV)== TRUE)
            {
                //LNext 함수의 호출을 통해서 visitV에 연결된 정점 하나를 얻는다.
                // 이렇게 얻은 정점의 정보는 nextV에 저장된다.
                if(nextV == v2)
                {
                    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
                    return TRUE;
                }
                // 이 정보를 바탕으로 방문을 시도한다.
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV); // 방문 성공했으니 푸쉬
                    visitV = nextV; // 담고 브레윀!
                    visitFlag = TRUE;
                    break;
                }
            }
        }
        // 정점 방문에 실패했다면 그에 따른 처리를 진행한다.
        if(visitFlag == FALSE) // 추가로 방문한 정점이 없었다면
        {
            // 길을 되돌아 가거나 시작 위치로 되돌아와서 프로그램을 종료하거나
            if(SIsEmpty(&stack)== TRUE) // 시작점으로 되돌아 왔음
                break;
            else
                visitV = SPop(&stack); // 길을 되돌아간다
        }
    }
    
    // 이후의 탐색을 위해서 탐색 정보 초기화
    memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
    return FALSE; // 목표를 찾지 못했다 !
}

void ConKruskalMST(ALGraph * pg) // 최소 비용 신장 트리를 구성하는 함수
{
    Edge recvEdge[20]; // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;
    
    // MST를 형성할 때까지 아래의 반복문 실행
    while(pg->numE+1 > pg -> numV) // MST 간선의 수 + 1 == 정점의 수
    {
        // 우선순위 큐에서 가중치가 제일 높은 간선의 정보를 꺼낸다.
        edge = PDequeue(&(pg->pqueue));
        
        // 우선순위 큐에서 꺼낸 간선을 실제로 그래프에서 삭제한다.
        RemoveEdge(pg,edge.v1,edge.v2);
        
        // 간선을 삭제하고 나서도 두 정점을 연결하는 경로가 있는지 확인한다.
        if(!IsConnVertex(pg,edge.v1,edge.v2))
        {
            // 경로가 없다면 삭제한 간선을 다시 살린다.
            RecoverEdge(pg,edge.v1,edge.v2,edge.weight);
            
            // 복원한 간선의 정보를 별도로 저장한다.
            recvEdge[eidx++] = edge;
        }
    }
    // 우선순위 큐에서 삭제된 간선의 정보를 회복
    for(i=0;i<eidx;i++)
    PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg) // 간선의 가중치 정보 출력
{
    PQueue copyPQ = pg -> pqueue;
    Edge edge;
    
    while(!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c ~ %c, w:%d \n", edge.v1+65,edge.v2+65,edge.weight);
    }
}


