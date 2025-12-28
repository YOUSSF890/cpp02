#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed b;
    Fixed c;
    // c.setRawBits(10);
    // a.setRawBits(15);

    // c = a + b;
    // std::cout << c.getRawBits() << std::endl;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    // std::cout << b << std::endl;
    std::cout << Fixed::max( a, c ) << std::endl;
    std::cout << Fixed::max( a, c ) << std::endl;
    std::cout << Fixed::min( a, c ) << std::endl;
    std::cout << Fixed::min( a, c ) << std::endl;
    // c = Fixed::max( a, c );
    // std::cout << c.getRawBits() << std::endl;

    return 0;
}