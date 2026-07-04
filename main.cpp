//
// Created by Maria on 04/07/2026.
//

#include "gui/gui.h"
#include <QApplication>
int main(int argc,char* argv[]) {
    QApplication app(argc,argv);
    Repository repo{"../astronomers.txt","../stars.txt"};
    Service service{repo};
    std::vector<GUI*> windows;
    for (const auto& a:service.getAstronomers()) {
        GUI* gui=new GUI{service,a};
        gui->show();
        windows.push_back(gui);
    }
    return app.exec();
}
