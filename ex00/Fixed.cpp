#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point = raw;
}

Fixed::Fixed(const Fixed &a)
{
    // *this = a;
    std::cout << "Copy constructor called" << std:: endl;
    a.getRawBits();
    this->fixed_point = 0;
}

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}