//
//  RSF.c
//  StructData_assignment_3
//
//  Created by 서희찬 on 2021/05/01.
//
#include <stdio.h>
#include <stdlib.h>
#include "RSF.h"

void ListInit(List * plist) // 초기화 함수
{
    plist->head = NULL;
    plist->numOfNode = 0;
}
int ListEmpty(List * plist){ //비어있는지 체크 함수
    //이를 통해서 노드가 모두 파괴됐을때 알려준다.
    if(plist->head == NULL) // head가 null이면 리스트는 비어 있다.
        return TRUE; // 비어있으면 참 반환
    else
        return FALSE;
}

void LWinInsert(List * plist, Data * win, Data * lose)
{
    
}
