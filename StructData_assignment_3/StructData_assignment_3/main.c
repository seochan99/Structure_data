//
//  main.c
//  StructData_assignment_3
//
//  Created by 서희찬 on 2021/05/01.
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
    int computerNum=0;
    printf("초기 노드 개수를 입력해주세요 : ");
    scanf("%d",&numNode);
    
    ListInit(&list);
    
    // numNode 만큼 노드 만들기
    for(i=0;i<numNode;i++)
    {
        ListInsert(&list); // 노드 생성 완료
    }

    
    //가위바위보
    while(userNum!=4)
    {
        while(1) // 에러 처리
        {
            printf("선택하세요.(1.가위,2.바위,3.보,4.끝내기) : ");
            scanf("%d",&userNum);
            if(userNum<=4 && userNum>0)
                break;
            else
                printf("1~4사이의 숫자를 입력해주세요.\n");
        }
        
        // computerNum 구하기
        computerNum = rand()%3+1;
        
        // 가위바위보 하기
        if((userNum==1&& computerNum ==3)||(userNum==2&& computerNum ==1)||(userNum==3&& computerNum ==2))
        {
            printf("컴퓨터가 패배했습니다.");
            // lose +1 추가 
            // lose >=2 체크
            // 맞으면 노드 삭제
            // 컴퓨터 왼쪽 노드 이동 (left)
        }
        else if(userNum ==  computerNum)
            
        {
            printf("비겼습니다.");
            continue;
        }
        else if((userNum == 1 && computerNum == 2)||(userNum == 2 && computerNum == 3)||(userNum == 3 && computerNum == 1))
        {
            printf("컴퓨터가 승리했습니다.");
            // win +1
            // win>=2 체크
            // 맞으면 양 옆에 노드 추가 (left right)
            // 컴퓨터 오른쪽 노드로 이동 (right)
        }
        
        
        
//        // 총 노드 갯수 출력 : LCount 함수
//        // node상태 화면 출력
            }
    return 0;
        }

    
    
    
    
