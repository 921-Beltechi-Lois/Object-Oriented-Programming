//
// Created by loisb on 24.03.2022.
//

#include "Service.h"

Service::Service(Repository &repository) : repo{repository} {}

int Service::addEvent_serv(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link)
{
    Event s{ title, description, date, time, people,link };
    return this->repo.addEvent_repo(s);

}

int Service::getSize() const
{
    return this->repo.getSize();
}
// TElem
Event* Service::get_repo() {
    //return Repository();
    return this->repo.getAllElems_Repo();
    //return this->repo; Repository&

}

int Service::removeEvent_serv(const std::string &title) {
    return this->repo.removeEvent_repo(title);
}

int
Service::updateEvent_serv(const std::string &title, const std::string &description, Date date, Time time, int people,
                          const std::string &link) {
    Event e{ title, description, date, time, people,link };
    return this->repo.updateEvent_repo(e);
}

int Service::find_event_serv(const std::string &title) {
    return this->repo.find_event(title);
}

void Service::sort(DynamicVector<Event>& filter_repo, int month){
    // TElem
    Event* current_repo = this->repo.getAllElems_Repo();

    if(month!=-1) {
        for (int i = 0; i < this->repo.getSize(); i++) {
            if (current_repo[i].getDate().get_month() == month)
                filter_repo.add(current_repo[i]);
        }
    }
    else if(month==-1) {
        for (int i = 0; i < this->repo.getSize(); i++) {
            filter_repo.add(current_repo[i]);
        }
    }

    int ok;
    do{
        ok=0;
        for(int i=0;i<filter_repo.getSize()-1;i++){
            if( (filter_repo[i].getDate().get_month() > filter_repo[i+1].getDate().get_month() ) ||
                    (filter_repo[i].getDate().get_month() == filter_repo[i+1].getDate().get_month() && filter_repo[i].getDate().get_day() > filter_repo[i+1].getDate().get_day() ) ||

                    (filter_repo[i].getDate().get_month() == filter_repo[i+1].getDate().get_month() && filter_repo[i].getDate().get_day() == filter_repo[i+1].getDate().get_day() &&
                    filter_repo[i].getTime().get_hour() >  filter_repo[i+1].getTime().get_hour() ) ||

                    (filter_repo[i].getDate().get_month() == filter_repo[i+1].getDate().get_month() && filter_repo[i].getDate().get_day() == filter_repo[i+1].getDate().get_day() &&
                     filter_repo[i].getTime().get_hour() ==  filter_repo[i+1].getTime().get_hour() && filter_repo[i].getTime().get_minute() > filter_repo[i+1].getTime().get_minute()) )
            {
                Event aux =filter_repo[i];
                filter_repo[i] = filter_repo[i+1];
                filter_repo[i+1]=aux;
                ok=1;
            }
        }

    }while(ok==1);

}

//DynamicVector& Service::get_repo_filter() {
//    return this->repo.get_repo_filter();
//}



