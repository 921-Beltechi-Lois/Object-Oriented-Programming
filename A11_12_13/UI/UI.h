//
// Created by loisb on 24.03.2022.
//

#ifndef A5_6_911_BELTECHI_LOIS_UI_H
#define A5_6_911_BELTECHI_LOIS_UI_H
#pragma once
#include "Service/Service.h"
#include "Domain/Event.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bits/stringfwd.h>
#include "Validators/Validator.h"
#include "Service/UserService.h"
#include "Exceptions/UserException.h"
#include "Windows.h"

class UI {

private:
    Service& serv;
    UserService& serv_user;
    EventValidator& validator;
    int  wrong_sort_data = 0;
public:
    UI(Service &service, UserService &servUser, EventValidator& validator);
    void startUI();
    void mode_A();
    void mode_U(int chosen_repo, std::vector<Event>& filter_repo, int current_index); ///

    void print_event_list();

    static void print_menu_A();

    void add_ev_ui();

    void remove_ev_ui();

    void update_ev_ui();

    static void print_menu_U();

    void print_user_list();

    int get_wrong_sort_data() const { return this->wrong_sort_data;}
    void set_wrong_sort_data(int value){ this->wrong_sort_data = value;}

    void user_sort_database(int &chosen_repo, std::vector<Event> &filter_repo, int& current_index); ///

    void userlist_add_from_database(int current_index, int &chosen_repo, std::vector<Event>& filter_repo);

    void userlist_remove();

    void openFile();
};


#endif //A5_6_911_BELTECHI_LOIS_UI_H
