#ifndef RECORD_H_
#define RECORD_H_
#include "person.h"

class Record: public person {

    public: 
    int numArrivals;
    Arrival();
    Arrival (Person *newPatient, int arrTime);
    ~Arrival();
    Person* getPatient;
    void print();

};
#endif