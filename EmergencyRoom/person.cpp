#include "person.h"
#include <ctime>
person::person() { //create a person with default values
	sick = false;
	everSick = false;
	severity = 0;
	numVisits = 0;
	totalTime = 0;
}

person::person(int sev, std::string name) { //make a person
	this->name = name; //set the name
	totalTime = 0; //start time
	if (sev > 0) { //if they have a valid severity
		this->getSick(sev); //make them sick with it
	}

}

//the failed functions
void person::spendTime() {//!!!!
	totalTime++; //add one to total time
}
void person::loseTime() {//!!!!
	totalTime--; //remove one from total time
}






bool person::isSick() {
	return sick; //return the bool value of if they are sick
}
bool person::wasSick() {
	return everSick; //return the bool value of if they were ever sick
}
void person::getSick(int severity) { 
	sick = true; //person is now sick
	this->severity = severity; //set their seveity to the passed in value
	everSick = true; //they have now been sick
	totalTime += severity; //add severity to the total time (it takes a doctor severity amount of time to cure the patient
	
}

person * person::cure() {
	sick = false; //the person is now cured
	severity = 0; //now severity
	std::cout <<"--" << name << " has been cured! " << std::endl;
	std::cout << std::endl;
	numVisits++; //increase number of visits
	return this; //return itself
}

bool person::operator < (person const& other) {
	return this->severity < other.severity; //compare the severities
}

int person::getSeverity() {
	return severity;
}
std::string person::getName() {
	return name;
}
person::~person() {
	
}
float person::getAvgVisitTime() {
	if (numVisits != 0) //prevent divide by zero from patients who have not finished their visit at end of run time
		return totalTime / numVisits;
	else
		return totalTime;
}
int person::getNumVisits() {
	return numVisits;
}