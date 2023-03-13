//
// Created by loisb on 24.03.2022.
//


#include "UI.h"
UI::UI(Service &service, Service &servUser) : serv{service}, serv_user(servUser) {
}

void UI::print_menu_A() {
    std::cout << "\n";
    std::cout << "Admin Menu: \n";
    std::cout << "   1. List all Events\n";
    std::cout << "   2. Add an Event \n";
    std::cout << "   3. Remove an Event name\n";
    std::cout << "   4. Update an Event\n";
    std::cout << "   0. Exit\n";
    //std::cout << "   back to mode-change: mode B\n";
}

void UI::print_given_list(DynamicVector<Event>& given_repo, int size_repo) {
    for(int i =0 ;i< size_repo; i++)
        std::cout<<given_repo[i].ToString()<<std::endl;
}


void UI::print_event_list() {
    std::cout<<"Event list\n\n";
    Event* current_repo = serv.get_repo();

    int size_repo = serv.getSize();
    for(int i =0 ;i< size_repo; i++){
        std::cout<<current_repo[i].ToString()<<std::endl;
    }
}
void UI::update_ev_ui() {
    std::cout << "Update an event ->\n";

    std::string title;

    std::cout<<"Type the name of the Event: ";
    getline(std::cin, title);
    int pos =this->serv.find_event_serv(title);
    //TElem
    Event* current_repo = serv.get_repo();

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

    if(option==1){
        std::cout<<"Update Description: ";
        getline(std::cin, desc);
        std::cout<<std::endl;
    }
    else if(option==2){
        std::cout<<"Date -> Month: ";
        std::cin>>month;
        std::cout<<std::endl;

        std::cout<<"Date -> Day: ";
        std::cin>>day;
        std::cout<<std::endl;

        d1.set_month(month);
        d1.set_day(day);
    }
    else if(option==3){
        std::cout<<"Time -> Hour: ";
        std::cin>>hour;
        std::cout<<std::endl;

        std::cout<<"Time -> Minute: ";
        std::cin>>minute;
        std::cout<<std::endl;

        t1.set_hour(hour);
        t1.set_minute(minute);
    }
    else if(option==4){
        std::cout<<"No. of people: ";
        std::cin>>no_of_people;
        std::cin.ignore(); ///
        std::cout<<std::endl;
    }
    else if(option==5){
        std::cout<<"Link: ";
        getline(std::cin, link);
        std::cout<<std::endl;
    }

    int res=this->serv.updateEvent_serv(title, desc, d1, t1, no_of_people, link);
    if (res ==1)
        std::cout<<"Event has been successfully updated!\n";
    else
        std::cout<<"Given Event does not exists!\n";

}

void UI::remove_ev_ui() {
    std::cout << "Remove an event ->\n";
    std::string title;

    std::cout<<"Event's title: ";
    getline(std::cin,title);
    std::cout<<std::endl;

    int res= serv.removeEvent_serv(title);
    if (res ==1)
        std::cout<<"Event has been successfully removed!\n";
    else
        std::cout<<"Given Event does not exists!\n";
}

void UI::add_ev_ui() {
    std::string title, desc, link;
    int month, day, hour, minute, no_of_people;
    std::cout<<"Add a new event ->\n";

    std::cout<<"Name: ";
    getline (std::cin, title);
    std::cout<<std::endl;

    std::cout<<"Description: ";
    getline(std::cin, desc);
    std::cout<<std::endl;

    std::cout<<"Date -> Month: ";
    std::cin>>month;
    std::cout<<std::endl;

    std::cout<<"Date -> Day: ";
    std::cin>>day;
    std::cout<<std::endl;

    std::cout<<"Time -> Hour: ";
    std::cin>>hour;
    std::cout<<std::endl;

    std::cout<<"Time -> Minute: ";
    std::cin>>minute;
    std::cout<<std::endl;

    std::cout<<"No. of people: ";
    std::cin>>no_of_people;
    std::cin.ignore(); ///
    std::cout<<std::endl;

    std::cout<<"Link: ";
    getline(std::cin, link);
    std::cout<<std::endl;

    Date date {month, day};
    Time time {hour, minute};

    int res = serv.addEvent_serv(title, desc, date, time , no_of_people, link);
    if (res ==1)
        std::cout<<"Event has been successfully added!\n";
    else
        std::cout<<"Event already exists!\n";
}

void UI::mode_A() {
    while(true){
        print_menu_A();
        int option;
        std::cout<<"Your option: ";
        std::cin>>option;
        std::cout<<std::endl;
        std::cin.ignore(); /// cin before getline -> error..

        if (option==1){
            print_event_list();
        }
        else if(option==2){
            add_ev_ui();
        }
        else if(option == 3){
            remove_ev_ui();

        }
        else if(option ==4){
            update_ev_ui();
        }
        else if(option==0){
            return;
        }
        else{
            std::cout<<"wrong input!\n";
        }
    }
}


