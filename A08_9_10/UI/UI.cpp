//
// Created by loisb on 24.03.2022.
//


#include "UI.h"

UI::UI(Service &service, UserService &servUser, EventValidator& validator) : serv{service}, serv_user(servUser), validator{validator} {
}

void UI::print_menu_A() {
    std::cout << "\n";
    std::cout << "Admin Menu: \n";
    std::cout << "   1. List all Events\n";
    std::cout << "   2. Add an Event \n";
    std::cout << "   3. Remove an Event name\n";
    std::cout << "   4. Update an Event\n";
    std::cout << "   0. Exit\n";
}

void UI::print_event_list() {
    std::cout<<"Event list\n\n";
    std::vector<Event> current_repo=serv.getAllService();

    for_each(current_repo.begin(), current_repo.end(),
             [](Event& event) { std::cout << event.ToString() <<std::endl; });
}
void UI::update_ev_ui() {
    std::cout << "Update an event ->\n";

    std::string title;

    std::cout<<"Type the name of the Event: ";
    getline(std::cin, title);
    int pos =this->serv.find_event_serv(title);

    std::vector<Event> current_repo=serv.getAllService();

    std::string desc=current_repo[pos].getDescription(), link=current_repo[pos].getLink();
    int month=current_repo[pos].getDate().get_month(), day=current_repo[pos].getDate().get_day(), hour=current_repo[pos].getTime().get_hour(),
            minute=current_repo[pos].getTime().get_minute(), no_of_people=current_repo[pos].getPeople();
    Date d1{month, day};
    Time t1{hour, minute};

    std::cout<<"What do you want to update?\n";
    std::cout<<"1. Description\n 2. Date \n 3. Time\n 4. No. of people\n 5. Link\n Your option: ";
    int option;
    std::cin>>option;
    std::cin.ignore();
    this->validator.validateString(std::to_string(option));

    if(option==1){
        while(true){
            try{
                std::cout<<"Update Description: ";
                getline(std::cin, desc);
                std::cout<<std::endl;
                this->validator.validateDescription(desc);
                break;
            }
            catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }

        }
    }
    else if(option==2){
        while(true){
            try{
                std::cout<<"Date -> Month: ";
                std::cin>>month;
                std::cout<<std::endl;
                this->validator.validateDate_Month(month);
                break;
            }catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }
        }
        while(true){
            try{
                std::cout<<"Date -> Day: ";
                std::cin>>day;
                std::cout<<std::endl;
                this->validator.validateDate_Day(day);
                break;
            }catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }
        }
        d1.set_month(month);
        d1.set_day(day);
    }
    else if(option==3){

        while(true){
            try{
                std::cout<<"Time -> Hour: ";
                std::cin>>hour;
                std::cout<<std::endl;
                std::string to_string_hour=std::to_string(hour);
                this->validator.validateTime_hour(to_string_hour);
                break;
            }catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }
        }

        while(true){
            try{
                std::cout<<"Time -> Minute: ";
                std::cin>>minute;
                std::cout<<std::endl;
                std::string to_string_minute=std::to_string(minute);///@@@@@@???
                this->validator.validateTime_minute(to_string_minute);
                break;
            }catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }
        }
        t1.set_hour(hour);
        t1.set_minute(minute);
    }
    else if(option==4){
        while(true){
            try{
                std::cout<<"No. of people: ";
                std::cin>>no_of_people;
                std::cin.ignore(); ///
                std::cout<<std::endl;
                this->validator.validatePeopleString(std::to_string(no_of_people));
                this->validator.validatePeople(no_of_people);
                break;
            }catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }
        }
    }
    else if(option==5){
        while(true){
            try{
                std::cout<<"Link: ";
                getline(std::cin, link);
                std::cout<<std::endl;
                this->validator.validateLink(link);
                break;
            }catch(ValidationException& ex){
                std::cout<<ex.what()<<std::endl;
            }
        }
    }

    this->serv.updateEvent_serv(title, desc, d1, t1, no_of_people, link);
    std::cout<<"Event has been successfully updated!\n";

}

void UI::remove_ev_ui() {
    std::cout << "Remove an event ->\n";
    std::string title;

    while(true){
        try{
            std::cout<<"Event's title: ";
            getline(std::cin,title);
            std::cout<<std::endl;
            this->validator.validateTitle(title);
            break;
        }catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }

    serv.removeEvent_serv(title);
    std::cout<<"Event has been successfully removed!\n";
}

