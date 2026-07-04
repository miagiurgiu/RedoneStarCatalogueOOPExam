//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_SERVICE_H
#define REDONESTARCATALOGUEOOPEXAM_SERVICE_H
#include "domain/Astronomer.h"
#include "domain/Star.h"
#include "repo/Repository.h"
#include <vector>

#include "domain/Subject.h"

class Service:public Subject {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    std::vector<Astronomer> getAstronomers() const;
    std::vector<Star> getStars() const;
    std::vector<Star> getStarsInConstellation(const std::string& constellation) const;
    void addStar(const std::string& name, const std::string& constellation,int RA, int Dec, int diameter);
    std::vector<Star> getStarsMatching(const std::string& text);
};



#endif //REDONESTARCATALOGUEOOPEXAM_SERVICE_H
