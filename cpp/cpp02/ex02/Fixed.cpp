#include "Fixed.hpp"

Fixed::Fixed() : fixed_val(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& fixed) {
	*this = fixed;
}

Fixed::Fixed(int const int_val) {
	this->fixed_val = int_val << this->frac_bits;
}

Fixed::Fixed(float const float_val) {
	this->fixed_val = roundf(float_val * (1 << this->frac_bits));
}

int	Fixed::getRawBits() const {
	return fixed_val;
}

void	Fixed::setRawBits(int const raw) {
	fixed_val = raw;
}

float	Fixed::toFloat() const {
	return (static_cast<float>(this->fixed_val) / (1 << this->frac_bits));
}

int	Fixed::toInt() const {
	return (this->fixed_val >> this->frac_bits);
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	fixed_val = fixed.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& fixed) const {
	return (this->fixed_val > fixed.fixed_val);
}

bool Fixed::operator<(const Fixed& fixed) const {
	return (this->fixed_val < fixed.fixed_val);
}

bool Fixed::operator>=(const Fixed& fixed) const {
	return (this->fixed_val >= fixed.fixed_val);
}

bool Fixed::operator<=(const Fixed& fixed) const {
	return (this->fixed_val <= fixed.fixed_val);
}

bool Fixed::operator==(const Fixed& fixed) const {
	return (this->fixed_val == fixed.fixed_val);
}

bool Fixed::operator!=(const Fixed& fixed) const {
	return (this->fixed_val != fixed.fixed_val);
}

Fixed Fixed::operator+(const Fixed& fixed) const {
	Fixed	added(this->toFloat() + fixed.toFloat());
	return (added);
}

Fixed Fixed::operator-(const Fixed& fixed) const {
	Fixed	subtracted(this->toFloat() - fixed.toFloat());
	return (subtracted);
}

Fixed Fixed::operator*(const Fixed& fixed) const {
	Fixed	multiplied(this->toFloat() * fixed.toFloat());
	return (multiplied);
}

Fixed Fixed::operator/(const Fixed& fixed) const {
	Fixed	divided(this->toFloat() / fixed.toFloat());
	return (divided);
}

Fixed& Fixed::operator++() {
	++(this->fixed_val);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);
	++(this->fixed_val);
	return (tmp);
}

Fixed& Fixed::operator--() {
	--(this->fixed_val);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	tmp(*this);
	--(this->fixed_val);
	return (tmp);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	return (f1.fixed_val <= f2.fixed_val ? f1 : f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	return (f1.fixed_val <= f2.fixed_val ? f1 : f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	return (f1.fixed_val >= f2.fixed_val ? f1 : f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	return (f1.fixed_val >= f2.fixed_val ? f1 : f2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}