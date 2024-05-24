#include "Places.h"
#include <algorithm>

Places::Places(std::string& _input)
{
	std::ifstream input(_input);
	if (input.is_open() != true)
		throw std::invalid_argument("This file does not exist!");
	while (!input.eof())
	{
		std::string name_place;
		double x1, y1, x2, y2;
		input >> name_place >> x1 >> y1 >> x2 >> y2;
		places.push_back(Place(name_place, x1, y1, x2, y2));
	}

	input.close();
}

std::string Places::check_range(double x, double y) const //широта это х, а долгота это у
{
	std::string name_out;
	for (auto& place : places)  //vector string ready!!
	{
		double x_min = std::min(place.x1, place.x2);
		double x_max = std::max(place.x1, place.x2);
		double y_min = std::min(place.y1, place.y2);
		double y_max = std::max(place.y1, place.y2);
		if ((x_min <= x) && (x_max >= x) && (y_min <= y) && (y_max >= y))
		{
			/*for (size_t i = 0; i < places.size(); i++)
			{
				name_out += place.name;
				name_out += " ";
			}*/
			//name_out = place.get_name();
			name_out += place.get_name();
			name_out += " ";
			return name_out;
		}
	}
	return "Unknown Place";
}
