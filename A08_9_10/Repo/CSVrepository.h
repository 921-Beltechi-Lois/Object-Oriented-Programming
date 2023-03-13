//
// Created by loisb on 18.04.2022.
//

#ifndef A8_9_911_BELTECHI_LOIS_CSVREPOSITORY_H
#define A8_9_911_BELTECHI_LOIS_CSVREPOSITORY_H

#include "UserRepository.h"

class CSVRepo: public UserRepository {
public:

    CSVRepo(const std::vector<Event>& UserList, const std::string& userFilename);

    int getSize() const override {return this->UserList.size();}

    std::vector<Event>& getAllElems_Repo() override;

    std::string& get_Filename() override{return this->UserFilename;}

    void addEvent_user_repo(const Event& event) override;
    int find_event(const std::string &g_title) override;

    void removeEvent_user_repo(std::string& title) override;

    void write_events_to_file() override;


    ~CSVRepo();
};



#endif //A8_9_911_BELTECHI_LOIS_CSVREPOSITORY_H
