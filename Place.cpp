#include "Place.h"

Place::Place(std::string name_place, double x1_place, double y1_place, double x2_place, double y2_place):
	name(name_place), x1(x1_place), y1(y1_place), x2(x2_place), y2(y2_place)
{
	
}

std::string Place::get_name() const
{
	return name;
}

