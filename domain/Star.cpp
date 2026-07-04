//
// Created by Maria on 04/07/2026.
//

#include "Star.h"


Star::Star(const std::string& name, const std::string& constellation,int RA, int Dec, int diameter):name{name},constellation{constellation},RA{RA},Dec{Dec},diameter{diameter}{

}
std::string Star::getName() const {
    return name;
}
std::string Star::getConstellation() const {
    return constellation;
}
int Star::getRA() const {
    return RA;
}
int Star::getDec() const {
    return Dec;
}
int Star::getDiameter() const {
    return diameter;
}

std::string Star::toString() const {
    return name+","+constellation+","+std::to_string(RA)+","+std::to_string(Dec)+","+std::to_string(diameter);
}
