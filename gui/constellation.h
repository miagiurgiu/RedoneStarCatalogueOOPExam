//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_CONSTELLATION_H
#define REDONESTARCATALOGUEOOPEXAM_CONSTELLATION_H

#include <QWidget>

#include "domain/Observer.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Constellation; }
QT_END_NAMESPACE

class Constellation : public QWidget,public Observer {
Q_OBJECT

public:
    explicit Constellation(Service& service,const Star& star,QWidget *parent = nullptr);
    ~Constellation() override;
    void update() override;
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Ui::Constellation *ui;
    Service& service;
    Star star;
};


#endif //REDONESTARCATALOGUEOOPEXAM_CONSTELLATION_H
