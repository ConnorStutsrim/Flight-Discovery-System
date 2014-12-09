#include "Time.h"

/*
Constructors
*/

// efault Constructor
Time::Time()
{
	timeInt = 0;
}
// Copy Constructor
Time::Time(const Time &t) {
	timeInt = t.timeInt;
}
// int-Value Constructor
Time::Time(int time) {
	timeInt = time;
}

/*
Operators
*/
// Time + int operator
// returns a Time equal to this plus argument number of minutes
Time Time::operator+(int duration) const {
	Time t;
	t.timeInt = this->timeInt + duration;
	return t;
}
// Time - Time operator
// returns an integer number of minutes between this and argument
int Time::operator-(const Time& rightTime) const {
	int i;
	i = this->timeInt - rightTime.timeInt;
	return i;
}

// Time == Time operator
// returns true if this and argument represent the same time
bool Time::operator==(const Time& rightTime) const {
	return this->timeInt == rightTime.timeInt;
}

// ostream << Time operator
// Outputs the Time argument to the ostream argument in <HH:mm><am/pm> format
ostream &operator<<(ostream &out, const Time &t) {
	string timeString;
	int timeTemp = t.timeInt;
	int hours = 0;
	int minutes = 0;
	bool am = true;
	
	// Converting number of minutes since midnight to military time
	while (timeTemp >= 60) {
		timeTemp -= 60;
		hours++;
	}
	minutes = timeTemp;
	
	// Converting military time to am/pm
	if (hours >= 12) {
		am = false;
		hours -= 12;
	}
	if (hours > 0 && hours < 10) {
		timeString.push_back(hours + 48);
	}
	else if (hours >= 10) {
		timeString.push_back('1');
		timeString.push_back((hours % 10) + 48);
	}
	else {
		timeString = "12";
	}
	timeString.push_back(':');
	timeString.push_back((minutes / 10) + 48);
	timeString.push_back((minutes % 10) + 48);
	if (am) {
	  timeString.push_back('a');
	}
	else {
		timeString.push_back('p');
	}
	timeString.push_back('m');
	out << timeString;
	return out;
}
