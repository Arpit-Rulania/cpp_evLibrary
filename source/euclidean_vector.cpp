// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "comp6771/euclidean_vector.hpp"
#include  <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <span>
#include <sstream>

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

	euclidean_vector::euclidean_vector(euclidean_vector const& vecc) {
		dimension_ = static_cast<size_t>(vecc.dimensions());
	    magnitude_ = std::make_unique<double[]>(dimension_);
	    std::copy(vecc.magnitude_.get(), vecc.magnitude_.get() + dimension_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector && vecc) {
		dimension_ = std::exchange(vecc.dimension_, 0u);
		magnitude_ = std::exchange(vecc.magnitude_, nullptr);
	}

	// Operations
	euclidean_vector& euclidean_vector::operator=(euclidean_vector const& vecc) {
		euclidean_vector copy = vecc;
		std::swap(copy, *this);
		return *this;
	}

	double& euclidean_vector::operator[](int i) noexcept {
		return magnitude_[static_cast<size_t>(i)];
	}

	double euclidean_vector::operator[](int i) const noexcept {
		return magnitude_[static_cast<size_t>(i)];
	}

	euclidean_vector euclidean_vector::operator+() {
		auto copy = *this;
		return copy;
	}

	euclidean_vector euclidean_vector::operator-() {
		/*
		std::for_each(magnitude_.get(), magnitude_.get() + dimension_, [](double& val){
																			val = val*(-1);
																		});
		*/
		std::transform(magnitude_.get(), magnitude_.get() + dimension_, magnitude_.get(), std::negate<double>());
		auto copy = *this;
		return copy;
	}

	euclidean_vector& euclidean_vector::operator+=(euclidean_vector const& vecc) {
		if (dimension_ != static_cast<size_t>(vecc.dimensions())) {
	        std::stringstream msg;
	        msg << "Dimensions of LHS(" << dimension_ << ") and RHS(" << vecc.dimensions() << ") do not match";
	        throw euclidean_vector_error(msg.str());
	    }
	    std::transform(magnitude_.get(), magnitude_.get() + dimension_, vecc.magnitude_.get(), magnitude_.get(), std::plus<double>());
	    return *this;
	}

	euclidean_vector& euclidean_vector::operator-=(euclidean_vector const& vecc) {
		if (dimension_ != static_cast<size_t>(vecc.dimensions())) {
	        std::stringstream msg;
	        msg << "Dimensions of LHS(" << dimension_ << ") and RHS(" << vecc.dimensions() << ") do not match";
	        throw euclidean_vector_error(msg.str());
	    }
	    std::transform(magnitude_.get(), magnitude_.get() + dimension_, vecc.magnitude_.get(), magnitude_.get(), std::minus<double>());
	    return *this;
	}

	euclidean_vector& euclidean_vector::operator*=(double d) {
		std::for_each(magnitude_.get(), magnitude_.get() + dimension_, [d](double& val){
																			val *= d;
																		});
		/*std::transform(magnitude_.get(), magnitude_.get() + dimension_, magnitude_.get(), [d](double& val){
																								return val*(d);
																							});*/
		return *this;
	}

	euclidean_vector& euclidean_vector::operator/=(double d) {
		if (d == 0) throw euclidean_vector_error("Invalid vector division by 0");
		std::for_each(magnitude_.get(), magnitude_.get() + dimension_, [d](double& val){
																			val /= d;
																		});
		return *this;
	}

	euclidean_vector::operator std::vector<double>() noexcept{
		std::vector<double> vecc(magnitude_.get(), magnitude_.get() + dimension_);
		return vecc;
	}

	// Member Functions:
	double euclidean_vector::at(int i) const {
		return magnitude_[static_cast<size_t>(i)];
	}

	int euclidean_vector::dimensions() const {
		return static_cast<int>(dimension_);
	}
}
