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
//    std::stringstream event;
//    event<<"Title: "<<this->title<<std::setw(20)<<"Description: "
//                                 <<this->description<<std::setw(30)<<"Date(month/day): "<<this->getDate().get_month()
//                                 <<"/"<<this->getDate().get_day()<<std::setw(20)<<"Time: "<<this->getTime().get_hour()
//                                 <<":"<<this->getTime().get_minute()<<std::setw(25)<<"People: "<<this->no_of_people
//                                 <<std::setw(15)<<"Link: "<<this->link;
//    return event.str();
    return this->title+","+this->description+","+std::to_string(this->getDate().get_month())+"/"+std::to_string(this->getDate().get_day())+","+
    std::to_string(this->getTime().get_hour())+":"+std::to_string(this->getTime().get_minute())+","+std::to_string(this->no_of_people)+","+
    this->link;
}


std::vector<std::string> tokenize(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}

std::istream &operator>>(std::istream &inputStream, Event &event) {
    std::string line;
    std::getline(inputStream, line);
    std::vector<std::string> tokens;
    if(line.empty())
        return inputStream;
    tokens=tokenize(line, ',');
    event.title=tokens[0];
    event.description=tokens[1];
    //event.date= static_cast<const Date>(transforma);


    Date date=event.getDate();
    date.set_month(std::stoi(tokens[2]));
    date.set_day(std::stoi(tokens[3]));
    event.setDate(date);

    Time time=event.getTime();
    time.set_hour((std::stoi(tokens[4])));
    time.set_minute((std::stoi(tokens[5])));
    event.setTime(time);

//    event.getDate().set_day(std::stoi(tokens[3]));
//    event.getTime().set_hour(std::stoi(tokens[4])); ??????
//    event.getTime().set_minute(std::stoi(tokens[5]));

    event.setPeople(std::stoi(tokens[6]));
    event.link=tokens[7];
    return inputStream;
}

std::ostream &operator<<(std::ostream& outputStream, const Event& eventOutput) {
    outputStream<<eventOutput.title<<","<<eventOutput.description<<","<<eventOutput.getDate().get_month()<<","<<
    eventOutput.getDate().get_day()<<","<<eventOutput.getTime().get_hour()<<","<<eventOutput.getTime().get_minute()<<","
    <<eventOutput.no_of_people<<","<<eventOutput.link;
    return outputStream;
}

bool Event::operator==(const Event &given_event) const {
    return this->title==given_event.title;
}


//void Event::openEvent(const Event& e1) {
//
//    ShellExecuteA(NULL, NULL, "chrome.exe", e1.getLink(), NULL, SW_SHOWMAXIMIZED);
//    system("<chrome.exe> http://google.com");
//
//}