#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("utility test 2") {
    // This is to test if unit works correctly and throws appropriate exceptions.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0};
	auto b = comp6771::unit(a);
	CHECK(b.at(0) == Approx(0.2672612419));
	CHECK(b.at(1) == Approx(0.5345224838));
	CHECK(b.at(2) == Approx(0.8017837257));
	// error if dimensions = 0
	auto const c = comp6771::euclidean_vector(0);
	CHECK_THROWS_AS(comp6771::unit(c), comp6771::euclidean_vector_error);
	// error if norm = 0
	auto const d = comp6771::euclidean_vector(0);
	CHECK_THROWS_AS(comp6771::unit(d), comp6771::euclidean_vector_error);
}
