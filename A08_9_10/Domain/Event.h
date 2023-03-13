//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_EVENT_H
#define A5_6_911_BELTECHI_LOIS_EVENT_H
#pragma once
#include <string>
#include "Domain/Date.h"
#include "Domain/Time.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
//#include <Windows.h>

class Event {
private:
    std::string title;
    std::string description;
    Date date;
    Time time;
    int no_of_people;
    std::string link;

public:
    Event();
    Event(const std::string& title, const std::string& description, const Date& date, const Time& time, int no_of_people, const std::string& link);
//    Event(const Event& rhs);

    std::string getTitle() const { return this->title; }
    std::string getDescription() const { return this->description; }
    Date getDate() const{ return this->date;}
    Time getTime() const {return this->time;}
    //double getDuration() const { return this->duration; }
    int getPeople() const{ return this->no_of_people;}
    std::string getLink() const { return this->link; }


//    void setTitle(const std::string& given_title) { this->title = given_title; }
//    void setDescription(const std::string& given_desc) { this->description = given_desc; }
    void setDate(const Date& given_date) { this->date = given_date; }
    void setTime(const Time& given_time) { this->time = given_time; }
    void setPeople(const int given_people) { this->no_of_people = given_people; }
//    void setLink(const std::string& given_link) { this->link = given_link; }

//    void openEvent(const Event& e1);
    std::string ToString();

    bool operator==(const Event& given_event) const;
    //static std::vector<std::string> tokenize(const std::string& str, char delimiter);
    friend std::istream& operator>>(std::istream& inputStream, Event& event);
    friend std::ostream & operator<<(std::ostream& outputStream, const Event& eventOutput);


};


#endif //A5_6_911_BELTECHI_LOIS_EVENT_H
