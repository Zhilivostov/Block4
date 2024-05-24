#pragma once
#include "Place.h"
#include <fstream>
#include <vector>

class Places final {
private:
	std::vector<Place> places;

public:
	Places() = default;
	Places(std::string&);

	std::string check_range(double, double) const;


};