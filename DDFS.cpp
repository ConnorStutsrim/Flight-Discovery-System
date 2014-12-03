#include "DDFS.h"

DDFS::DDFS() {
	
}


void DDFS::addFlight(Flight newFlight) {
	int i = 0;
	bool duplicate = false;
	string newDepartCityName = newFlight.getDepartureCity();
	for (i; i < departureNodes.size(); i++) {
		if (departureNodes[i].CityName == newDepartCityName) {
			duplicate = true;
			break;
		}
	}
	if (duplicate) {
		departureNodes[i].addFlight(newFlight);
	}
	else {
		DepartNode newDepartureNode;
		newDepartureNode.setCityName(newDepartCityName);
		newDepartureNode.addFlight(newFlight);
		departureNodes.push_back(newDepartureNode);
	}

}

void DDFS::print() {
	for (int i = 0; i < departureNodes.size(); i++) {
		departureNodes[i].print();
	}
}