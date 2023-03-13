//
// Created by loisb on 04.05.2022.
//

#ifndef T2_911_BELTECHI_LOIS_1_DWELLING_H
#define T2_911_BELTECHI_LOIS_1_DWELLING_H

#include <string>


class Dwelling {
    double price;
    bool isProfitable;
public:
    Dwelling():price{0}, isProfitable{false}{};
    Dwelling(double price, bool isProfitable):price{price}, isProfitable{isProfitable}{};
    double getdw_price() const {return this->price;}
    bool get_isProfitable() const {return this->isProfitable;}
    std::string toString(){ return "Dwelling,"+std::to_string(price)+","+std::to_string(this->isProfitable);};

};


#endif //T2_911_BELTECHI_LOIS_1_DWELLING_H
