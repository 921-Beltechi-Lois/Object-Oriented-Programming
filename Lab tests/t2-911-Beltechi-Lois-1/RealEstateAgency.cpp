//
// Created by loisb on 04.05.2022.
//

#include "RealEstateAgency.h"


Dwelling RealEstateAgency::addDwelling(double price, bool isProfitable) {
    Dwelling d{price, isProfitable};
    this->dwellings.push_back(d);
    return d;
}

void RealEstateAgency::updateClient(const std::string& name, double income) {
    int index=0;
    for(auto v:this->clients){
        if(v->get_name()==name){
            break;
        }
        index++;
    }

    this->clients[index]->set_income(income);
}

std::vector<Client *> RealEstateAgency::getInterestedClients(Dwelling d) {
    std::vector<Client *> filter;
    for(auto v:this->clients) {
        if(v->isInterested(d)){
            filter.push_back(v);
        }
    }
    return filter;
}

void RealEstateAgency::writeToFile(const std::string &filename) {
    std::ofstream fout{filename};

    for(auto v: this->clients){
        fout<<v->toString()<<","<<"total income:"<<v->totalIncome()<<"\n";
    }
}



