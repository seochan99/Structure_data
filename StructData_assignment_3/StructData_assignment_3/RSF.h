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
    struct _node * right; // 다음 노드
    struct _node * left; // 이전 노드
}Node;

typedef struct _dbLinkedList{ // 이중연결려스트
    Node * head; // 머리(맨 앞 데이터 표시)
    int numOfNode; // 총 노드의 겟수
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist); // 초기화
int ListEmpty(List * plist);
void LWinInsert(List *plist, Data * win, Data * lose); // 이겼을 시 양 옆에 win.lose 을 가진 데이터 삽입

int LFirst(List * plist, Data * pdata); // 첫번재 데이터
int LNext(List * plist,Data *pdata);
int LPrevious(List * plist, Data * pdata);

int LCount(List * plist);



#endif /* RSF_h */
