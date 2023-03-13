//
// Created by loisb on 17.03.2022.
//

#include "Operation.h"
#include "Country.h"
#include <stdlib.h>

Operation* createOperation(opType type, Country* p) {
    Operation* op = malloc(sizeof(Operation));
    op->type = type;

    Country* copyOfP = copyPlanet(p); ///
    op->p = copyOfP;

    return op;
}

void destroyOperation(Operation* o) {
    if (o == NULL)
        return;

    destroyCountry(o->p);
    free(o);
}

opType getOpType(Operation* o) {
    if (o == NULL)
        return -1;
    return o->type;
}

Country* getOpObject(Operation* o) {
    if (o == NULL)
        return NULL;
    return o->p;
}
