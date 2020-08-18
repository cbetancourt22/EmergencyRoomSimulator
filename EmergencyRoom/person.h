////////////////////////////////
// title: person.h
// descr: used to define a person/patient for the ER
//        a person can get sick, be cured and statistice about their visits to the ER can be printed
// Author: Xavi, Apoorv, Caleb
////////////////////////////////
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class person
{
private:
	std::string name; //holds the persons name
	std::vector<std::string> names; //holds the 2000 persons that are in the town of Simville
	float numVisits; //number of times visiting the ER
	bool sick; //the person is sick if this is true
	bool everSick; //the person has been sick if this true
	int severity; //if not sick == 0 if sick it indicates how sick from 1-20
	float totalTime; //total amount of time spent at the ER

public:
	person();
	person(int sev, std::string name); //takes in a severity and name; creates a person with them
	std::string getName(); //returns the persons names
	bool isSick(); //returns if the person is sick
	bool wasSick(); //returns if the person has ever been sick
	void getSick(int severity); //makes patient sick with passed in int severity
	person* cure(); //cures the person and returns a pointer to them
	bool operator < (person const& other); //overload of the < operator used to sort for priority queue
	int getSeverity(); //returns the persons severity 
	~person();
	float getAvgVisitTime(); //returns the calculation of the persons average visit time
	int getNumVisits(); //returns the number of visits a person makes to the ER

	//failed functions to keep track of time in queue
	void spendTime(); //used to increment total time by 1
	void loseTime();//used to deincrement total time by 1
};

#endif // PERSON_