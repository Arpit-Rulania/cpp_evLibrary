#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 8") {
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	CHECK_NOTHROW(a /= 1.2);
	CHECK(a.at(0) == Approx(0.83333333));
	CHECK(a.at(1) == Approx(-1.66666667));
	CHECK(a.at(2) == Approx(-2.5));
	CHECK(a.at(3) == Approx(6.66666667));
	CHECK(a.at(4) == Approx(-18.9166667));
	CHECK_THROWS_AS(a /= 0, comp6771::euclidean_vector_error);
}