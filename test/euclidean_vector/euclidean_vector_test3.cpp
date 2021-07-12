#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("constructor test 2") {
	// Check if unary constructor works.
	auto const a1 = comp6771::euclidean_vector(2);
	CHECK(a1.at(0) == 0);
	CHECK(a1.at(1) == 0);
	CHECK(a1.dimensions() == 2);
}