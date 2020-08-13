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
