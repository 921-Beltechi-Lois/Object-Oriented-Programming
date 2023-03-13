//
// Created by loisb on 02.06.2022.
//

#ifndef A14_911_BELTECHI_LOIS_MYLISTTABLEMODEL_H
#define A14_911_BELTECHI_LOIS_MYLISTTABLEMODEL_H


#pragma once
#include <qabstractitemmodel.h>
#include "Service/Service.h"

#include "Service/UserService.h"

class MylistTableModel : public QAbstractTableModel
{
private:
	UserService& user_service;

public:
	MylistTableModel(UserService& service) : user_service{ user_service } {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};



#endif //A14_911_BELTECHI_LOIS_MYLISTTABLEMODEL_H
