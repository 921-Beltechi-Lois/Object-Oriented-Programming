//
// Created by loisb on 18.04.2022.
//

#include "HTMLrepository.h"

HTMLRepo::HTMLRepo(const std::vector<Event>& UserList,const std::string& userFilename){
    this->UserList=UserList;
    this->UserFilename=userFilename;
}

std::vector<Event> &HTMLRepo::getAllElems_Repo() {
    if (this->UserList.empty()) {
        std::string error;
        error += std::string("The user database is empty!");
        throw UserException(error);
    }
    return this->UserList;
}

void HTMLRepo::addEvent_user_repo(const Event& event) {
    int pos=this->find_event(event.getTitle());
    if(pos==-1){
        this->UserList.push_back(event);
        this->write_events_to_file();
    }
    else{
        std::string error;
        error += std::string("Given Event already exists in your list!");
        throw RepositoryException(error);
    }
}

int HTMLRepo::find_event(const std::string &g_title) {
    int index=-1;
    std::vector<Event>::iterator it;
    it = std::find_if(this->UserList.begin(), this->UserList.end(), [&g_title](Event& e){return e.getTitle() == g_title;});
    if( it != this->UserList.end()){
        index = it - this->UserList.begin();
    }
    return index;
}

void HTMLRepo::removeEvent_user_repo(std::string &title) {
    int pos = find_event(title);
    if (pos!=-1){
        this->UserList.erase(this->UserList.begin() + pos);
        this->write_events_to_file();
        return;
    }
    std::string error;
    error += std::string("Given Event does not belong to the database!");
    throw RepositoryException(error);
}

void HTMLRepo::write_events_to_file() {
    std::ofstream fout(this->UserFilename);
    fout << "<!DOCTYPE html>\n<html><head><title>Event List</title></head><body>\n";
    fout << "<table border=\"1\">\n";
    fout << "<tr><td>Title</td><td>Description</td><td>Date</td><td>Time</td><td>People</td><td>Link</td></tr>\n";
    for (const Event& event: this->UserList) {
        std::string month=std::to_string(event.getDate().get_month());
        std::string day=std::to_string(event.getDate().get_day());
        std::string date=month+"/"+day;

        std::string hour=std::to_string(event.getTime().get_hour());
        std::string minute=std::to_string(event.getTime().get_minute());
        std::string time=hour+":"+minute;

        fout << "<tr><td>" << event.getTitle() << "</td>"
             << "<td>" << event.getDescription() << "</td>"
             << "<td>" << date << "</td>"<< "<td>" << time << "</td>"<< "<td>" << event.getPeople() << "</td>"
             << "<td><a href=\"" << event.getLink() << "\">"<<event.getLink()<<"</a></td>" << '\n';
    }
    fout << "</table></body></html>";
    fout.close();
}


HTMLRepo::~HTMLRepo()=default;



