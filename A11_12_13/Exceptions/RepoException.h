//
// Created by loisb on 17.04.2022.
//

#ifndef A8_9_911_BELTECHI_LOIS_REPOEXCEPTION_H
#define A8_9_911_BELTECHI_LOIS_REPOEXCEPTION_H

#include <string>
#include <algorithm>

class RepositoryException: public std::exception {
private:
    std::string message;
public:
    explicit RepositoryException(std::string& _message);

    const char *what() const noexcept override;
};


#endif //A8_9_911_BELTECHI_LOIS_REPOEXCEPTION_H
