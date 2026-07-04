//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_GUI_H
#define REDONESTARCATALOGUEOOPEXAM_GUI_H

#include <QWidget>

#include "domain/Astronomer.h"
#include "domain/Observer.h"
#include "service/Service.h"


class StarTableModel;
QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget,public Observer {
Q_OBJECT

public:
    explicit GUI(Service& service, const Astronomer& astronomer,QWidget *parent = nullptr);
    ~GUI() override;
    void update() override;

private:
    Ui::GUI *ui;
    Service& service;
    Astronomer astronomer;
    StarTableModel* model;
    void connectSignalsAndSlots();
};


#endif //REDONESTARCATALOGUEOOPEXAM_GUI_H
