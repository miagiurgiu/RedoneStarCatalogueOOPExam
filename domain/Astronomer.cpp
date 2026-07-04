//
// Created by Maria on 04/07/2026.
//

#include "Astronomer.h"

Astronomer::Astronomer(const std::string &name, const std::string &constellation):name{name},constellation{constellation} {
}

std::string Astronomer::getName() const {
    return name;
}

std::string Astronomer::getConstellation() const {
    return constellation;
}
