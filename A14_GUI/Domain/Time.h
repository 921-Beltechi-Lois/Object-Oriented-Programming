//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_TIME_H
#define A5_6_911_BELTECHI_LOIS_TIME_H

#endif //A5_6_911_BELTECHI_LOIS_TIME_H

//typedef struct{
//    int hour;
//    int minute;
//}Time;
//
//Time initialize(Time& t, int hour, int minute);
//int get_hour();
//int get_minute();
//int set_hour();
//int set_minute();

#pragma once

class Time {
private:
    int hour;
    int minute;
public:
    Time();
    Time(int hour, int minute);
    Time(const Time& copy);
    int get_hour() const { return this->hour;}
    int get_minute() const { return this->minute;}
    void set_hour(int set_hour){this->hour = set_hour;}
    void set_minute(int set_minute){this->minute = set_minute;}
};