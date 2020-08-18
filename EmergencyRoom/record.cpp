#include "record.h"


int Arrival::numArrivals = 0;

Arrival::Arrival() {
    person = NULL;
    time = 0;
    numArrivals++;
} 
Arrival::~Arrival() {
    //destructor
}

Arrival::Arrival(Person *newPatient, int Ptime) {
    person = newPatient;
    time = Ptime;
    numArrivals++;
} 

Person* Arrival::getPatient() {
    return person;
} 
void Arrival::print() {
    std::cout << "Patient: " << person->getPatientNumber() << "arrived at " << time << endl;
    std::cout << endl;
}