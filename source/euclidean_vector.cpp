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
#include <list>
#include <cmath>

namespace comp6771 {
	// Constructors
	euclidean_vector::euclidean_vector() noexcept{
		dimension_ = 1;
		magnitude_ = std::make_unique<double[]>(dimension_);
		std::fill(magnitude_.get(), magnitude_.get()+dimension_, 0.0);
	}

	euclidean_vector::euclidean_vector(int i) noexcept{
		dimension_ = static_cast<size_t>(i);
		magnitude_ = std::make_unique<double[]>(dimension_);
		std::fill(magnitude_.get(), magnitude_.get()+dimension_, 0.0);
	}

	euclidean_vector::euclidean_vector(int i, double j) noexcept{
		dimension_ = static_cast<size_t>(i);
		magnitude_ = std::make_unique<double[]>(dimension_);
		std::fill(magnitude_.get(), magnitude_.get()+dimension_, j);
	}

	euclidean_vector::euclidean_vector(std::vector<double>::const_iterator begin,
                                       std::vector<double>::const_iterator end) noexcept{
		dimension_ = static_cast<size_t>(end - begin);
        magnitude_ = std::make_unique<double[]>(dimension_);
        std::copy(begin, end, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(std::initializer_list<double> i) noexcept{
		dimension_ = static_cast<size_t>(i.size());
        magnitude_ = std::make_unique<double[]>(dimension_);
        std::copy(i.begin(), i.begin() + dimension_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector const& vecc) noexcept{
		dimension_ = static_cast<size_t>(vecc.dimensions());
	    magnitude_ = std::make_unique<double[]>(dimension_);
	    std::copy(vecc.magnitude_.get(), vecc.magnitude_.get() + dimension_, magnitude_.get());
	}

	euclidean_vector::euclidean_vector(euclidean_vector && vecc) noexcept{
		dimension_ = std::exchange(vecc.dimension_, 0u);
		magnitude_ = std::exchange(vecc.magnitude_, nullptr);
	}

	// Operations
	euclidean_vector& euclidean_vector::operator=(euclidean_vector const& vecc) noexcept {
		dimension_ = static_cast<size_t>(vecc.dimensions());
		std::copy(vecc.magnitude_.get(), vecc.magnitude_.get() + dimension_, magnitude_.get());
		return *this;
	}

	euclidean_vector& euclidean_vector::operator=(euclidean_vector&& vecc) noexcept {
		dimension_ = std::exchange(vecc.dimension_, 0u);
		magnitude_ = std::exchange(vecc.magnitude_, nullptr);
		return *this;
	}

	double& euclidean_vector::operator[](int i) noexcept {
		return magnitude_[static_cast<size_t>(i)];
	}

	double euclidean_vector::operator[](int i) const noexcept {
		return magnitude_[static_cast<size_t>(i)];
	}

	euclidean_vector euclidean_vector::operator+() noexcept {
		auto copy = *this;
		return copy;
	}

	euclidean_vector euclidean_vector::operator-() noexcept {
		std::transform(magnitude_.get(), magnitude_.get() + dimension_,
					   magnitude_.get(), std::negate<double>());
		auto copy = *this;
		return copy;
	}

	euclidean_vector& euclidean_vector::operator+=(euclidean_vector const& vecc) {
		if (dimension_ != static_cast<size_t>(vecc.dimensions())) {
	        std::stringstream msg;
	        msg << "Dimensions of LHS(" << dimension_ << ") and RHS(" << vecc.dimensions() << ") do not match";
	        throw euclidean_vector_error(msg.str());
	    }
	    std::transform(magnitude_.get(), magnitude_.get() + dimension_,
	                   vecc.magnitude_.get(), magnitude_.get(), std::plus<double>());
	    return *this;
	}

	euclidean_vector& euclidean_vector::operator-=(euclidean_vector const& vecc) {
		if (dimension_ != static_cast<size_t>(vecc.dimensions())) {
	        std::stringstream msg;
	        msg << "Dimensions of LHS(" << dimension_ << ") and RHS(" << vecc.dimensions() << ") do not match";
	        throw euclidean_vector_error(msg.str());
	    }
	    std::transform(magnitude_.get(), magnitude_.get() + dimension_,
	                   vecc.magnitude_.get(), magnitude_.get(), std::minus<double>());
	    return *this;
	}

	euclidean_vector& euclidean_vector::operator*=(double d) noexcept {
		std::for_each(magnitude_.get(), magnitude_.get() + dimension_,
					  [d](double& val){ val *= d;});
		return *this;
	}

	euclidean_vector& euclidean_vector::operator/=(double d) {
		if (d == 0) throw euclidean_vector_error("Invalid vector division by 0");
		std::for_each(magnitude_.get(), magnitude_.get() + dimension_,
					  [d](double& val){ val /= d;});
		return *this;
	}

	euclidean_vector::operator std::vector<double>() noexcept {
		std::vector<double> vecc(magnitude_.get(), magnitude_.get() + dimension_);
		return vecc;
	}

	euclidean_vector::operator std::list<double>() noexcept {
		std::list<double> dList(magnitude_.get(), magnitude_.get() + dimension_);
		return dList;
	}

	// Member Functions:
	double euclidean_vector::at(int i) const {
		if (i < 0 || i >= static_cast<int>(dimension_)) {
	        std::stringstream msg;
	        msg << "Index" << i << "is not valid for this euclidean_vector object";
	        throw euclidean_vector_error(msg.str());
	    }
		return magnitude_[static_cast<size_t>(i)];
	}

	double& euclidean_vector::at(int i) {
		if (i < 0 || i >= static_cast<int>(dimension_)) {
	        std::stringstream msg;
	        msg << "Index" << i << "is not valid for this euclidean_vector object";
	        throw euclidean_vector_error(msg.str());
	    }
		return magnitude_[static_cast<size_t>(i)];
	}

	int euclidean_vector::dimensions() const noexcept{
		return static_cast<int>(dimension_);
	}

	// Friends:
	bool operator==(euclidean_vector const& a, euclidean_vector const& b) noexcept{
		if (a.dimensions() != b.dimensions()) {
			return false;
		}
		for (int i = 0; i < a.dimensions(); ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}

	bool operator!=(euclidean_vector const& a, euclidean_vector const& b) noexcept {
		return !(a == b);
	}

	euclidean_vector operator+(euclidean_vector const& a, euclidean_vector const& b) {
		if (a.dimensions() != b.dimensions()) {
	        std::stringstream msg;
	        msg << "Dimensions of LHS(" << a.dimensions() << ") and RHS(" << b.dimensions() << ") do not match";
	        throw euclidean_vector_error(msg.str());
	    }
		auto c = b;
		std::transform(a.magnitude_.get(), a.magnitude_.get() + a.dimensions(),
					   b.magnitude_.get(), c.magnitude_.get(), std::plus<double>());
	    return c;
	}

	euclidean_vector operator-(euclidean_vector const& a, euclidean_vector const& b) {
		if (a.dimensions() != b.dimensions()) {
	        std::stringstream msg;
	        msg << "Dimensions of LHS(" << a.dimensions() << ") and RHS(" << b.dimensions() << ") do not match";
	        throw euclidean_vector_error(msg.str());
	    }
		auto c = b;
		std::transform(a.magnitude_.get(), a.magnitude_.get() + a.dimensions(),
					   b.magnitude_.get(), c.magnitude_.get(), std::minus<double>());
	    return c;
	}

	euclidean_vector operator*(euclidean_vector const& a, double d) noexcept {
		auto b = a;
		std::transform(a.magnitude_.get(), a.magnitude_.get() + a.dimensions(),
					   b.magnitude_.get(), [d](double& val){ return val*(d);});
		return b;
	}

	euclidean_vector operator*(double d, euclidean_vector const& a) noexcept {
		auto b = a;
		std::transform(a.magnitude_.get(), a.magnitude_.get() + a.dimensions(),
					   b.magnitude_.get(), [d](double& val){ return val*(d);});
		return b;
	}

	euclidean_vector operator/(euclidean_vector const& a, double d) {
		if (d == 0) throw euclidean_vector_error("Invalid vector division by 0");
		auto b = a;
		std::transform(a.magnitude_.get(), a.magnitude_.get() + a.dimensions(),
					   b.magnitude_.get(), [d](double& val){ return val/(d);});
		return b;
	}

	std::ostream& operator<<(std::ostream& ostr, euclidean_vector const& a) noexcept {
		ostr << "[";
        if (a.dimensions() > 0) {
            for (int i = 0; i <= a.dimensions() - 1; ++i) {
                ostr << a[i];
                if (i < a.dimensions() - 1) ostr << " ";
            }
	    }
	    ostr << "]";
	    return ostr;
	}

	double euclidean_norm(euclidean_vector const& v) noexcept{
		if (v.dimensions() == 0) return 0;
	    auto d = 0.0;
	    for (int i = 1; i < v.dimensions(); ++i) {
			d += v[i];
	    }
	    d += pow(v[v.dimensions()-1], 2);
		return sqrt(d);
	}

	euclidean_vector unit(euclidean_vector const& v) {
		if (v.dimensions() == 0) {
			throw euclidean_vector_error("euclidean_vector with no dimensions does not have a unit vector");
		}
		auto d = euclidean_norm(v);
		if (d == 0) {
			throw euclidean_vector_error("euclidean_vector with zero euclidean normal does not have a unit vector");
		}
		auto uv = v;
		for (int i = 0; i < v.dimensions(); ++i) {
			uv[i] = v[i]/d;
	    }
		return uv;
	}
}
