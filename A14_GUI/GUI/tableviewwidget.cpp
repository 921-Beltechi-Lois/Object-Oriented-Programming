//
// Created by loisb on 02.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TableViewWidget.h" resolved

#include "tableviewwidget.h"
#include "ui_TableViewWidget.h"
#include "MylistTableModel.h"


TableViewWidget::TableViewWidget(UserService& user_service,QWidget *parent) :
        QWidget(parent), ui(new Ui::TableViewWidget), user_service(user_service) {
    ui->setupUi(this);
    MylistTableModel* model = new MylistTableModel(user_service);
    ui->TableVIEW->setModel(model);
    //this->ui->tableView;
}

TableViewWidget::~TableViewWidget() {

}

