//
// Created by Maria on 04/07/2026.
//

#include "StarTableModel.h"

StarTableModel::StarTableModel(const std::vector<Star> &stars,QObject* parent):stars{stars},QAbstractTableModel{parent}{
}

int StarTableModel::rowCount(const QModelIndex &parent) const {
    return static_cast<int>(stars.size());
}

int StarTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant StarTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role !=Qt::DisplayRole)
        return QVariant{};
    const auto& s=stars[index.row()];
    if (index.column()==0)
        return QString::fromStdString(s.getName());
    if (index.column()==1)
        return QString::fromStdString(s.getConstellation());
    if (index.column()==2)
        return s.getRA();
    if (index.column()==3)
        return s.getDec();
    if (index.column()==4)
        return s.getDiameter();
    return QVariant{};
}

void StarTableModel::updateData(const std::vector<Star> &newData) {
    beginResetModel();
    stars=newData;
    endResetModel();
}
