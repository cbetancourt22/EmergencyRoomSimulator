//#include "pch.h"
#include "doctor.h"

doctor::doctor() {
	busy = false;
	workingTime = 0;
}
bool doctor::isBusy() {
	return busy;
}
bool doctor::treat(person & patient) {
	std::cout << "__Patient " << patient.getName() << " with severity " << patient.getSeverity() << " is being treated by a doctor." << std::endl;
	std::cout << "__They have been treated for " << workingTime << " minutes." << std::endl;
	std::cout << std::endl;
	
	if (!busy) { //if the doctor is just starting to treat the patient
		busy = true; //the doctor is now busy
		
	}
	if (workingTime >= patient.getSeverity()) { //a severity of n takes n minutes to cure so if the working time == the severity the patient can be cured
		busy = false; //the doctor is now not busy
		patient.cure(); //cure the patient 
		workingTime = 0; //reset the doctors working time
		return true; //the patient is cured. return true
	}
	else {
		workingTime++; //the patient is not cured. Credit one minute to the working time
		return false; //the patient is not cured return false
	}
}
