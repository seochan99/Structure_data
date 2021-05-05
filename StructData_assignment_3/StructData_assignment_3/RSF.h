//
//  RSF.h
//  StructData_assignment_3
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
    Data name; // 노드 이름
}Node;

typedef struct _dbLinkedList{ // 이중연결려스트
    Node * cumputer_ptr; // 컴퓨터 
    Node * head; // 머리(맨 앞 데이터 표시)
    Node * cur; // 조회 목적
    int numOfNode; // 총 노드의 겟수
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist); // 초기화
int ListEmpty(List * plist); //

//void ListInsert(List * plist); // 초기 numNode 노드 생성

void insertEnd(List*plist); // 끝에 노드 추가

void LWinInsert(Node * computer_ptr)
; // 이겼을 시 양 옆에 win.lose 을 가진 데이터 삽입
int Lfirst(List * plist,Data * pWin, Data * pLose);
 // 첫 노드
int LNext(List * plist, Data * pWin, Data * pLose);
 // 그 이후 노드 탐색
int LPrevious(List * plist, Data * pWin, Data * pLose)
; //이전 노드 탐색

int LCount(List * plist); // 모든 노드의 개수 반환

void printNode(List * plist);

void playerLose(Node * computer_ptr);

void playerWin(Node * computer_ptr);

// 양방향 삽입
//void LWinInsert(List * plist, Data * win, Data * lose)
//{
    //헤드와 연결되있는 노드 앞에 삽입
//그 노드 사이 삽입
// 노드 이어주기
// 맨 앞노드 맨 뒷 노드 연결
//}

// 노드제거
// Data LoseRemove(List *plist)
// 제거할 노드 갯수 체크 -> 1개라면 제거 노드 알려준 후 게임 끝
// 아니라면 -> 제거 노드 확인 후 노드 앞 뒤 연결

#endif /* RSF_h */
