//
// Created by loisb on 19.04.2022.
//

#include "UserException.h"

UserException::UserException(std::string &_message) : message(_message){}

const char* UserException::what() const noexcept {
    return message.c_str();
}