//
// Created by loisb on 24.03.2022.
//
#include "Domain/Event.h"
#include "Repo/Repository.h"
#include "Service/UserService.h"
#include "Service/Service.h"
#include "UI/UI.h"

#include "Test/Tests.h"
#include "Validators/Validator.h"


using namespace std;
    int main(){

//        Date d1{12, 2};
//        Time t1{17, 10};
//
//        Date d2{11, 3};
//        Time t2{19, 10};
//
//        Date d3{12, 2};
//        Time t3{16, 10};
//
//        Date d4{10, 3};
//        Time t4{12, 10};
//
//        Date d5{6, 2};
//        Time t5{21, 10};
//
//        Date d6{7, 28};
//        Time t6{19, 10};
//
//        Date d7{5, 29};
//        Time t7{13, 21};
//
//        Date d8{2, 19};
//        Time t8{11, 10};
//
//        Date d9{01, 1};
//        Time t9{12, 59};
//
//        Date d10{12, 30};
//        Time t10{16, 40};

        Test::testAll();
        ///\Admin
        //std::string filename=R"(C:\Users\loisb\Documents\CLion_Projects\a8-9-911-Beltechi-Lois\StartApp\events.txt)";
        std::string filename="StartApp/events.txt";
        Repository repo{filename};
        repo.read_events_from_file();
        Service s{repo};

        ///\User
        //std::string user_filename="StartApp/userevents.txt";
        //Repository user_repo{user_filename};
        //Service s_user{user_repo};
        UserService s_user{repo};


//        s.addEvent_serv("first Ev", "desc1", d1, t1, 103, "https://tinyurl.com/2p85hxt7");
//        s.addEvent_serv("second Ev", "desc2", d2, t2, 303, "https://tinyurl.com/mr4cebxy");
//        s.addEvent_serv("third Ev", "desc3", d3, t3, 233, "https://tinyurl.com/znates9a");
//        s.addEvent_serv("fourth Ev", "desc4", d4, t4, 115, "https://tinyurl.com/4ur9t9a9");
//        s.addEvent_serv("fifth Ev", "desc5", d5, t5, 100, "https://tinyurl.com/2p8hpzsh");
//        s.addEvent_serv("sixth Ev", "desc6", d6, t6, 117, "https://tinyurl.com/2yxfsaaj");
//        s.addEvent_serv("seventh Ev", "desc7", d7, t7, 900, "https://tinyurl.com/4yhfxnxf");
//        s.addEvent_serv("eight Ev", "desc8", d8, t8, 800, "https://tinyurl.com/2p9da497");
//        s.addEvent_serv("ninth Ev", "desc9", d9, t9, 260, "https://tinyurl.com/2ntspku5");
//        s.addEvent_serv("Tenth Ev", "desc@", d10, t10, 111, "https://tinyurl.com/4srv5e99");
//
//        repo.write_events_to_file();

/// here the initialization with html/csv
//// user_service {csv_repo, or html_repo}

        EventValidator validator{};
        UI ui{s, s_user, validator};
        ui.startUI();
        return 0;
}