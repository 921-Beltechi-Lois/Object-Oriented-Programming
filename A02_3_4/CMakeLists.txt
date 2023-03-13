cmake_minimum_required(VERSION 3.21)
project(A2-3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a2-3
        Country.c
        Country.h
        CountryRepository.c
        CountryRepository.h
        main.c
        Service.c
        Service.h
        UI.c
        UI.h
        DynamicArray.h
        DynamicArray.c
        Operation.c
        Operation.h)
