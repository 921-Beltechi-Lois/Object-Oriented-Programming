//
// Created by loisb on 17.03.2022.
//

#ifndef _OPERATION_H
#define _OPERATION_H

#endif //_OPERATION_H

#pragma once
#include "Country.h"

// version 2 - operation contains functions (function pointers) for
// the undo and redo functions, as well as the parameters for them
//typedef int (*undoPtrFct)(void*, void*);
//
//typedef struct
//{
//	void* obj;
//	undoPtrFct undoFct, redoFct;
//} Operation;


typedef enum {
    ADD,
    DELETE,
    UPDATE,
    UPDATE2
} opType;

typedef struct {
    opType type;
    Country* p;
} Operation;

Operation* createOperation(opType type, Country* p);
void destroyOperation(Operation* o);

opType getOpType(Operation* o);
Country* getOpObject(Operation* o);
