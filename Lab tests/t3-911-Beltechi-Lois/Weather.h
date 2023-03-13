//
// Created by loisb on 25.05.2022.
//

#ifndef T3_911_BELTECHI_LOIS_WEATHER_H
#define T3_911_BELTECHI_LOIS_WEATHER_H


#include <string>

class Weather {
    int hour_start;
    int hour_end;
    int temperature;
    int precipitation;
    std::string description;

public:
    Weather():hour_start{0}, hour_end{0}, temperature{0}, precipitation{0}, description{""}{};
    Weather(int start, int end, int temperature, int precipitation, std::string description):hour_start{start}, hour_end{end}, temperature{temperature}, precipitation{precipitation}, description{description}{};

    int get_start(){return this->hour_start;};
    int get_end(){return this->hour_end;};
    int get_temperature(){return this->temperature;};
    int get_precipitation(){return this->precipitation;};
    std::string get_description(){return this->description;};

    std::string to_string(){return std::to_string(this->hour_start)+","+std::to_string(this->hour_end)+","+std::to_string(this->temperature)+","+std::to_string(this->precipitation)+","+this->description;};



};


#endif //T3_911_BELTECHI_LOIS_WEATHER_H
