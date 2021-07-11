#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

TEST_CASE("constructor test 4") {
    std::vector<double> v{10.0, 20.0, 30.0};
	auto const a1 = comp6771::euclidean_vector(v.begin(), v.end());
	CHECK(a1.at(0) == 10.0);
	CHECK(a1.at(1) == 20.0);
	CHECK(a1.at(2) == 30.0);
	CHECK(a1.dimensions() == 3);
}