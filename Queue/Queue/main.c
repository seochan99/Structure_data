//
//  main.c
//  Queue
//
//  Created by 서희찬 on 2021/04/04.
//

#include <stdio.h>
#include "CircularQueue.h"

int main(void){
    
    // Queue의 생성 및 초기화 //
    Queue q;
    QueueInit(&q);
    
    // 데이터 넣기 //
    Enqueue(&q, 1); Enqueue(&q, 2);
    Enqueue(&q, 3); Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    // 데이터 빼기 //
    while(!QIsEmpty(&q)) // True 일떄 == 안비어져 있을때까지 와일문 실행
        printf("%d ", Dequeue(&q));
    
    return 0;
}
