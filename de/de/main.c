#include <stdio.h>
#include "Deque.h"

int main(void)
{
    // Deque¿« ª˝º∫ π◊ √ ±‚»≠ ///////
    Deque deq;
    DequeInit(&deq);

    // µ•¿Ã≈Õ ≥÷±‚ 1¬˜ ///////
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);

    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    // µ•¿Ã≈Õ ≤®≥ª±‚ 1¬˜ ///////
    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveFirst(&deq));

    printf("\n");

    // µ•¿Ã≈Õ ≥÷±‚ 2¬˜ ///////
    DQAddFirst(&deq, 3);
    DQAddFirst(&deq, 2);
    DQAddFirst(&deq, 1);
    
    DQAddLast(&deq, 4);
    DQAddLast(&deq, 5);
    DQAddLast(&deq, 6);

    // µ•¿Ã≈Õ ≤®≥ª±‚ 2¬˜ ///////
    while(!DQIsEmpty(&deq))
        printf("%d ", DQRemoveLast(&deq));

    return 0;
}
