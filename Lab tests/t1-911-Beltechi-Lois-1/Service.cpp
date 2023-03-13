//
// Created by loisb on 06.04.2022.
//

#include "Service.h"

int Service::add_s(const std::string &name, int day, int month, int year, double sum, const std::string& isPaid) {
    Bill b{name, day, month, year, sum, isPaid};
    int val = this->repo.add_r(b);
    return val;
}

void Service::sort(DynamicVector<Bill> &list) {
    Bill* cur_repo=get_repo_s();

    for(int i=0;i<get_size_s();i++){
        if(cur_repo[i].get_isPaid()=="false")
            list.add(cur_repo[i]);
    }

    int ok;
    do{
        ok=0;

        for(int i=0;i<list.getSize()-1;i++){
            if(list[i].get_year() > list[i+1].get_year() || list[i].get_year() == list[i+1].get_year() && list[i].get_month() > list[i+1].get_month() ||
                    list[i].get_year() == list[i+1].get_year() && list[i].get_month() == list[i+1].get_month() && list[i].get_day() == list[i+1].get_day())
            {
                std::swap(list[i],list[i+1]);
                ok=1;
            }
        }

    }while(ok==1);
}
