//
// Created by Maria on 04/07/2026.
//

#include "Repository.h"
#include <fstream>
#include <sstream>

Repository::Repository(const std::string &astronomersFile, const std::string &starsFile):astronomersFile{astronomersFile}, starsFile{starsFile}{
    loadAstronomers();
    loadStars();
}

std::vector<Astronomer> Repository::getAstronomers() const {
    return astronomers;
}

std::vector<Star> Repository::getStars() const {
    return stars;
}

void Repository::loadAstronomers() {
    std::ifstream fin(astronomersFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name;
        std::string constellation;
        std::getline(ss,name,',');
        std::getline(ss,constellation,',');
        astronomers.emplace_back(name,constellation);
    }
    fin.close();
}

void Repository::loadStars() {
    std::ifstream fin(starsFile);
    if (!fin.is_open())
        throw std::runtime_error("could not open");
    std::string line;
    while (std::getline(fin,line)) {
        std::stringstream ss(line);
        std::string name;
        std::string constellation;
        std::string RAString,DecString,diameterString;
        std::getline(ss,name,',');
        std::getline(ss,constellation,',');
        std::getline(ss,RAString,',');
        std::getline(ss,DecString,',');
        std::getline(ss,diameterString,',');

        int RA=std::stoi(RAString);
        int Dec=std::stoi(DecString);
        int diameter=std::stoi(diameterString);
        stars.emplace_back(name,constellation,RA,Dec,diameter);
    }
    fin.close();
}

void Repository::save() {
    std::ofstream fout(starsFile);
    std::sort(stars.begin(),stars.end(),[](const Star& s1, const Star& s2) {
        return s1.getConstellation()<s2.getConstellation();
    });
    for (const auto& s:stars) {
        fout<<s.toString()<<"\n";
    }
}

void Repository::addStar(const Star &s) {
    stars.push_back(s);
    save();
}
