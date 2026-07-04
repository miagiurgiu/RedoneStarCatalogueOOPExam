//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_STARTABLEMODEL_H
#define REDONESTARCATALOGUEOOPEXAM_STARTABLEMODEL_H
#include <QAbstractTableModel>

#include "Star.h"


class StarTableModel:public QAbstractTableModel {
    Q_OBJECT
private:
    std::vector<Star> stars;
public:
    explicit StarTableModel(const std::vector<Star>& stars,QObject* parent=nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    void updateData(const std::vector<Star>& newData);
};



#endif //REDONESTARCATALOGUEOOPEXAM_STARTABLEMODEL_H
