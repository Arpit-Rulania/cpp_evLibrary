#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("constructor test 5") {
	auto const a1 = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	CHECK(a1.at(0) == 1.0);
	CHECK(a1.at(1) == 2.0);
	CHECK(a1.at(2) == 3.0);
	CHECK(a1.at(3) == 8.0);
	CHECK(a1.at(4) == 22.7);
	CHECK(a1.dimensions() == 5);
}