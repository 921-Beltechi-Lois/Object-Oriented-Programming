//
// Created by loisb on 19.04.2022.
//

#include "UserService.h"

UserService::UserService(Repository& repository1, UserRepository* userRepository1): repository(repository1) {
    this->UserRepo = userRepository1;
}

UserService::UserService(Repository &repository1): repository(repository1) {}

std::vector<Event> UserService::getAllUserService() {
    if (this->UserRepo->getAllElems_Repo().empty()) {
        std::string error;
        error += std::string("The list of events is empty!");
        if (!error.empty())
            throw UserException(error);
    }
    return this->UserRepo->getAllElems_Repo();
}

void UserService::addUserService(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link) {
    Event s{ title, description, date, time, people,link };
    this->UserRepo->addEvent_user_repo(s);
}

void UserService::removeUserService(std::string &title) {
    this->UserRepo->removeEvent_user_repo(title);
}

void UserService::repositoryType(const std::string& fileType) {
    if (fileType == "csv") {
        std::vector<Event> userVector;
        std::string userFile = "StartApp/EventList.csv";
        auto * repo = new CSVRepo{ userVector,userFile};
        this->UserRepo = repo;
    }else if (fileType == "html") {
        std::vector<Event> userVector ;
        std::string userFile = "StartApp/EventList.html";
        auto * repo = new HTMLRepo{userVector,userFile};
        this->UserRepo = repo;
    } else {
        std::string error;
        error += std::string("The filename is invalid!");
        if(!error.empty())
            throw UserException(error);
    }
}


UserService::~UserService() = default;


