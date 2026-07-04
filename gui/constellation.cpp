//
// Created by Maria on 04/07/2026.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Constellation.h" resolved

#include "constellation.h"
#include "ui_Constellation.h"
#include <QPainter>


Constellation::Constellation(Service& service,const Star& star,QWidget *parent) :
    QWidget(parent), ui(new Ui::Constellation),service{service},star{star} {
    ui->setupUi(this);
    service.registerObserver(this);
    Constellation::update();
}

Constellation::~Constellation() {
    service.unregisterObserver(this);
    delete ui;
}


void Constellation::update() {
    repaint();
}

void Constellation::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    int x=100;
    int y=100;
    auto stars=service.getStarsInConstellation(star.getConstellation());
    for (const auto& s:stars) {
        int RA=s.getRA();
        int Dec=s.getDec();
        int diameter=s.getDiameter();
        int radius=diameter/2;
        //painter.drawText(RA,Dec-5,QString::fromStdString(s.toString()));
        painter.drawEllipse(RA,Dec,20*radius,20*radius);
        if (s.getName()==star.getName()) {
            painter.setBrush(Qt::red);
        }
        else {
            painter.setBrush(Qt::black);
        }
        y +=30;
    }
}
