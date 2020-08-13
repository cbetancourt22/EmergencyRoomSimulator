////////////////////////////////
// title: EmergencyRoom.h
// descr: Defines and Emergency room which has doctors, nurses and patients
//        doctors and nurses can take patients and treat them and statistics about the simulation
//        are defined and printed from the emergency room
// Author: Xavi, Apoorv, Caleb
////////////////////////////////
#ifndef EMERGENCYROOM_H
#define EMERGENCYROOM_H
#include <queue>
#include "Personnel.h"
#include <vector>
#include "person.h"
#include <iostream>
#include <set>
#include "Nurse.h"
#include "doctor.h"
#include <iterator>
#include <map>
//changed
class EmergencyRoom
{
public:
	EmergencyRoom();
	void addPatient(person* p); //probably use with arrival object?
	void addNurse(Nurse* n); //adds pointer to nurse n into the set
	void addDoctor(doctor* d); //adds pointer to doctor d into the set
	void setPatientsPerHour(int num); //takes in and interger and sets it as the number of patients per hour desired
	void takePatients(); //updates for each tick. Non busy doctors and nurses will take a patient
	void treatPatients(); //doctors and nurses with patient will treat them for one time tick
	~EmergencyRoom();
	int getPatientsPerHour(); 
	// Records from Patients
	void printPatients(); //prints the names and statistics for each patient
	void searchName(); //finds patient by name
	void displayRecords(); // Menu of options
	void printAvgVisitTime(); //prints the average visit time for each patient
							//because we were unable to implement time update for the people in the queue in time of the due date
							//the average time really ends up being the average severity as time should = time in queue + time to treat (severity) but we only got severity to work


private:
	std::vector<person*> residents; //holds the 2000 persons that are in the town of Simville (maybe change to a map or set etc to meet requirments of project
	std::set<Nurse*> nurses; //holds the nurses
	std::set<doctor*> doctors; //holds the doctors
	std::priority_queue<person*> high_sev; //can only be treated by doctors (severity 11-20)
	std::priority_queue<person*> low_sev; //can be treated by both (severity 1-10)
	int numPatientsPerHour;
	std::map<Personnel*, person*> beingTreated; //patients with doctor or nurse
	std::map<std::string, person*> residentsTreated; //patients who have visited the ER
};

#endif