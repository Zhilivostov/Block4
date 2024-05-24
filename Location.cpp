#include "Location.h"
#include <algorithm>

Location::Location(time_t _time, std::string _name, double _x, double _y):
	name(_name), time(_time), x(_x), y(_y)
{

}

//Location::cmp
//{
//	bool operator() (Location a, Location b)
//	{
//		return a.give_time() > b.give_time();
//	}
//}

std::string Location::get_name() const
{
	return name;
}

time_t Location::get_time() const
{
	return time;
}

double Location::get_x() const
{
	return x;
}

double Location::get_y() const
{
	return y;
}