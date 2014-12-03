#include "DepartNode.h"

DepartNode::DepartNode() {

}

void DepartNode::setCityName(string City) {
	CityName = City;
}

void DepartNode::addFlight(Flight newFlight) {
	int i = 0;
	bool duplicate = false;
	string newFlightCityName = newFlight.getDestinationCity();
	for (i; i < DestinationList.size(); i++) {
		if (DestinationList[i].CityName == newFlightCityName) {
			duplicate = true;
			break;
		}
	}
	FlightList.push_back(newFlight);
	if (duplicate) {
		DestinationList[i].addFlight(newFlight);
	}
	else {
		DestNode newDestination;
		newDestination.setCityName(newFlightCityName);
		newDestination.addFlight(newFlight);
		DestinationList.push_back(newDestination);
	}
	
}

void DepartNode::print() {
	for (int i = 0; i < FlightList.size(); i++) {
		FlightList[i].print();
	}
}