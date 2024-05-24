#pragma once
#include <string>
#include <vector>



class Place final {
public:
	std::string name;
	double x1;
	double y1;
	double x2;
	double y2;

public:
	Place(std::string, double, double, double, double);

	std::string get_name() const;

};
