#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 3") {
    // This is to test if .at() works correctly and throws required exceptions.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	CHECK(a.at(0) == 1.0);
	CHECK(a.at(1) == 2.0);
	CHECK(a.at(2) == 3.0);
	CHECK(a.at(3) == 8.0);
	CHECK(a.at(4) == 22.7);
	a.at(4) = 50.0;
	CHECK(a.at(4) == 50.0);
	CHECK(a.dimensions() == 5);
	CHECK_THROWS_AS(a.at(9), comp6771::euclidean_vector_error);
	CHECK_THROWS_AS(a.at(-1), comp6771::euclidean_vector_error);
	CHECK_THROWS_AS(a.at(9) = 1, comp6771::euclidean_vector_error);
	CHECK_THROWS_AS(a.at(-1) = 1, comp6771::euclidean_vector_error);
}