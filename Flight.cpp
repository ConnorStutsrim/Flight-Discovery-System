#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Flight.h"
#include "Function.h"


/*
Constructors
*/

//Default Constructor
Flight::Flight() {
	departureCity = "No_City";
	destinationCity = "No_City";
	cost = "$0";
	costInt=0;
	departureTime = "0:00am";
	departureTimeInt=0;
	destinationTime = "0:00am";
	destinationTimeInt=0;
}

//Value-input constructor
Flight::Flight(string departureCity, string destinationCity, string cost, string departureTime, string destinationTime){
	this->departureCity = departureCity;
	this->destinationCity = destinationCity;
	this->cost = cost;
	string temp=cost;
	temp[0]='0';
	istringstream (temp)>>costInt;
	this->departureTime = departureTime;
	departureTimeInt=Time(departureTime);
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