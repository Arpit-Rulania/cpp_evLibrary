#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("friend test 1") {
    // This is to test if == works correctly.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto b = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto d = comp6771::euclidean_vector{1.0, -2.0, 3.0, 8.0, 22.7};
	auto c = (a == b);
	auto e = (a == d);
	CHECK(c == true);
	CHECK(e == false);
}

TEST_CASE("friend test 2") {
    // This is to test if != works correctly.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto b = comp6771::euclidean_vector{1.0, 2.0, 3.0, 8.0, 22.7};
	auto d = comp6771::euclidean_vector{1.0, -2.0, 3.0, 8.0, 22.7};
	auto c = (a != b);
	auto e = (a != d);
	CHECK(c == false);
	CHECK(e == true);
}