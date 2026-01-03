#include "Fixed.hpp"

int main( void ) {
    Fixed a(0.99609375f);
    Fixed const b( Fixed( 5.05f ) * Fixed( 3 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}