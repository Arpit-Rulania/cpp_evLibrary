// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"
#include  <algorithm>
#include <vector>

namespace comp6771 {
	// Constructors
	euclidean_vector::euclidean_vector() {
		dimension_ = 1;
		magnitude_ = std::make_unique<double[]>(dimension_);
		std::fill(magnitude_.get(), magnitude_.get()+dimension_, 0.0);
	}

	euclidean_vector::euclidean_vector(int i) {
		dimension_ = static_cast<size_t>(i);
		magnitude_ = std::make_unique<double[]>(dimension_);
		std::fill(magnitude_.get(), magnitude_.get()+dimension_, 0.0);
	}

	euclidean_vector::euclidean_vector(int i, double j) {
		dimension_ = static_cast<size_t>(i);
		magnitude_ = std::make_unique<double[]>(dimension_);
		std::fill(magnitude_.get(), magnitude_.get()+dimension_, j);
	}

	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator begin,
                                       std::vector<double>::const_iterator end) {
		dimension_ = static_cast<size_t>(end - begin);
        magnitude_ = std::make_unique<double[]>(dimension_);
        std::copy(begin, end, magnitude_.get());
	}

	// Member Functions:
	double euclidean_vector::at(int i) const {
		return magnitude_[static_cast<size_t>(i)];
	}
}
