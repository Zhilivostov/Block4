#include "Parser.h"
#include "Location.h"
#include <chrono>
#include <ctime>
#include <iomanip>

const char* timeformat = "%Y-%m-%dT%H:%M:%S";
std::string txt = ".txt";

Parser::Parser(std::string& in_places):
	base(Database()), places(Places(in_places))
{

}

Database& Parser::get_base()
{
	return base;
}

Places& Parser::get_places()
{
	return places;
}

//void Parser::init_fields(std::string& in_places)
//{
//	places = Places(in_places);
//	base = Database();
//}

void Parser::take_date(std::string& _input)
{
	std::ifstream input(_input);
	while (!input.eof())
	{
		std::string time;
		size_t id;
		double x, y;
		input >> time >> id >> x >> y;
		Location location(parse_time(time), places.check_range(x, y), x, y);
		base.add_record(id, location);
	}
	input.close();
}

void Parser::output_data(size_t& id)
{
	std::string out_name = std::to_string(id)+txt;
	std::ofstream out(out_name);
	base.id_information(out, id);
	base.user_route(out, id);
	out.close();

}

time_t Parser::parse_time(std::string& time_string)
{
	tm time_tm;
	std::istringstream ss(time_string);
	if (!(ss >> std::get_time(&time_tm, timeformat)) || ss.fail())
		throw std::invalid_argument("Wrong time's format!");

	return mktime(&time_tm);
}


//std::string Parser::det_place(double latitude, double longitude)
//{
//	return places.check_range(latitude, longitude);
//}

//void Parser::init_data()
//{
//
//}
