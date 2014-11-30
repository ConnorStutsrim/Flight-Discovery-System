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
	cost = "$0";
	costInt=0;
	departureTime = "0:00am";
	destinationTime = "0:00am";
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

bool Flight::checkDep(string str){
	if (str==departureCity){
		return 1;
	}
	return 0;
}

bool Flight::checkDes(string str){
	if (str==destinationCity){
		return 1;
	}
	return 0;
}

//convert time string to int using ascii code
int Time(string Atime){
	int TimeInt;
	if (Atime.length()==7){
		TimeInt=((Atime[0]-48)*600)+((Atime[1]-48)*60)+((Atime[3]-48)*10)+(Atime[4]-48);
		if (Atime[5]=='p'){
			TimeInt=TimeInt+720;
		}
	}
	else{
		TimeInt=(Atime[0]-48)*60+(Atime[2]-48)*10+(Atime[3]-48);
		if (Atime[4]=='p'){
			TimeInt=TimeInt+720;
		}
	}
	return TimeInt;
}
