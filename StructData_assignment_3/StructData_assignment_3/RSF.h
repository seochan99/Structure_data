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
    Data numOfNode; // 총 노드의 겟수
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist); // 초기화

void insertEnd(List*plist); // 끝에 노드 추가

void LWinInsert(List * plist,Node * computer_ptr); // 이겼을 시 양 옆에 win.lose 을 가진 데이터 삽입
int LCount(List * plist); // 모든 노드의 개수 반환

// 노드 출력
void printNode(List * plist);

// 플레이어 짐(캄퓨터 승)
void playerLose(List * plist);

// 플레이어 이김(컴퓨터 짐 )
void playerWin(List * plist);

// 노드삭제
void LoseRemove(List * plist);


#endif /* RSF_h */
