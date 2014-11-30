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
		if (!checkDepCity(temp,flights)){
			cout<<"No Such Departure City in File!"<<endl;
		}
		else{
			depart=temp;
			break;
		}
	}
	
	while(1){
		cout<<"Destination_City: ";
		getline(cin,temp);
		if (!checkDesCity(temp,flights)){
			cout<<"No Such Destination City in File!"<<endl;
		}
		else if (temp==depart){
			cout<<"Same Departure_City and Destination_City!"<<endl;
		}
		else{
			dest=temp;
			break;
		}
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
		if (!checkDate(temp)){
			cout<<"Wrong Format!"<<endl;
		}
		else if (Date(temp)<Date(depDate)){
			cout<<"Return Date Must Be After Departure Date!"<<endl;
		}
		else{
			returnDate=temp;
			break;
		}
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

void Trip::Objective(){
	string temp;
	cout<<"\n\nCustomer Objective Options: \nJ: Just Get Me There\nF: Fewest Hops\nS: Shortest Trip\nC: Cheapest\n\nP: Display the entire Daily Flight Schedule"<<endl;
	getline(cin, temp);
	if (temp=="J"){
		/* code */
	}
	else if (temp=="F"){
		cout<<temp<<endl;
	}
	else if (temp=="S"){
		cout<<temp<<endl;
	}
	else if (temp=="C"){
		cout<<temp<<endl;
	}
	else if (temp=="P"){
		cout<<temp<<endl;
	}
}

bool checkDepCity(string str,vector<Flight> flights){
	for (std::vector<Flight>::iterator i = flights.begin(); i != flights.end(); ++i){
		if ((*i).checkDep(str)){
			return 1;
		}
	}
	return 0;
}
bool checkDesCity(string str,vector<Flight> flights){
	for (std::vector<Flight>::iterator i = flights.begin(); i != flights.end(); ++i){
		if ((*i).checkDes(str)){
			return 1;
		}
	}
	return 0;
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
	int x= (str[9]-48)*10000+(str[8]-48)*100000+(str[7]-48)*1000000+(str[6]-48)*10000000+(str[4]-48)*1000+(str[3]-48)*100+(str[0]-48)*10+(str[1]-48);
	return x;
}