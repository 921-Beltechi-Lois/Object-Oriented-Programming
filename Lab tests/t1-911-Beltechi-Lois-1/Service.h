//
// Created by loisb on 06.04.2022.
//

#ifndef T1_911_BELTECHI_LOIS_1_SERVICE_H
#define T1_911_BELTECHI_LOIS_1_SERVICE_H

#include "Repo.h"
#include "Bill.h"

class Service {
    Repo& repo;
public:
    Service(Repo& repo): repo{repo} {}
    /*
     * Adds to the list the given data from the ui
     * Return True if added succesfully, otherwise false
     */
    int add_s(const std::string& name, int day, int month, int year, double sum, const std::string& isPaid);
    int get_size_s(){return this->repo.get_size_r();}
    Bill* get_repo_s(){return this->repo.get_repo_r();}

    /*
     * finds bill and returns its position in the list, or -1 if it does not exist
     */
    int find_bill_s(Bill& b){return this->repo.find_bill(b);}
    void sort(DynamicVector<Bill>& list);
};


#endif //T1_911_BELTECHI_LOIS_1_SERVICE_H
