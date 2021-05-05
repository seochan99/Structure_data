//
//  RSF.c
//  StructData_assignment_3
//
#include <stdio.h>
#include <stdlib.h>
#include "RSF.h"

void ListInit(List * plist) // 초기화 함수
{
    plist->head = NULL;
    plist->numOfNode = 0;
    // cur은 LFirst 호출시 초기화 되니 별도 초기화 X
    plist->cumputer_ptr = plist->head;
}

void ListInsert(List * plist){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->lose = 0;
    newNode->win = 0; // 승패 0으로 초기화
    
    newNode->right = plist->head;
    
    if(plist->head != NULL) // 두번재 이후 노드 추가시에만 실행
        plist->head->left = newNode;
    
    
    newNode ->left = plist->head; // 새노드의 이전이 기존 노드를 가리키게한다 (원형 )
    plist->head->right = newNode;
    plist->head = newNode;

    (plist->numOfNode)++; // 업업 !
}

int ListEmpty(List * plist){ //비어있는지 체크 함수
    //이를 통해서 노드가 모두 파괴됐을때 알려준다.
    if(plist->head == NULL) // head가 null이면 리스트는 비어 있다.
        return TRUE; // 비어있으면 참 반환
    else
        return FALSE;
}

// 플레이어 승리시 win += 1, win>=2 검사
//void PlayerWin()

// 플레이어 패배시 lose += 1 함수
// void PlayerLose()

int Lfirst(List * plist,Data * pWin, Data * pLose)
{
    if(plist->head == NULL)
        return FALSE;
    
    plist->cur = plist->head; // cur이 첫 번째 노드를 가리킨다.
    *pWin = plist->cur->win;
    *pLose = plist->cur->lose;
    return TRUE;
}

int LNext(List * plist, Data * pWin, Data * pLose)
{
    if(plist->cur->right == NULL)
        return FALSE;
    
    plist->cur = plist->cur->right; // cur 오른쪽 이동
    *pWin = plist->cur->win; // cur가리키는 승/패 반환
    *pLose = plist->cur->lose;
    return TRUE;
}

int LPrevious(List * plist, Data * pWin, Data * pLose)
{
    if(plist->cur->left == NULL)
        return FALSE;
    
    plist->cur = plist->cur->left; // cur 왼쪽 이동
    *pWin = plist->cur->win; // 왼쪽 으로 간 cur의 승/패 반환
    *pLose = plist->cur->lose;
    return TRUE;
}

// 양방향 삽입
//void LWinInsert(List * plist, Data * win, Data * lose)
//{
//
//}

// 노드제거
// void LoseRemove(List *plist)


//
