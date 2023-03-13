//
// Created by loisb on 11.06.2022.
//

#include "ScreenWritersRepo.h"



#include "ScreenWritersRepo.h"

void ScreenWritersRepo::LoadData() {
    ifstream inFile("screenwriters.txt");
    ScreenWriter currentElement;
    this->screenWriters.clear();
    while(inFile >> currentElement){
        this->screenWriters.push_back(currentElement);
    }
    inFile.close();
}

ScreenWritersRepo::ScreenWritersRepo() {

}

ScreenWritersRepo::~ScreenWritersRepo() {

}

vector<ScreenWriter> &ScreenWritersRepo::getScreenWriters() {
    return this->screenWriters;
}
