#include "Nurse.h" 
Nurse::Nurse(){
	busy = false;
	workingTime = 0;
}
bool Nurse::isBusy() { //returns true if the nurse is with a patient
	return busy; 
}

bool Nurse::treat(person & patient) {
	std::cout << "__Patient " << patient.getName() << " with severity " << patient.getSeverity() << " is being treated by a nurse." << std::endl;
	std::cout << "__They have been treated for " << workingTime << " minutes." << std::endl;
	std::cout << std::endl;
	if (!busy) { //if the nurse is just starting to treat the patient
		busy = true; //the nurse is now busy
		
	}
	if (workingTime == patient.getSeverity()) { //a severity of n takes n minutes to cure so if the working time == the severity the patient can be cured
		patient.cure(); //cure the patient 
		busy = false; //the nurse is now not busy
		workingTime = 0; //reset working time
		return true; //the patient is cured. return true
	}
	else {
	workingTime++; //the patient is not cured. Credit one minute to the working time
		return false; //the patient is not cured return false
	}
}
bool Nurse::canTreat(int sev) { 
	if (sev <= 10) { //if the patients severity is 10 or less the nurse can treat the patient
		return true;
	}
	return false; //otherwise they cannot treat
}