//
// Created by loisb on 24.03.2022.
//

#include "Repository.h"

int Repository::addEvent_repo(const Event &e) {
    std::string title = e.getTitle();
    int pos = find_event(title);
    if (pos==-1){
        this->events.add(e);
        return 1;
    }
    return 0;
}
int Repository::removeEvent_repo(const std::string& title) {

    int pos = find_event(title);
    if (pos!=-1){
        this->events.remove(pos);
        return 1;
    }
    return 0;
}

int Repository::updateEvent_repo(const Event &e) {
    int pos =find_event(e.getTitle());
    if (pos!=-1){
        this->events.update(e, pos);
        return 1;
    }
    return 0;
}

int Repository::getSize() const {
    return this->events.getSize();
}

// TeLem
Event* Repository:: getAllElems_Repo() {
    return this->events.getAllElems();
}

//Event Repository::get_arr_on_pos_repo() {
//    ///return this->events.get_arr_on_pos();
//}

int Repository::find_event(const std::string& g_title){
    for(int i=0;i< this->getSize(); i++){
        std::string get_current_title = this->events.get_arr_on_pos(i).getTitle();
        if(strcmp(g_title.c_str(), get_current_title.c_str())==0){
            return i;
        }
    }
    return -1;
}


