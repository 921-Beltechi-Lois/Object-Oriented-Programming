//
// Created by loisb on 02.06.2022.
//

#ifndef A14_911_BELTECHI_LOIS_TABLEVIEWWIDGET_H
#define A14_911_BELTECHI_LOIS_TABLEVIEWWIDGET_H

#include <QWidget>
#include "ui_TableViewWidget.h"
#include "Service/UserService.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TableViewWidget; }
QT_END_NAMESPACE

class TableViewWidget : public QWidget {
Q_OBJECT

public:
    explicit TableViewWidget(UserService& user_service, QWidget *parent = nullptr);

    ~TableViewWidget() override;

public:
    Ui::TableViewWidget *ui;
    UserService& user_service;
    //add()
};


#endif //A14_911_BELTECHI_LOIS_TABLEVIEWWIDGET_H
