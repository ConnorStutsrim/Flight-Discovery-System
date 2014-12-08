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
	int cost;	//variable used for DDFS:FewestHops()
	int hops;	//variable used for DDFS:CheapestTrip()
	
public:
	DDFS();
	void JustGetMeThereToday(string start,string prevCity ,string dest, int currentTime);
	void FewestHops(string start,string prevCity ,string dest, int currentTime);
	void ShortestTrip(string start,string prevCity ,string dest, int currentTime);
	void CheapestTrip(string start,string prevCity ,string dest, int currentTime);
	void setFlightVector();
	void addFlight(Flight);
	void createDataVector();
	void print();
	void printDataVector();

};

#endif
