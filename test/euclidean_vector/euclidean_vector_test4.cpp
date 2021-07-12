#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("constructor test 3") {
	// Check if 2 parameter constructor works.
	auto const a1 = comp6771::euclidean_vector(3, 3.0);
	CHECK(a1.at(0) == 3);
	CHECK(a1.at(1) == 3);
	CHECK(a1.at(2) == 3);
	CHECK(a1.dimensions() == 3);
}