//
//  Person.c
//  HashTable
//
//  Created by 서희찬 on 2021/04/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p)
{
    return p->ssn; // key 값이니 별도로 함수를 짜주었다.
}

void ShowPerInfo(Person * p)
{
    printf("주민등록번호 : %d \n",p->ssn);
    printf("이름 : %s \n",p->name);
    printf("주소: %s \n",p->addr);
    printf("\n");
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
    Person*newP = (Person*)malloc(sizeof(Person));
    newP->ssn = ssn;
    strcpy(newP->name, name);
    strcpy(newP->addr, addr);
    return newP;
}
