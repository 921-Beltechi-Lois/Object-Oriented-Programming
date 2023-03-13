//
// Created by loisb on 19.04.2022.
//

#ifndef A8_9_911_BELTECHI_LOIS_USERREPOSITORY_H
#define A8_9_911_BELTECHI_LOIS_USERREPOSITORY_H
#include "Domain/Event.h"
#include <algorithm>
#include "Exceptions/RepoException.h"
#include "Exceptions/UserException.h"

class UserRepository {
protected:
    std::vector<Event> UserList;
    std::string UserFilename;
public:


    explicit UserRepository(std::vector<Event>& eventList);

    UserRepository();


    virtual int getSize() const=0;

    virtual std::vector<Event>& getAllElems_Repo()=0;

    virtual std::string& get_Filename()=0;


    virtual void addEvent_user_repo(const Event& event)=0;
    virtual int find_event(const std::string& g_title)=0;

    virtual void removeEvent_user_repo(std::string& title)=0;

    virtual void write_events_to_file()=0;

    ~UserRepository();
};


#endif //A8_9_911_BELTECHI_LOIS_USERREPOSITORY_H
