#include "Fixed.hpp"

void	test(void) {
	Fixed	a(1.0f);
	Fixed	b(2);

	std::cout << "------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a > b ? "true" : "false") << std::endl;
	std::cout << (a != b ? "true" : "false") << std::endl;
	std::cout << a + b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a - b << std::endl;	
	std::cout << ++a << std::endl;
	std::cout << --b << std::endl;
}

int	main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// test();
	
	return 0;
}