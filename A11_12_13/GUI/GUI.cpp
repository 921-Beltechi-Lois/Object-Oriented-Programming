//
// Created by loisb on 11.05.2022.
//

#include <QVBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QPainter>
#include "GUI.h"
//#include "ui_GUI.h"

void GUI::initGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#4D2D52>Welcome to the Event List App! <br> Select your mode!</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    titleFont.setWeight(63);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);
    this->adminButton->setText("Admin mode");
    layout->addWidget(this->adminButton);
    this->userButton->setText("User mode");
    layout->addWidget(this->userButton);
    this->setLayout(layout);
    this->setStyleSheet("background-color:#D9DBF1");
}

void GUI::showAdmin() {
    auto* admin = new AdminGUI(this, this->service, this->validator, this->repository);
    admin->show();
}

void GUI::showUser() {
    auto* user = new UserGUI(this, this->service, this->userService, this->validator);
    user->show();
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &GUI::showAdmin);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &GUI::showUser);
}


GUI::GUI(Service &service, UserService &userService, EventValidator &validator, Repository &repository1)
: service(service), userService(userService), validator(validator), repository(repository1){
    this->titleWidget = new QLabel(this);
    this->adminButton = new QPushButton(this);
    this->userButton = new QPushButton(this);
    this->initGUI();
    this->connectSignalsAndSlots();
}


GUI::~GUI() = default;

AdminGUI::AdminGUI(QWidget* parent, Service &serv, EventValidator& validator1, Repository& repo): service{serv}, validator{validator1}, repository{repo}{
    this->titleWidget = new QLabel(this);
    //this->filter_items_edit = new QLineEdit{}; /////
    this->filter_items_edit = new QLineEdit{};


    this->eventsListWidget = new QListWidget{};
    this->titleLineEdit = new QLineEdit{};
    this->descriptionLineEdit = new QLineEdit{};
    this->dateLineEdit = new QLineEdit{};
    this->timeLineEdit = new QLineEdit{};
    this->peopleLineEdit= new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->addButton = new QPushButton("Add");
    this->deleteButton = new QPushButton("Delete");
    this->updateButton = new QPushButton("Update");
    //this->chartButton = new QPushButton("Display chart");
    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initAdminGUI();
    this->populateList();
    this->connectSignalsAndSlots();

    this->listModel = new EventListModel{this->repository};

}

void AdminGUI::initAdminGUI() {
//    QLinearGradient gradient_button;
//    gradient_button.setColorAt(0, Qt::white);
//    gradient_button.setColorAt(1, Qt::red);

    auto* layout = new QVBoxLayout(this);

//    ui->label->setStyleSheet(
//            "* {color: qlineargradient(spread:pad, x1:0 y1:0, x2:1 y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
//            "background: qlineargradient( x1:0 y1:0, x2:1 y2:0, stop:0 cyan, stop:1 blue);}");


//    QLinearGradient lg(10., 10., 110., 110.);
//    lg.setColorAt(0.0, Qt::red);
//    lg.setColorAt(0.5, Qt::green);
//    lg.setColorAt(1.0, Qt::blue);
//    QPainter painter(this->eventsListWidget);
//    painter.setBrush(lg);
//    painter.drawRect({10, 10, 110, 110});

    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#4D2D52>ADMIN MODE</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    titleFont.setWeight(63);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    layout->addWidget(this->filter_items_edit); ///@@
    //auto* layout_wrapper = new QVBoxLayout{ this };

    //auto* layout_widget = new QWidget;
    //layout_wrapper->addWidget(filter_items_edit);
    //layout_wrapper->addWidget(layout_widget);

    layout->addWidget(this->eventsListWidget);

    auto * eventDetailsLayout = new QFormLayout{};
    eventDetailsLayout->addRow("Title", this->titleLineEdit);
    eventDetailsLayout->addRow("Description", this->descriptionLineEdit);
    eventDetailsLayout->addRow("Date", this->dateLineEdit);
    eventDetailsLayout->addRow("Time", this->timeLineEdit);
    eventDetailsLayout->addRow("No. of people", this->peopleLineEdit);
    eventDetailsLayout->addRow("Link", this->linkLineEdit);
    layout->addLayout(eventDetailsLayout);

    auto* buttonsLayout = new QGridLayout{};

 /////
//    QLinearGradient gradient_button(0, 0, this->addButton->width(), 0);
//    gradient_button.setColorAt(0, Qt::white);
//    gradient_button.setColorAt(1, Qt::red);
//
//    auto palette = this->addButton->palette();
//    palette.setBrush(QPalette::Button, QBrush(gradient_button));
//    this->addButton->setPalette(palette);
    ////

    buttonsLayout->addWidget(this->addButton, 0, 0);

//    QPalette palette_1 = this->addButton->palette();
//    palette_1.setColor(QPalette::Button, Qt::red);
//    this->addButton->setPalette(palette_1);
//    this->addButton->update();

    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updateButton, 1, 0);
    ///buttonsLayout->addWidget(this->chartButton, 1, 1);
    layout->addLayout(buttonsLayout);
}

