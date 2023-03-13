//
// Created by loisb on 17.04.2022.
//

#include "Validator.h"

ValidationException::ValidationException(std::string &_message): message(_message) {}

const char* ValidationException::what() const noexcept {
    return message.c_str();
}


EventValidator::EventValidator() = default;

bool EventValidator::validateString(const std::string& input) {
    for (char i : input)
        if (isdigit(i) != false)
            return false;
    return true;
}

void EventValidator::validateTitle(const std::string& title) {
    std::string errors;
    if (!validateString(title))
        errors += std::string("The title input contains digits!");
    if (title.length() == 0)
        errors += std::string("The title input is empty!");
    if (!isupper(title[0]))
        errors += std::string("The title should start with a capital letter!");
    if (!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateDescription(const std::string &desc) {
    std::string errors;
    if (desc.length() == 0)
        errors += std::string("The description input is empty!");
    else if (desc.length() < 3)
        errors += std::string("The description size must be >=3!");
    if (!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateDate_Month(int month) {
    std::string errors;
    if (month<1 || month>12)
        errors += std::string("Provided month should be between 1-12!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateDate_Day(int day) {
    std::string errors;
    if (day<1 || day>31)
        errors += std::string("Provided day should be between 1-31!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateTime_hour(std::string& hour) {
    std::string errors;
    int hour_int;
    hour_int= std::stoi(hour);
    if (hour.length()!=2)
        errors += std::string("Provided hour should have 2 digits!");
    else if(hour_int>23)
        errors+=std::string("Provided hour should be between 00-23");

    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateTime_minute(std::string& minute) {
    std::string errors;
    int minute_int;
    minute_int= std::stoi(minute);
    if (minute.length()!=2)
        errors += std::string("Provided minute should have 2 digits!");
    else if(minute_int>59)
        errors+=std::string("Provided minute should be between 00-59!");

    if(!errors.empty())
        throw ValidationException(errors);
}


void EventValidator::validatePeopleString(const std::string& no_of_people) {
    std::string errors;
    if (no_of_people.empty())
        errors += std::string("The no_of_people input is empty!");
    if (no_of_people.find_first_not_of("0123456789") != std::string::npos)
        errors += std::string("The no_of_people input has non-digit characters!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validatePeople(int no_of_people) {
    std::string errors;
    if (no_of_people<0)
        errors += std::string("no_of_people cannot be smaller than 0!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validateLink(const std::string& link) {
    std::string errors;
    if (link.length() == 0)
        errors += std::string("The link input is empty!");
    if (link.find("www") == std::string::npos)
        errors += std::string("The link is not a valid one!");
    if(!errors.empty())
        throw ValidationException(errors);
}

EventValidator::~EventValidator()=default;