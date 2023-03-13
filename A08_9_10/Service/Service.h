//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_SERVICE_H
#define A5_6_911_BELTECHI_LOIS_SERVICE_H

#pragma once
#include "Repo/Repository.h"
#include "Repo/CSVrepository.h"
#include "Repo/HTMLrepository.h"
#include "Repo/UserRepository.h"
#include "Exceptions/UserException.h"

class Service
{
private:
    Repository& repo;
    //Repository& user_repo;

public:
    explicit Service(Repository &repository);

    void addEvent_serv(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link);
    void removeEvent_serv(const std::string& title);
    void updateEvent_serv(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link);
    int getSize() const;

    /// Gets the object of type Event of the current_repo
    std::vector<Event>& getAllService();
    //Event* getAllService();

    /// Finds the event by the "name_title", returning its position
    int find_event_serv(const std::string& title);

    /// Sorts a filtered_repo (Dynamic Vector type) in 2 ways: By a giving month / By all months...adding from the current_repo only the months we want
    /// Then the sorting is done by Date...
    void filter_sort(std::vector<Event>& filter_repo, int month);


//    std::string& get_Filename_serv(){return this->repo.get_Filename();}
//    void repositoryType(const std::string& fileType);

};


#endif //A5_6_911_BELTECHI_LOIS_SERVICE_H
