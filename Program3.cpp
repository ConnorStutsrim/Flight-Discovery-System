/*
	CS 240 Program3
	Group 6C
	group members:
		Connor Stutsrim
		Robert Valenti
		Xin Xin
*/
#include <iostream>
#include <fstream>
using namespace std;

#include "Trip.h"

bool checkCity(string str){
	for (int i = 0; i < str.length(); ++i){
		if (str[i] != '_' && (str[i]<65 || str[i]>90) && (str[i]<97 || str[i]>122)){
			return 0;
		}
	}
	if (str.length() == 0){
		return 0;
	}
	return 1;
}
bool checkDate(string str){
	if (str[0]>47 && str[0]<52 && str[1]>47 && str[1]<58 && str[2] == '/' && (str[3] == '0' || str[3] == '1') && str[4]>47 && str[4]<58 && str[5] == '/' && str[6]>47 && str[6]<58 && str[7]>47 && str[7]<58 && str[8]>47 && str[8]<58 && str[9]>47 && str[9]<58){
		return 1;
	}
	return 0;
}
bool checkTime(string str){
	if (str[0] == '0'){
		if (str[1]>47 && str[1]<58 && str[2] == ':' && str[3]>47 && str[3]<55 && str[4]>47 && str[4]<58 && (str[5] == 'a' || str[5] == 'p') && str[6] == 'm'){
			return 1;
		}
	}
	if (str[0] == '1'){
		if (str[1]>47 && str[1]<51 && str[2] == ':' && str[3]>47 && str[3]<55 && str[4]>47 && str[4]<58 && (str[5] == 'a' || str[5] == 'p') && str[6] == 'm'){
			return 1;
		}
	}
	return 0;
}

//Will be used to construct the Graph flightSchedule
void readFile(char const *filename, /*Graph &flightSchedule*/){
	string temp, departureCity, destinationCity, departureTime, destinationTime, cost;
	ifstream ddfs;
	ddfs.open(filename);
	while (1){
		if (!(ddfs >> departureCity)){
			ddfs.close();
			break;
		}
		else{
			ddfs >> destinationCity;
			ddfs >> departureTime;
			ddfs >> destinationTime;
			ddfs >> cost;
			Flight Aflight(departureCity, destinationCity, cost, departureTime, destinationTime);
			//flights.push_back(Aflight);
		}
	}
}



int main(int argc, char const *argv[]){
	if (argc==2){
		/*Trip newTrip;
		newTrip.readFile(argv[1]);
		newTrip.userInput();*/
	}
	else{
		cout<<"Wrong command line format!\nCommand line should be 'fly <ddfs.txt>'"<<endl;
		return 0;
	}
	return 0;
}