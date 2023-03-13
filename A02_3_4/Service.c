#include "Service.h"
//#include <stdlib.h>
//#include <string.h>
#include "Operation.h"

//Country *save_updated_country = NULL;
//Country *save_updated_countryy[100] = {0};
//int current_index = -1;
//int one_redo = 0; ///
Service *createService(CountryRepo *repo) {
    Service *s = malloc(sizeof(Service));
    if (s == NULL)
        return NULL;
    s->repo = repo;
    s->undoStack = createDynamicArray(10, &destroyOperation);
    s->redoStack = createDynamicArray(10, &destroyOperation);
    return s;
}

void destroyService(Service *s) {
    if (s == NULL)
        return;

    // first destroy the repository inside
    destroyRepo(s->repo);
    destroy(s->redoStack);
    destroy(s->undoStack);

    // then free the memory
    free(s);
}

int addCountry(Service *s, char *name, char *continent, double population) {
    // given name/continent/population are stored in the new object Country, which will be added in CountryRepo
    // Return 1 - added, otherwise 0
    Country *p = createCountry(name, continent, population);

    int res = add(s->repo, p);
    // if the country was not added - destroy it (as it will not be destroyed by the repository)
    if (res == 0) {
        destroyCountry(p);
    } // ? notinrepo? }


    Operation *op = createOperation(ADD, p);
    if (op == NULL)
        return -1;
    add_dynamic_array(s->undoStack, op);
    return res;
}

int removeCountry(Service *s, char *name) {   // return: res ->> removed = true, otherwise false

//    int res = removeCountryRepo(s->repo, name);
//    // if the planet was not added - destroy it (as it will not be destroyed by the repository)
//    if (res == 0){
//        return 0; // false
//    }
//    return res;

    Country *p = findByName(s->repo, name);
    Operation *op = createOperation(DELETE, p);
    if (op == NULL)
        return -1;
    add_dynamic_array(s->undoStack, op);

    return removeCountryRepo(s->repo, name);

}


//void redo_updated_country(Country *p) {
//    current_index++;
//    save_updated_countryy[current_index] = p;
//
//}

int updateCountry(Service *s, char name[], double quantity, int option) {
    // return : 1 - successfully updated, 0 otherwise

    Country *p = findByName(s->repo, name);

    Operation *op = NULL;
    if(option ==1)
        op = createOperation(UPDATE, p);
    else
        op = createOperation(UPDATE2, p);

    int res = update(s->repo, name, quantity, option);



    if (res == 1) {
//        p = findByName(s->repo, name); ///
//        redo_updated_country(p); // save the val...
        int i=0;
        add_dynamic_array(s->undoStack, op);
    }
    return res;
}

CountryRepo *getRepo(Service *s) {
    return s->repo;
}

CountryRepo *filter(Service *s, char type[], int option, double given_value_of_population) {
    // We create a new Repo for the filtered Countries (by name)
    // Return : res  (if the given type is null ->> al countries will be displayed, so repo size is 0)
    //                value != null, new repo will be returned
    // this will be done with the help of 'find_name' which filters the old repo into the new one
    CountryRepo *res = createRepo();


    if (strcmp(type, "null") == 0 && option == 1) {
        return res;
    }

    //int val = find(res, type, "continent");
    //res->size = getLength(res);

    CountryRepo *previous_repo = getRepo(s);
    if (option == 1) {
        res = find_name(previous_repo, res, type);
    } else if (option == 2) {
        res = find_continent(previous_repo, res, type, given_value_of_population);
    }

    // for each planet that fulfills the condition, create a copy and add it to "res"
    // why should we create a copy?

    return res;
}

CountryRepo *sort(Service *s, CountryRepo *res) {
    int ok;
    do {
        ok = 0;
        for (int i = 0; i < res->countries->length - 1; i++) {
            if (getPopulation_from_dyn_arr(res->countries, i) > getPopulation_from_dyn_arr(res->countries, i + 1)) {
                //if(getPopulation(res->countries->elems[i]) > getPopulation(res->countries->elems[i+1])){
                ok = 1;
                DynamicArray *aux = res->countries->elems[i];
                res->countries->elems[i] = res->countries->elems[i + 1];
                res->countries->elems[i + 1] = aux;
            }
        }
    } while (ok == 1);
    return res;
}

