#include "DestNode.h"

DestNode::DestNode() {
	CityName = "No City";
}

void DestNode::setCityName(string City) {
	CityName = City;
}

void DestNode::addFlight(Flight newFlight) {
	FlightList.push_back(newFlight);
}
