//
// Created by loisb on 19.04.2022.
//

#ifndef A8_9_911_BELTECHI_LOIS_USEREXCEPTION_H
#define A8_9_911_BELTECHI_LOIS_USEREXCEPTION_H

#include <string>
#include <algorithm>

class UserException: public std::exception {
private:
    std::string message;
public:
    explicit UserException(std::string& _message);

    const char *what() const noexcept override;
};

#endif //A8_9_911_BELTECHI_LOIS_USEREXCEPTION_H
