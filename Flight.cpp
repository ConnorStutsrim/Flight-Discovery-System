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
	// Unifying String
	char TimeString[7];
	int timeInt;
	if (Atime.length() != 7) {
		TimeString[0] = '0';
		for (int i = 1; i <= 6; i++) {
			TimeString[i] = Atime[i - 1];
		}
	}
	else {
		if (Atime[1] == '2') {
			TimeString[0] = '0';
			TimeString[1] = '0';
			for (int i = 2; i <= 6; i++) {
				TimeString[i] = Atime[i];
			}
		}
		else {
			for (int i = 0; i <= 6; i++) {
				TimeString[i] = Atime[i];
			}
		}
	}
	// Calculating timeInt;
	if (TimeString[5] == 'p') {
		timeInt += 720;
	}
	timeInt += ((TimeString[0] * 600) + (TimeString[1] * 60) + (TimeString[3] * 10) + TimeString[4]);
	return timeInt;
}

// Prints the flight details to cout
// Prints flight detials in format <Departure City> <Destination City> <Departure Time> <Destination Time> $<cost>
void Flight::print() {
	cout << departureCity << " " << destinationCity << " " << departureTime << " " << destinationTime << " $" << cost << endl;
}

Flight::~Flight() {

}
