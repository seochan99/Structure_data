// made multiQueue
#include <stdio.h>
#include <stdlib.h> // rand()
#include <time.h>

int main(void)
{
    int subQueueNum;
    int randomOfQueue=0, randomEnDe=0;
    int sizeOfQueue;
    int i;
    int num=0;
    srand(time(NULL));
    printf("멀티큐 생성에 오신것을 환영합니다.\n");
    printf("서브 큐의 개수 N 을 입력해주세요 ! : ");
    scanf ("%d",&subQueueNum);
    printf("전체 큐의 최대크기 S 를 입력해주세요 ! : ");
    scanf("%d",&sizeOfQueue);
    
    while (1) {
        printf("선택해주세요.\n");
        printf("계속 실행 : 1 ");
        printf(" 그만 ! : 2 \n");
        scanf("%d",&num);
        
        // 난수 발생
        if(num == 1)
        {

            for(i=0;i<sizeOfQueue*3;i++) // s의 3배 크기만큼 실행 반복문
            {
                randomOfQueue = rand() % subQueueNum +1 ;
                randomEnDe = rand() % 2 + 1;
                // 엔큐
            }
        }
        else if(num == 2)
        {
            printf("\n종료합니다. \n");
            break;
        }
    }
    
    
    
    
    
    return 0;
}
