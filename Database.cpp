#include "Database.h"
#include <iostream>
#include <fstream>


void Database::add_record(size_t _id, Location _location)
{
	data[_id].insert(_location);
}

void Database::user_route(std::ofstream& output, size_t& id) const
{
	if (data.find(id) == data.end())
		output << "No user`s route!" << std::endl;
	else
	{
		output << "User " << id << " route:" << std::endl;
		for (const auto& locs : data.at(id))
		{
			output << locs.get_name() << "->";
		}
		output << "End";
	}
}

void Database::id_information(std::ofstream& output, size_t& id) const
{
	if (data.find(id) == data.end())
		output << "No id informations!" << std::endl;
	else
	{
		for (const auto& locs : data.at(id))
		{
			output << locs.get_time() << " " << locs.get_name() << " " << locs.get_x() << " " << locs.get_y() << " " << std::endl;
		}
	}
}
