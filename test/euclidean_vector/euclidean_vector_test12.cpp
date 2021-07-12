#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("Operation test 4") {
	auto a = comp6771::euclidean_vector{1.0, -2.0, -3.0, 8.0, -22.7};
	auto const b = comp6771::euclidean_vector{-1.0, 2.0, 3.0, -8.0, 22.7};
	-a;
	std::cout << a.at(2) << '\n';
	CHECK(a.at(0) == b.at(0));
	CHECK(a.at(1) == b.at(1));
	CHECK(a.at(2) == b.at(2));
	CHECK(a.at(3) == b.at(3));
	CHECK(a.at(4) == b.at(4));
}