#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 6") {
	// Check if -= overload is working.
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto const b = comp6771::euclidean_vector{-1.2, 41.0, 19.0, -3.0, 42.7};
	CHECK_NOTHROW(a -= b);
	CHECK(a.at(0) == Approx(2.2));
	CHECK(a.at(1) == Approx(-43.0));
	CHECK(a.at(2) == Approx(-22.0));
	CHECK(a.at(3) == Approx(11.0));
	CHECK(a.at(4) == Approx(-65.4));
	auto const c = comp6771::euclidean_vector{-1.0, 1.0, 9.0};
	CHECK_THROWS_AS(a -= c, comp6771::euclidean_vector_error);
}