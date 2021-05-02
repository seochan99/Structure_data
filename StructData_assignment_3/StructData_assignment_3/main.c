//
//  main.c
//  StructData_assignment_3
//
//  Created by 서희찬 on 2021/05/01.
//

#include <stdio.h>
#include <stdlib.h>
#include "RSF.h"


int main(void)
{
    int i,j;
    int numNode; // 초기 노드의 갯수
    int userNum; //가위바위보
    int computerNum;
    printf("초기 노드 개수를 입력해주세요 : ");
    scanf("%d",&numNode);
    
    // numNode 만큼 노드 만들기
    
    while(userNum!=4)
    {
        
        printf("선택하세요.(1.가위,2.바위,3.보,4.끝내기) : ");
        scanf("%d",&userNum);
        // computerNum 구하기
        // 가위바위보 하기
        
        // 가위바위보 알고리즘 //.
        // 만약 플레이어가 이기면
        // win 올리는데, 2 이상이면 0으로 변경 후 노드 양쪽 삽입 후(LInsert) 현재 노드 오른쪽으로 이동(LNext 함수)
        // 만약 플레이어가 지면
        // lose올리고 lose가 2이상이면 현재 노드 삭제 후 (앞으로 이동 후 ) 현재 노드 왼쪽으로 이동(LPrev 함수)
        
        // 비기면 다시 시작(continue)
        
        // 총 노드 갯수 출력 : LCount 함수
        while(j=1;j<=numNode;j++)
        {
            //만약 노드의 끝이 아니라면
                // win = 첫번째 노드의 데이타(헤드가 가리키는 곳)
                // lose = 첫번째 노드의 데이타
                //만약 현재노드가 아니라면
                printf("node %d : win = %d, lose = %d<->",j,win,lose);
                // 만약 현재 노드라면
                printf("node* %d : win = %d, lose = %d<->",j);
            //노드의 끝이라면
            //출력 후
            //탈출 ~ !
        }
        }
        
    }
    
    
    
    return 0;
}
