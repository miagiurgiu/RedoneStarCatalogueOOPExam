//
// Created by Maria on 04/07/2026.
//

#ifndef REDONESTARCATALOGUEOOPEXAM_SUBJECT_H
#define REDONESTARCATALOGUEOOPEXAM_SUBJECT_H
#include <vector>

#include "Observer.h"


class Subject {
private:
    std::vector<Observer*> observers;
public:
    Subject()=default;
    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();
};



#endif //REDONESTARCATALOGUEOOPEXAM_SUBJECT_H
