//
// Created by loisb on 06.04.2022.
//

#ifndef T1_911_BELTECHI_LOIS_1_BILL_H
#define T1_911_BELTECHI_LOIS_1_BILL_H
#include <iostream>
#include <sstream>

class Bill {
private:
    std::string name;
    int day, month, year;
    double sum;
    std::string isPaid;
public:
    Bill():name{""}, day{0}, month{0}, year{0}, sum{0.0}, isPaid{"false"}{}
    Bill(const std::string& name, int day, int month, int year, double sum, const std::string& isPaid):name{name}, day{day}, month{month}, year{year}, sum{sum}, isPaid{isPaid}{}

    std::string get_name() const {return this->name;}
    //std::string get_name() const {return this->name;}
    int get_day() const { return this->day;}
    int get_month() const{ return this->month;}
    int get_year() const { return this->year;}
    std::string get_isPaid() const{return this->isPaid;}
    void set_bill(const std::string& value) { this->isPaid=value;}
    void set_sum(double value) { this->sum=value;}
    std::string ToString();
};


#endif //T1_911_BELTECHI_LOIS_1_BILL_H
