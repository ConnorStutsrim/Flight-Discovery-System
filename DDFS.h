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
	
public:
	DDFS();
	void JustGetMeThereToday(string start,string prevCity ,string dest, int currentTime);
	void setFlightVector();
	void addFlight(Flight);
	void createDataVector();
	void print();
	void printDataVector();

};

#endif
