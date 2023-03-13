//
// Created by loisb on 11.06.2022.
//

#ifndef E911_911_BELTECHI_LOIS_1_SCREENWRITERWINDOW_H
#define E911_911_BELTECHI_LOIS_1_SCREENWRITERWINDOW_H

#include <QWidget>

#include "ScreenWriter.h"
#include "IdeasRepo.h"
#include "TableModel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ScreenWriterWindow; }
QT_END_NAMESPACE

class ScreenWriterWindow : public QWidget {
Q_OBJECT

public:
    explicit ScreenWriterWindow(TableModel* tableModel,IdeasRepo& repo,ScreenWriter& writer, QWidget *parent = nullptr);

    ~ScreenWriterWindow() override;

private:
    Ui::ScreenWriterWindow *ui;

    ScreenWriter& writer;

    std::string current_writer;
    std::string expertise;

    void check();
    int getSelectedIndex();

    void accepted_ideas();

    TableModel* tableModel2;
    IdeasRepo& repo;

    int selected_index;
};


#endif //E911_911_BELTECHI_LOIS_1_SCREENWRITERWINDOW_H
