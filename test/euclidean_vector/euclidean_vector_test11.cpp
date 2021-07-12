#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 3") {
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto b = +a;
	CHECK(b.at(0) == 1.0);
	CHECK(b.at(1) == 2.0);
	CHECK(b.at(2) == 3.0);
	CHECK(b.at(3) == 8.0);
	CHECK(b.at(4) == 22.7);
	CHECK(b.dimensions() == 5);
}