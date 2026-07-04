//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_REPOSITORY_H
#define REDONESTARCATALOGUEOOPEXAM_REPOSITORY_H
#include <string>

#include "domain/Astronomer.h"
#include "domain/Star.h"
#include <vector>

class Repository {
private:
    std::string astronomersFile;
    std::string starsFile;
    std::vector<Astronomer> astronomers;
    std::vector<Star> stars;
public:
    Repository(const std::string& astronomersFile, const std::string& starsFile);
    std::vector<Astronomer> getAstronomers() const;
    std::vector<Star> getStars() const;
    void loadAstronomers();
    void loadStars();
    void save();
};



#endif //REDONESTARCATALOGUEOOPEXAM_REPOSITORY_H
