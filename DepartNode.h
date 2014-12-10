#ifndef DEPARTNODE_H_
#define DEPARTNODE_H_

#include "DestNode.h"
#include <string>
#include <vector>

class DepartNode {
private:
	

public:
	DepartNode();
	
	string CityName;
	vector<Flight> FlightList;
	vector<DestNode> DestinationList;
	
	void setCityName(string);
	void addFlight(Flight);
	Flight nextFlight(std::string, Time);
	Flight nextFlightAnyTime(std::string, Time);
	void print();
};

#endif
