//
//  ALGraph.h
//  Graph
//
//  Created by 서희찬 on 2021/04/23.
//

#ifndef ALGraph_h
#define ALGraph_h

#include "DLinkedList.h"

// 정점의 이름을 상수화
enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
    int numV; // 정점의 수
    int numE; // 간선의 수
    List * adjList; //간선의 정보
}ALGraph;

// init graph
void GraphInit(ALGraph * pg, int nv);

// 그래프 리소스 해제
void GraphDestroy(ALGraph * pg);

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV );

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

#endif /* ALGraph_h */
