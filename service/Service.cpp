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