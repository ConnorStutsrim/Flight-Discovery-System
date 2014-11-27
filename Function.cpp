#include <string>		//string
#include <iostream>		//cin/cout
#include <vector>		//vector
#include <fstream>		//read/write file
using namespace std;

#include "Function.h"
#include "Flight.h"

void readFile(char const *filename){
	vector<Flight> flights;
	string temp,departureCity,destinationCity,departureTime,destinationTime,cost;
	ifstream ddfs;
	ddfs.open(filename);
	while(1){
		if (!(ddfs>>departureCity)){
			ddfs.close();
			break;
		}
		else{
			ddfs>>destinationCity;
			ddfs>>departureTime;
			ddfs>>destinationTime;
			ddfs>>cost;
			Flight Aflight(departureCity, destinationCity, cost, departureTime, destinationTime);
			flights.push_back(Aflight);
		}
	}
	userInput();
}
void userInput(){

}

//convert time string to int using ascii code
int Time(string Atime){
	int TimeInt;
	if (Atime.length()==7){
		TimeInt=((Atime[0]-48)*600)+((Atime[1]-48)*60)+((Atime[3]-48)*10)+(Atime[4]-48);
		if (Atime[5]=='p'){
			TimeInt=TimeInt+720;
		}
	}
	else{
		TimeInt=(Atime[0]-48)*60+(Atime[2]-48)*10+(Atime[3]-48);
		if (Atime[4]=='p'){
			TimeInt=TimeInt+720;
		}
	}
	return TimeInt;
}