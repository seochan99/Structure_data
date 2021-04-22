//
//  Person.h
//  HashTable
//
//  Created by 서희찬 on 2021/04/22.
//

#ifndef Person_h
#define Person_h

#define STR_LEN 50

typedef struct _person
{
    int ssn; //주민번호 : 키
    char name[STR_LEN];
    char addr[STR_LEN];
    
}Person;

int GetSSN(Person*p);
void ShowPerInfo(Person * p);
Person * MakePersonData(int ssn, char * name, char * addr);

#endif /* Person_h */
