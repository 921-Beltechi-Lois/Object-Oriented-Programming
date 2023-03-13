//
// Created by loisb on 25.05.2022.
//

#include <QApplication>
#include "Repo.h"
#include "gui.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    Repo repo{};
    repo.ReadFromFile();
    gui GUI{repo};
    GUI.show();
    return a.exec();

}
