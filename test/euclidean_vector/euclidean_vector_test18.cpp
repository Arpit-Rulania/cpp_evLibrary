#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>
#include <list>

TEST_CASE("Operation test 10") {
	// Check if static_cast<std::list<double>> overload is working.
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto const vf = static_cast<std::list<double>>(a);
	bool found = (std::find(vf.begin(), vf.end(), (1.0)) != vf.end());
	CHECK(found == true);
	found = (std::find(vf.begin(), vf.end(), (-2.0)) != vf.end());
	CHECK(found == true);
	found = (std::find(vf.begin(), vf.end(), (-3.0)) != vf.end());
	CHECK(found == true);
	found = (std::find(vf.begin(), vf.end(), (8.0)) != vf.end());
	CHECK(found == true);
	found = (std::find(vf.begin(), vf.end(), (-22.7)) != vf.end());
	CHECK(found == true);
	found = (std::find(vf.begin(), vf.end(), (-22222222.7)) != vf.end());
	CHECK(found == false);
	found = (std::find(vf.begin(), vf.end(), (0)) != vf.end());
	CHECK(found == false);
	CHECK(vf.size() == 5);
}