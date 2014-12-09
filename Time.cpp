#include "Time.h"

Time::Time()
{
	timeInt = 0;
}

Time::Time(const Time &t) {
	timeInt = t.timeInt;
}

Time::Time(int time) {
	timeInt = time;
}


Time Time::operator+(int duration) const {
	Time t;
	t.timeInt = this->timeInt + duration;
	return t;
}

int Time::operator-(const Time& rightTime) const {
	int i;
	i = this->timeInt - rightTime.timeInt;
	return i;
}

bool Time::operator==(const Time& rightTime) const {
	return this->timeInt == rightTime.timeInt;
}

ostream &operator<<(ostream &out, const Time &t) {
	string timeString;
	int timeTemp = t.timeInt;
	int hours = 0;
	int minutes = 0;
	bool am = true;
	while (timeTemp >= 60) {
		timeTemp -= 60;
		hours++;
	}
	minutes = timeTemp;
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
		timeString.push_back("am");
	}
	else {
		timeString.push_back("pm");
	}
	out << timeString;
	return out;
}
