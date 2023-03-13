//
// Created by loisb on 11.06.2022.
//

#include <QApplication>
#include "IdeasRepo.h"
#include "ScreenWritersRepo.h"
#include "screenwriterwindow.h"
#include "TableModel.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    ScreenWritersRepo screen_repo;
    IdeasRepo ideas_repo;
    screen_repo.LoadData();
    ideas_repo.LoadData();

    TableModel* model= new TableModel{ideas_repo}; ///!!!

    for(auto v: screen_repo.getScreenWriters()){
        ScreenWriterWindow* ww=new ScreenWriterWindow(model,ideas_repo, v);
//        ScreenWriterWindow* ww=new ScreenWriterWindow(v);
    }

    a.exec();
    return 0;
}