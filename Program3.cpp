/*
	CS 240 Program3
	Group 6C
	group members:
		Connor Stutsrim
		Robert Valenti
		Xin Xin
*/
#include <iostream>
using namespace std;

#include "Function.h"

int main(int argc, char const *argv[]){
	if (argc==2){
		readFile(argv[1]);
	}
	else{
		cout<<"Wrong command line format!\nCommand line should be 'fly <ddfs.txt>'"<<endl;
		return 0;
	}
	return 0;
}