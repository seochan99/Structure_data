//
//  main.c
//  ALGraphKruskal
//
//  Created by 서희찬 on 2021/04/25.
//

#include <stdio.h>
#include "ALGraphKruskal.h"

int main(void)
{
    ALGraph graph;
    GraphInit(&graph, 6);

    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, B, C, 2);
    AddEdge(&graph, A, C, 12);
    AddEdge(&graph, A, D, 8);
    AddEdge(&graph, D, C, 6);
    AddEdge(&graph, A, F, 11);
    AddEdge(&graph, F, D, 4);
    AddEdge(&graph, D, E, 3);
    AddEdge(&graph, E, C, 7);
    AddEdge(&graph, F, E, 13);

    
    ConKruskalMST(&graph); // MST 변환
    ShowGraphEdgeInfo(&graph);
    ShowGraphEdgeWeightInfo(&graph);

    

    GraphDestroy(&graph);
    return 0;
}
