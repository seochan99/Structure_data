//
//  ALGraphBFS.h
//  ALGraphBFS
//
//  Created by 서희찬 on 2021/04/24.
//

#ifndef ALGraphBFS_h
#define ALGraphBFS_h

#include "DLinkedList.h"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual{
    int numV;
    int numE;
    List * adjList;
    int * visitInfo;
}ALGraph;

//그래프의 초기화
void GraphInit(ALGraph * pg , int nv);

//그래프의 리소스 해제
void GraphDestroy(ALGraph * pg);

//간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg);

// 정점의 정보 출력 : DFS 기반
void BFShowGraphVertex(ALGraph * pg, int startV);


#endif /* ALGraphBFS_h */
