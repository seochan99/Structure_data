#include <stdio.h>
#include <stdlib.h>


// 1번 문제
//int main(void)
//{
//    int num1,num2;
//    while(1)
//    {   printf("더할 두 수를 입력 해주세요(-10000이상 10000이하의 정수)\n");
//        printf("첫번째 숫자 : ");
//        scanf("%d",&num1);
//        printf("두번째 숫자 : ");
//        scanf("%d",&num2);
//        if((num1<10000&&num1>-10000)&&(num2<10000&&num2>-10000))
//            break;
//        else
//            printf("-10000 이상 10000 이하의 정수를 입력해주세요.\n");
//    }
//    printf("두 수의 합 : %d\n",num1+num2);
//
//
//    return 0;
//}


//2
//int main(void){
//    int num1;
//    while(1)
//    {
//        printf("성적을 입력해주세요(0이상100이하의 정수) : ");
//        scanf("%d",&num1);
//        if(0<=num1&&num1<=100)
//            break;
//        else
//            printf("0이상 100이하의 정수를 입력해주세요. \n");
//    }
//    if(num1>=90)
//        printf("A\n");
//    else if(90>num1&&num1>=80)
//        printf("B\n");
//    else if(80>num1&&num1>=70)
//        printf("C\n");
//    else if(70>num1&&num1>=60)
//        printf("D\n");
//    else
//        printf("F\n");
//    return 0;
//}


//3
//int main(void)
//{
//    int num1;
//    while(1)
//    {
//        printf("1이상 100이하의 정수를 입력해주세요 ");
//        scanf("%d",&num1);
//        if(1<=num1&&num1<=100)
//            break;
//        else
//            printf("1이상 100이하의 정수를 입력해주세요. \n");
//    }
//    for(int i=0;i<=num1;i++)
//    {
//
//        for(int j = 0; j<i;j++)
//        {
//            printf("*");
//
//        }
//        printf("\n");
//    }
//    return 0;
//}


//4
int main(void)
{
    int num1,i,max,min;
    int arr[100];
    int result = 0;
    
    while(1)
    {
        printf("입력을 원하는 숫자의 갯수를 입력해주세요 : ");
        scanf("%d",&num1);
        
        if(1<=num1 && 100>=num1)
            break;
        else
            printf("1이상 100이하의 숫자를 입력해주새요.\n");
    }
    printf("%d개의 숫자를 입력해주세요 \n",num1);
    // 최대값 구하기
    for(int i=0;i<num1;i++)
    {
        scanf("%d",&arr[i]);
        result += arr[i];
    }

    // 최대 최소 구하기
     max = min = arr[0];
     for(i=1; i<num1; i++)
     {
         if(arr[i] > max)
             max = arr[i];
         if(arr[i] < min)
             min = arr[i];
     }
    
    printf("총 합 : %d ", result);
    printf("최솟값 : %d ", min);
    printf("최댓값 : %d \n", max);


    return 0;
}


// 5
//int main(void)
//{
//    int num1;
//    long long result=0;
//    while(1)
//    {
//        printf("약수의 합을 원하는 정수를 입력해주세요.\n");
//        scanf("%d",&num1);
//        if(num1>=1 && num1<= 1000000000)
//            break;
//        else
//            printf("1이상 1,000,000,000 이하의 정수를 입력해주세요.\n");
//    }
//    for(int i=1;i<=num1;i++)
//    {
//        if(num1%i==0)
//            result += i;
//    }
//    printf("약수의 총 합 : %lld \n", result);
//
//    return 0;
//}

//6

//// HEADER //
//#define TRUE    1
//#define FALSE    0
//
//typedef int Data;
//
//typedef struct _node
//{
//    Data data;
//    struct _node * next;
//    struct _node * prev;
//} Node;
//
//typedef struct _lQueue
//{
//    Node * front;
//    Node * rear;
//} LQueue;
//
//typedef LQueue Queue;
//
//void QueueInit(Queue * pq);
//int QIsEmpty(Queue * pq);
//
//void Enqueue(Queue * pq, Data data);
//Data Dequeue(Queue * pq);
//
//// MAIN //
//int main(void)
//{
//    int f=1;
//    int n,k;
//    int num;
//    // Q 생성, 초기화
//    Queue q;
//    QueueInit(&q);
//
//    printf("요세푸스 수열 입니다.\n");
//    printf("N을 입력해주세요 : ");
//    scanf("%d",&n);
//    printf("K를 입력해주세요 : ");
//    scanf("%d",&k);
//    printf("\n");
//
//    // 데이터 넣기
//    for(int i=1;i<=n;i++)
//    {
//        Enqueue(&q, i); // 큐에 숫자 집어 넣기
//    }
//
//    // 배열 생성
//    while(!QIsEmpty(&q)) // 큐가 비어 있을때까지 진행
//    {
//        for(int j=1;j<k;j++)
//        {
//            Enqueue(&q, Dequeue(&q));
//        }
//
//        // 하나의 숫자를 꺼내고 그 숫자 출력
//        num = Dequeue(&q);
//        printf("수열 %d번째 숫자 : %d \n",f,num);
//        f++;
//    }
//
//}
//
//
//// Funtion //
//void QueueInit(Queue * pq) // 큐 초기화
//{
//    pq->front = NULL;
//    pq->rear = NULL;
//}
//
//int QIsEmpty(Queue * pq) // 큐의 빈 여부를 확인하기 위한 함수
//{
//    if(pq->front == NULL)
//        return TRUE; // 큐가 비었다.(TRUE)
//    else
//        return FALSE; // 큐가 안비었다(FALSE)
//}
//
//void Enqueue(Queue * pq, Data data) // 큐에 추가
//{
//    Node * newNode = (Node*)malloc(sizeof(Node));
//    newNode->next = NULL;
//    newNode->data = data;
//
//    if(QIsEmpty(pq)) // 큐가 비어있다면
//    {
//        pq->front = newNode;
//        pq->rear = newNode;
//        newNode->prev = NULL;
//    }
//    else // 안비어있다면(첫 번째 이후 노드의 추가라면 )
//    {
//        pq->rear->next = newNode;
//        newNode->prev = pq->rear; // 새노드의 이전이 전에 노드를 가리키게한다.
//        pq->rear = newNode; // 꼬리가 새 노드를 가리킨다.
//    }
//}
//
//Data Dequeue(Queue * pq)
//{
//    Node * delNode;
//    Data retData;
//
//    if(QIsEmpty(pq))
//    {
//        printf("삭제 불가!");
//        exit(-1);
//    }
//    delNode = pq->front;
//    retData = delNode->data;
//    pq->front = pq->front->next;
//
//    free(delNode);
//
//    if(pq->front == NULL) // 제거할게 더 이상 없어용
//        pq->rear = NULL;
//    else
//        pq->front->prev = NULL; // 첫번째 노드를 제거하고 다음 노드의 prev 를 NULL로 설정 해준다.
//
//    return retData;
//}
