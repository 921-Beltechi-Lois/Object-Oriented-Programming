//
// Created by loisb on 11.06.2022.
//

#ifndef E911_911_BELTECHI_LOIS_1_SCREENWRITER_H
#define E911_911_BELTECHI_LOIS_1_SCREENWRITER_H



#pragma once
#include <vector>
#include <string>
using namespace std;
#include <fstream>
#include <sstream>


class ScreenWriter {

private:
    string name;
    string expertise;

public:
    ScreenWriter();
    ScreenWriter(string name, string expertise);
    ~ScreenWriter();

    string getExpertise();
    string getName();



    friend istream& operator>>(istream&, ScreenWriter&);

};



#endif //E911_911_BELTECHI_LOIS_1_SCREENWRITER_H
