#include "Time.h"

Time::Time() {
	timeInt = 0;
}

Time::Time(const Time &t) {
	timeInt = t.timeInt;
}

Time::Time(int time) {
	timeInt = time;
}


Time Time::operator+(const Time& rightTime) const {
	Time t;
	t.timeInt = this->timeInt + rightTime.timeInt;
	return t;
}

Time Time::operator-(const Time& rightTime) const {
	Time t;
	t.timeInt = this->timeInt - rightTime.timeInt;
	return t;
}

bool Time::operator==(const Time& rightTime) const {
	return this->timeInt == rightTime.timeInt;
}

ostream &operator<<(ostream &out, const Time &t) {
	string timeString;
	int timeTemp = t.timeInt;
	int hours;
	int minutes;
	bool am = true;
	while (timeTemp > 60) {
		timeTemp -= 60;
		hours += 1;
	}
	minutes = timeTemp;
	if (hours >= 12) {
		am = false;
		hours -= 12;
	}
	if (hours > 0 && hours < 10) {
		timeString[0] = hours + 48;
	}
	else if (hours >= 10) {
		timeString[0] = '1';
		timeString[1] = hours + 48;
	}
	else {
		timeString = "12";
	}
	timeString[2] = ':';
	timeString[3] = (minutes / 10) + 48;
	timeString[4] = (minutes % 10) + 48;
	out << timeString;
}