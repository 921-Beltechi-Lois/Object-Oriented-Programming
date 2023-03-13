cmake_minimum_required(VERSION 3.22)
project(a5_6_911_Beltechi_Lois)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(a5_6_911_Beltechi_Lois
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
        )