#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 1") {
	auto const a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto const b = comp6771::euclidean_vector{-1.0, 2.0, 3.0, -8.0, 22.7};
	CHECK(b == -a);
}