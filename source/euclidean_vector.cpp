// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"
#include  <algorithm>
#include <vector>
#include <utility>

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

	euclidean_vector::euclidean_vector(std::initializer_list<double> i) {
		dimension_ = static_cast<size_t>(i.size());
        magnitude_ = std::make_unique<double[]>(dimension_);
        std::copy(i.begin(), i.begin() + dimension_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector const& ev) {
		dimension_ = static_cast<size_t>(ev.dimensions());
	    magnitude_ = std::make_unique<double[]>(dimension_);
	    std::copy(ev.magnitude_.get(), ev.magnitude_.get() + dimension_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector && ev) {
		dimension_ = std::exchange(ev.dimension_, 0u);
		magnitude_ = std::exchange(ev.magnitude_, nullptr);
	}

	// Operations
	double& euclidean_vector::operator[](int i) noexcept {
		return magnitude_[static_cast<size_t>(i)];
	}

	double euclidean_vector::operator[](int i) const noexcept {
		return magnitude_[static_cast<size_t>(i)];
	}

	// Member Functions:
	double euclidean_vector::at(int i) const {
		return magnitude_[static_cast<size_t>(i)];
	}

	int euclidean_vector::dimensions() const {
		return static_cast<int>(dimension_);
	}

	void euclidean_vector::setAt(size_t i, double doub) const {
		magnitude_[i] = doub;
	}
}
