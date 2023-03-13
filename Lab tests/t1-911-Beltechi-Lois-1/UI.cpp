//
// Created by loisb on 06.04.2022.
//

#include "UI.h"

void UI::start() {
    while(true){
        print_menu();
        int option;
        std::cout<<"option: \n";
        std::cin>>option;
        if(option==1){
            std::string name;
            int day,month,year;
            double sum;
            std::string isPaid;

            std::cout<<"input name: \n";
            std::cin>>name;
            std::cout<<"input day: \n";
            std::cin>>day;
            std::cout<<"input month: \n";
            std::cin>>month;
            std::cout<<"input year: \n";
            std::cin>>year;
            std::cout<<"input sum: \n";
            std::cin>>sum;
            std::cout<<"input isPaid: \n";
            std::cin>>isPaid;
            int val = this->serv.add_s(name,day,month, year,sum,isPaid);
            if(val==1)
                std::cout<<"added!\n";
            else
                std::cout<<"couldn't added!\n";

        }
        else if(option ==0)
            return;

        else if(option==3){
            Bill* cur_repo=this->serv.get_repo_s();
            for(int i=0;i<this->serv.get_size_s();i++){
                std::cout<<cur_repo[i].ToString()<<std::endl;
            }
        }
        else if(option==2){
            std::string name;
            std::cout<<"name of the company: \n";
            std::cin>>name;
            int day, year, month;
            std::cout<<"input day: \n";
            std::cin>>day;
            std::cout<<"input month: \n";
            std::cin>>month;
            std::cout<<"input year: \n";
            std::cin>>year;

            Bill b{name, day, month, year, 0.00, "false"};
            int pos = this->serv.find_bill_s(b);
            if(pos!=-1){
                Bill* repo = this->serv.get_repo_s();
                if (repo[pos].get_isPaid()=="true")
                    std::cout<<"This bill is already paid!\n";
                else{
                    repo[pos].set_bill("true");
                    repo[pos].set_sum(0.0);
                    std::cout<<"bill was successfully paid!\n";
                }
            }
            else{
                std::cout<<"given info does not exists!\n";
            }
        }
        else if(option == 4){
            DynamicVector<Bill> list{};
            this->serv.sort(list);
            for(int i=0;i<list.getSize();i++){
                std::cout<<list[i].ToString()<<std::endl;
            }
        }
    }
}

void UI::print_menu() {
    std::cout<<"1.add\n";
    std::cout<<"2. pay a bill\n";
    std::cout<<"3. show list\n";
    std::cout<<"4. filter & sort \n";
}