void AdminGUI::populateList() {
    this->eventsListWidget->clear();
    std::vector<Event> allEvents = this->service.getAllService();
    for (Event& event: allEvents)
        this->eventsListWidget->addItem(QString::fromStdString(event.getTitle()));
}

void AdminGUI::connectSignalsAndSlots() {
    connect(this->filter_items_edit, &QLineEdit::textChanged, this, &AdminGUI::filter_list);

    QObject::connect(this->eventsListWidget, &QListWidget::itemSelectionChanged, [this]() {
        int selectedIndex = this->getSelectedIndex();
        if (selectedIndex < 0)
            return ;
        Event event = this->service.getAllService()[selectedIndex];
        this->titleLineEdit->setText(QString::fromStdString(event.getTitle()));
        this->descriptionLineEdit->setText(QString::fromStdString(event.getDescription()));
        Date d=event.getDate();
        std::string date;
        date=std::to_string(d.get_month())+"/"+std::to_string(d.get_day());
        this->dateLineEdit->setText(QString::fromStdString(date));
        Time t=event.getTime();
        std::string time;
        time=std::to_string(t.get_hour())+":"+std::to_string(t.get_minute());
        this->timeLineEdit->setText(QString::fromStdString(time));
        this->peopleLineEdit->setText(QString::fromStdString(std::to_string(event.getPeople())));
        this->linkLineEdit->setText(QString::fromStdString(event.getLink()));
    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addEvent);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteEvent);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateEvent);

    //TODO @
    //QObject::connect(this->chartButton, &QPushButton::clicked, this, &AdminGUI::displayChart);
}

void AdminGUI::filter_list() {
    if(this->eventsListWidget->count() > 0){
        this->eventsListWidget->clear();
        //this->events_list_vector.clear();
    }
    for(auto& event: this->service.get_events_by_string(this->filter_items_edit->text().toStdString())){
        QString event_in_list = QString::fromStdString(event.ToString());
        auto* ev=new QListWidgetItem{event_in_list};
        //events_list_vector.push_back(event);
        this->eventsListWidget->addItem(ev);
    }
}

int AdminGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->eventsListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()) {
        this->titleLineEdit->clear();
        this->descriptionLineEdit->clear();
        this->dateLineEdit->clear();
        this->timeLineEdit->clear();
        this->peopleLineEdit->clear();
        this->linkLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void AdminGUI::addEvent() {
    std::string title = this->titleLineEdit->text().toStdString();
    std::string description = this->descriptionLineEdit->text().toStdString();
    std::string date = this->dateLineEdit->text().toStdString();
    std::string time = this->timeLineEdit->text().toStdString();
    std::string people = this->peopleLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();

    Date d{std::stoi(date.substr(0,2)), std::stoi(date.substr(3,2))};
    Time t{std::stoi(time.substr(0,2)), std::stoi(time.substr(3,2))};
    try {
//        this->validator.validateTitle(title);
//        this->validator.validateDescription(description);
        this->validator.validateDate_Month(std::stoi(date.substr(0,2))); // Month/Day
        this->validator.validateDate_Day(std::stoi(date.substr(3,2)));
        std::string hour=time.substr(0,2), minute=time.substr(3,2);
        this->validator.validateTime_hour(hour);
        this->validator.validateTime_minute(minute);
        int people2 = std::stoi(people);
        this->validator.validatePeopleString(people);
        this->validator.validatePeople(people2);
        this->validator.validateLink(link);

        this->service.addEvent_serv(title, description, d, t, people2, link);
        this->populateList();
    } catch (ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    } catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at adding event!");
        error->exec();
    }
}

void AdminGUI::deleteEvent() {
    try {
        std::string title = this->titleLineEdit->text().toStdString();
        this->validator.validateTitle(title);
        this->service.removeEvent_serv(title);
        this->populateList();
    } catch (ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    } catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at deleting event!");
        error->exec();
    }
}

