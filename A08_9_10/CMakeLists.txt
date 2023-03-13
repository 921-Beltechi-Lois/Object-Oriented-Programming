cmake_minimum_required(VERSION 3.21.1)
project(a8_9_911_Beltechi_Lois)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(a8_9_911_Beltechi_Lois
        StartApp/events.txt
        Test/Tests.cpp
        Test/Tests.h
        DynamicVector/DynamicVector.cpp
        DynamicVector/DynamicVector.h
        Domain/Event.cpp
        Domain/Event.h
        StartApp/main.cpp
        Repo/Repository.cpp
        Repo/Repository.h
        Service/Service.cpp
        Service/Service.h
        UI/UI.cpp
        UI/UI.h
        Domain/Date.cpp
        Domain/Date.h
        Domain/Time.cpp
        Domain/Time.h
        Validators/Validator.h
        Validators/Validator.cpp
        Exceptions/RepoException.h
        Exceptions/RepoException.cpp
        Repo/HTMLrepository.cpp Repo/HTMLrepository.h Repo/CSVrepository.cpp Repo/CSVrepository.h Exceptions/UserException.cpp Exceptions/UserException.h Repo/UserRepository.cpp Repo/UserRepository.h Service/UserService.cpp Service/UserService.h)