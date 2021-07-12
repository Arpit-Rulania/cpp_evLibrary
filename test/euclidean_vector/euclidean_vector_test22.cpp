#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("friend test 3") {
    // This is to test if c = a+b works correctly and throws exceptions.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto b = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto c = a + b;
	CHECK(c.at(0) == Approx(2.0));
	CHECK(c.at(1) == Approx(4.0));
	CHECK(c.at(2) == Approx(6.0));
	CHECK(c.at(3) == Approx(16.0));
	CHECK(c.at(4) == Approx(45.4));
	auto d = comp6771::euclidean_vector{1.0};
	CHECK_THROWS_AS(a + d, comp6771::euclidean_vector_error);
}