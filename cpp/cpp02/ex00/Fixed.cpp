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

Fixed& Fixed::operator= (const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_val = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_val;
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_val = raw;
}