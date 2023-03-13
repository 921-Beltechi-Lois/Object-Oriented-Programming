cmake_minimum_required(VERSION 3.21.1)
project(a11_12_911_Beltechi_Lois)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.15.1/mingw81_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Charts
        REQUIRED)


include_directories(.)

add_executable(a11_12_911_Beltechi_Lois
        Domain/Date.cpp
        Domain/Date.h
        Domain/Event.cpp
        Domain/Event.h
        Domain/Time.cpp
        Domain/Time.h
        DynamicVector/DynamicVector.cpp
        DynamicVector/DynamicVector.h
        Exceptions/RepoException.cpp
        Exceptions/RepoException.h
        Exceptions/UserException.cpp
        Exceptions/UserException.h
        Repo/CSVrepository.cpp
        Repo/CSVrepository.h
        Repo/HTMLrepository.cpp
        Repo/HTMLrepository.h
        Repo/Repository.cpp
        Repo/Repository.h
        Repo/UserRepository.cpp
        Repo/UserRepository.h
        Service/Service.cpp
        Service/Service.h
        Service/UserService.cpp
        Service/UserService.h
        StartApp/main.cpp
        Test/Tests.cpp
        Test/Tests.h
        UI/UI.cpp
        UI/UI.h
        Validators/Validator.cpp
        Validators/Validator.h GUI/GUI.cpp GUI/GUI.h GUI/qtclass.cpp GUI/qtclass.h GUI/qtclass.ui GUI/merge.cpp GUI/merge.h GUI/merge.ui)





target_link_libraries(a11_12_911_Beltechi_Lois
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Charts)

if (WIN32)
    set(DEBUG_SUFFIX)
    #    if (CMAKE_BUILD_TYPE MATCHES "Debug")
    #        set(DEBUG_SUFFIX "d")
    #    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
