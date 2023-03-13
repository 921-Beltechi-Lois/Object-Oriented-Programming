//
// Created by loisb on 04.05.2022.
//

#ifndef T2_911_BELTECHI_LOIS_1_REALESTATEAGENCY_H
#define T2_911_BELTECHI_LOIS_1_REALESTATEAGENCY_H


#include "Client.h"
#include "Dwelling.h"
#include <vector>
#include <fstream>
class RealEstateAgency {
    std::vector<Dwelling> dwellings;
    std::vector<Client*> clients;
public:
    Dwelling addDwelling(double price, bool isProfitable);
    std::vector<Dwelling> get_dwellings(){return this->dwellings;}
    std::vector<Client*> get_clients(){return this->clients;}

    void updateClient(const std::string& name, double income);
    void addClient(Client* c){this->clients.push_back(c);}
    std::vector<Client*> getInterestedClients(Dwelling d);

    void writeToFile(const std::string& filename);


};



#endif //T2_911_BELTECHI_LOIS_1_REALESTATEAGENCY_H
