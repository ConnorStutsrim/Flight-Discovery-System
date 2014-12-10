#include "DepartNode.h"

DepartNode::DepartNode() {

}

void DepartNode::setCityName(string City) {
	CityName = City;
}

void DepartNode::addFlight(Flight newFlight) {
	int i = 0;
	bool duplicate = false;
	string newFlightCityName = newFlight.destinationCity;
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

Flight DepartNode::nextFlight(std::string destCityName, Time currentTime) {
  Flight retFlight;
currentTime.timeInt = 0; //take this out once time is fixed
  for (int i = 0; i < DestinationList.size(); i++) {
    if (DestinationList[i].CityName == destCityName) {
      for (int j = 0; j < DestinationList[i].FlightList.size(); j++) {
	if (DestinationList[i].FlightList[j].departureTime.timeInt > currentTime.timeInt) {
	  retFlight = DestinationList[i].FlightList[j];
	  break;
	}
      }
    }
  }
  return retFlight; 
}

void DepartNode::print() {
	for (int i = 0; i < FlightList.size(); i++) {
		FlightList[i].print();
	}
}
