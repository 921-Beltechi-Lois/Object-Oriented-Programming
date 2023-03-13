//
// Created by loisb on 25.05.2022.
//

#ifndef T3_911_BELTECHI_LOIS_GUI_H
#define T3_911_BELTECHI_LOIS_GUI_H

#include <QWidget>
#include "Repo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gui; }
QT_END_NAMESPACE

class gui : public QWidget {
Q_OBJECT

public:
    explicit gui(Repo& repo, QWidget *parent = nullptr);

    ~gui() override;
    void populateList();

private:
    Repo& repo;
    Ui::gui *ui;
};


#endif //T3_911_BELTECHI_LOIS_GUI_H
