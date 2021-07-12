#include "comp6771/euclidean_vector.hpp"

#include <catch2/catch.hpp>
#include <iostream>
#include <utility>

TEST_CASE("utility test 1") {
    // This is to test if norm works correctly and throws appropriate exceptions.
	auto a = comp6771::euclidean_vector{1.0, 2.0, 3.0};
	auto b = unit(a);
	CHECK(b.at(0) == Approx(0.2672612419));
	CHECK(b.at(1) == Approx(0.5345224838));
	CHECK(b.at(2) == Approx(0.8017837257));
	//auto const c = comp6771::euclidean_vector(0);
	//auto d = comp6771::euclidean_norm(c);
	//CHECK(d == Approx(0));
}
