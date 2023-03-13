//
// Created by loisb on 11.06.2022.
//

#ifndef E911_911_BELTECHI_LOIS_1_SCREENWRITERSREPO_H
#define E911_911_BELTECHI_LOIS_1_SCREENWRITERSREPO_H


#pragma once
#include "ScreenWriter.h"

class ScreenWritersRepo {

private:
    vector<ScreenWriter> screenWriters;


public:
    void LoadData();
    ScreenWritersRepo();
    ~ScreenWritersRepo();
    vector<ScreenWriter>& getScreenWriters();

};



#endif //E911_911_BELTECHI_LOIS_1_SCREENWRITERSREPO_H
