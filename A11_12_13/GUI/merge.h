//
// Created by loisb on 22.05.2022.
//

#ifndef A11_12_911_BELTECHI_LOIS_MERGE_H
#define A11_12_911_BELTECHI_LOIS_MERGE_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class merge; }
QT_END_NAMESPACE

class merge : public QWidget {
Q_OBJECT

public:
    explicit merge(QWidget *parent = nullptr);

    ~merge() override;

private:
    Ui::merge *ui;
};


#endif //A11_12_911_BELTECHI_LOIS_MERGE_H
