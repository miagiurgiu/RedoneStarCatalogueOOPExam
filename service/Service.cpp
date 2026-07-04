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

std::vector<Star> Service::getStarsInConstellation(const std::string& constellation) const {
    std::vector<Star> result;
    for (const auto& s:repo.getStars()) {
        if (s.getConstellation()==constellation)
            result.push_back(s);
    }
    return result;
}

void Service::addStar(const std::string &name, const std::string &constellation, int RA, int Dec, int diameter) {
    if (name.empty())
        throw std::runtime_error("empty name");
    if (diameter<=0)
        throw std::runtime_error("inappropriate diameter");
    for (const auto& s:repo.getStars()) {
        if (s.getName()==name)
            throw std::runtime_error("another one with the same name");
    }
    Star newStar{name,constellation,RA,Dec,diameter};
    repo.addStar(newStar);
    notify();
}
