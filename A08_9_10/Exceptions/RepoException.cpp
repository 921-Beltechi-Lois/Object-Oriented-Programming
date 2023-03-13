//
// Created by loisb on 17.04.2022.
//

#include "RepoException.h"

RepositoryException::RepositoryException(std::string &_message) : message(_message){}

const char* RepositoryException::what() const noexcept {
    return message.c_str();
}
