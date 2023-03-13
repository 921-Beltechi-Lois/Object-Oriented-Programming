//
// Created by loisb on 24.03.2022.
//

#include "Repository.h"


Repository::Repository(std::string& event_filename):  eventsFilename{event_filename} {}

Repository::Repository(): eventsFilename{""} {}

void Repository::read_events_from_file() {
    if(!this->eventsFilename.empty()){
        Event eventFromFile;
        std::ifstream fin(this->eventsFilename);
        while(fin>>eventFromFile){
            if(std::find(this->events.begin(),this->events.end(), eventFromFile)==this->events.end())
                this->events.push_back(eventFromFile);
        }
        fin.close();
    }
}

void Repository::write_events_to_file() {
    if(!this->eventsFilename.empty()){
        std::ofstream fout(this->eventsFilename);
        for(const Event& event: this->events){
            fout<<event<<"\n";
        }
        fout.close();
    }
}

void Repository::addEvent_repo(const Event &e) {
    std::string title = e.getTitle();
    int pos = find_event(title);
    if (pos==-1){
        this->events.push_back(e);
        this->write_events_to_file();
        return;
    }
    std::string error;
    error += std::string("Given Event already exists!");
    if(!error.empty())
        throw RepositoryException(error);
}

void Repository::removeEvent_repo(const std::string& title) {

    int pos = find_event(title);
    if (pos!=-1){
        this->events.erase(this->events.begin() + pos);
        this->write_events_to_file();
        return;
    }
    std::string error;
    error += std::string("Given Event does not belong to the database!");
    throw RepositoryException(error);
}

void Repository::updateEvent_repo(const Event &e) {
    int pos =find_event(e.getTitle());
    if (pos!=-1){
        this->events[pos] = e;
        this->write_events_to_file();
        return;
    }
    std::string error;
    error += std::string("Given Event does not belong to the database!");
    throw RepositoryException(error);
}

int Repository::find_event(const std::string& g_title){

    int index=-1;
    std::vector<Event>::iterator it;
    it = std::find_if(this->events.begin(), this->events.end(), [&g_title](Event& e){return e.getTitle() == g_title;});
    if( it != this->events.end()){
        index = it - this->events.begin();
    }
    return index;
}

int Repository::getSize() const {
    return this->events.size();
}

std::vector<Event>& Repository:: getAllElems_Repo() {
    if (this->events.empty()) {
        std::string error;
        error += std::string("The database is empty!");
        throw RepositoryException(error);
    }
    return this->events;
}


