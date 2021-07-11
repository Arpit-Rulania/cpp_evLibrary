#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>

TEST_CASE("constructor test 1") {
	auto const a1 = comp6771::euclidean_vector();
	CHECK(a1.at(0) == 0);
	CHECK(a1.dimensions() == 1);
}