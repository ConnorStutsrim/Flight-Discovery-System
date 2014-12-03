#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include "Time.h"


class Flight{
private:
	std::string departureCity;
	std::string destinationCity;
	float cost;
	Time departureTime;		//Times are implemented as the number of minutes after midnight
	Time destinationTime;

public:
	/*
	Constructors
	*/
	Flight();
	Flight(string, string, float, int, int);	//Construct a flight for the given values
	Flight(string, string, float, Time, Time);
	Flight(string, string, string, string, string);
	Flight(string);								//Construct a flight from a single string of information

	/*
	Utility functions
	*/
	string getDepartureCity();	
	string getDestinationCity();
	string getDepartureTimeString();
	string getDestinationTimeString();
	string getCostString();
	int timeStringToInt(string Atime);
	void print();
	//Destructor
	~Flight();
};

#endif