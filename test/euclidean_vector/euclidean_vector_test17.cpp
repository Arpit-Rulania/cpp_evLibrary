#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>
#include <vector>

TEST_CASE("Operation test 9") {
	// Check if static_cast<std::vector<double>> overload is working.
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto const vf = static_cast<std::vector<double>>(a);
	CHECK(vf[0] == Approx(1.0));
	CHECK(vf[1] == Approx(-2.0));
	CHECK(vf[2] == Approx(-3.0));
	CHECK(vf[3] == Approx(8.0));
	CHECK(vf[4] == Approx(-22.7));
	CHECK(vf.size() == 5);
}