////////////////////////////////
// title:nurse.h 
// descr: defines a nurse that works in an emergency room
//        nurse is a subclass of Personnel and can be used to treat patients
// Author: Xavi, Apoorv, Caleb
////////////////////////////////
#include "Personnel.h"
#include <string>

#ifndef NURSE_H
#define NURSE_H
//changed
class Nurse: public Personnel {
public:
	Nurse();	
	bool treat(person &patient); //takes in a patient, returns true when the patient is curred and false when still treated
	bool canTreat(int sev); //returns if the nurse can treat the illness (sev < 11)
	bool isBusy(); //returns if the nurse is busy
private:
	bool busy; //holds the value of if the nurse is with a patient
	int workingTime; //time spent with an individual patient

};
#endif