#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = b * c;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << a << std::endl;
	a = c / b;
	std::cout << a << std::endl;
	std::cout << b / c << std::endl;
	return 0;
}