void UI::mode_U(int chosen_repo, DynamicVector<Event>& filter_repo, int current_index) {
    //Repository user_repo{};
    //Service user_service{user_repo};
    //user_service=this->serv; copy constr?
    while(true){
        print_menu_U();
        int option;
        std::cout<<"Choose option: ";
        std::cin>>option;
        std::cin.ignore();
        std::cout<<std::endl;

        /// Sort database by month
        if (option==1){

            user_sort_database(chosen_repo, filter_repo, current_index);

        }
            /// Parse the event list and ADD elements until user wants
        else if(option==2){
            userlist_add_from_database(current_index, chosen_repo, filter_repo);

        }
            /// Remove Event from list
        else if(option==3){
            userlist_remove();

        }
            /// Print User list
        else if(option==4) {

            print_user_list();

        }
        else if(option==0){
            return;
        }
    }

}

void UI::userlist_remove() {//print_user_list();
    std::cout<<"\n";
    std::cout<<"Remove an event (type its name): ";
    //std::cin.ignore();
    std::string inp;
    getline(std::cin,inp);

    int res = serv_user.removeEvent_serv(inp);
    if(res==1){
        std::cout<<"Event has been successfully removed from your list!\n";
        Event* current_repo = serv.get_repo();
        int pos = serv.find_event_serv(inp);
        current_repo[pos].setPeople(current_repo[pos].getPeople()-1);
    }
    else{
        std::cout<<"You don't have this event in your list!\n";
    }
}

void UI::userlist_add_from_database(int current_index, int &chosen_repo, DynamicVector<Event> &filter_repo) {
    if(get_wrong_sort_data() == 0) { // data is sorted ok

        current_index = 0;
        std::string OK = "Y";
        while (strcmp(OK.c_str(), "Y") == 0) {
            std::cout << "Event that you can go to -->   ";
            if (filter_repo.getSize() > 0) {
                if (current_index >= filter_repo.getSize()) {
                    current_index = 0;
                }
                std::cout<<filter_repo[current_index].ToString()<<std::endl;
            } else {
                Event *current_repo = serv.get_repo();
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
                int res;
                if (filter_repo.getSize() > 0 && chosen_repo == 1) {
                    res = serv_user.addEvent_serv(filter_repo[current_index].getTitle(),
                                                  filter_repo[current_index].getDescription(),
                                                  filter_repo[current_index].getDate(),
                                                  filter_repo[current_index].getTime(),
                                                  filter_repo[current_index].getPeople() + 1,
                                                  filter_repo[current_index].getLink());
                } else {
                    Event *current_repo = serv.get_repo();
                    res = serv_user.addEvent_serv(current_repo[current_index].getTitle(),
                                                  current_repo[current_index].getDescription(),
                                                  current_repo[current_index].getDate(),
                                                  current_repo[current_index].getTime(),
                                                  current_repo[current_index].getPeople() + 1,
                                                  current_repo[current_index].getLink());
                    chosen_repo = 0;
                }

                if (res == 1) {
                    std::cout << "*** Event has been successfully added to your list!\n";
                    Event *current_repo = serv.get_repo();
                    current_repo[current_index].setPeople(current_repo[current_index].getPeople() + 1);
                } else
                    std::cout << "You already have this event in your list, use option 4 to see your list!\n";

            }
            current_index++;
            std::cout << "\n" << "Do you want to continue? Y/N";
            //std::cin.ignore();
            //std::cin>>OK;
            getline(std::cin, OK);
            std::cout << "\n";
        }
    }
    else{
        std::cout<< "previous database sort has not been found, so choose another one in order to add it properly!\n";
    }
}

void UI::user_sort_database(int &chosen_repo, DynamicVector<Event> &filter_repo, int& current_index) {
    int given_month = -1;
    std::cout<<"Input a month integer (-1 for all of them): ";
    std::cin>>given_month;
    std::cin.ignore();
    std::cout<<std::endl;

    if(filter_repo.getSize()) {
        DynamicVector<Event> new_list;
        filter_repo = new_list;
    }

    serv.sort(filter_repo, given_month);
    if (filter_repo.getSize() == 0){
        std::cout<<"no such data found!\n";
        set_wrong_sort_data(1);
    }
    else{
        print_given_list(filter_repo,filter_repo.getSize());

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
    if (serv_user.getSize() > 0) {
        std::cout << "My list: \n";
        Event *user_r = serv_user.get_repo();
        print_given_list(reinterpret_cast<DynamicVector<Event> &>(user_r), serv_user.getSize());
    }
    else
        std::cout << "You have no events in your list!";
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
    std::cout<<std::endl;
    if(option==1){
        std::cout << "Mode A has been activated...\n";
        mode_A();
    }
    else if (option==2) {
        std::cout << "Mode U has been activated...\n";

        int chosen_repo=0;
        DynamicVector<Event> filter_repo; ///int
        int current_index=0;
        mode_U(chosen_repo, filter_repo, current_index);
    }
    else if(option ==0){
        return;
    }
    else{
        std::cout << "This mode does not exist!\n";
    }
}