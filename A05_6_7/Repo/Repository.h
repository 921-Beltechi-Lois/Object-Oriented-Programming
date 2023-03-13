//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_REPOSITORY_H
#define A5_6_911_BELTECHI_LOIS_REPOSITORY_H

#include "DynamicVector/DynamicVector.h"
#include "Domain/Event.h"
#include <string>
#include <cstring>

class Repository
{
private:
    DynamicVector<Event> events;
    //int x;
    //DynamicVector user_events;

public:
    //Repository(){}
    int addEvent_repo(const Event& e);
    int removeEvent_repo(const std::string& title);
    int updateEvent_repo(const Event& e);

    ///  /// Finds the event by the "name_title", returning its position
    int find_event(const std::string& title);

    /// Size of the repo
    int getSize() const;

    /// returns the obj of the Elems that are introduced in DynamicVector
    Event* getAllElems_Repo();

//    DynamicVector& get_repo_filter() {return this->events;} ///type Dyn for '='
//    Event get_arr_on_pos_repo();
    //DynamicVector& get_repo_user() {return this->user_events;} ///



};


#endif //A5_6_911_BELTECHI_LOIS_REPOSITORY_H
