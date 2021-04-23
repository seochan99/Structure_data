#include <stdio.h>
#include "ALGraph.h"

int main(void)
{
    ALGraph graph;// 그래프의 생성
    GraphInit(&graph, 5); // 그래프의 초기화
    
    AddEdge(&graph, A, B); // A B 연결
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);
    
    ShowGraphEdgeInfo(&graph); // 그래프의 간선정보 출력
    GraphDestroy(&graph); // 그래프의 리소스 소멸
    
    return 0;
}


