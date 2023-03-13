//
// Created by loisb on 19.04.2022.
//

#ifndef A8_9_911_BELTECHI_LOIS_USERSERVICE_H
#define A8_9_911_BELTECHI_LOIS_USERSERVICE_H

#include "Repo/UserRepository.h"
#include "Repo/Repository.h"
#include "Repo/CSVrepository.h"
#include "Repo/HTMLrepository.h"
#include "Repo/UserRepository.h"
#include "Exceptions/UserException.h"
class UserService {
    UserRepository* UserRepo;
    Repository& repository;
public:

    UserService(Repository& repository1, UserRepository* userRepository1);
    explicit UserService(Repository& repository1);


    void addUserService(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link);
    void removeUserService(std::string& title);


    int getSizeUserService() const {return this->UserRepo->getSize();};
    std::vector<Event> getAllUserService();

    std::string& getFileService(){ return this->UserRepo->get_Filename();}

    void repositoryType(const std::string& fileType);


    ~UserService();
};


#endif //A8_9_911_BELTECHI_LOIS_USERSERVICE_H
