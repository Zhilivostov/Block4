//#include "pch.h"
#include "Parser.h"
#include <gtest/gtest.h>

TEST(Testwork, Goodsituation)
{
	std::string file = "Places.txt";
	std::string id_file = "User_locations.txt";
	size_t one = 01;
	size_t two = 02;
	size_t three = 03;
	size_t four = 04;
	Parser pp(file);
	EXPECT_NO_THROW(pp.take_date(id_file));
	pp.output_data(one);
	pp.output_data(two);
	pp.output_data(three);
	EXPECT_NO_THROW(pp.output_data(four));
}