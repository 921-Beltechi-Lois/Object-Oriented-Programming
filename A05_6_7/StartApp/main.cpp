//
// Created by loisb on 24.03.2022.
//
#include "Domain/Event.h"
#include "Repo/Repository.h"
#include "Service/Service.h"
#include "UI/UI.h"

#include <assert.h>
#include "DynamicVector/DynamicVector.h"
class Test{
public:
    static void testAll();
    static void test_Event_Date_Time();
    static void test_Dynamic_Vector();
    static void test_Repository();
    static void test_Service();

};

void Test::test_Event_Date_Time() {
    Date d{12,12};
    Time t{12, 12};
    Event e{"title","hey", d, t, 12, "https://idk.ro"};
    assert(e.getTitle() == "title");
    assert(e.getDescription() == "hey");
    assert(e.getLink() == "https://idk.ro");

    assert(e.getDate().get_month()==12);
    assert(e.getDate().get_day()==12);
    assert(e.getTime().get_hour() == 12);
    assert(e.getTime().get_minute() == 12);

    assert(e.getPeople()==12);
    assert(e.getLink()=="https://idk.ro");

    e.setPeople(13);
    assert(e.getPeople()==13);

    t.set_hour(17);
    assert(t.get_hour()==17);
    t.set_minute(20);
    assert(t.get_minute()==20);

    d.set_month(10);
    assert(d.get_month()==10);
    d.set_day(21);
    assert(d.get_day()==21);


}

void Test::test_Repository() {
    Repository repo{};
    Date d{12,12};
    Time t{12, 12};
    Event e{"title","hey", d, t, 12, "https://idk.ro"};
    repo.addEvent_repo(e);
    int res =repo.addEvent_repo(e);
    assert(res==0);
    res =repo.find_event(e.getTitle());
    assert(res==0);
    res =repo.find_event("asd");
    assert(res==-1);
    assert(repo.getSize()==1);
    //assert(repo.getAllElems_Repo());

    Event* get_all_ev = repo.getAllElems_Repo();
    Event e_update{"title","DA", d, t, 12, "https://idk.ro"};
    repo.updateEvent_repo(e_update);
    assert(e_update.getDescription()=="DA");
    Event e_no_existing_name_for_upd{"idk","DA", d, t, 12, "https://idk.ro"};
    res = repo.updateEvent_repo(e_no_existing_name_for_upd);
    assert(res==0);
    repo.removeEvent_repo(e_update.getTitle());

    assert(repo.getSize()==0);

    res =repo.removeEvent_repo("not_existing_name");
    assert(res==0);
}

void Test::test_Service() {
    Repository repo{};
    Service s{repo};
    s.addEvent_serv("title", "desc", Date{1,1}, Time{12, 12}, 20, "https://idk.ro");
    assert(s.getSize()==1);


    s.updateEvent_serv("title", "change_desc", Date{1,1}, Time{12, 12}, 20, "https://idk.ro");
    int pos=s.find_event_serv("title");
    Event* get_event = s.get_repo();
    assert(get_event->getDescription()=="change_desc");

    s.removeEvent_serv("title");
    s.removeEvent_serv("no_existing");
    assert(s.getSize()==0);
    DynamicVector<Event> filter_repo;

    s.addEvent_serv("first Ev", "desc1", Date{12,15}, Time{12, 12}, 103, "https://tinyurl.com/2p85hxt7");
    s.addEvent_serv("tenth Ev", "desc@", Date{12, 13}, Time{19, 21}, 111, "https://tinyurl.com/4srv5e99");
    s.sort(filter_repo, 12);
    assert(filter_repo.get_arr_on_pos(0).getTitle()=="tenth Ev");
    assert(filter_repo.get_arr_on_pos(1).getTitle()=="first Ev");

    DynamicVector<Event> filter_repo2;
    s.sort(filter_repo2, -1);
    assert(filter_repo2.get_arr_on_pos(0).getTitle()=="tenth Ev");
    assert(filter_repo2.get_arr_on_pos(1).getTitle()=="first Ev");

}

void Test::test_Dynamic_Vector() {
    DynamicVector<int> v1{ 2 };
    DynamicVector<int> v22{ 2 };

    v1=v1; // in case in '=' op it has the same adress
    assert(v1.getSize()== v1.getSize());

    v1.add(10);
    v1.add(20);
    assert(v1.getSize() == 2);
    assert(v1[1] == 20);
    v1[1] = 25;
    assert(v1[1] == 25);
    v1.add(30);
    assert(v1.getSize() == 3);

    DynamicVector<int> v2{ v1 };
    assert(v2.getSize() == 3);

    DynamicVector<int> v3;
    v3 = v1;
    assert(v3[0] == 10);

    DynamicVector<int> v33{0};
    v33.add(40);
    v33.add(50);
    v33.add(60);
    v33.add(70);
    v33.add(80);
    v33.add(90);
    v33.add(100);
    v33.add(200);
    v33.add(300);
    v33.add(400);
    assert(v33.getSize()==10);

    v33.update(999, 0);
    assert(v33.get_arr_on_pos(0)==999);
//    // test iterator
//    DynamicVector<int>::iterator it = v1.begin();
//    assert(*it == 10);
//    assert(it != v1.end());
//    it++;
//    assert(*it == 25);
//
//    int i = 0;
//    for (auto x : v1)
//        i++;
//    assert(i == 3);
}

void Test::testAll() {
    test_Event_Date_Time();
    test_Repository();
    test_Service();
    test_Dynamic_Vector();
}


using namespace std;
    int main(){
        Test::testAll();

        Date d1{12, 2};
        Time t1{17, 10};

        Date d2{11, 3};
        Time t2{19, 10};

        Date d3{12, 2};
        Time t3{16, 10};

        Date d4{10, 3};
        Time t4{12, 10};

        Date d5{6, 2};
        Time t5{21, 10};

        Date d6{7, 28};
        Time t6{19, 10};

        Date d7{5, 29};
        Time t7{13, 21};

        Date d8{2, 19};
        Time t8{11, 10};

        Date d9{01, 1};
        Time t9{12, 59};

        Date d10{12, 30};
        Time t10{16, 40};

        Repository repo{};

        Service s{repo};
        Repository user_repo{};
        Service s_user{user_repo};



        s.addEvent_serv("first Ev", "desc1", d1, t1, 103, "https://tinyurl.com/2p85hxt7");
        s.addEvent_serv("second Ev", "desc2", d2, t2, 303, "https://tinyurl.com/mr4cebxy");
        s.addEvent_serv("third Ev", "desc3", d3, t3, 233, "https://tinyurl.com/znates9a");
        s.addEvent_serv("fourth Ev", "desc4", d4, t4, 115, "https://tinyurl.com/4ur9t9a9");
        s.addEvent_serv("fifth Ev", "desc5", d5, t5, 100, "https://tinyurl.com/2p8hpzsh");
        s.addEvent_serv("sixth Ev", "desc6", d6, t6, 117, "https://tinyurl.com/2yxfsaaj");
        s.addEvent_serv("seventh Ev", "desc7", d7, t7, 900, "https://tinyurl.com/4yhfxnxf");
        s.addEvent_serv("eight Ev", "desc8", d8, t8, 800, "https://tinyurl.com/2p9da497");
        s.addEvent_serv("ninth Ev", "desc9", d9, t9, 260, "https://tinyurl.com/2ntspku5");
        s.addEvent_serv("tenth Ev", "desc@", d10, t10, 111, "https://tinyurl.com/4srv5e99");

        UI ui{s, s_user};
        ui.startUI();
        return 0;
}