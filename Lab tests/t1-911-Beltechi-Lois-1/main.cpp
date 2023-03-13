//
// Created by loisb on 06.04.2022.
//

#include <iostream>
#include "Repo.h"
#include "Service.h"
#include "UI.h"
#include <assert.h>
class Test{
public:
    static void TestAdd();
    static void TestBill();

};

void Test::TestAdd() {
    Repo r{};
    Service serv{r};
    serv.add_s("name1", 12, 12, 2020, 4.0, "false");
    serv.add_s("name2", 12, 12, 2021, 7.0, "true");
    assert(serv.get_size_s()==2);
    Bill* repo = serv.get_repo_s();
    assert(repo[0].get_name()=="name1");
    assert(repo[1].get_name()=="name2");

}

void Test::TestBill() {
    Repo r{};
    Service serv{r};
    serv.add_s("name1", 12, 12, 2020, 4.0, "false");
    serv.add_s("name2", 12, 12, 2021, 7.0, "true");
    Bill b {"name1", 12, 12, 2020, 4.0, "false"};
    int pos = serv.find_bill_s(b);
    assert(pos==0);
    Bill* repo = serv.get_repo_s();
}

int main(){
    Test t{};
    t.TestAdd();
    t.TestBill();
    Repo r{};
    Service serv{r};
    UI ui{serv};
    serv.add_s("name1", 12, 12, 2020, 4.0, "false");
    serv.add_s("name2", 12, 12, 2021, 7.0, "true");
    serv.add_s("name3", 12, 12, 2022, 10.0, "false");
    serv.add_s("name4", 12, 12, 2023, 6.0, "true");
    serv.add_s("name5", 12, 12, 2024, 4.0, "false");

    ui.start();


    return 0;
}