//
// Created by loisb on 04.05.2022.
//

#include "Client.h"

bool Person::isInterested(Dwelling d) {
    if(d.getdw_price()/1000<=this->income) // Person has Total income=income
        return true;
    return false;
}

std::string Person::toString() {
    return "Person,"+this->name+","+std::to_string(this->income);
}

double Person::totalIncome() {
    return this->income; ////////
}

double Company::totalIncome() {
    double result= this->income+this->moneyFromInvestments;
    return result;
}

bool Company::isInterested(Dwelling d) {
    double get_total_income_company = totalIncome();
    if(d.getdw_price()/100<=get_total_income_company && d.get_isProfitable()){
        return true;
    }
    return false;
}

std::string Company::toString() {
    return "Company,"+this->name+","+std::to_string(this->income)+","+std::to_string(this->moneyFromInvestments);
}