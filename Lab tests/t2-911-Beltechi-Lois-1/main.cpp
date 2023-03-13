//
// Created by loisb on 04.05.2022.
//

#include <iostream>

#include "UI.h"
#include "RealEstateAgency.h"
int main() {

    RealEstateAgency re{};
    Dwelling dd =re.addDwelling(20, false);

    Client* p_person=new Person{"name1", 20.0};
    Client* p_person2=new Person{"name2", 21.0};

    re.addClient(p_person);
    re.addClient(p_person2);

    Client* p_company=new Company{"name3", 20.0, 20};
    Client* p_company2=new Company{"name4", 21.0, 30};

    re.addClient(p_company);
    re.addClient(p_company2);


    UI ui{re};
    ui.start();

    return 0;
}