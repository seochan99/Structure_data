#include <stdio.h>


// 1번 문제
//int main(void)
//{
//    int num1,num2;
//    printf("더할 두 수를 입력 해주세요");
//    scanf("%d %d",&num1,&num2);
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
//int main(void)
//{
//    int num1;
//    int arr[100];
//    int result = 0;
//    int max=0;
//    int min=10000;
//    printf("입력을 원하는 숫자의 갯수를 입력해주세요 : ");
//    scanf("%d ",&num1);
//
//    for(int i=0;i<num1;i++)
//    {
//        scanf("%d",&arr[i]);
//        result += arr[i];
//    }
//    for(int j=0;j<num1;j++)
//    {
//        if(arr[j]>=max)
//            max = arr[j];
//        if (arr[j]<min)
//            min = arr[j];
//    }
//
//    printf("총 합 : %d ", result);
//    printf("최댓값 : %d ", max);
//    printf("최솟값 : %d \n", min);
//
//    return 0;
//}


// 5
int main(void)
{
    int num1;
    int result=0;
    printf("약수의 합을 원하는 정수를 입력해주세요.\n");
    scanf("%d",&num1);
    for(int i=1;i<=num1;i++)
    {
        if(num1%i==0)
            result += i;
    }
    printf("약수의 총 합 : %d \n", result);
    
    return 0;
}

