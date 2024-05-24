#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include "Database.h"
#include "Places.h"


class Parser final
{
private:
	
	Database base;
	Places places;

public:
	Parser() = default;
	Parser(std::string&);
	//void init_fields(std::string&);
	Database& get_base();
	Places& get_places();
	void take_date(std::string&);
	void output_data(size_t&);
	time_t parse_time(std::string&);
	//std::string det_place(double, double);
	//void init_data();

};

