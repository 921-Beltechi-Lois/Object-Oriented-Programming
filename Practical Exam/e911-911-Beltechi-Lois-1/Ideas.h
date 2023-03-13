//
// Created by loisb on 11.06.2022.
//

#ifndef E911_911_BELTECHI_LOIS_1_IDEAS_H
#define E911_911_BELTECHI_LOIS_1_IDEAS_H

#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include <sstream>

class Idea {

private:
    string description;
    string status;
    string creator;
    string act;

public:

    Idea();
    Idea(string description, string status, string creator, string act);
    ~Idea();

    string getDescription();
    string getStatus();
    string getCreator();
    string getAct();

    void setStatus(string status);

    static vector<string> tokenize(string str, char delimiter);
    friend ostream& operator<<(ostream&, const Idea&);

    friend istream& operator>>(istream&, Idea&);



};

#endif //E911_911_BELTECHI_LOIS_1_IDEAS_H
