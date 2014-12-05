#ifndef TIME_H_
#define TIME_H_

#include <string>
#include <iostream>

using namespace std;

class Time {
private:
	int timeInt;

public:
	Time();
	Time(const Time&);
	Time(int);
	
	Time operator+(int duration) const;
	int operator-(const Time& rightTime) const;
	bool operator==(const Time& rightTime) const;

	friend ostream& operator<<(ostream &out, const Time &t);
};


#endif
