//
// Created by loisb on 11.06.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScreenWriterWindow.h" resolved

#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <iostream>
#include "screenwriterwindow.h"
#include "ui_ScreenWriterWindow.h"


ScreenWriterWindow::ScreenWriterWindow(TableModel* tableModel,IdeasRepo& repo,ScreenWriter& writer, QWidget *parent) :
        repo{repo}, writer{writer},QWidget(parent), ui(new Ui::ScreenWriterWindow) {
    ui->setupUi(this);

    current_writer=writer.getName();
//    expertise=writer.getExpertise();
    this->setWindowTitle(QString::fromStdString(writer.getName()));
    this->show();

    // this->ui->ideasTableView->setModel(this->tableModel);

    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
    proxyModel->setSourceModel(tableModel);
    proxyModel->setSortRole(Qt::UserRole);
    ui->IdeatableView->setModel(proxyModel);
    ui->IdeatableView->setSortingEnabled(true);
    this->tableModel2=tableModel;

    if(this->writer.getExpertise() != "Senior")
        this->ui->AcceptpushButton->setEnabled(false);

//    vector<Idea> i = this->repo.getAcceptedIdeas(this->writer);
//    if(i.empty())
//        this->ui->DEVELOP->setEnabled(false);

    //Idea i{"cf","da","bn", "tu"};
    //tableModel->addIdea(i);
    //this->repo.addIdea(i);


    QObject::connect(this->ui->AddpushButton, &QPushButton::clicked, this, [this]() {
        //Idea i{"cf","da","bn", "tu"};
        std::string desc=this->ui->DesclineEdit->text().toStdString();
        string act=this->ui->ActlineEdit->text().toStdString();

        if(desc.empty() || (act!="1" && act!="2" && act!="3")){
            QMessageBox msgBox;
            msgBox.setText("desc is empty or act is not 1,2,3");
            msgBox.exec();
            this->ui->DesclineEdit->clear();
            this->ui->ActlineEdit->clear();
            return;
        }
        string status="proposed";
        string creator=current_writer;

        Idea i{desc, status, creator, act};
        this->tableModel2->addIdea(i);

        this->ui->DesclineEdit->clear();
        this->ui->ActlineEdit->clear();


        //this->tableModel2->addIdea(i);
        //this->repo.addIdea(i);
    });

    QObject::connect(this->ui->IdeatableView, &QTableView::clicked, this, &ScreenWriterWindow::check);
    QObject::connect(this->ui->AcceptpushButton, &QPushButton::clicked, this, [this]() {
        if(selected_index!=-1){
            Idea i = this->repo.getIdeas()[selected_index];
            this->repo.acceptIdea(i);



        }

//        QObject::connect(this->ui->IdeatableView, &QTableView::clicked, this, &ScreenWriterWindow::accepted_ideas);

    });

    QObject::connect(this->ui->DEVELOP, &QPushButton::clicked, this, [this]() {
            vector<Idea> ideas=this->repo.getAcceptedIdeas(this->writer);
            for(auto v: ideas){
                this->ui->QTextEdit->addItem(QString::fromStdString(v.getDescription()+v.getStatus()+v.getCreator()+v.getAct()));
            }
    });


    QObject::connect(this->ui->SavepushButton, &QPushButton::clicked, this, [this]() {
        if(selected_index!=-1){
            Idea i =this->repo.getIdeas()[selected_index];
            std::ofstream f("1.txt");
            string text;
//            Idea ii{i.getStatus(), i.getDescription(), i.getAct(), i.getCreator()};
//            f>>ii;
//
//            while(f>>ii){
//
//            }
        }

    });

    QObject::connect(this->ui->QTextEdit, &QListWidget::itemSelectionChanged, [this]() {
        int index=getSelectedIndex();
        selected_index=index;
    });
//    this->ui.



}

ScreenWriterWindow::~ScreenWriterWindow() {
    delete ui;
}



//void ScreenWriterWindow::notifyModel() {
//    this->tableModel->updateInternalData();
//}

void ScreenWriterWindow::check() {
    vector<Idea> i = this->repo.getAcceptedIdeas(this->writer);
    if(i.empty())
        this->ui->DEVELOP->setEnabled(false);
    else
        this->ui->DEVELOP->setEnabled(true);


    std::cout<<"alo";
    int index = this->getSelectedIndex();
    //std::cout<<writer<<" ";
    if(this->writer.getExpertise() != "Senior") {
        this->setEnabled(false);
        this->selected_index=-1;
        return;
    }
    else{
        string status = this->repo.getIdeas()[index].getStatus();
        if(status == "accepted") {
            this->ui->AcceptpushButton->setEnabled(false);
            this->selected_index=-1;
            return;}
        else{ //proposed
            this->ui->AcceptpushButton->setEnabled(true);
            this->selected_index=index;
            //Idea i = this->repo.getIdeas()[index];
            //this->repo.acceptIdea(i);
            return;}
    }
}

int ScreenWriterWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->ui->IdeatableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}





