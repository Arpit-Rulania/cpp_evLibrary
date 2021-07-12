#ifndef COMP6771_EUCLIDEAN_VECTOR_HPP
#define COMP6771_EUCLIDEAN_VECTOR_HPP

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>

namespace comp6771 {
	class euclidean_vector_error : public std::runtime_error {
	public:
		explicit euclidean_vector_error(std::string const& what)
		: std::runtime_error(what) {}
	};

	class euclidean_vector {
	public:
		// Constructors:
		euclidean_vector() noexcept;
		explicit euclidean_vector(int i) noexcept;
		euclidean_vector(int i, double j) noexcept;
		euclidean_vector(std::vector<double>::const_iterator begin, std::vector<double>::const_iterator end) noexcept;
		euclidean_vector(std::initializer_list<double> i) noexcept;
		euclidean_vector(euclidean_vector const& vecc) noexcept;
		euclidean_vector(euclidean_vector && vecc) noexcept;
		// Operations:
		euclidean_vector& operator=(euclidean_vector const& vecc) noexcept;
		euclidean_vector& operator=(euclidean_vector&& vecc) noexcept;
		double& operator[](int i) noexcept;
        double operator[](int i) const noexcept;
        euclidean_vector operator+() noexcept;
        euclidean_vector operator-() noexcept;
        euclidean_vector& operator+=(euclidean_vector const& vecc);
        euclidean_vector& operator-=(euclidean_vector const& vecc);
        euclidean_vector& operator*=(double d) noexcept;
        euclidean_vector& operator/=(double d);
        explicit operator std::vector<double>() noexcept;
        explicit operator std::list<double>() noexcept;

		// Member Functions:
		double at(int i) const;
		double& at(int i);
		int dimensions() const noexcept;

		// Friends:
		friend bool operator==(euclidean_vector const& a, euclidean_vector const& b) noexcept;
		friend bool operator!=(euclidean_vector const& a, euclidean_vector const& b) noexcept;
		friend euclidean_vector operator+(euclidean_vector const& a, euclidean_vector const& b);

	private:
		// ass2 spec requires we use double[]
		// NOLINTNEXTLINE(modernize-avoid-c-arrays)
		std::unique_ptr<double[]> magnitude_;
		std::size_t dimension_;
		// TODO more if needed
	};
} // namespace comp6771
#endif // COMP6771_EUCLIDEAN_VECTOR_HPP
