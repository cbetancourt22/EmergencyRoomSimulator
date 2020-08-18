////////////////////////////////
// title: Emergency Room Simulator
// descr: Allows a user to define an emergency room with nurses, doctors and arrival rate
//        simulates one week of run time
// Author: Xavi, Apoorv, Caleb
////////////////////////////////

#include "EmergencyRoom.h"
#include "doctor.h"
#include "person.h"
#include "Nurse.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
	void setUpER(EmergencyRoom * room); //takes in pointer to Emergency Room, lets user define the number of nurses, doctors and number of patients arriving per hour
	void updateRoomQueue(EmergencyRoom * r, int seed, std::vector<std::string>* names); //takes in a pointer to the emergency room, a seed time for the random number generator and the pool of names 
																						//Adds arriving person(s) to the priority queues

	void openFile(std::vector<std::string> * names); //opens the file of names and puts them in the vector
	std::string getRandName(std::vector<std::string> * names, int seed); //returns a random name from the vector of names given said vector and a seed (clock tick)

int main() {
	std::vector<std::string> names; //to hold the name of our residents
	EmergencyRoom room;
	EmergencyRoom* ER = &room;
	setUpER(ER); //let the user define the emergency room
	openFile(&names); //fill our vector with names
	
	int runTime = 7 * 24 * 60;

	for (int i = 0; i < runTime; i++) { //for each minute
		updateRoomQueue(ER, i, &names); //patients arrive
		ER->takePatients(); //doctors and nurses take the next patient
		ER->treatPatients(); //patients are treated

	}
	ER->displayRecords();
	
}

void setUpER(EmergencyRoom * room) {
	
	cout << "Welcome to the Emergency Room Simulator" << endl;
	cout << endl;
	int numDocs; 
	cout << "How many doctors? ";
	cin >> numDocs; //user defines the number of doctors
	int numNurse;
	cout << "How many nurses? ";
	cin >> numNurse; //user defines number of nurses

	cout << "How many patients per hour? (cap 60) " << endl;
	int numPerhour;
	cin >> numPerhour; //user defines the number of patients per hour
	if (numPerhour > 60) { //user error check
		numPerhour = 60;
	}
	room->setPatientsPerHour(numPerhour); //set the number of patients per hour

	for (int i = 0; i < numNurse; i++) { //fill the ER with nurses and doctors
		room->addNurse(new Nurse);
	}
	for (int i = 0; i < numDocs; i++) {
		room->addDoctor(new doctor);
	}

}
void updateRoomQueue(EmergencyRoom * r, int seed, std::vector<std::string>* names) {
	int clockTick = seed;
	seed++;
	srand(seed); //send our seed value to create random numbers
	int prob = rand() % 10; //probablity for what type of patient arrives
	
	
	if (clockTick % 60 < r->getPatientsPerHour()) { //true if a person should be comming
		if (prob < 7) {//70% chance
						//low sev
			int sev = rand() % 10;
			r->addPatient(new person(sev, getRandName(names, seed))); //create and add a new person to the ER with a random name
		}
		if (prob > 6 && prob < 9) { //20% chance
									//medium sev
			int sev = 11 + (std::rand() % (15 - 11 + 1)); //sev should be a number between 11 and 15
			r->addPatient(new person(sev, getRandName(names, seed))); //create and add a new person to the ER with a random name
		}
		if (prob > 8) { //10% chance
						//high sev
			int sev = 16 + (std::rand() % (20 - 16 + 1)); //sev should be a number between 16 and 20
			r->addPatient(new person(sev, getRandName(names, seed))); //create and add a new person to the ER with a random name
		}

	}
}

void openFile(std::vector<std::string>* names)
{
	std::string line;
	std::ifstream FirstNamestxt;

	//FirstNamestxt.open(".\\\\data\\\\Residents_of_273ville.txt"); //visual studio code
	FirstNamestxt.open(".\\Residents_of_273ville.txt"); //visual studio 2019

	if (FirstNamestxt.fail()) //if we get an error
	{
		std::cout << "Couldn't open the file" << std::endl; //notify user
	}

	if (FirstNamestxt.is_open()) //if we open the file
	{
		while (getline(FirstNamestxt, line))
		{
			names->push_back(line); //put each name in our vector of names
		}
	}
	FirstNamestxt.close(); //close the file
	
}
std::string getRandName(std::vector<std::string>* names, int seed)
{
	srand(seed); //uses the clock tick as a random see
	int randNum = rand() % 2000; //pick a number between 0 and 2000
	std::string randomName = names->at(randNum); //grab the name at our random index

	return randomName; //return this name
}