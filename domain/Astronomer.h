//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_ASTRONOMER_H
#define REDONESTARCATALOGUEOOPEXAM_ASTRONOMER_H
#include <string>


class Astronomer {
private:
    std::string name;
    std::string constellation;
public:
    Astronomer(const std::string& name, const std::string& constellation);
    std::string getName() const;
    std::string getConstellation() const;
};



#endif //REDONESTARCATALOGUEOOPEXAM_ASTRONOMER_H
