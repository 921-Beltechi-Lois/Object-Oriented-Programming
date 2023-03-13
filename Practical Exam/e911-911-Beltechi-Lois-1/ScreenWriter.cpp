//
// Created by loisb on 11.06.2022.
//

#include "ScreenWriter.h"


ScreenWriter::ScreenWriter() {

}

ScreenWriter::ScreenWriter(string name, string expertise):name{name}, expertise{expertise} {

}

ScreenWriter::~ScreenWriter() {

}

string ScreenWriter::getName() {
    return this->name;
}

string ScreenWriter::getExpertise() {
    return this->expertise;
}

istream &operator>>(istream &input, ScreenWriter &s) {
    input>>s.name>>s.expertise;
    return input;
}
