#ifndef TRIP_H
#define TRIP_H

#include <vector>		//vector
using namespace std;

#include "Flight.h"

class Trip{
private:
	vector<Flight> flights;
	string depart;
	string dest;
	string depDate;
	string returnDate;
	string depTime;
	string returnTime;
public:
	Trip();
	~Trip();
	void readFile(char const *);
	void userInput();
};

bool checkCity(string);
bool checkDate(string);
bool checkTime(string);
int Date(string);

#endif