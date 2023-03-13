//
// Created by loisb on 02.06.2022.
//



#include "MylistTableModel.h"


int MylistTableModel::rowCount(const QModelIndex& parent) const
{
    return this->user_service.getSizeSavedList();
    //return this->service.getSizeSavedList();
}

int MylistTableModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant MylistTableModel::data(const QModelIndex& index, int role) const
{
    Event currentSaved = this->user_service.getAllUserService()[index.row()];
    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case 0:
                return QString::fromStdString(currentSaved.getTitle());
            case 1:
                return QString::fromStdString(currentSaved.getDescription());
            case 2:
                return QString::number(currentSaved.getPeople());
            case 3:
                return QString::fromStdString(currentSaved.getLink());
            default:
                break;
        }
    }
    return QVariant();
}

QVariant MylistTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    return QString("Title");
                case 1:
                    return QString("Description");
                case 2:
                    return QString("Age");
                case 3:
                    return QString("Photograph");
                default:
                    break;

            }
        }
    }
    return QVariant();
}