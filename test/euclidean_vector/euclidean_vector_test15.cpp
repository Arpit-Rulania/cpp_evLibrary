#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 7") {
	// Check if *= overload is working.
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	CHECK_NOTHROW(a *= 1.2);
	CHECK(a.at(0) == Approx(1.2));
	CHECK(a.at(1) == Approx(-2.4));
	CHECK(a.at(2) == Approx(-3.6));
	CHECK(a.at(3) == Approx(9.6));
	CHECK(a.at(4) == Approx(-27.24));
}