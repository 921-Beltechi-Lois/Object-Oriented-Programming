//
// Created by loisb on 11.06.2022.
//

#ifndef E911_911_BELTECHI_LOIS_1_IDEASREPO_H
#define E911_911_BELTECHI_LOIS_1_IDEASREPO_H



#pragma once

#include "ScreenWriter.h"
#include "Ideas.h"
class IdeasRepo  {

private:

    vector<Idea> ideas;


public:

    IdeasRepo();
    ~IdeasRepo();
    void LoadData();
    int checkExistence(Idea i);
    vector<Idea>& getIdeas();
    void addIdea(Idea i);
    void acceptIdea(Idea& i);
    vector<Idea> getAcceptedIdeas(ScreenWriter s);
    vector<Idea> sortByActs();

    int getSize(){return this->ideas.size();}
    void clear(){this->ideas.clear();}

};



#endif //E911_911_BELTECHI_LOIS_1_IDEASREPO_H
