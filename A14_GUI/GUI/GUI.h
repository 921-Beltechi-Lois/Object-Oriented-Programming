//
// Created by loisb on 11.05.2022.
//

#ifndef A11_12_911_BELTECHI_LOIS_GUI_H
#define A11_12_911_BELTECHI_LOIS_GUI_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QTableView>
#include "Service/Service.h"
#include "Service/UserService.h"
#include "Validators/Validator.h"

#include "tableviewwidget.h"
#include "ui_TableViewWidget.h"

class EventListModel: public QAbstractListModel {
private:
    Repository& repository;
public:
    explicit EventListModel(Repository& repo): repository{ repo } {};

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
};

class GUI: public QWidget {
private:
    TableViewWidget* table;
    Service& service;
    UserService& userService;
    EventValidator& validator;
    Repository& repository;
    void initGUI();
    QLabel* titleWidget;
    QPushButton* adminButton;
    QPushButton* userButton;
    QPushButton* tableButton;
    void showAdmin();
    void showUser();
    void showTable();
    void connectSignalsAndSlots();
public:
    explicit GUI(Service &service, UserService &userService, EventValidator &validator, Repository &repository1);
    ~GUI() override;
};

class AdminGUI: public QWidget {
private:

    Service& service;
    EventValidator& validator;
    Repository& repository;
    void initAdminGUI();
    QLabel* titleWidget;

    QListWidget* eventsListWidget;
    //std::vector<Event> events_list_vector;

    QLineEdit* titleLineEdit, *descriptionLineEdit, *dateLineEdit, *timeLineEdit, *peopleLineEdit,*linkLineEdit, *filter_items_edit; ////@@@@
    QPushButton* addButton, *deleteButton, *updateButton, *chartButton; ///
    EventListModel* listModel;

    void populateList();
    void connectSignalsAndSlots();
    int getSelectedIndex() const;
    void addEvent();
    void deleteEvent();
    void updateEvent();
    //void displayChart();
    void filter_list();

    QWidget* chartWindow;
public:
    explicit AdminGUI(QWidget* parent, Service& serv, EventValidator& validator1, Repository& repo);
    ~AdminGUI() override;
};

class UserGUI: public QWidget {
private:
    TableViewWidget* table;

    Service& service;
    UserService& userService;
    EventValidator& validator;
    void initUserGUI();
    QLabel* titleWidget;


    QTableView *tableView;
    QListWidget* eventsListWidget, *user_eventListWidget;
    QLineEdit* titleLineEdit, *descriptionLineEdit, *dateLineEdit, *timeLineEdit, *peopleLineEdit,*linkLineEdit, *monthFilterLineEdit; ////@@@@
    QPushButton* addButton, *deleteButton, *filterButton, *openListButton;
    QRadioButton* csvButton, *htmlButton;
    bool repoTypeSelected;
    bool filtered;
    void populateEventList();
    void populateUserEventList();
    void connectSignalsAndSlots();
    int getSelectedIndex() const;
    void addEvent();
    void removeEvent();
    void filterEvents();
public:
    explicit UserGUI(QWidget* parent, Service& serv, UserService& userserv, EventValidator& validator1);
    ~UserGUI() override;
};


#endif //A11_12_911_BELTECHI_LOIS_GUI_H
