//
//  Slot.h
//  HashTable
//
//  Created by 서희찬 on 2021/04/22.
//

#ifndef Slot_h
#define Slot_h
#include "Person.h"

typedef int Key; // ssn
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
    Key key;
    Value val;
    enum SlotStatus status;
}Slot;

#endif /* Slot_h */



