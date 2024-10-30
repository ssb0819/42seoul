#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixed_val;
	static const int	frac_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed(int const int_val);
	Fixed(float const float_val);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat() const;
	int		toInt() const;

	Fixed& operator=(const Fixed& fixed);
	bool operator>(const Fixed& fixed) const;
	bool operator<(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed) const;
	bool operator<=(const Fixed& fixed) const;
	bool operator==(const Fixed& fixed) const;
	bool operator!=(const Fixed& fixed) const;
	Fixed operator+(const Fixed& fixed) const;
	Fixed operator-(const Fixed& fixed) const;
	Fixed operator*(const Fixed& fixed) const;
	Fixed operator/(const Fixed& fixed) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed&	min(Fixed& f1, Fixed& f2);
	const static Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&	max(Fixed& f1, Fixed& f2);
	const static Fixed&	max(const Fixed& f1, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
