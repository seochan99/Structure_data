//
//  main.c
//  StructData_assignment_3
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RSF.h"


int main(void)
{
    srand((unsigned)time(NULL));
    List list;

    int i,j;
    int win=0,lose=0;
    int numNode; // 초기 노드의 갯수
    int userNum=0; //가위바위보
    int computerNum=0; // 컴퓨터의 선택
    //int numberOfNode=0; // 노드번호
    printf("초기 노드 개수를 입력해주세요  : ");
    scanf("%d",&numNode);
    
    ListInit(&list); // 초기화
    
    // numNode 만큼 노드 만들기
    for(i=0;i<numNode;i++)
    {
        insertEnd(&list); // 노드 추가
    }
    //가위바위보
    while(userNum!=4)
    {
        while(1) // 에러 처리
        {
            printf("\n선택하세요.(1.가위,2.바위,3.보,4.끝내기) : ");
            scanf("%d",&userNum);
            if(userNum<=4 && userNum>0)
                break;
            else
                printf("1~4사이의 숫자를 입력해주세요.\n");
        }
        
        // computerNum 구하기
        computerNum = rand()%3+1;
    
        // 가위바위보 하기
        if((userNum==1&& computerNum ==3)||(userNum==2&& computerNum ==1)||(userNum==3&& computerNum ==2)) // 플레이어 승
        {
            printf("컴퓨터가 패배했습니다.\n");
            playerWin(&list);
            
        }
        else if(userNum ==  computerNum) // 비김
        {
            printf("비겼습니다.\n");
            continue;
        }
        else if((userNum == 1 && computerNum ==  2)||(userNum == 2 && computerNum == 3)||(userNum == 3 && computerNum == 1)) // 플레이어 짐
        {
            printf("컴퓨터가 승리했습니다.\n");
            playerLose(&list);
        }
        
        // 총 노드 갯수 출력 : LCount 함수
        printf("총 노드 갯수 : %d\n",LCount(&list)+1);
        // node상태 화면 출력
        printNode(&list);
    }
    
    printf("\n 프로그램을 종료합니다. \n");

    return 0;
        }

    
    
    
    
