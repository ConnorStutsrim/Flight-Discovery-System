#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <iostream>
using namespace std;

class Flight{
private:
	string departureCity;
	string destinationCity;
	string cost;
	int costInt;
	string departureTime;		//Times are implemented as the number of minutes after midnight
	int departureTimeInt;
	string destinationTime;
	int destinationTimeInt;

public:
	/*
	Constructors
	*/
	Flight();
	Flight(string, string, string, string, string);	//Construct a flight for the fiven values
	Flight(string);							//Construct a flight from a single string of information
};

#endif