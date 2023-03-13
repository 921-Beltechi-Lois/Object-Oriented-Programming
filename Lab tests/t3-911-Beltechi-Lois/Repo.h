//
// Created by loisb on 25.05.2022.
//

#ifndef T3_911_BELTECHI_LOIS_REPO_H
#define T3_911_BELTECHI_LOIS_REPO_H

#include "Weather.h"
#include <vector>
#include <fstream>
class Repo {
    std::vector<Weather> weather_vector;
public:
    Repo();
    void ReadFromFile();
    std::vector<Weather> getAll(){return this->weather_vector;};
    std::vector<Weather> sort();
};



#endif //T3_911_BELTECHI_LOIS_REPO_H
