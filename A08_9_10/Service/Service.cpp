//
// Created by loisb on 24.03.2022.
//

#include "Service.h"

Service::Service(Repository &repository) : repo{repository}{}

void Service::addEvent_serv(const std::string& title, const std::string& description, Date date, Time time, int people, const std::string& link)
{
    Event s{ title, description, date, time, people,link };
    this->repo.addEvent_repo(s); //
   // this->UserRepo->addEvent_repo(s); // UI (serv, user_serv) -> which one is here-> using only UserRepo as abstract Class
}

void Service::removeEvent_serv(const std::string &title) {
    this->repo.removeEvent_repo(title);
}

void Service::updateEvent_serv(const std::string &title,
                               const std::string &description, Date date, Time time, int people,
                          const std::string &link) {
    Event e{ title, description, date, time, people,link };
    this->repo.updateEvent_repo(e);
}

int Service::find_event_serv(const std::string &title) {
    return this->repo.find_event(title);
}

int Service::getSize() const
{
    return this->repo.getSize();
}
// TElem
std::vector<Event>& Service::getAllService() {
    return this->repo.getAllElems_Repo();
}

void Service::filter_sort(std::vector<Event>& filter_repo, int month){
    std::vector<Event> current_repo; /// reserve;;;
    current_repo = this->repo.getAllElems_Repo();

    if(month!=-1)
        std::copy_if(current_repo.begin(), current_repo.end(), std::back_inserter(filter_repo),[&month](Event& event){return event.getDate().get_month()==month;});

    else if(month==-1)
        std::copy_if(current_repo.begin(), current_repo.end(), std::back_inserter(filter_repo),[&](Event& e){return true;});


    std::sort(filter_repo.begin(), filter_repo.end(),
              [](const Event&a, const Event& b){return ( (a.getDate().get_month() < b.getDate().get_month() ) ||
                                                         (a.getDate().get_month() == b.getDate().get_month() && a.getDate().get_day() < b.getDate().get_day() ) ||

                                                         (a.getDate().get_month() == b.getDate().get_month() && a.getDate().get_day() == b.getDate().get_day() &&
                                                          a.getTime().get_hour() <  b.getTime().get_hour() ) ||

                                                         (a.getDate().get_month() == b.getDate().get_month() && a.getDate().get_day() == b.getDate().get_day() &&
                                                          a.getTime().get_hour() ==  b.getTime().get_hour() && a.getTime().get_minute() < b.getTime().get_minute()) );});
}

//void Service::repositoryType(const std::string &fileType) {
//    if (fileType == "csv") {
//        ///std::vector<Event> userVector;
//        std::string userFile = "StartApp/EventList.csv";
//        auto * repo = new CSVRepo{ userFile};
//        //this->UserRepo = repo;
//    }else if (fileType == "html") {
//        ///std::vector<Event> userVector ;
//        std::string userFile = "StartApp/EventList.html";
//        auto * repo = new HTMLRepo{userFile};
//        //this->userRepository = repo;
//    } else {
//        std::string error;
//        error += std::string("The filename is invalid!");
//        if(!error.empty())
//            throw UserException(error);
//    }
//}
