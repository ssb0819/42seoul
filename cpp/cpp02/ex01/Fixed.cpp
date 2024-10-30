#include "Fixed.hpp"

Fixed::Fixed() : fixed_val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(int const int_val) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed_val = int_val << this->frac_bits;
}

Fixed::Fixed(float const float_val) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_val = roundf(float_val * (1 << this->frac_bits));
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_val = fixed.getRawBits();
	return *this;
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}