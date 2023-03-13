//
// Created by loisb on 17.04.2022.
//

#ifndef A8_9_911_BELTECHI_LOIS_VALIDATORCLASS_H
#define A8_9_911_BELTECHI_LOIS_VALIDATORCLASS_H

#include "Domain/Event.h"
#include "Domain/Date.h"
#include "Domain/Time.h"
#include <vector>
#include <algorithm>

class ValidationException: public std::exception {
private:
    std::string message;
public:
    explicit ValidationException(std::string& _message);

    const char *what() const noexcept override;
};

class EventValidator {
public:
    EventValidator();

    bool validateString(const std::string& input);

    void validateTitle(const std::string& title);

    void validateDescription(const std::string& desc);

    void validateDate_Month(int month);
    void validateDate_Day(int day);
    void validateTime_hour(std::string& hour);
    void validateTime_minute(std::string& minute);

    void validatePeopleString(const std::string& no_of_people);

    void validatePeople(int no_of_people);

    void validateLink(const std::string& link);

    ~EventValidator();
};


#endif //A8_9_911_BELTECHI_LOIS_VALIDATORCLASS_H
