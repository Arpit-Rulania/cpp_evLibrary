#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("friend test 5") {
    // This is to test if (b = a * constant) works correctly.
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto b = -1.2 * a;
	CHECK(b.at(0) == Approx(-1.2));
	CHECK(b.at(1) == Approx(2.4));
	CHECK(b.at(2) == Approx(3.6));
	CHECK(b.at(3) == Approx(-9.6));
	CHECK(b.at(4) == Approx(27.24));
}

TEST_CASE("friend test 6") {
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto b = a * 1.2;
	CHECK(b.at(0) == Approx(1.2));
	CHECK(b.at(1) == Approx(-2.4));
	CHECK(b.at(2) == Approx(-3.6));
	CHECK(b.at(3) == Approx(9.6));
	CHECK(b.at(4) == Approx(-27.24));
}