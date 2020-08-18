////////////////////////////////
// title:Personnel.h 
// descr: Abstract base class used to force doctor and Nurse
//        to implement methods to treat and return if they are with patient
// Author: Xavi, Apoorv, Caleb
////////////////////////////////
#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <iostream>
#include <string>
#include "person.h"
class Personnel
{
//Abstract base class
private:
	virtual bool treat(person & patient) = 0; //both doctors and nurses need to be able to treat patients
	virtual bool isBusy() = 0; //returns if the doctor or nurse is busy
};


#endif