//
// Created by loisb on 19.04.2022.
//

#include "UserRepository.h"


UserRepository::UserRepository() = default;

UserRepository::UserRepository(std::vector<Event>& eventList) {
    this->UserList = eventList;
}

UserRepository::~UserRepository() = default;