//
// Created by loisb on 06.04.2022.
//

#ifndef T1_911_BELTECHI_LOIS_1_UI_H
#define T1_911_BELTECHI_LOIS_1_UI_H

#include "Service.h"
#include "Bill.h"
class UI {
    Service& serv;
public:
    UI(Service& serv): serv{serv}{}
    void start();
    void print_menu();
};


#endif //T1_911_BELTECHI_LOIS_1_UI_H
