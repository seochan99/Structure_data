//
//  RSF.c
//  StructData_assignment_3
//
#include <stdio.h>
#include <stdlib.h>
#include "RSF.h"

void ListInit(List * plist) // 초기화 함수
{
    plist->cumputer_ptr = plist->head; // 컴퓨터 머리가리키기 이게맞나..?
    plist->head = NULL;
    plist->numOfNode = 0;
    // cur은 LFirst 호출시 초기화 되니 별도 초기화 X
    plist->cumputer_ptr = plist->head;
}

//void ListInsert(List * plist){
//    Node * newNode = (Node*)malloc(sizeof(Node));
//    newNode->lose = 0;
//    newNode->win = 0; // 승패 0으로 초기화
//
//    newNode->right = plist->head;
//
//    if(plist->head != NULL) // 두번재 이후 노드 추가시에만 실행
//        plist->head->left = newNode;
//
//
//    newNode ->left = plist->head->left; // 새노드의 이전이 기존 노드를 가리키게한다 (원형 )
//    plist->head->right = newNode; //
//    plist->head = newNode;
//
//    (plist->numOfNode)++; // 업업 !
//}



// 플레이어 승리시 win += 1, win>=2 검사
//void PlayerWin()

// 플레이어 패배시 lose += 1 함수
// void PlayerLose()
int ListEmpty(List * plist){ //비어있는지 체크 함수
    //이를 통해서 노드가 모두 파괴됐을때 알려준다.
    if(plist->head == NULL) // head가 null이면 리스트는 비어 있다.
        return TRUE; // 비어있으면 참 반환
    else
        return FALSE;
}

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
// 컴퓨터 노드 받기
void LWinInsert(List * plist,Node * computer_ptr)
{
    // 오른쪽 노드 생성
    Node * newNodeRight = (Node*)malloc(sizeof(Node));
    newNodeRight->win=0;
    newNodeRight->lose=0;
    (plist->numOfNode)++;
    newNodeRight->name = plist->numOfNode;
    
    //왼쪽 노드 생성
    Node * newNodeLeft = (Node*)malloc(sizeof(Node));
    newNodeLeft->win=0;
    newNodeLeft->lose=0;
    (plist->numOfNode)++;
    newNodeLeft->name = plist->numOfNode; // 이름 설정
    
    // 연결해주기
    // 오른쪽
    // computer_ptr 다음 노드와 오른쪽 삽입된 노드간의 연결
    newNodeRight->right = computer_ptr->right;
    computer_ptr->right->left = newNodeRight;
    
    //computer_ptr 노드와 오른쪽 삽입 새 노드 연결
    computer_ptr->right = newNodeRight;
    newNodeRight->left = computer_ptr;
    
    
    //왼쪽
    //computer_ptr 이전 노드와 왼쪽 삽입된 노드간의 연결
    newNodeLeft->left = computer_ptr->left;
    computer_ptr->left->right = newNodeLeft;
    
    //computer_ptr 노드와 왼쪽 삽입 새 노드 연결
    computer_ptr->left = newNodeLeft;
    newNodeLeft->right = computer_ptr;

    
}

void playerWin(List * plist) //플레이어 승리시
{
    plist->cumputer_ptr->win++; // 승 하나 올리기
    if((plist->cumputer_ptr->win) >= 2) // 2이상 일때
    {
        //노드 양방향 삽입
        plist->cumputer_ptr->win = 0; // 승리 0초기화
        LWinInsert(plist,plist->cumputer_ptr); // 양쪽 새노드 삽입
    }
    plist->cumputer_ptr = plist->cumputer_ptr->left; // 왼쪽으로 이동
}

void playerLose(List * plist) // 플레이어 패배시
{
    plist->cumputer_ptr->lose =plist->cumputer_ptr->lose + 1; // 패배 하나 올리기
    if((plist->cumputer_ptr->lose)>=2) // 패배 2이상
    {
        LoseRemove(plist);
    }
    plist->cumputer_ptr = plist->cumputer_ptr->right; // 오른쪽 이동
}


// 노드제거
 void LoseRemove(List * plist)
{
     Node * rpos = plist->cumputer_ptr;
     
     plist->cumputer_ptr->left->right = plist->cumputer_ptr->right;
     plist->cumputer_ptr->right->left = plist->cumputer_ptr->left;
     
     plist->cumputer_ptr = plist->cumputer_ptr->left; // 컴퓨터 왼쪽으로 이동
     free(rpos);
     (plist->numOfNode)--;
 }



void insertEnd(List*plist) // 노드 뒤로 이어가기
{
    if(plist->head== NULL) // 리스트가 비어있다면
    {
        Node * newNode = (Node*)malloc(sizeof(Node));
        newNode->win=0;
        newNode->lose=0;
        newNode->right = newNode->left = newNode;//자기자신을 가리킴 -> 원형
        plist->head = newNode;
        plist->cumputer_ptr = plist->head;
        return;
    }
    
    //노드가 비어있지 않다면
    Node * last = plist->head->left; // 마지막 노드 찾기
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->win = 0;
    newNode->lose = 0; // 초기화 진행
    
    newNode->right = plist->head;
    plist->head->left = newNode;
    newNode->left = last;
    last->right = newNode;
    
    (plist->numOfNode)++; // 노드 숫자 증가
    newNode->name = plist->numOfNode; // 노드 번호 할당
}
int LCount(List * plist) // 갯수세기
{
    return plist->numOfNode;
}

void printNode(List * plist){
    if(plist->head==NULL)
    {
        return ;
        
    }
    plist->cur = plist->head; // cur 이 첫번째 노드 가리킴
    printf("HEAD");
    
    // 제일 처음 출력 => HEAD*
    // 컴퓨터 노드 위치 까지 계산 후 그 위치에 * 찍기...
    for(int k=0;k<plist->numOfNode+1;k++)
    {
        printf("->NODE %d(WIN:%D LOSE:%d)<-",plist->cur->name+1,plist->cur->win,plist->cur->lose);
        plist->cur = plist->cur->right;
        
    }
    
}