void AdminGUI::updateEvent() {
    int index = this->getSelectedIndex();
    try {
        if (index < 0) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText("No event selected!");
            error->setWindowTitle("Selection error!");
            error->exec();
        } else {
            std::string old_title = this->service.getAllService()[index].getTitle();
            std::string new_title = this->titleLineEdit->text().toStdString();
            std::string old_description = this->service.getAllService()[index].getDescription();
            std::string new_description = this->descriptionLineEdit->text().toStdString();

            Date old_date= this->service.getAllService()[index].getDate();
            std::string new_date=this->dateLineEdit->text().toStdString();

            Time old_time=this->service.getAllService()[index].getTime();
            std::string new_time=this->timeLineEdit->text().toStdString();

            Date d{std::stoi(new_date.substr(0,2)), std::stoi(new_date.substr(3,2))};
            Time t{std::stoi(new_time.substr(0,2)), std::stoi(new_time.substr(3,2))};

            int old_people = this->service.getAllService()[index].getPeople();
            std::string new_people = this->peopleLineEdit->text().toStdString();

            std::string old_link=this->linkLineEdit->text().toStdString();
            std::string new_link = this->linkLineEdit->text().toStdString();

            this->validator.validateTitle(new_title);
            this->validator.validateDescription(new_description);
            this->validator.validateDate_Month(std::stoi(new_date.substr(0,2))); // Month/Day
            this->validator.validateDate_Day(std::stoi(new_date.substr(3,2)));
            std::string hour=new_time.substr(0,2), minute=new_time.substr(3,2);
            this->validator.validateTime_hour(hour);
            this->validator.validateTime_minute(minute);
            int people2 = std::stoi(new_people);
            this->validator.validatePeopleString(new_people);
            this->validator.validatePeople(people2);
            this->validator.validateLink(new_link);

            this->service.updateEvent_serv(old_title, new_description,
                                           Date{std::stoi(new_date.substr(0,2)),std::stoi(new_date.substr(3,2))},
                                           Time{std::stoi(new_time.substr(0,2)), std::stoi(new_time.substr(3,2))},
                                           people2,new_link);
            this->populateList();
        }
    } catch (ValidationException& exc) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(exc.what());
        error->setWindowTitle("Invalid input!");
        error->exec();
    } catch (RepositoryException& re) {
        auto* error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(re.what());
        error->setWindowTitle("Error at updating event!");
        error->exec();
    }
}


AdminGUI::~AdminGUI() = default;



/// ******** EventListModel

int EventListModel::rowCount(const QModelIndex &parent) const {
    return this->repository.getAllElems_Repo().size();
}

QVariant EventListModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    Event currentEvent = this->repository.getAllElems_Repo()[row];
    if(role == Qt::DisplayRole)
    {
        return QString::fromStdString(currentEvent.getTitle());
    }
    return QVariant();
}




/// ******************* USER GUI

UserGUI::UserGUI(QWidget* parent, Service& serv, UserService &userserv, EventValidator& validator1): service{serv}, userService{userserv}, validator{validator1} {
    this->titleWidget = new QLabel(this);
    this->eventsListWidget = new QListWidget{};
    this->user_eventListWidget = new QListWidget{};
    this->titleLineEdit = new QLineEdit{};
    this->descriptionLineEdit = new QLineEdit{};
    this->dateLineEdit = new QLineEdit{};
    this->timeLineEdit = new QLineEdit{};
    this->peopleLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->monthFilterLineEdit = new QLineEdit{};
    this->addButton = new QPushButton("Add to the user event list");
    this->deleteButton= new QPushButton("Remove event from the user list");
    this->filterButton = new QPushButton("Filter");
    this->openListButton = new QPushButton("Open file");
    this->csvButton = new QRadioButton("CSV");
    this->htmlButton = new QRadioButton("HTML");
    this->repoTypeSelected = false;
    this->filtered = false;
    setParent(parent);
    setWindowFlag(Qt::Window);
    this->initUserGUI();
    this->populateEventList();
    this->connectSignalsAndSlots();
}


