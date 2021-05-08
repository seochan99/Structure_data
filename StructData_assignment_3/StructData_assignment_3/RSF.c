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
//    plist->cumputer_ptr = plist->head;
}

// 양방향 삽입
// 컴퓨터 노드 받기
void LWinInsert(List * plist,Node * computer_ptr)
{
    
    //왼쪽 노드 생성
    Node * newNodeLeft = (Node*)malloc(sizeof(Node));
    newNodeLeft->win=0;
    newNodeLeft->lose=0;
    (plist->numOfNode)++;
    newNodeLeft->name = plist->numOfNode; // 이름 설정
    
    // 오른쪽 노드 생성
    Node * newNodeRight = (Node*)malloc(sizeof(Node));
    newNodeRight->win=0;
    newNodeRight->lose=0;
    (plist->numOfNode)++;
    newNodeRight->name = plist->numOfNode;

    
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

// 총노드갯수
int LCount(List * plist)
{
    return plist->numOfNode+1;
}

// 노드 출력
void printNode(List * plist){
    int numNodes = plist->numOfNode+1;
    if(plist->head==NULL)
    {
        return ;
        
    }
    plist->cur = plist->head; // cur 이 첫번째 노드 가리킴
    if(LCount(plist)==0)
        printf("HEAD*");
    else{
        printf("HEAD");
    // 제일 처음 출력 => HEAD*
    // 컴퓨터 노드 위치 까지 계산 후 그 위치에 * 찍기...
    for(int j=0 ;j<numNodes;j++)
    {
        if(plist->cur == plist->cumputer_ptr)
        {
            printf("->NODE%d*(WIN:%D LOSE:%d)<-",plist->cur->name+1,plist->cur->win,plist->cur->lose);
        }
        else
        {
        printf("->NODE%d(WIN:%D LOSE:%d)<-",plist->cur->name+1,plist->cur->win,plist->cur->lose);
        }
        plist->cur = plist->cur->right;
    }
    }
}


// 발견한 오류
// 노드 1이 패배2일때 제거가 안됨
// 그러나 나머지 노드들은 제거잘됨
// 나머지 기능들 이상 무
// 추가 생각 name-> 구조체말고 구현하기... how..

