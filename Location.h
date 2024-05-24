#pragma once
#include <ctime>
#include <string>


class Location final {
private:

	time_t time;
	std::string name;
	double x; // широта 
	double y; // долгота

public:
	
	Location(time_t, std::string, double, double);
	std::string get_name() const;
	time_t get_time() const;
	double get_x() const;
	double get_y() const;

};

