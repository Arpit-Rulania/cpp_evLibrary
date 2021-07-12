#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("utility test 1") {
    // This is to test if norm works correctly and throws appropriate exceptions.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0};
	auto b = comp6771::euclidean_norm(a);
	CHECK(b == Approx(3.74165739));
	auto const c = comp6771::euclidean_vector(0);
	auto d = comp6771::euclidean_norm(c);
	CHECK(d == Approx(0));
}