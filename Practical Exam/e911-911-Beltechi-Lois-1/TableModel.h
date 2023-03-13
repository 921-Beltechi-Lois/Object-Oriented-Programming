//
// Created by loisb on 11.06.2022.
//

#ifndef E911_911_BELTECHI_LOIS_1_TABLEMODEL_H
#define E911_911_BELTECHI_LOIS_1_TABLEMODEL_H


#include <QAbstractTableModel>
#include "IdeasRepo.h"

class TableModel: public QAbstractTableModel {

private:
    IdeasRepo& repository;

public:

    TableModel(IdeasRepo& repository, QObject* parent = NULL);

    ~TableModel();

// number of rows
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

// number of columns
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

// Value at a given position
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

// add header data
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

// will be called when a cell is edited
//    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

// used to set certain properties of a cell
    Qt::ItemFlags flags(const QModelIndex & index) const override;

    void updateInternalData();


    void addIdea(const Idea& i);
    void clearData();
};


#endif //E911_911_BELTECHI_LOIS_1_TABLEMODEL_H
