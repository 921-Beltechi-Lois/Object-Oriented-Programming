cmake_minimum_required(VERSION 3.21.1)
project(t2_911_Beltechi_Lois_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t2_911_Beltechi_Lois_1
        Dwelling.cpp
        Dwelling.h UI.cpp UI.h main.cpp Client.cpp Client.h RealEstateAgency.h RealEstateAgency.cpp)
