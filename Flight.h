#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight{
private:
	string departureCity;
	string destinationCity;
	int cost;
	int departureTime;		//Times are implemented as the number of minutes after midnight
	int destinationTime;

public:
	/*
	Constructors
	*/
	Flight();
	Flight(string, string, int, int, int);	//Construct a flight for the fiven values
	Flight(string);							//Construct a flight from a single string of information
}

#endif