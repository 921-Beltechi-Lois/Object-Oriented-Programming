//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_REPOSITORY_H
#define A5_6_911_BELTECHI_LOIS_REPOSITORY_H

//#include "DynamicVector/DynamicVector.h"
#pragma once
#include "Domain/Event.h"
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Exceptions/RepoException.h"
class Repository
{
protected:
    std::vector<Event> events;
    std::string eventsFilename;

public:
    void read_events_from_file();
    void write_events_to_file();

    explicit Repository(std::string& event_filename);

    Repository();

    void addEvent_repo(const Event& e);
    void removeEvent_repo(const std::string& title);
    void updateEvent_repo(const Event& e);

    ///\Finds the event by the "name_title", returning its position
    int find_event(const std::string& title);

    ///\Size of the repo
    int getSize() const;

    ///\returns the obj of the Elems that are introduced in DynamicVector
    std::vector<Event>& getAllElems_Repo();


};


#endif //A5_6_911_BELTECHI_LOIS_REPOSITORY_H
