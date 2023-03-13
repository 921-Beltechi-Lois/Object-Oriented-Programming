//
// Created by loisb on 06.04.2022.
//

#ifndef T1_911_BELTECHI_LOIS_1_REPO_H
#define T1_911_BELTECHI_LOIS_1_REPO_H

#include "DynamicVector.h"
#include "Bill.h"

class Repo {
    DynamicVector<Bill> list;
public:
    Bill* get_repo_r() { return this->list.getAllElems();}
    int get_size_r(){return this->list.getSize();}
    /*
    * Adds to the list the given data from the ui
    * Return True if added succesfully, otherwise false
    */
    int add_r(Bill& b);
    /*
     * finds bill and returns its position in the list, or -1 if it does not exist
     */
    int find_bill(Bill& b);
};


#endif //T1_911_BELTECHI_LOIS_1_REPO_H
