//
//  RSF.h
//  StructData_assignment_3
//
//  Created by 서희찬 on 2021/05/01.
//

#ifndef RSF_h
#define RSF_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct node // 노드 구조체
{
    Data win; // 플레이어 이긴 횟수 저장
    Data lose; // 플레이아 진 횟수 저장
    struct node * right; // next
    struct node * left; // prev
}Node;

typedef struct _dbLinkedList{ // 이중연결려스트
    Node * cumputer_ptr;
    Node * head; // 머리(맨 앞 데이터 표시)
    Node * cur; // 조회 목적
    int numOfNode; // 총 노드의 겟수
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist); // 초기화
int ListEmpty(List * plist); //
void ListInsert(List * plist); // 초기 numNode 노드 생성
void LWinInsert(List  *plist); // 이겼을 시 양 옆에 win.lose 을 가진 데이터 삽입
int Lfirst(List * plist,Data * pWin, Data * pLose);
 // 첫 노드
int LNext(List * plist, Data * pWin, Data * pLose);
 // 그 이후 노드 탐색
int LPrevious(List * plist, Data * pWin, Data * pLose)
; //이전 노드 탐색

int LCount(List * plist); // 모든 노드의 개수 반환



#endif /* RSF_h */
