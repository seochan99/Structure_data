//
//  main.c
//  ListQueue
//
//  Created by 서희찬 on 2021/04/04.
//

#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
    // Queue의 생성 및 초기화 //
    Queue q;
    QueueInit(&q);
    
    // 데이터 넣기 //
    Enqueue(&q, 1); Enqueue(&q, 2); Enqueue(&q, 3); Enqueue(&q, 4); Enqueue(&q, 5);
    
    // 데이터 꺼내기 //
    while(!QIsEmpty(&q)) // queue가 비어 있지 않는 이상 계속 와이이이일~~
        printf("%d ", Dequeue(&q));
    
    return 0;
}
