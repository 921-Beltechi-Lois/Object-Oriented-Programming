//
// Created by loisb on 18.04.2022.
//

#include "CSVrepository.h"

CSVRepo::CSVRepo(const std::vector<Event>& UserList, const std::string& userFilename) {
    this->UserList=UserList;
    this->UserFilename = userFilename;
}

std::vector<Event> &CSVRepo::getAllElems_Repo() {
    if (this->UserList.empty()) {
        std::string error;
        error += std::string("The user database is empty!");
        throw UserException(error);
    }
    return this->UserList;
}

void CSVRepo::addEvent_user_repo(const Event& event) {
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

void CSVRepo::removeEvent_user_repo(std::string &title) {
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

int CSVRepo::find_event(const std::string &g_title) {
    int index=-1;
    std::vector<Event>::iterator it;
    it = std::find_if(this->UserList.begin(), this->UserList.end(), [&g_title](Event& e){return e.getTitle() == g_title;});
    if( it != this->UserList.end()){
        index = it - this->UserList.begin();
    }
    return index;
}

void CSVRepo::write_events_to_file() {
    std::ofstream fout(this->UserFilename);
    if (!this->UserList.empty()) {
        for (const Event& event: this->UserList) {
            fout<<event<<"\n";
        }
    }
    fout.close();
}

CSVRepo::~CSVRepo()=default;



