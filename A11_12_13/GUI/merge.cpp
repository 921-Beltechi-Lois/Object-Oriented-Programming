//
// Created by loisb on 22.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_merge.h" resolved

#include "merge.h"
#include "ui_merge.h"


merge::merge(QWidget *parent) :
        QWidget(parent), ui(new Ui::merge) {
    ui->setupUi(this);
}

merge::~merge() {
    delete ui;
}

