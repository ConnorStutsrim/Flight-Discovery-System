#include <string>		//string
#include <iostream>		//cin/cout
#include <vector>		//vector
#include <fstream>		//read/write file
using namespace std;

#include "Trip.h"
#include "Flight.h"

Trip::Trip(){}
Trip::~Trip(){}

int Date(string str){
	int x = (str[9] - 48) * 10000 + (str[8] - 48) * 100000 + (str[7] - 48) * 1000000 + (str[6] - 48) * 10000000 + (str[4] - 48) * 1000 + (str[3] - 48) * 100 + (str[0] - 48) * 10 + (str[1] - 48);
	return x;
}

void Trip::addFlight(Flight inputFlight) {
	itinerary.push_back(inputFlight);
}

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