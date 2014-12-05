#ifndef DESTNODE_H_
#define DESTNODE_H_

#include "Flight.h"
#include <string>
#include <vector>

class DestNode {
private:
	

public:
	DestNode();
	std::string CityName;
	std::vector<Flight> FlightList;
	void setCityName(string);
	void addFlight(Flight);
};

#endif