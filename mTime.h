#pragma once
#pragma once
#include <iostream>
using namespace std;

class mTime
{
	int hour{};
	int min{};
	int sec{};
public:
	//add constructurs getter setters and stream output function, which output time in given format Hr : Min: Sec
	mTime();
	mTime(int h, int m, int s);
	mTime(mTime& t);
	void set_time(int h, int m, int s);
	void set_hours(int h);
	void set_min(int m);
	void set_sec(int s);
	void get_time();
	int get_hours();
	int get_min();
	int get_sec();
	friend ostream& operator<< (ostream& out, const mTime& t);
};

mTime::mTime()
{
	hour = 0;
	min = 0;
	sec = 0;
}

mTime::mTime(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

mTime::mTime(mTime& t)
{
	if (t.hour > 0 && t.min > 0 && t.sec > 0)
	{
		hour = t.hour;
		min = t.min;
		sec = t.sec;
	}
}

void mTime::set_time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void mTime::set_hours(int h)
{
	hour = h;
}

void mTime::set_min(int m)
{
	min = m;
}

void mTime::set_sec(int s)
{
	sec = s;
}

void mTime::get_time()
{
	cout << hour << " : " << min << " : " << sec;
}

int mTime::get_hours()
{
	return hour;
}

int mTime::get_min()
{
	return min;
}

int mTime::get_sec()
{
	return sec;
}

ostream& operator<< (ostream& out, const mTime& t)
{
	out << t.hour << " : " << t.min << " : " << t.sec;
	return out;
}