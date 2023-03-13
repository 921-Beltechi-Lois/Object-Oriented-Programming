//
// Created by loisb on 04.05.2022.
//

#ifndef T2_911_BELTECHI_LOIS_1_UI_H
#define T2_911_BELTECHI_LOIS_1_UI_H

#include "RealEstateAgency.h"

class UI {
    RealEstateAgency& re;
public:
    explicit UI(RealEstateAgency& re): re{re}{};
    void start();
    void print_menu();
};


#endif //T2_911_BELTECHI_LOIS_1_UI_H
