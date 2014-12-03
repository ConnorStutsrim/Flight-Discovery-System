#ifndef DDFS_H_
#define DDFS_H_

#include "DepartNode.h"
#include <vector>

class DDFS {
private:
	std::vector<DepartNode> departureNodes;
	
public:
	DDFS();

	void addFlight(Flight);
	void print();
};

#endif