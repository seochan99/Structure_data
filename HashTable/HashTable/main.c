#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main(void)
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;
    
    TBLInit(&myTbl, MyHashFunc);
    
    // 데이터 입력
    np = MakePersonData(20120003, "Lee", "SEOUL");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20130012, "Seo", "MASAN");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20120025, "Hwe", "SEOUL");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    // 데이터 탐색
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 20130012);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 20120025);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    
    // 데이터 삭제
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 20130012);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 20120025);
    if(rp != NULL)
        free(rp);
    
    return 0;
}
