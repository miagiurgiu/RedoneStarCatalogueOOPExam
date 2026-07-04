//
// Created by Maria on 04/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include "domain/StarTableModel.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QPushButton>

#include "constellation.h"

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
    updateFields();
}

void GUI::connectSignalsAndSlots() {
    connect(ui->checkBox,&QCheckBox::toggled,this,&GUI::updateFields);
    connect(ui->addButton,&QPushButton::clicked,this,&GUI::addStar);
    connect(ui->viewButton,&QPushButton::clicked,this,&GUI::view);
}

void GUI::updateFields() {
    std::vector<Star> stars;
    if (ui->checkBox->isChecked())
        stars=service.getStarsInConstellation(astronomer.getConstellation());
    else
        stars=service.getStars();
    model->updateData(stars);
}

void GUI::addStar() {
    std::string name=ui->nameLineEdit->text().toStdString();
    int ra=ui->RALineEdit->text().toInt();
    int dec=ui->DecLineEdit->text().toInt();
    int diameter=ui->diameterLineEdit->text().toInt();
    try {
        service.addStar(name,astronomer.getConstellation(),ra,dec,diameter);
    }
    catch (const std::exception& e) {
        QMessageBox::critical(this,"ERROR",e.what());
    }
}

void GUI::view() {
    QModelIndexList selection=ui->tableView->selectionModel()->selectedIndexes();
    if (selection.empty())
        return;
    int row=selection.at(0).row();
    auto stars=service.getStars();
    auto selectedStar=stars[row];

    //auto newConstellation=new Constellation{service,selectedStar,this}; // WITHOUT "THIS" !!!
    auto newConstellation=new Constellation{service,selectedStar};
    newConstellation->show();
}
