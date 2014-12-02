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
	Time(const Time &t);
	Time(int time);
	
	Time operator+(const Time& rightTime) const;
	Time operator-(const Time& rightTime) const;
	bool operator==(const Time& rightTime) const;

	friend ostream& operator<<(ostream &out, const Time &t);
};


#endif