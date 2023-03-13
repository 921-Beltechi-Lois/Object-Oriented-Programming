//
// Created by loisb on 04.05.2022.
//

#include "UI.h"

void UI::start() {
    while(true){
        print_menu();
        int option;
        std::cin>>option;
        if(option==0)
            return;
        else if(option==1){
            std::string name;
            double new_income;
            std::cout<<"name:\n";
            std::cin>>name;
            std::cout<<"new_income:\n";
            std::cin>>new_income;
            this->re.updateClient(name, new_income);
        }
        else if(option==2){
            std::vector<Client*> vec_cle=this->re.get_clients();
            for(auto v: vec_cle){
                std::cout<<v->toString()<<"\n";
            }
            //std::cout<<"\n";
            std::vector<Dwelling> vec_dwe =this->re.get_dwellings();
            for(auto v: vec_dwe){
                std::cout<<v.toString()<<"\n";
            }
        }
        else if(option==3){
            double price;
            bool isProfitable;
            std::cout<<"price\n";
            std::cin>>price;
            std::cout<<"isProfitable 0/1:\n";
            std::cin>>isProfitable;
            std::cout<<"Interested clients are:\n";
            Dwelling d= this->re.addDwelling(price, isProfitable);
            std::vector<Client*> filter_interested_now=this->re.getInterestedClients(d);
            for(auto v: filter_interested_now){
                std::cout<<v->toString()<<"\n";
            }
        }
        else if(option==4){
            this->re.writeToFile("a.txt");
        }
    }
}

void UI::print_menu() {
    std::cout<<"1. update\n";
    std::cout<<"2. show clients & dwellings\n";
    std::cout<<"3. add a dwelling\n";
    std::cout<<"4. write to file + total income\n";

}
