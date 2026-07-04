//
// Created by Maria on 04/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include "domain/StarTableModel.h"


GUI::GUI(Service& service, const Astronomer& astronomer,QWidget *parent) :
    QWidget(parent), ui(new Ui::GUI),service{service},astronomer{astronomer} {
    ui->setupUi(this);
    service.registerObserver(this);
    this->setWindowTitle(QString::fromStdString(astronomer.getName()));
    model=new StarTableModel{service.getStars(),this};
    ui->tableView->setModel(model);
    connectSignalsAndSlots();
    GUI::update();
}

GUI::~GUI() {
    service.unregisterObserver(this);
    delete ui;
}

void GUI::update() {
    return;
}

void GUI::connectSignalsAndSlots() {
    return;
}
