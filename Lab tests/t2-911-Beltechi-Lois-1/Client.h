//
// Created by loisb on 04.05.2022.
//

#ifndef T2_911_BELTECHI_LOIS_1_CLIENT_H
#define T2_911_BELTECHI_LOIS_1_CLIENT_H


#include <string>
#include <iostream>
#include "Dwelling.h"

class Client {
protected:
    std::string name;
    double income;

    //Dwelling& dwelling;

public:
    Client(): name{""}, income{0}{};
    Client(const std::string& name, double income): name{name}, income{income}{};

    virtual double totalIncome()=0;
    virtual std::string toString()=0; //??
    virtual bool isInterested(Dwelling d)=0;

    virtual std::string get_name()=0;
    virtual void set_income(double new_income)=0;

};

class Person: public Client {
    Person(): Client{"", 0}{};;
    bool isInterested(Dwelling d) override;
    double totalIncome() override;
    std::string toString() override;
    std::string get_name() override{return this->name;}

public:
    Person(const std::string& name, double income): Client{name, income}{}
    void set_income(double new_income) override{this->income=new_income;}
};

class Company: public Client{
    double moneyFromInvestments;
public:
    Company(): Client{"", 0}, moneyFromInvestments{0}{};
    Company(const std::string& name, double income, double moneyFromInvestments): Client{name, income}, moneyFromInvestments{moneyFromInvestments}{};
    double totalIncome() override;
    std::string toString() override;
    bool isInterested(Dwelling d) override;
    std::string get_name() override{return this->name;}

    void set_income(double new_income) override{this->income=new_income;}
};



#endif //T2_911_BELTECHI_LOIS_1_CLIENT_H
