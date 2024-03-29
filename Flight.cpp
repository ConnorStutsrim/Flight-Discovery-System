#include <string>
#include <iostream>
#include <sstream>

#include "Flight.h"


/*
Constructors
*/

//Default Constructor
Flight::Flight() {
	departureCity = "No_City";
	destinationCity = "No_City";
	cost = 0;
	departureTime = 0;
	destinationTime = 0;
	duration = 0;
}

//				Value-input constructors
//string, float, int constructor
Flight::Flight(string departureCity, string destinationCity, float cost, int departureTime, int destinationTime){
	this->departureCity = departureCity;
	this->destinationCity = destinationCity;
	this->cost = cost;
	this->departureTime = Time(departureTime);
	this->destinationTime = Time(destinationTime);
	this->duration = destinationTime - departureTime;
}
//string, float, string constructor
Flight::Flight(string departureCity, string destinationCity, float cost, Time departureTime, Time destinationTime){
	this->departureCity = departureCity;
	this->destinationCity = destinationCity;
	this->cost = cost;
	this->departureTime = departureTime;
	this->destinationTime = destinationTime;
	this->duration = destinationTime - departureTime;
}
//string, string, string constructor
Flight::Flight(string departureCity, string destinationCity, string cost, string departureTime, string destinationTime){
	this->departureCity = departureCity;

	this->destinationCity = destinationCity;
	
	string correctedCostString = cost.substr(1);
	float costFloat = std::stof(correctedCostString);
	this->cost = costFloat;
	
	this->departureTime = Time(timeStringToInt(departureTime));
	
	this->destinationTime = Time(timeStringToInt(destinationTime));
	
	this->duration = this->destinationTime - this->departureTime;
}

//String constructor
Flight::Flight(string inputString) {

}

/*
Utility Functions
*/

// Converts time string to int
// Takes a string formatted as <HH:mm><am/pm>
// Returns an integer number of minutes since midnight
int Flight::timeStringToInt(string Atime){
	int TimeInt;
	if (Atime.length() == 7){
		TimeInt = ((Atime[0] - 48) * 600) + ((Atime[1] - 48) * 60) + ((Atime[3] - 48) * 10) + (Atime[4] - 48);
		if (Atime[5] == 'p'){
			TimeInt = TimeInt + 720;
		}
	}
	else{
		TimeInt = (Atime[0] - 48) * 60 + (Atime[2] - 48) * 10 + (Atime[3] - 48);
		if (Atime[4] == 'p'){
			TimeInt = TimeInt + 720;
		}
	}
	if (TimeInt >= 1440 || (TimeInt>=720&&TimeInt<780)) {
		TimeInt -= 720;
	}
	return TimeInt;
}

// Prints the flight details to cout
// Prints flight detials in format <Departure City> <Destination City> <Departure Time> <Destination Time> $<cost>
void Flight::print() {
	cout << departureCity << " " << destinationCity << " " << departureTime << " " << destinationTime << " $" << cost << endl;
}

Flight::~Flight() {

}
