#include <string>
#include <iostream>
#include <sstream>
using namespace std;

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
}

//Value-input constructor
Flight::Flight(string departureCity, string destinationCity, float cost, int departureTime, int destinationTime){
	this->departureCity = departureCity;
	this->destinationCity = destinationCity;
	this->cost = cost;
	this->departureTime = Time::Time(departureTime);
	this->destinationTime = Time::Time(destinationTime);
}

Flight::Flight(string departureCity, string destinationCity, float cost, Time departureTime, Time destinationTime){
	this->departureCity = departureCity;
	this->destinationCity = destinationCity;
	this->cost = cost;
	this->departureTime = departureTime;
	this->destinationTime = destinationTime;
}

Flight::Flight(string departureCity, string destinationCity, string cost, string departureTime, string destinationTime){
	this->departureCity = departureCity;

	this->destinationCity = destinationCity;
	
	string::size_type sz;
	float costFloat = stof(cost, &sz);
	this->cost = costFloat;
	
	this->departureTime = Time(timeStringToInt(departureTime));
	
	this->destinationTime = Time(timeStringToInt(destinationTime));
}

//String constructor
Flight::Flight(string inputString) {

}

//convert time string to int using ascii code
int timeStringToInt(string Atime){
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
	return TimeInt;
}