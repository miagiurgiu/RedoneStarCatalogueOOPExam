//
// Created by Maria on 04/07/2026.
//

#include "Service.h"


Service::Service(Repository& repo):repo{repo}{
}
std::vector<Astronomer> Service::getAstronomers() const {
    return repo.getAstronomers();
}
std::vector<Star> Service::getStars() const {
    return repo.getStars();
}