#pragma once
#include <map>
#include <set>
#include "Location.h"
#include <string>

//bool operator<(const Location& left, const Location& right) 
//{
//	return (left.give_time() < right.give_time()) || (left.give_name() < right.give_name()) || (left.give_latitude() < right.give_latitude()) || (left.give_longitude() < right.give_longitude());
//	//return left.give_time() < right.give_time();
//}

struct cmp {
	bool operator() (Location a, Location b) const
	{
		return a.get_time() > b.get_time();// || (a.get_name() < b.get_name()) || (a.get_x() < b.get_x()) || (a.get_y() < b.get_y());
	}
};

class Database final
{
private:

	std::map<size_t, std::set<Location, cmp>> data; //через класс парсер вставлять не локацию, а адрес вместе с названием места, то есть уже обработанные координаты а не сырые из файла

public:
	Database() = default;
	void add_record(size_t, Location);
	void user_route(std::ofstream&, size_t&) const;
	void id_information(std::ofstream&, size_t&) const;
};

