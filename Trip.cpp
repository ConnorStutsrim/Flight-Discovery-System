#include <string>		//string
#include <iostream>		//cin/cout
#include <vector>		//vector
#include <fstream>		//read/write file
using namespace std;

#include "Trip.h"
#include "Flight.h"

Trip::Trip(){}
Trip::~Trip(){}
void Trip::readFile(char const *filename){
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
}
void Trip::userInput(){
	string temp;

	//Departure Information
	cout<<"Please Specify Departure Information: "<<endl;
	while(1){
		cout<<"Departure_City: ";
		getline(cin,temp);
		if (checkCity(temp)){
			depart=temp;
			break;
		}
		else{cout<<"Wrong Format!"<<endl;}
	}
	
	while(1){
		cout<<"Destination_City: ";
		getline(cin,temp);
		if (checkCity(temp)){
			dest=temp;
			break;
		}
		else{cout<<"Wrong Format!"<<endl;}
	}

	while(1){
		cout<<"Departure Date(DD/MM/YYYY): ";
		getline(cin,temp);
		if (checkDate(temp)){
			depDate=temp;
			break;
		}
		else{cout<<"Wrong Format!"<<endl;}
	}
	
	while(1){
		cout<<"Earliest Acceptable Departure Time(HH:MMam/pm): ";
		getline(cin,temp);
		if (checkTime(temp)){
			depTime=temp;
			break;
		}
		else{cout<<"Wrong Format!"<<endl;}
	}
	
	//Return Trip Information
	cout<<"Please Specify Return Trip Information: "<<endl;

	while(1){
		cout<<"Return Date(DD/MM/YYYY): ";
		getline(cin,temp);
		if (checkDate(temp)){
			returnDate=temp;
			break;
		}
		else{cout<<"Wrong Format!"<<endl;}
	}
	
	while(1){
		cout<<"Earliest Acceptable Return Time(HH:MMam/pm): ";
		getline(cin,temp);
		if (checkTime(temp)){
			returnTime=temp;
			break;
		}
		else{cout<<"Wrong Format!"<<endl;}
	}
	
}

bool checkCity(string str){
	for (int i = 0; i < str.length(); ++i){
		if (str[i] !='_' && (str[i]<65 || str[i]>90) && (str[i]<97 || str[i]>122)){
			return 0;
		}
	}
	if (str.length()==0){
		return 0;
	}
	return 1;
}
bool checkDate(string str){
	if (str[0]>47 && str[0]<52 && str[1]>47 && str[1]<58 && str[2]=='/' && (str[3]=='0'||str[3]=='1') && str[4]>47 && str[4]<58 && str[5]=='/' && str[6]>47 && str[6]<58 && str[7]>47 && str[7]<58 && str[8]>47 && str[8]<58 && str[9]>47 && str[9]<58){
		return 1;
	}
	return 0;
}
bool checkTime(string str){
	if (str[0]=='0'){
		if (str[1]>47 && str[1]<58 && str[2]==':' && str[3]>47 &&str[3]<55 && str[4]>47 && str[4]<58 && (str[5]=='a'||str[5]=='p') && str[6]=='m'){
			return 1;
		}
	}
	if (str[0]=='1'){
		if (str[1]>47 && str[1]<51 && str[2]==':' && str[3]>47 &&str[3]<55 && str[4]>47 && str[4]<58 && (str[5]=='a'||str[5]=='p') && str[6]=='m'){
			return 1;
		}
	}
	return 0;
}
int Date(string str){
	return (str[9]-48)*10000+(str[8]-48)*100000+(str[7]-48)*1000000+(str[6]-48)*10000000+(str[4]-48)*1000+(str[3]-48)*100+(str[1]-48)*10+(str[0]-48)
}