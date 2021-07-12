#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 2") {
	// Check if [] overload is working.
	auto a1 = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	double a {a1[4]};
	CHECK(a == 22.7);
	a1[1] = 12.33;
	double b {a1[1]};
	CHECK(b == 12.33);
}