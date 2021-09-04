//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main(void)
//{
////    int subway_1 = 30;
////    int subway_2 = 40;
////    int subway_3 = 50;
////
////    printf("1 is %d\n",subway_1);
////    printf("1 is %d\n",subway_2);
////    printf("1 is %d\n",subway_3);
//
//    //배열
////    int subway_array[3];
////    subway_array[0]=30;
////    subway_array[1]=20;
////    subway_array[2]=10;
////    for(int i=0;i<3;i++)
////    {
////        printf("%d is %d\n",i,subway_array[i]);
////    }
//
//    // 값 설정 방법
//    // 값은 항상 초기화 !
////    int arr[10]={1,2,3,4,5,6,7,8,9,10};
////    printf("%d",arr[3]);
//  // 문자 vs 문자열
////    char str[7]="coding"; //[c][o][d][i][n][g][\0] // 끝을 나타내는 \0자리 마련 .. !
////    printf("%s \n",str);
//  // ASCII CODE
//    // \\ a : 97 \\ A:65\\ 0:48
//
//    //project
//    srand(time(NULL));
//    printf("\n\n == father is bold == \n\n");
//    int ans;
//    int treatment = rand() % 4; // choose shampoo
//
//    int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
//    int prevCntShowBottle = 0;
//
//    for(int i=1;i<=3;i++)
//    {
//        int bottle[4]={0,0,0,0};
//        do{
//            cntShowBottle = rand()%2 + 2;
//        }while(cntShowBottle==prevCntShowBottle);
//
//        int isinclude = 0;
//        printf("%d 번째 시도 \n",i);
//
//        //
//        for(int j=0;j<cntShowBottle;j++)
//        {
//            int randBottle = rand()%4;
//            if(bottle[randBottle]==0)
//            {
//                bottle[randBottle]=1;
//                if(randBottle==treatment)
//                {
//                    isinclude=1;
//                }
//            }
//            else
//            {
//                j--;
//            }
//
//        }
//        //
//        for(int k=0;k<4;k++)
//        {
//            if(bottle[k]==1)
//            {
//                printf("%d ",k+1);
//            }
//            printf(" 물약을 머리에 바릅니다.\n\n");
//            if(isinclude==1)
//            {
//                printf("Success!");
//            }
//            else{
//                printf("Fail!");
//            }
//            printf("\n.... gogogo ");
//            getchar();
//        }
//    }
//    printf("What?");
//    scanf("%d",&ans);
//
//    if(ans == treatment+1)
//    {
//        printf("\n Sucess !");
//    }
//    else
//    {
//        printf("No!!!, %d is good",treatment+1);
//    }
//
//    return 0;
//}
