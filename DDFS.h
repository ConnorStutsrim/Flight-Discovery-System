#ifndef DDFS_H_
#define DDFS_H_
#include "DepartNode.h"
#include <vector>

struct data{
string currentCity;
int cumulativeTime;
string previousCity;
};

class DDFS {
private:
	std::vector<data> dataVector;
	std::vector<DepartNode> departureNodes;
	std::vector<Flight> flights;
	string startingCity;
	string destinationCity;
	bool firstTravelIteration;
	Time startingTime;
	char iti;
	
public:
	DDFS();
	void JustGetMeThereToday(string start,string prevCity ,string dest, int currentTime);
	void FewestHops(string start,string prevCity ,string dest, int currentTime, int hops);
	void ShortestTrip(string start,string prevCity ,string dest, int currentTime);
	void CheapestTrip(string start,string prevCity ,string dest, int currentTime, int cost);
	void setFlightVector();
	void addFlight(Flight);
	void printFlightVector();
	void createDataVector(string city);
	void print();
	void printDataVector();

};

#endif
