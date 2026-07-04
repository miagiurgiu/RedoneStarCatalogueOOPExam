//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_STAR_H
#define REDONESTARCATALOGUEOOPEXAM_STAR_H

#include <string>

class Star {
private:
    std::string name;
    std::string constellation;
    int RA;
    int Dec;
    int diameter;
public:
    Star(const std::string& name, const std::string& constellation,int RA, int Dec, int diameter);
    std::string getName() const;
    std::string getConstellation() const;
    int getRA() const;
    int getDec() const;
    int getDiameter() const;
    std::string toString() const;
};



#endif //REDONESTARCATALOGUEOOPEXAM_STAR_H
