//
// Created by loisb on 25.05.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui.h" resolved

#include <QMessageBox>
#include "gui.h"
#include "ui_gui.h"


gui::gui(Repo& repo, QWidget *parent) :
        QWidget(parent), ui(new Ui::gui), repo(repo) {
    ui->setupUi(this);
    this->populateList();

    QObject::connect(this->ui->FilterlineEdit, &QLineEdit::textChanged, [this](){
        this->ui->listWidget->clear();

        std::string given_temp_value=this->ui->FilterlineEdit->text().toStdString();

        if(given_temp_value.empty()){
            this->populateList();
            return;
        }

        for(auto&v: this->repo.getAll()){
            if(v.get_temperature()>std::stoi(given_temp_value)){
                this->ui->listWidget->addItem(QString::fromStdString(v.to_string()));
            }
        }
    });

    QObject::connect(this->ui->CalcpushButton, &QPushButton::clicked, [this](){
        this->ui->ShowlineEdit->clear();

        std::string description=this->ui->DesclineEdit->text().toStdString();
        int temperature=this->ui->TemplineEdit->text().toInt();
        int precip=this->ui->PreciplineEdit->text().toInt();

        // given weather, temp > 20 (given_value), precip<30 (given_value)
        int hours=0;
        for(auto&v: this->repo.getAll()){
            if(v.get_description()==description && v.get_temperature()>temperature && v.get_precipitation()<precip){
                int how_many=v.get_end()-v.get_start();
                hours+=how_many;
            }
        }
        if (hours == 0) {
            QMessageBox msgBox;
            msgBox.setText("No such intervals found!");
            msgBox.exec();
        }
        this->ui->ShowlineEdit->setText(QString::fromStdString(std::to_string(hours)));
    });
}

gui::~gui() {
    delete ui;
}

void gui::populateList() {
    //std::vector<Weather> sorted=this->repo.getAll();
    this->repo.sort();

    for(auto&v: this->repo.getAll()){
        this->ui->listWidget->addItem(QString::fromStdString(v.to_string()));
    }
}