int undo(Service *s) {
    if (s == NULL)
        return -1; // error

    int stackSize = getLength_dynamic_array(s->undoStack);
    if (stackSize == 0)
        return 1; // no more undos
    Operation *op = get_arr_on_pos(s->undoStack, stackSize - 1);;
    if (op == NULL)
        return -1;
    Country *p = getOpObject(op);
    if (p == NULL)
        return -1;

    if (getOpType(op) == ADD)
        removeCountryRepo(s->repo, getName(p));
    else if (getOpType(op) == DELETE)
        add(s->repo, copyPlanet(p));
    else if (getOpType(op) == UPDATE)
        update(s->repo, getName(p), getPopulation(p), 1);
    else if(getOpType(op)== UPDATE2){
        Country* p1 = findByName(s->repo, getName(p));
        Operation *redo_op = createOperation(getOpType(op), p1); // add last Obj of the Undostack here
        update(s->repo, getName(p), getPopulation(p), 1);
        add_dynamic_array(s->redoStack, redo_op);
        remove_dynamic_array(s->undoStack, stackSize - 1);
        stackSize = getLength_dynamic_array(s->undoStack);
        op = get_arr_on_pos(s->undoStack, stackSize - 1);
        p = getOpObject(op);
        p1 = findByName(s->repo, getName(p));
        redo_op = createOperation(getOpType(op), p1); // add last Obj of the Undostack here
        update(s->repo, getName(p), getPopulation(p), 1);

        add_dynamic_array(s->redoStack, redo_op);
        remove_dynamic_array(s->undoStack, stackSize - 1);
        return 0;
    }

    // must have a copy, because p
    // will be destroyed when deleting
    // the operation from the stack

    // remove the operation from "the stack"
    // should be added to the redo stack
    Operation *redo_op = createOperation(getOpType(op), p); // add last Obj of the Undostack here
    add_dynamic_array(s->redoStack, redo_op);
    remove_dynamic_array(s->undoStack, stackSize - 1);



    //add(s->redoStack, op);//??
    return 0;
}

int redo(Service *s) {
    if (s == NULL)
        return -1; // error
    int stackSize = getLength_dynamic_array(s->redoStack);

    //s->redoStack->length -1 //todo
    if (stackSize == 0) {
//        current_index = 0;
        return 1;
    }// no more redos
    Operation *op = get_arr_on_pos(s->redoStack, stackSize - 1);
    if (op == NULL)
        return -1;
    Country *p = getOpObject(op);
    if (p == NULL)
        return -1;
    Country* p1 = NULL;
    if (getOpType(op) == ADD)
        add(s->repo, copyPlanet(p));

    else if (getOpType(op) == DELETE)
        removeCountryRepo(s->repo, getName(p));
    else if (getOpType(op) == UPDATE)
        update(s->repo, getName(p), getPopulation(p), 1); //// ????
    else if (getOpType(op) == UPDATE2) {
        p1 = findByName(s->repo, getName(p));
        Operation *undo_op = createOperation(getOpType(op), p1); // add last Obj of the Undostack here
        update(s->repo, getName(p), getPopulation(p), 1);


        add_dynamic_array(s->undoStack, undo_op);
        remove_dynamic_array(s->redoStack, stackSize - 1);


        stackSize = getLength_dynamic_array(s->redoStack);
        op = get_arr_on_pos(s->redoStack, stackSize - 1);
        p = getOpObject(op);
        p1 = findByName(s->repo, getName(p));
        undo_op = createOperation(getOpType(op), p1); // add last Obj of the Undostack here
        update(s->repo, getName(p), getPopulation(p), 1);


        add_dynamic_array(s->undoStack, undo_op);
        remove_dynamic_array(s->redoStack, stackSize - 1);
        return 0;
    }

//        one_redo = 1;
//    } else if (getOpType(op) == UPDATE && one_redo == 1) {
//        update(s->repo, getName(p), getPopulation(save_updated_countryy[current_index]), 1); //// ????
//        current_index++;
//    }

    // must have a copy, because p
    // will be destroyed when deleting
    // the operation from the stack

    // remove the operation from "the stack"
    // should be added to the redo stack

    //add_dynamic_array(s->redoStack, op);

    Operation *undo_op = createOperation(getOpType(op), p); // add last Obj of the Undostack here
    add_dynamic_array(s->undoStack, undo_op);

    remove_dynamic_array(s->redoStack, stackSize - 1);
    return 0;
}

void test_undo_redo(){

    CountryRepo* repo = createRepo();
    Service* serv = createService(repo);
    addCountry(serv,"Ukraine", "Europe", 12.5);

    assert(getLength(serv->repo) == 1);
    undo(serv);
    assert(getLength(serv->repo) == 0);
    redo(serv);
    assert(getLength(serv->repo) == 1);


    destroyService(serv);

}



