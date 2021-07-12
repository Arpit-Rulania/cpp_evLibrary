#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("utility test 3") {
    // This is to test if dot product works correctly and throws appropriate exceptions.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0};
	auto b = comp6771::euclidean_vector{5.0, -2.4, 0};
	auto c = comp6771::dot(a,b);
	CHECK(c == Approx(0.2));
	// error if dimensions are unequal:
	auto d = comp6771::euclidean_vector{5.0};
	CHECK_THROWS_AS(comp6771::dot(a, d), comp6771::euclidean_vector_error);
}
