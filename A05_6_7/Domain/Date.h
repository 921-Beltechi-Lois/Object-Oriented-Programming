//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_DATE_H
#define A5_6_911_BELTECHI_LOIS_DATE_H

#pragma once
class Date {
private:
    //int year;
    int month;
    int day;
public:
    Date();
    Date(int month, int day);
    Date(const Date& copy);
    //int get_year() const { return this->year;}
    int get_month() const { return this->month;}
    int get_day() const { return this->day;}
    //void set_year(int set_year){this->year = set_year;}
    void set_month(int set_month){this->month = set_month;}
    void set_day(int set_day){this->day = set_day;}
};


#endif //A5_6_911_BELTECHI_LOIS_DATE_H
