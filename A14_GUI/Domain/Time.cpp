//
// Created by loisb on 24.03.2022.
//

#include "Time.h"
//Time initialize(Time& t, int hour, int minute){
//    t.hour=hour;
//    t.minute=minute;
//    return t;
//}
//int get_hour(){
//
//};
//int get_minute();
//int set_hour();
//int set_minute();

Time::Time(): hour{0}, minute{0} {

}

Time::Time(int hour, int minute): hour{hour}, minute{minute} {

}

Time::Time(const Time &copy) {
    this->hour = copy.hour;
    this->minute = copy.minute;
}
