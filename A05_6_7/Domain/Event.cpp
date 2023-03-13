//
// Created by loisb on 24.03.2022.
//


#include "Event.h"

Event::Event(): title{""}, description{""}, date{},  time{}, no_of_people{0}, link{""}{

}

Event::Event(const std::string &title, const std::string &description, const Date &date, const Time &time,
             int no_of_people, const std::string &link):
             title{title}, description{description}, date{date}, time{time}, no_of_people{no_of_people}, link{link}{

}

std::string Event::ToString() {
    std::stringstream event;
    event<<"Title: "<<this->title<<std::setw(20)<<"Description: "
         <<this->description<<std::setw(30)<<"Date(month/day): "<<this->getDate().get_month()
         <<"/"<<this->getDate().get_day()<<std::setw(20)<<"Time: "<<this->getTime().get_hour()
         <<":"<<this->getTime().get_minute()<<std::setw(25)<<"People: "<<this->no_of_people
         <<std::setw(15)<<"Link: "<<this->link;
    return event.str();
}

//void Event::openEvent(const Event& e1) {
//
//    ShellExecuteA(NULL, NULL, "chrome.exe", e1.getLink(), NULL, SW_SHOWMAXIMIZED);
//    system("<chrome.exe> http://google.com");
//
//}

//void Event::print_event(Event& e){
//    std::cout<<"Event Title: "<<e.getTitle()<<" "<<""
//}

//Event::Event(const Event &rhs) {
//
//}
