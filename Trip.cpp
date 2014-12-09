#include <string>		//string
#include <iostream>		//cin/cout
#include <vector>		//vector
#include <fstream>		//read/write file
using namespace std;

#include "Trip.h"
#include "Flight.h"

Trip::Trip(){}
Trip::~Trip(){}

// Takes string representation of date and returns integer representaiton of date
int Date(string str){
	int x = (str[9] - 48) * 10000 + (str[8] - 48) * 100000 + (str[7] - 48) * 1000000 + (str[6] - 48) * 10000000 + (str[4] - 48) * 1000 + (str[3] - 48) * 100 + (str[0] - 48) * 10 + (str[1] - 48);
	return x;
}

// Takes a Flight argument and adds a copy of that flight to the itinerary structure
void Trip::addFlight(Flight inputFlight) {
	itinerary.push_back(inputFlight);
}

// Handles user input of trip information
// Prompts the user for input for trip fields (Departure City, Destination City, Departure Date, Departure Time, 
// Return Date, and Return Time) and stores that information in the appropriate fields. Also checks that user 
// input is in the correct format and can be interpreted.
void Trip::userInput(){
	string temp;

	//Departure Information
	cout << "Please Specify Departure Information: " << endl;
	while (1){
		cout << "Departure_City: ";
		getline(cin, temp);
		if (checkCity(temp)){
			depart = temp;
			break;
		}
		else{ cout << "Wrong Format!" << endl; }
	}

	while (1){
		cout << "Destination_City: ";
		getline(cin, temp);
		if (checkCity(temp)){
			dest = temp;
			break;
		}
		else{ cout << "Wrong Format!" << endl; }
	}

	while (1){
		cout << "Departure Date(DD/MM/YYYY): ";
		getline(cin, temp);
		if (checkDate(temp)){
			depDate = temp;
			break;
		}
		else{ cout << "Wrong Format!" << endl; }
	}

	while (1){
		cout << "Earliest Acceptable Departure Time(HH:MMam/pm): ";
		getline(cin, temp);
		if (checkTime(temp)){
			depTime = temp;
			break;
		}
		else{ cout << "Wrong Format!" << endl; }
	}

	//Return Trip Information
	cout << "Please Specify Return Trip Information: " << endl;

	while (1){
		cout << "Return Date(DD/MM/YYYY): ";
		getline(cin, temp);
		if (checkDate(temp)){
			returnDate = temp;
			break;
		}
		else{ cout << "Wrong Format!" << endl; }
	}

	while (1){
		cout << "Earliest Acceptable Return Time(HH:MMam/pm): ";
		getline(cin, temp);
		if (checkTime(temp)){
			returnTime = temp;
			break;
		}
		else{ cout << "Wrong Format!" << endl; }
	}

}

// Departure City getter
string Trip::getDepartCity()
{
	return depart;
}

// Destination City getter
string Trip::getDestCity()
{
	return dest;
}

// Departure City getter
int Trip::getDepTime()
{
// Unifying String
char TimeString[7];
int timeInt;
if (depTime.length() != 7) {
	TimeString[0] = '0';
	for (int i = 1; i <= 6; i++) {
		TimeString[i] = depTime[i - 1];
	}
}
else {
	if (depTime[1] == '2') {
		TimeString[0] = '0';
		TimeString[1] = '0';
		for (int i = 2; i <= 6; i++) {
			TimeString[i] = depTime[i];
		}
	}
	else {
		for (int i = 0; i <= 6; i++) {
			TimeString[i] = depTime[i];
		}
	}
}
// Calculating timeInt;
if (TimeString[5] == 'p') {
	timeInt += 720;
}
timeInt += (((TimeString[0] - 48) * 600) + ((TimeString[1] - 48) * 60) + ((TimeString[3]  - 48)* 10) + (TimeString[4] - 48));
return timeInt;
}

// Return time getter
int Trip::getReturnTime() {
// Unifying String
	char TimeString[7];
	int timeInt;
	if (returnTime.length() != 7) {
		TimeString[0] = '0';
		for (int i = 1; i <= 6; i++) {
			TimeString[i] = returnTime[i - 1];
		}
	}
	else {
		if (returnTime[1] == '2') {
			TimeString[0] = '0';
			TimeString[1] = '0';
			for (int i = 2; i <= 6; i++) {
				TimeString[i] = returnTime[i];
			}
		}
		else {
			for (int i = 0; i <= 6; i++) {
				TimeString[i] = returnTime[i];
			}
		}
	}
	// Calculating timeInt;
	if (TimeString[5] == 'p') {
		timeInt += 720;
	}
	timeInt += (((TimeString[0] - 48) * 600) + ((TimeString[1] - 48) * 60) + ((TimeString[3]  - 48)* 10) + (TimeString[4] - 48));
	return timeInt;
}
