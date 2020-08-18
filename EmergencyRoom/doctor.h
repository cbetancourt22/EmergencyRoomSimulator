////////////////////////////////
// title:doctor.h 
// descr: defines a doctor that works in an emergency room
//        doctor is a subclass of Personnel and can be used to treat patients
// Author: Xavi, Apoorv, Caleb
////////////////////////////////
#include "Personnel.h"
#include <string>
#ifndef DOCTOR_H
#define DOCTOR_H

class doctor : public Personnel {
public:
	doctor();
	bool treat(person & patient); //returns when/if patient is treated, uses the cure function on the patient that is passed in.
	bool isBusy(); //returns whether the doctor is with a patient

private:
	bool busy; //holds if the doctor is with a patient
	int workingTime; //time spent with a patient

};
#endif