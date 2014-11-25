#include "Flight.h"

using namespace std;

/*
Constructors
*/

//Default Constructor
Flight::Flight() {
	departureCity = "No City";
	destinationCity = "No City";
	cost = 0;
	departureTime = 0;
	destinationTime = 0;
}

//Value-input constructor
Flight::Flight(string departureCity, string destinationCity, int cost, int departureTime, int destinationTime){
	this->departureCity = departureCity;
	this->destinationCity = destinationCity;
	this->cost = cost;
	this->departureTime = departureTime;
	this->destinationTime = destinationTime;
}

//String constructor
Flight::Flight(string inputString) {
	int stringLength = inputString.length();
	int parsed = 0;
	for (int i = 0; i <= 5; i++) {
		int tokenLength = 0;
		while (inputString[parsed + tokenLength] != ' ' && inputString[parsed + tokenLength] != '/0') {
			tokenLength++;
		}
	}
}