void UserGUI::initUserGUI() {
    auto* layout = new QVBoxLayout(this);
    QFont titleFont = this->titleWidget->font();
    this->titleWidget->setText("<p style='text-align:center'><font color=#4D2D52>USER MODE <br> Select the type of file you want for saving your event list!</font></p>");
    titleFont.setItalic(true);
    titleFont.setPointSize(10);
    titleFont.setStyleHint(QFont::System);
    titleFont.setWeight(63);
    this->titleWidget->setFont(titleFont);
    layout->addWidget(this->titleWidget);

    auto* radioButtonsLayout = new QGridLayout(this);
    radioButtonsLayout->addWidget(this->csvButton, 0, 0);
    radioButtonsLayout->addWidget(this->htmlButton, 1, 0);
    radioButtonsLayout->addWidget(this->openListButton, 0, 1);
    layout->addLayout(radioButtonsLayout);

    auto* listLayout = new QGridLayout(this);
    listLayout->addWidget(this->eventsListWidget, 0, 0);
    listLayout->addWidget(this->user_eventListWidget, 0, 1);
    layout->addLayout(listLayout);

    auto * eventDetailsLayout = new QFormLayout{};
    eventDetailsLayout->addRow("Title", this->titleLineEdit);
    eventDetailsLayout->addRow("Description", this->descriptionLineEdit);
    eventDetailsLayout->addRow("Date", this->dateLineEdit);
    eventDetailsLayout->addRow("Time", this->timeLineEdit);
    eventDetailsLayout->addRow("People", this->peopleLineEdit);
    eventDetailsLayout->addRow("Link", this->linkLineEdit);
    eventDetailsLayout->addRow(this->addButton);
    eventDetailsLayout->addRow(this->deleteButton); ////
    layout->addLayout(eventDetailsLayout);


    auto *filterTitle = new QLabel("<p style='text-align:center'><font color=#4D2D52><br>Filter the available events by month</font></p>");
    QFont filterFont = filterTitle->font();
    filterFont.setPointSize(10);
    filterFont.setStyleHint(QFont::System);
    filterFont.setWeight(63);
    filterTitle->setFont(filterFont);
    layout->addWidget(filterTitle);

    auto *  filterDetailsLayout = new QFormLayout{};
    filterDetailsLayout->addRow("Month", this->monthFilterLineEdit);
    filterDetailsLayout->addRow(this->filterButton);
    layout->addLayout(filterDetailsLayout);
}

// Admin list
void UserGUI::populateEventList() {
    this->eventsListWidget->clear();
    std::vector<Event> allEvents = this->service.getAllService();
    for (Event& event: allEvents)
        this->eventsListWidget->addItem(QString::fromStdString(event.getTitle()));
}
// User list
void UserGUI::populateUserEventList() {
    this->user_eventListWidget->clear();
    std::vector<Event> allEvents = this->userService.getAllUserService();
    for (Event& event: allEvents)
        this->user_eventListWidget->addItem(QString::fromStdString(event.getTitle()));
}

void UserGUI::connectSignalsAndSlots() {
    QObject::connect(this->eventsListWidget, &QListWidget::itemClicked, [this]() {
        std::string event_name = this->eventsListWidget->selectedItems().at(0)->text().toStdString();
        int index = this->service.find_event_serv(event_name);
        Event event = this->service.getAllService()[index];

        this->titleLineEdit->setText(QString::fromStdString(event.getTitle()));
        this->descriptionLineEdit->setText(QString::fromStdString(event.getDescription()));
        Date d=event.getDate();
        std::string date;
        date=std::to_string(d.get_month())+"/"+std::to_string(d.get_day());
        this->dateLineEdit->setText(QString::fromStdString(date));
        Time t=event.getTime();
        std::string time;
        time=std::to_string(t.get_hour())+":"+std::to_string(t.get_minute());
        this->timeLineEdit->setText(QString::fromStdString(time));
        this->peopleLineEdit->setText(QString::fromStdString(std::to_string(event.getPeople())));
        this->linkLineEdit->setText(QString::fromStdString(event.getLink()));
        //std::string link = std::string("start ").append(event.getLink());
        //system(link.c_str());
    });

    QObject::connect(this->csvButton, &QRadioButton::clicked, [this]() {
        this->userService.repositoryType("csv");
        this->repoTypeSelected = true;
    });

    QObject::connect(this->htmlButton, &QRadioButton::clicked, [this]() {
        this->userService.repositoryType("html");
        this->repoTypeSelected = true;
    });

    QObject::connect(this->openListButton, &QPushButton::clicked, [this]() {
        if (!this->repoTypeSelected) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Warning);
            error->setText("Please select the type of file you want!");
            error->setWindowTitle("File type warning!");
            error->exec();
        } else {
            std::string link = std::string("start ").append(this->userService.getFileService());
            system(link.c_str());
        }
    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserGUI::addEvent);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &UserGUI::removeEvent);

    QObject::connect(this->filterButton, &QPushButton::clicked, this, &UserGUI::filterEvents);
}

int UserGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->eventsListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.empty()) {
        this->titleLineEdit->clear();
        this->descriptionLineEdit->clear();
        this->dateLineEdit->clear();
        this->timeLineEdit->clear();
        this->peopleLineEdit->clear();
        this->linkLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;

}

void UserGUI::addEvent() {
    if (!this->repoTypeSelected) {
        auto *error = new QMessageBox();
        error->setIcon(QMessageBox::Warning);
        error->setText("Please select the type of file you want!");
        error->setWindowTitle("File type warning!");
        error->exec();
    } else {

        std::string title = this->titleLineEdit->text().toStdString();
        std::string description = this->descriptionLineEdit->text().toStdString();
        std::string date = this->dateLineEdit->text().toStdString();
        std::string time = this->timeLineEdit->text().toStdString();
        std::string people = this->peopleLineEdit->text().toStdString();
        std::string link = this->linkLineEdit->text().toStdString();

        Date d{std::stoi(date.substr(0,2)), std::stoi(date.substr(3,2))};
        Time t{std::stoi(time.substr(0,2)), std::stoi(time.substr(3,2))};

        try {
           // this->validator.validateTitle(title);
            //this->validator.validateDescription(description);
            //this->validator.validateDate_Month(std::stoi(date.substr(0,2))); // Month/Day
            //this->validator.validateDate_Day(std::stoi(date.substr(3,2)));
            std::string hour=time.substr(0,2), minute=time.substr(3,2);
            //this->validator.validateTime_hour(hour);
            //this->validator.validateTime_minute(minute);
            int people2 = std::stoi(people);
            this->validator.validatePeopleString(people);
            this->validator.validatePeople(people2);
            this->validator.validateLink(link);

            Event event = Event{title, description, Date{std::stoi(date.substr(0,2)), std::stoi(date.substr(3,2))},
                                Time {std::stoi(time.substr(0,2)), std::stoi(time.substr(3,2))},people2, link};

            this->userService.addUserService(title, description, Date{std::stoi(date.substr(0,2)), std::stoi(date.substr(3,2))},
                                             Time {std::stoi(time.substr(0,2)), std::stoi(time.substr(3,2))},people2, link);
            if (!this->filtered)
                this->populateEventList(); // admin provided list
            else
                this->user_eventListWidget->addItem(this->eventsListWidget->takeItem(this->getSelectedIndex()));
            this->populateUserEventList(); // user's list
        } catch (ValidationException& exc) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(exc.what());
            error->setWindowTitle("Invalid input!");
            error->exec();
        } catch (RepositoryException& re) {
            auto* error = new QMessageBox();
            error->setIcon(QMessageBox::Critical);
            error->setText(re.what());
            error->setWindowTitle("Error at adding event!");
            error->exec();
        }
    }
}

void UserGUI::removeEvent() {
    //try {
        std::string title = this->titleLineEdit->text().toStdString();
//        this->validator.validateTitle(title);
        this->userService.removeUserService(title);
        this->populateUserEventList();
//    } catch (ValidationException& exc) {
//        auto* error = new QMessageBox();
//        error->setIcon(QMessageBox::Critical);
//        error->setText(exc.what());
//        error->setWindowTitle("Invalid input!");
//        error->exec();
//    } catch (RepositoryException& re) {
//        auto* error = new QMessageBox();
//        error->setIcon(QMessageBox::Critical);
//        error->setText(re.what());
//        error->setWindowTitle("Error at deleting user event!");
//        error->exec();
    //}
}

void UserGUI::filterEvents() {
    try {
        std::string month_filter = this->monthFilterLineEdit->text().toStdString();
        if (month_filter.empty()) {
            this->filtered = false;
            this->populateEventList();
        } else {

//            this->validator.validateDate_Month(std::stoi(month_filter));

            std::vector<Event> validEvents;
            this->service.filter_sort(validEvents, std::stoi(month_filter));
            if (validEvents.empty()) {
                std::string error;
                error += std::string("The list of valid events is empty!");
                if(!error.empty())
                    throw UserException(error);
            } else {
                this->filtered = true;
                this->eventsListWidget->clear();
                for (Event& event: validEvents)
                    this->eventsListWidget->addItem(QString::fromStdString(event.getTitle()));
            }
        }
    } catch (ValidationException& ve) {
        auto *error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(ve.what());
        error->setWindowTitle("Validation error!");
        error->exec();
    } catch (UserException& ue) {
        auto *error = new QMessageBox();
        error->setIcon(QMessageBox::Critical);
        error->setText(ue.what());
        error->setWindowTitle("Filter error!");
        error->exec();
    }
}



UserGUI::~UserGUI() =default;
