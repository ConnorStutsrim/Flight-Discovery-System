#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "Time.h"

class Time;
class Flight{
private:
	

public:
	/*
	Constructors
	*/
	Flight();
	Flight(string, string, float, int, int);	//Construct a flight for the given values
	Flight(string, string, float, Time, Time);
	Flight(string, string, string, string, string);
	Flight(string);	

	std::string departureCity;
	std::string destinationCity;
	float cost;
	Time departureTime;		//Times are implemented as the number of minutes after midnight
	Time destinationTime;
	int duration;
							//Construct a flight from a single string of information

	/*
	Utility functions
	*/
	int timeStringToInt(string Atime);
	void print();
	//Destructor
	~Flight();
};

#endif
