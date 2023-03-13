//
// Created by loisb on 06.04.2022.
//

#include "Repo.h"

int Repo::add_r(Bill &b) {
    int val= find_bill(b);
    if(val==-1){
        this->list.add(b);
        return 1;
    }
    return 0;
}

int Repo::find_bill(Bill &b) {
    Bill* cur_repo = get_repo_r();
    for(int i=0;i<get_size_r();i++){
        if(cur_repo[i].get_name() == b.get_name() && cur_repo[i].get_day() == b.get_day() && cur_repo[i].get_month() == b.get_month() &&
        cur_repo[i].get_year()== b.get_year()){
            return i;
        }
    }
    return -1;
}