void UI::add_ev_ui() {
    std::string title, desc, link, hour, minute, no_of_people;
    //int month, day, hour, minute, no_of_people;
    int month, day;
    std::cout<<"Add a new event ->\n";

    while(true){
        try{
            std::cout<<"Name: ";
            getline (std::cin, title);
            std::cout<<std::endl;
            this->validator.validateTitle(title);
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
    while(true){
        try{
            std::cout<<"Description: ";
            getline(std::cin, desc);
            std::cout<<std::endl;
            this->validator.validateDescription(desc);
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
    while(true){
        try{
            std::cout<<"Date -> Month: ";
            std::cin>>month;
            std::cout<<std::endl;
            this->validator.validateDate_Month(month);
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }

    while(true){
        try{
            std::cout<<"Date -> Day: ";
            std::cin>>day;
            std::cout<<std::endl;
            this->validator.validateDate_Day(day);
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }

    while(true){
        try{
            std::cout<<"Time -> Hour: ";
            std::cin>>hour;
            std::cout<<std::endl;
            this->validator.validateTime_hour(hour); ////
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
    while(true){
        try{
            std::cout<<"Time -> Minute: ";
            std::cin>>minute;
            std::cout<<std::endl;
            this->validator.validateTime_minute(minute);
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
    while(true){
        try{
            std::cout<<"No. of people: ";
            std::cin>>no_of_people;
            std::cin.ignore(); ///
            std::cout<<std::endl;
            this->validator.validatePeopleString(no_of_people);
            this->validator.validatePeople(std::stoi(no_of_people));
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
    while(true){
        try{
            std::cout<<"Link: ";
            getline(std::cin, link);
            std::cout<<std::endl;
            this->validator.validateLink(link);
            break;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }

    Date date {month, day};
    Time time {std::stoi(hour), std::stoi(minute)};

    serv.addEvent_serv(title, desc, date, time , std::stoi(no_of_people), link);
    std::cout<<"Event has been successfully added!\n";
}

void UI::mode_A() {
    while(true) {
        try {
            print_menu_A();
            int option;
            std::cout << "Your option: ";
            std::cin >> option;
            std::cout << std::endl;
            std::cin.ignore(); /// cin before getline -> error..

            if (option == 1) {
                print_event_list();
            } else if (option == 2) {
                add_ev_ui();
            } else if (option == 3) {
                remove_ev_ui();

            } else if (option == 4) {
                update_ev_ui();
            } else if (option == 0) {
                return;
            } else {
                std::cout << "wrong input!\n";
            }

        }
        catch (ValidationException &ex) {
            std::cout << ex.what() << std::endl;
        }
        catch (RepositoryException &ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}


void UI::mode_U(int chosen_repo, std::vector<Event>& filter_repo, int current_index) {

    while(true){
        try{
            print_menu_U();
            int option;
            std::cin>>option;
            std::cin.ignore();

            if (option==1)
                user_sort_database(chosen_repo, filter_repo, current_index);
            else if(option==2)
                userlist_add_from_database(current_index, chosen_repo, filter_repo);
            else if(option==3)
                userlist_remove();
            else if(option==4)
                print_user_list();
            else if (option==5)
                this->openFile();
            else if(option==0)
                return;

            else
                std::cout<<"Bad input!"<<std::endl;
        }
        catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
        catch (RepositoryException &ex) {
            std::cout << ex.what() << std::endl;
        }
    }
}

void UI::userlist_remove() {
    std::cout<<"\n";
    std::string inp;

    while(true){
        try{
            std::cout<<"Remove an event (type its name): ";
            getline(std::cin,inp);
            break;
        }catch(ValidationException& ex){
            std::cout<<ex.what()<<std::endl;
        }
    }
    serv_user.removeUserService(inp);
    std::cout<<"Event has been successfully removed from your list!\n";
    std::vector<Event> current_repo=serv.getAllService();
    int pos = serv.find_event_serv(inp);
    current_repo[pos].setPeople(current_repo[pos].getPeople()-1);
}

void UI::userlist_add_from_database(int current_index, int &chosen_repo, std::vector<Event>& filter_repo) {
    if(get_wrong_sort_data() == 0) { // data is sorted ok

        current_index = 0;
        std::string OK = "Y";
        while (strcmp(OK.c_str(), "Y") == 0) {
            std::cout << "Event that you can go to -->   ";
            if (!filter_repo.empty()) {
                if (current_index >= filter_repo.size()) {
                    current_index = 0;
                }
                std::cout<<filter_repo[current_index].ToString()<<std::endl;
            } else {
                std::vector<Event> current_repo=serv.getAllService();
                if (current_index >= serv.getSize()) {
                    current_index = 0;
                }
                std::cout<<current_repo[current_index].ToString()<<std::endl;
            }
            std::cout << "\n";
            std::string answer;
            std::cout << "Do you want to add this event to your list -> Y/N: ";
            getline(std::cin, answer);
            std::cout << std::endl;
            if (strcmp(answer.c_str(), "Y") == 0) {
                if (!filter_repo.empty() && chosen_repo == 1) {
                    serv_user.addUserService(filter_repo[current_index].getTitle(),
                                                  filter_repo[current_index].getDescription(),
                                                  filter_repo[current_index].getDate(),
                                                  filter_repo[current_index].getTime(),
                                                  filter_repo[current_index].getPeople() + 1,
                                                  filter_repo[current_index].getLink());
                } else {
                    std::vector<Event> current_repo=serv.getAllService();
                    serv_user.addUserService(current_repo[current_index].getTitle(),
                                                  current_repo[current_index].getDescription(),
                                                  current_repo[current_index].getDate(),
                                                  current_repo[current_index].getTime(),
                                                  current_repo[current_index].getPeople() + 1,
                                                  current_repo[current_index].getLink());
                    chosen_repo = 0;
                }
                std::cout << "*** Event has been successfully added to your list!\n";
                std::vector<Event> current_repo=serv.getAllService();
                current_repo[current_index].setPeople(current_repo[current_index].getPeople() + 1);
            }
            current_index++;
            std::cout << "\n" << "Do you want to continue? Y/N";
            getline(std::cin, OK);
            std::cout << "\n";
        }
    }
    else
        std::cout<< "previous database filter_sort has not been found, so choose another one in order to add it properly!\n";
}

void UI::user_sort_database(int &chosen_repo, std::vector<Event> &filter_repo, int& current_index) {

    int given_month = -1;
    std::cout<<"Input a month integer (-1 for all of them): ";
    std::cin>>given_month;
    std::cin.ignore();
    std::cout<<std::endl;

    if(!filter_repo.empty())
        filter_repo.clear();

    serv.filter_sort(filter_repo, given_month);
    if (filter_repo.empty()){
        std::cout<<"no such data found!\n";
        set_wrong_sort_data(1);
    }
    else{
        for_each(filter_repo.begin(), filter_repo.end(),
                 [](Event& event) { std::cout << event.ToString() <<std::endl; });
//        for (auto s : filter_repo)
//            cout << filter_repo.ToString() << std::endl;

        std::cout<<std::endl;

        std::cout<<"First event that will be opened in browser is:\n";
        std::cout<<filter_repo[0].ToString()<<std::endl;

//                Event e1{filter_repo[0].getTitle(),filter_repo[0].getDescription(), Date{0,0}, Time{0,0}, 10, filter_repo[0].getLink()};
//                e1.openEvent(e1);

        current_index=0;
        chosen_repo=1;
        set_wrong_sort_data(0);
    }
}

void UI::print_user_list() {
    try{
        std::cout << "My list: \n";
        std::vector<Event> user_r = serv_user.getAllUserService();
        for_each(user_r.begin(), user_r.end(),
                 [](Event& event) { std::cout << event.ToString() <<std::endl; });
    }
    catch(UserException& ex){
        std::cout<<ex.what()<<std::endl;
    }

}

void UI::print_menu_U() {
    std::cout << "\n";
    std::cout << "User Menu: \n";
    std::cout << "   1. See events for a given month ordered chronologically(if month=-1 - show all months)\n";
    std::cout << "   2. Go through the selected database & add an Event to your list \n";
    std::cout << "   3. Remove an Event Name\n";
    std::cout << "   4. Show My list Event\n";
    std::cout << "   0. Exit\n";
}

void UI::startUI() {
    int option;
    std::cout<<"1. Administrator mode"<<std::endl<<"2. User mode"<<std::endl<<"0. Exit\n"<<"Your option: ";
    std::cin>>option;
    std::cin.ignore();
    std::cout<<std::endl;
    if(option==1){
        std::cout << "Mode A has been activated...\n";
        mode_A();
    }
    else if (option==2) {
        std::cout << "Mode U has been activated...\n";

        std::cout<<"Enter the type of the file in which you want to save the user event list(csv or html):"<<std::endl;
        std::string fileType;
        while (true) {
            try {
                getline(std::cin, fileType);
                this->serv_user.repositoryType(fileType);
                break;
            }catch (RepositoryException& ex) {
                std::cout<<ex.what()<<std::endl;
            }
        }

        int chosen_repo=0, current_index=0;

        std::vector<Event> filter_repo;

        mode_U(chosen_repo, filter_repo, current_index);
    }
    else if(option ==0){
        return;
    }
    else{
        std::cout << "This mode does not exist!\n";
    }
}

void UI::openFile() {
    std::string link = std::string("start ").append(this->serv_user.getFileService());
    system(link.c_str());
}
