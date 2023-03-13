//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_SERVICE_H
#define A5_6_911_BELTECHI_LOIS_SERVICE_H


#include "Repo/Repository.h"

class Service
{
private:
    Repository& repo;
    //Repository& user_repo;

public:
    Service(Repository &repository);

    int addEvent_serv(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link);
    int removeEvent_serv(const std::string& title);
    int updateEvent_serv(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link);
    int getSize() const;

    /// Gets the object of type Event of the current_repo
    Event* get_repo();

    /// Finds the event by the "name_title", returning its position
    int find_event_serv(const std::string& title);

    /// Sorts a filtered_repo (Dynamic Vector type) in 2 ways: By a giving month / By all months...adding from the current_repo only the months we want
    /// Then the sorting is done by Date...
    void sort(DynamicVector<Event>& filter_repo,  int month);

    ///DynamicVector& get_repo_filter();

    //Repository& get_repo_user{};

};


#endif //A5_6_911_BELTECHI_LOIS_SERVICE_H
