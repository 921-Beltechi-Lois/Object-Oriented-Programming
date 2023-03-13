//
// Created by loisb on 25.05.2022.
//

#include "Repo.h"
#include <sstream>
#include <algorithm>
Repo::Repo() {

}

void Repo::ReadFromFile() {
    std::ifstream f("file.txt");
    std::string text;
    while (getline(f, text)) {
        std::stringstream s(text);
        int start, end, temperature, precipitation;
        std::string description;
        s >> start;
        s >> end;
        s >> temperature;
        s>> precipitation;
        s>>description;
        Weather w{start, end, temperature, precipitation, description};
        this->weather_vector.push_back(w);
    }
}

std::vector<Weather> Repo::sort() {
    std::sort(this->weather_vector.begin(), this->weather_vector.end(), [](Weather& a, Weather& b){return a.get_start()<b.get_start()
                                                                                                          || a.get_start()==b.get_start() && a.get_end()<b.get_end();});
    return this->weather_vector;
}